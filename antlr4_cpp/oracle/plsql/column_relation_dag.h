/*************************************************************************
* @file column_relation_dag.h
* @brief data structure for column dag
* 遍历 column_dag 算法，生成 map
* 1. 查询之前，先加载一次等价条件，因为有时候给出的 mask_item 可能不会出现在子查询
*    中,仅仅作为等价条件出现在 join_on_part 中
* 2. 在 table_to_column_list 中查询表是否存在，如果存在，说明在当前子查询中使用
*    了该表，同时，查找列是否存在，如果存在，将该列信息加入到 map_columns_list
* 3. 根据第 2 步中的子查询名称 subquery_name，在 table_to_subquery_list 中查询 
*    子查询是否存在，如果存在，说明该子查询存在别名(比如from (...) t) 或者该
*    子查询是在 with clause 中。
* 4. 根据 map_columns_list，在 equivalent_cond_list 中查询等价条件，并将等价
*    条件加入到 map_columns_list
* 5. 每增加一个新的等价条件，都需要重复 2 - 4 步骤
* @author Jona
* @date 10/09/2019
*************************************************************************/
#ifndef __COLUMN_RELATION_DAG_H__ 
#define __COLUMN_RELATION_DAG_H__ 

#include <string>
#include <vector>

#include "item.h"

// relationships with table and subquery
struct Table2Subquery {
    std::string table_name;
    std::string subquery_name;
};

// from table_list to column_list
struct Tables2Columns {
    std::string subquery_name;  // pointer out which subquery it is
    TableItemList from;
    ColumnItemList to;
};

// equivalent conditions 
struct EquivalentCond {
    ColumnItem from;
    ColumnItem to;
};

typedef std::vector<Table2Subquery> Table2SubqueryList;
typedef std::vector<Tables2Columns> Tables2ColumnsList;
typedef std::vector<EquivalentCond> EquivalentCondList;

struct ColumnDAG {
    Table2SubqueryList table_to_subquery_list;
    Tables2ColumnsList table_to_column_list;
    EquivalentCondList equivalent_cond_list;

    void clear() {
      table_to_subquery_list.clear();
      table_to_column_list.clear();
      equivalent_cond_list.clear();
    }
};

static const int SUBQUERY_SUFFIX = 0;
static const int SUBQUERY_WITHCLAUSE = 1;
static const int SUBQUERY_TABLE_PREFIX = 2;
static const int SUBQUERY_IN_ELEMENTS_PREFIX = 3;
static const int SUBQUERY_ATOM_PREFIX = 4;

static std::map<int, std::string> SUBQUERY_NAMES_PART = {
  {SUBQUERY_SUFFIX, "_SUBQUERY_SECSMART"}, 
  {SUBQUERY_WITHCLAUSE, "_WITHCLAUSE_SECSMART"}, 
  {SUBQUERY_TABLE_PREFIX, "TABLE_REF_SECSMART_"},
  {SUBQUERY_IN_ELEMENTS_PREFIX, "IN_ELEMENTS_SECSMART_"},
  {SUBQUERY_ATOM_PREFIX, "ATOM_SECSMART_"}
};

static void TravelColumnDag(const ColumnDAG &dag) {
  Table2Subquery tb2subquery;
  Tables2Columns tb2column;
  EquivalentCond equ_cond;

  // show equivalent conditions
  std::cout << "===========equivalent_cond_list===========\n";
  for (auto equ_cond : dag.equivalent_cond_list) {
    std::cout << "from---> ";
    std::cout << "table_name: " << equ_cond.from.table 
      << ", column: " << equ_cond.from.column << std::endl;
    std::cout << "to-----> ";
    std::cout << "table_name: " << equ_cond.to.table
      << ", column: " << equ_cond.to.column << std::endl;
  }

  std::cout << "\n===========table to subquery list===========\n";
  for (auto tb2subquery : dag.table_to_subquery_list) {
    std::cout << tb2subquery.table_name << " <--> " << tb2subquery.subquery_name << std::endl;
  }

  std::cout << "\n===========table to column list===========\n";
  for (auto tb2column : dag.table_to_column_list) {
    std::cout << "subquery_name: " << tb2column.subquery_name << std::endl;
    std::cout << "table list [schema, table, alias]---> \n";
    for (auto table_item : tb2column.from) {
      std::cout << "[" << table_item.schema << ", " 
        << table_item.table << ", " << table_item.alias << "], ";
    }
    std::cout << std::endl;

    std::cout << "column list --> ";
    for (auto column_item : tb2column.to) {
      std::cout << "[" << column_item.schema<< ", " 
        << column_item.table << ", " << column_item.column << ", " 
        << column_item.alias << "],    ";
    }
    std::cout << std::endl << std::endl;
  }
}

static bool StrCaseCmp(const std::string &str1, const std::string &str2) {
  return strcasecmp(str1.c_str(), str2.c_str()) == 0;
}

std::string& string_tolower(std::string &str) {
  std::transform(str.begin(), str.end(), str.begin(), 
      [](unsigned char c) -> unsigned char { return std::tolower(c); });
  return str;
}

static bool IsItemInMap(std::map<ColumnItem, ColumnItemList> &map, 
    ColumnItem &item) {
  for (auto iter=map.begin(); iter!=map.end(); ++iter) {
    for (auto col_item : iter->second) {
      if (StrCaseCmp(item.table, col_item.table)
          && StrCaseCmp(item.column, col_item.column)) {
        // item exists in map, don't add again
        return true;
      }
    }
  }

  return false;
}

/***********************************************************
 * get map_columns from column_dag based on column_item, the key is key
 * @author Jona
 * @param 
 * * @map_columns 
 * * @key key in map_columns
 * * @column_dag 
 * * @column_item
 * @date 17/09/2019 
***********************************************************/ 
static void FindFromTableToColumnList(
    std::map<ColumnItem, ColumnItemList> &map_columns,
    ColumnItem &key,
    ColumnDAG &column_dag,
    ColumnItem &column_item) {
  bool matched = false;
  TableItem tb_item_save;     // save matched table and column info
  ColumnItem col_item_save;
  auto table_to_column_list = column_dag.table_to_column_list;

  tb_item_save.clear();
  col_item_save.clear();
  for (auto table2column : table_to_column_list){
    for (auto table_item : table2column.from) {
      if (StrCaseCmp(table_item.table, column_item.table)
          || (!table_item.alias.empty()
            && StrCaseCmp(table_item.alias, column_item.table))) {
        // matched table name
        matched = true;
        tb_item_save = table_item;
        break;
      }
    }

    // add table name first and then check IsItemInMap, finally to decide whether
    // to insert or not
    std::string cur_query_name = table2column.subquery_name;
    if (matched) {
      for (auto col_item : table2column.to) {
        if (StrCaseCmp(col_item.column, column_item.column) 
            || (!column_item.alias.empty() 
              && StrCaseCmp(col_item.column, column_item.alias))
            || (!col_item.alias.empty() 
              && StrCaseCmp(col_item.alias, column_item.column))) {
          if (col_item.table.empty()) {
            // with clause subquery_name contains SUBQUERY_WITHCLAUSE and always
            // has no table_name, sometimes simple sql sentences also have no
            // table_name in column_item
            if (cur_query_name.find(SUBQUERY_WITHCLAUSE) != std::string::npos) {
              cur_query_name = tb_item_save.table;
            } 
            col_item.table = tb_item_save.table;

            if (!IsItemInMap(map_columns, col_item)) {
              map_columns[key].push_back(col_item);
              col_item_save = col_item;
              break;
            }
          } else {
            // col_item.table is not empty
            if (StrCaseCmp(col_item.table, tb_item_save.table)
                || (!tb_item_save.alias.empty() 
                  && StrCaseCmp(col_item.table, tb_item_save.alias))) {

              if (!IsItemInMap(map_columns, col_item)) {
                map_columns[key].push_back(col_item);
                col_item_save = col_item;
                break;
              }
            }
          } // end else

        }
      } // end for
      
      // Here, column_item matched in table_to_column_list.from(table_list), but
      // not matched in table_to_column_list.to(column_list), in this case, sqls
      // may be like:
      //  select A.a, B.b from A join (select c b, d from C) B on A.d = B.d;
    } else {
      // not matched, item not belong to current subquery, find next
      continue;
    }

    // find current subquery is a table_ref alias or in with_clause
    // col_item_save saves the matched column in current subquery, and maybe has
    // an alias if it is used in upper level query_block
    auto tb2subquery_list = column_dag.table_to_subquery_list;
    std::string next_subquery_name {""};
    for (auto tb2subquery : tb2subquery_list) {
      if (StrCaseCmp(tb2subquery.subquery_name, cur_query_name)) {
        if (!tb2subquery.table_name.empty()) {
          // current subquery belong to table_name which is the name of upper level query
          // maybe like from (select ...) t
          ColumnItem item_next;
          item_next.table = tb2subquery.table_name;
          item_next.column = column_item.column;
          item_next.alias = col_item_save.alias;

          FindFromTableToColumnList(map_columns, key, column_dag, item_next);

          break;  // only once
        }
      } else if (StrCaseCmp(tb2subquery.table_name, cur_query_name)) {
        // maybe in with clause, cur_query_name is with_query_name
        // for example: 
        //    with A (name, score) as (select ...)
        if (!tb2subquery.subquery_name.empty()) {
          next_subquery_name = tb2subquery.subquery_name;

          // find next_subquery_name in table_to_column_list
          for (auto table_to_col : table_to_column_list) {
            if (!StrCaseCmp(next_subquery_name, table_to_col.subquery_name))
              continue;

            // matched subquery_name
            // check if column matched col_item_save.column
            // Here only need to match column or column_alias, because it is in
            // subquery and table name maybe just an alias name or subquery_name
            for (auto mcol_item : table_to_col.to) {
              if (StrCaseCmp(mcol_item.column, col_item_save.column)
                  || (!mcol_item.alias.empty() && StrCaseCmp(mcol_item.alias, col_item_save.column))) {
                if (!IsItemInMap(map_columns, mcol_item)) {
                  map_columns[key].push_back(mcol_item);

                  FindFromTableToColumnList(map_columns, key, column_dag, mcol_item);
                }
              }
            }
          }
        }

        break;
      } else {
        continue;
      }
    }

    // get all the info related to current subquery
    // next
    matched = false;
    tb_item_save.clear();
    col_item_save.clear();
  }

  // after find all the info related to column_item, load equivalent_cond_list
  // again, except duplicated elements
  // column name (or alias name) must be the same
  //
  // cond.from.column = column_item.column
  // cond.from.column = column_item.alias
  // cond.to.column   = column_item.column
  // cond.to.column   = column_item.alias
  auto equivalent_cond_list = column_dag.equivalent_cond_list;
  for (auto cond : equivalent_cond_list) {
    if (StrCaseCmp(cond.from.column, column_item.column)
        || StrCaseCmp(cond.to.column, column_item.column)
        || (!column_item.alias.empty() 
          && (StrCaseCmp(cond.from.column, column_item.alias) 
            ||StrCaseCmp(cond.to.column, column_item.alias)))) {

      // add the one who is not in map
      // avoid to call FindFromTableToColumnList repeatedly

      //cond.from
      if (StrCaseCmp(cond.from.column, column_item.column)) {
        // column_item had been called FindFromTableToColumnList
        if (!IsItemInMap(map_columns, cond.from)) {
          map_columns[key].push_back(cond.from);
        }
      } else {
        if (!IsItemInMap(map_columns, cond.from)) {
          map_columns[key].push_back(cond.from);
          FindFromTableToColumnList(map_columns, key, column_dag, cond.from);
        }
      }

      // cond.to
      if (StrCaseCmp(cond.to.column, column_item.column)) {
        if (!IsItemInMap(map_columns, cond.to))
          map_columns[key].push_back(cond.to);
      } else {
        if (!IsItemInMap(map_columns, cond.to)) {
          map_columns[key].push_back(cond.to);
          FindFromTableToColumnList(map_columns, key, column_dag, cond.to);
        }
      }
       
    }
  }
}

static void GetColumnRelations(
    ColumnDAG &dag, MaskItem &mask_item, 
    std::map<ColumnItem, ColumnItemList> &column_relations_map) {
  // push item self into map first
  // we ignore root query block, so here should add column itself first
  ColumnItem item;
  item.table  = mask_item.table;
  item.column = mask_item.column;
  column_relations_map[item].push_back(item);

  // sometimes item is not used in subquery, and only exist in join_on_part, 
  // at this moment, we can not find the related subquery in table_to_column_list, 
  // and can only find it in equivalent_cond_list. So, load equivalent_cond_list
  // firstly before FindFromTableToColumnList, and after that, 
  // FindFromTableToColumnList again.
  //
  // NOTE: (very important)
  // column_relations_map mustn't have duplicated elements

  FindFromTableToColumnList(column_relations_map, item, dag, item);

}

/***********************************************************
 * load columns from physical table_item, columns saved in column_list.
 * here, we just load the columns from table.json file which contains all the
 * database informations saved by java program.
 * @author Jona
 * @param 
 *  @column_list: save all the columns from table_item
 * @date 16/10/2019 
***********************************************************/ 
static void LoadFromPhysicalTable(ColumnItemList &column_list, TableItem table_item) {
  // analogue table.json
  std::map<std::string, std::vector<std::string>> tablename_to_columns;
  tablename_to_columns["student"] = {"id", "stu_no", "sex", "name", "phone"};
  tablename_to_columns["course"] = {"stu_no", "course_no", "course_name", "score"};
  tablename_to_columns["grade"] = {"name", "grade_name"};
  tablename_to_columns["dept"] = {"name", "id", "dept_no"};
  tablename_to_columns["\"dt_test\""] = {"test_id", "test_name", "test_others"};

  // sqls had been toupper, here should tolower first
  auto column_string = tablename_to_columns[string_tolower(table_item.table)];
  for (auto col_str : column_string) {
    ColumnItem col_tmp;
    col_tmp.column = col_str;
    col_tmp.table = table_item.alias.empty() ? table_item.table : table_item.alias;
    column_list.push_back(col_tmp);
  }
}

static bool CheckTableValid(std::string table_name) {
  if (table_name.empty()) {
    return false;
  }

  for (auto iter = SUBQUERY_NAMES_PART.begin(); iter != SUBQUERY_NAMES_PART.end(); iter++) {
    if (table_name.find(iter->second) != std::string::npos) {
      return false;
    }
  }

  return true;
}

/***********************************************************
 * get all table columns from dag
 * @author Jona
 * @param 
 *  @column_list: save column info 
 *  @table_item: table which we want to get its columns
 * @date 15/10/2019 
***********************************************************/ 
static void GetColumnsFromTable(ColumnDAG &dag, ColumnItemList &column_list, 
    TableItem table_item) {

  // find subquery_name if table_item is a subquery
  std::string subquery_name;
  for (auto tb2subquery : dag.table_to_subquery_list) {
    if (StrCaseCmp(tb2subquery.table_name, table_item.table)) {
      subquery_name = tb2subquery.subquery_name;
      break;
    }
  }

  if (subquery_name.empty()) {
    // table_item is not a subquery, load it from physical table
    // TODO: Not Implementes
    LoadFromPhysicalTable(column_list, table_item);

    if (column_list.empty()) {
      std::cout << "table: " << table_item.table << "has no columns or not exist." << std::endl;
    }
  } else {
    for (auto tb2col : dag.table_to_column_list) {
      if (!StrCaseCmp(tb2col.subquery_name, subquery_name)) {
        continue;
      }

      // all the columns in current subquery are table_item's columns
      for (auto col_tmp : tb2col.to) {
        if (!StrCaseCmp(col_tmp.column, "*")) {
          // if col_tmp has an alias name, its name in table_item should be alias
          ColumnItem col_item_tmp;
          col_item_tmp.column = col_tmp.alias.empty()? col_tmp.column : col_tmp.alias;

          // check table name is valid or not
          if (CheckTableValid(table_item.table)) {
            col_item_tmp.table = table_item.table;
          }

          column_list.push_back(col_item_tmp);
        } else {
          // col_tmp also contains '*'
          // find its table and recursive
          // its table should be in tb2col.from, also in 2 situation
          // 1. only '*'
          if (col_tmp.table.empty()) {
            for (auto table_tmp : tb2col.from) {
              GetColumnsFromTable(dag, column_list, table_tmp);
            }
          } else {
            // 2. tableA.*
            for (auto table_tmp : tb2col.from) {
              if (StrCaseCmp(table_tmp.table, col_tmp.table)
                  || StrCaseCmp(table_tmp.alias, col_tmp.table)) {

                GetColumnsFromTable(dag, column_list, table_tmp);
              }
            }
          } // end else tableA.*
        } // end else col_tmp also contains '*'
      } 
    } // end for (auto tb2col : dag.table_to_column_list)
  }
}

/***********************************************************
 * replace column info with star from ColumnDAG.
 * @author Jona
 * @param 
 *  @col : column with star (like '*' or 'table.*' or 'schema.table.*')
 * @date 15/10/2019 
***********************************************************/ 
static ColumnItemList GetAllColumnsInsteadOfStar(ColumnDAG &dag, ColumnItem col) {
  ColumnItemList columns_replace_star;

  if (!StrCaseCmp(col.column, "*")) {
    return columns_replace_star;
  }

  // get table_item_list from top level query 
  TableItemList table_list;
  for (auto tb2col : dag.table_to_column_list) {
    if (tb2col.subquery_name.empty()) {
      // top level query
      table_list = tb2col.from;
    }
  }

  if (col.table.empty()) {
    // only '*'
    // here we should replace star with all columns in table_list
    for (auto table_tmp : table_list) {
      GetColumnsFromTable(dag, columns_replace_star, table_tmp);
    }

    return columns_replace_star;
  }

  // tableA.*
  // here we should replace star with all columns in tableA
  TableItem table_item;
  for (auto table_tmp : table_list) {
    if (StrCaseCmp(table_tmp.table, col.table) 
        || StrCaseCmp(table_tmp.alias, col.table)) {
      // get table item from table_list
      table_item = table_tmp;
      break;
    }
  }
  GetColumnsFromTable(dag, columns_replace_star, table_item);

  return columns_replace_star;
}

static TableItemList GetTableListFromTopLevelQueryInDag(ColumnDAG column_dag) {
  auto tb2column_list = column_dag.table_to_column_list;

  for (auto tb2col : tb2column_list) {
    if (tb2col.subquery_name.empty()) {
      return tb2col.from;
    }
  }

  return {};
}

/***********************************************************
 * Check whether col_item is in column_relations_map[mask_item] or not, if it is,
 * add mask_functions for it.
 * if col_item.table is empty, we should know its table from top level query in 
 * column_dag
 * @author Jona
 * @param 
 * @date 23/09/2019 
***********************************************************/ 
static bool IsMaskColumn(ColumnDAG column_dag, 
    std::map<ColumnItem, ColumnItemList> &column_relations_map, 
    MaskItem &mask_item, ColumnItem &col_item) {
  ColumnItem citem;
  citem.table = mask_item.table;
  citem.column = mask_item.column;
  auto column_list = column_relations_map[citem];

  for (auto mitem : column_list) {
    if (!StrCaseCmp(col_item.column, mitem.column))
      continue;

    // matched column
    // if table is empty, we must know column is belong to which table
    // so, here we should get it from dag first
    //
    // TODO: [FIXME] here we don't consider mask.schema 
    // if col_item.schema is empty, get default schema first and then compare 
    // with mitem.schema, otherwise, compare col_item.schema with mitem.schema
    // directly
    //
    if (col_item.table.empty()) {
      TableItemList table_list_in_top_level = 
        GetTableListFromTopLevelQueryInDag(column_dag);

      if (table_list_in_top_level.empty()) {
        return false;
      } else {
        for (auto tb_tmp : table_list_in_top_level) {
          if (StrCaseCmp(tb_tmp.table, mitem.table)) {
            return true;
          }
        }
      }
    } else {
      if (StrCaseCmp(col_item.table, mitem.table))
        return true;
    }
  }
  return false;
}

#endif
