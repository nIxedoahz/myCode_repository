
// Generated from /home/jona/myGit/myCode_repository/antlr4_cpp/hive/HqlsqlLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  HqlsqlLexer : public antlr4::Lexer {
public:
  enum {
    T_ACTION = 1, T_ADD = 2, T_ALL = 3, T_ALLOCATE = 4, T_ALTER = 5, T_AND = 6, 
    T_ANSI_NULLS = 7, T_ANSI_PADDING = 8, T_AS = 9, T_ASC = 10, T_ASSOCIATE = 11, 
    T_AT = 12, T_AUTO_INCREMENT = 13, T_AVG = 14, T_BATCHSIZE = 15, T_BEGIN = 16, 
    T_BETWEEN = 17, T_BIGINT = 18, T_BINARY_DOUBLE = 19, T_BINARY_FLOAT = 20, 
    T_BINARY_INTEGER = 21, T_BIT = 22, T_BODY = 23, T_BREAK = 24, T_BY = 25, 
    T_BYTE = 26, T_CALL = 27, T_CALLER = 28, T_CASCADE = 29, T_CASE = 30, 
    T_CASESPECIFIC = 31, T_CAST = 32, T_CHAR = 33, T_CHARACTER = 34, T_CHARSET = 35, 
    T_CLIENT = 36, T_CLOSE = 37, T_CLUSTERED = 38, T_CLUSTER = 39, T_CMP = 40, 
    T_COLLECT = 41, T_COLLECTION = 42, T_COLUMN = 43, T_COMMENT = 44, T_CONSTANT = 45, 
    T_COMMIT = 46, T_COMPRESS = 47, T_CONCAT = 48, T_CONDITION = 49, T_CONSTRAINT = 50, 
    T_CONTINUE = 51, T_COPY = 52, T_COUNT = 53, T_COUNT_BIG = 54, T_CREATE = 55, 
    T_CREATION = 56, T_CREATOR = 57, T_CS = 58, T_CURRENT = 59, T_CURRENT_SCHEMA = 60, 
    T_CURSOR = 61, T_DATABASE = 62, T_DATABASES = 63, T_DATA = 64, T_DATE = 65, 
    T_DATETIME = 66, T_DAY = 67, T_DAYS = 68, T_DEC = 69, T_DECIMAL = 70, 
    T_DECLARE = 71, T_DEFAULT = 72, T_DEFERRED = 73, T_REBUILD = 74, T_DEFINED = 75, 
    T_DEFINER = 76, T_DEFINITION = 77, T_DELETE = 78, T_DELIMITED = 79, 
    T_DELIMITER = 80, T_DESC = 81, T_DESCRIBE = 82, T_DIAGNOSTICS = 83, 
    T_DIR = 84, T_DIRECTORY = 85, T_DISTINCT = 86, T_DISTRIBUTE = 87, T_DO = 88, 
    T_DOUBLE = 89, T_DROP = 90, T_DYNAMIC = 91, T_ELSE = 92, T_ELSEIF = 93, 
    T_ELSIF = 94, T_ENABLE = 95, T_DISABLE = 96, T_CHECK = 97, T_NOVALIDATE = 98, 
    T_RELY = 99, T_NORELY = 100, T_END = 101, T_ENGINE = 102, T_ESCAPED = 103, 
    T_EXCEPT = 104, T_EXEC = 105, T_EXECUTE = 106, T_EXCEPTION = 107, T_EXCLUSIVE = 108, 
    T_EXISTS = 109, T_EXIT = 110, T_FALLBACK = 111, T_FALSE = 112, T_FETCH = 113, 
    T_FIELDS = 114, T_FILE = 115, T_FILES = 116, T_JAR = 117, T_FLOAT = 118, 
    T_FOR = 119, T_FOREIGN = 120, T_FORMAT = 121, T_FOUND = 122, T_FROM = 123, 
    T_FULL = 124, T_FUNCTION = 125, T_GET = 126, T_GLOBAL = 127, T_GO = 128, 
    T_GRANT = 129, T_REVOKE = 130, T_GROUP = 131, T_ROLE = 132, T_ROLES = 133, 
    T_HANDLER = 134, T_HASH = 135, T_HAVING = 136, T_HDFS = 137, T_HIVE = 138, 
    T_HOST = 139, T_IDENTITY = 140, T_IF = 141, T_IGNORE = 142, T_IMMEDIATE = 143, 
    T_IN = 144, T_INCLUDE = 145, T_INDEX = 146, T_INDEXES = 147, T_INITRANS = 148, 
    T_INNER = 149, T_INOUT = 150, T_INSERT = 151, T_INT = 152, T_INT2 = 153, 
    T_INT4 = 154, T_INT8 = 155, T_INTEGER = 156, T_INTERSECT = 157, T_INTERVAL = 158, 
    T_INTO = 159, T_INVOKER = 160, T_IS = 161, T_ISOPEN = 162, T_ITEMS = 163, 
    T_JOIN = 164, T_KEEP = 165, T_KEY = 166, T_KEYS = 167, T_LANGUAGE = 168, 
    T_LEAVE = 169, T_LEFT = 170, T_LIKE = 171, T_LIMIT = 172, T_LINES = 173, 
    T_LOCAL = 174, T_LOCATION = 175, T_LOCATOR = 176, T_LOCATORS = 177, 
    T_LOCKS = 178, T_LOG = 179, T_LOGGED = 180, T_LOGGING = 181, T_LOOP = 182, 
    T_MAP = 183, T_MATCHED = 184, T_MAX = 185, T_MAXTRANS = 186, T_MERGE = 187, 
    T_MESSAGE_TEXT = 188, T_MICROSECOND = 189, T_MICROSECONDS = 190, T_MIN = 191, 
    T_MULTISET = 192, T_NCHAR = 193, T_NEW = 194, T_NVARCHAR = 195, T_NO = 196, 
    T_NOCOUNT = 197, T_NOCOMPRESS = 198, T_NOLOGGING = 199, T_NONE = 200, 
    T_NOT = 201, T_NOTFOUND = 202, T_NULL = 203, T_NUMERIC = 204, T_NUMBER = 205, 
    T_OBJECT = 206, T_OFF = 207, T_ON = 208, T_ONLY = 209, T_OPEN = 210, 
    T_OR = 211, T_ORDER = 212, T_OUT = 213, T_OUTER = 214, T_OVER = 215, 
    T_OVERWRITE = 216, T_OWNER = 217, T_PACKAGE = 218, T_PARTITION = 219, 
    T_PCTFREE = 220, T_PCTUSED = 221, T_PLS_INTEGER = 222, T_PRECISION = 223, 
    T_PRESERVE = 224, T_PRIMARY = 225, T_PRINT = 226, T_PROC = 227, T_PROCEDURE = 228, 
    T_QUALIFY = 229, T_QUERY_BAND = 230, T_QUIT = 231, T_QUOTED_IDENTIFIER = 232, 
    T_RAISE = 233, T_REAL = 234, T_REFERENCES = 235, T_REGEXP = 236, T_REPLACE = 237, 
    T_RESIGNAL = 238, T_RESTRICT = 239, T_RESULT = 240, T_RESULT_SET_LOCATOR = 241, 
    T_RETURN = 242, T_RETURNS = 243, T_REVERSE = 244, T_RIGHT = 245, T_RLIKE = 246, 
    T_ROLLBACK = 247, T_ROW = 248, T_ROWS = 249, T_ROWTYPE = 250, T_ROW_COUNT = 251, 
    T_RR = 252, T_RS = 253, T_PWD = 254, T_TRIM = 255, T_SCHEMA = 256, T_SCHEMAS = 257, 
    T_SECOND = 258, T_SECONDS = 259, T_SECURITY = 260, T_SEGMENT = 261, 
    T_SELECT = 262, T_SET = 263, T_RESET = 264, T_SESSION = 265, T_SESSIONS = 266, 
    T_SETS = 267, T_SHARE = 268, T_SIGNAL = 269, T_SIMPLE_DOUBLE = 270, 
    T_SIMPLE_FLOAT = 271, T_SIMPLE_INTEGER = 272, T_SMALLDATETIME = 273, 
    T_SMALLINT = 274, T_SQL = 275, T_SQLEXCEPTION = 276, T_SQLINSERT = 277, 
    T_SQLSTATE = 278, T_SQLWARNING = 279, T_STATS = 280, T_STATISTICS = 281, 
    T_STEP = 282, T_STORAGE = 283, T_STORED = 284, T_STRING = 285, T_BINARY = 286, 
    T_SUBDIR = 287, T_SUBSTRING = 288, T_SUM = 289, T_SUMMARY = 290, T_SYS_REFCURSOR = 291, 
    T_TABLE = 292, T_TABLES = 293, T_VIEW = 294, T_VIEWS = 295, T_TABLESPACE = 296, 
    T_TEMPORARY = 297, T_EXTERNAL = 298, T_TERMINATED = 299, T_TEXTIMAGE_ON = 300, 
    T_THEN = 301, T_TIMESTAMP = 302, T_TINYINT = 303, T_TITLE = 304, T_TO = 305, 
    T_TOP = 306, T_TRANSACTION = 307, T_TRANSACTIONS = 308, T_TRUE = 309, 
    T_TRUNCATE = 310, T_TYPE = 311, T_UNION = 312, T_UNIQUE = 313, T_UPDATE = 314, 
    T_UR = 315, T_USE = 316, T_USING = 317, T_VALUE = 318, T_VALUES = 319, 
    T_VAR = 320, T_VARCHAR = 321, T_VARCHAR2 = 322, T_VARYING = 323, T_VOLATILE = 324, 
    T_WHEN = 325, T_WHERE = 326, T_WHILE = 327, T_WITH = 328, T_WITHOUT = 329, 
    T_WORK = 330, T_XACT_ABORT = 331, T_ABORT = 332, T_XML = 333, T_YES = 334, 
    T_ARRAY = 335, T_STRUCT = 336, T_BOOLEAN = 337, T_LITERAL = 338, T_SERDE = 339, 
    T_SEQUENCEFILE = 340, T_TEXTFILE = 341, T_RCFILE = 342, T_ORC = 343, 
    T_PARQUET = 344, T_AVRO = 345, T_JSONFILE = 346, T_INPUTFORMAT = 347, 
    T_OUTPUTFORMAT = 348, T_FILEFORMAT = 349, T_T = 350, T_S = 351, T_FUNCTIONS = 352, 
    T_IMPORT = 353, T_EXPORT = 354, T_ACTIVITY_COUNT = 355, T_CUME_DIST = 356, 
    T_CURRENT_DATE = 357, T_CURRENT_TIMESTAMP = 358, T_CURRENT_USER = 359, 
    T_DENSE_RANK = 360, T_FIRST_VALUE = 361, T_LAG = 362, T_LAST_VALUE = 363, 
    T_LEAD = 364, T_MAX_PART_STRING = 365, T_MIN_PART_STRING = 366, T_MAX_PART_INT = 367, 
    T_MIN_PART_INT = 368, T_MAX_PART_DATE = 369, T_MIN_PART_DATE = 370, 
    T_PART_COUNT = 371, T_PART_LOC = 372, T_RANK = 373, T_ROW_NUMBER = 374, 
    T_STDEV = 375, T_STD = 376, T_SYSDATE = 377, T_VARIANCE = 378, T_USER = 379, 
    T_DBPROPERTIES = 380, T_TBLPROPERTIES = 381, T_IDXPROPERTIES = 382, 
    T_PURGE = 383, T_BUCKETS = 384, T_SKEWED = 385, T_DIRECTORIES = 386, 
    T_SERDEPROPERTIES = 387, T_RENAME = 388, T_SORTED = 389, T_SORT = 390, 
    T_CHANGE = 391, T_EXCHANGE = 392, T_RECOVER = 393, T_PARTITIONS = 394, 
    T_PROTECTION = 395, T_ARCHIVE = 396, T_UNARCHIVE = 397, T_TOUCH = 398, 
    T_OFFLINE = 399, T_NO_DROP = 400, T_COMPACT = 401, T_CONCATENATE = 402, 
    T_WAIT = 403, T_COLUMNS = 404, T_FIRST = 405, T_LAST = 406, T_NULLS = 407, 
    T_AFTER = 408, T_MATERIALIZED = 409, T_REWRITE = 410, T_PARTITIONED = 411, 
    T_DISTRIBUTED = 412, T_MACRO = 413, T_SHOW = 414, T_EXTENDED = 415, 
    T_FORMATTED = 416, T_SEMI = 417, T_CROSS = 418, T_LATERAL = 419, T_RELOAD = 420, 
    T_LOAD = 421, T_INPATH = 422, T_PRINCIPALS = 423, T_COMPACTIONS = 424, 
    T_CONF = 425, T_ADMIN = 426, T_OPTION = 427, T_PRIVILEGES = 428, T_LOCK = 429, 
    T_SHOW_DATABASE = 430, T_COMPUTE = 431, T_CACHE = 432, T_METADATA = 433, 
    T_NOSCAN = 434, T_UNIONTYPE = 435, T_ANALYZE = 436, T_EXPLAIN = 437, 
    T_CBO = 438, T_AST = 439, T_DEPENDENCY = 440, T_AUTHORIZATION = 441, 
    T_VECTORIZATION = 442, T_COST = 443, T_JOINCOST = 444, T_OPERATOR = 445, 
    T_EXPRESSION = 446, T_DETAIL = 447, T_UNBOUNDED = 448, T_PRECEDING = 449, 
    T_FOLLOWING = 450, T_RANGE = 451, T_TABLESAMPLE = 452, T_BUCKET = 453, 
    T_OF = 454, T_PERCENTS = 455, T_WINDOW = 456, T_DIV = 457, T_YEAR = 458, 
    T_MONTH = 459, T_MINUTE = 460, T_TIME = 461, T_ZONE = 462, T_ADD_SIGN = 463, 
    T_COLON = 464, T_COMMA = 465, T_PIPE = 466, T_DIV_SIGN = 467, T_DOT2 = 468, 
    T_EQUAL = 469, T_EQUAL2 = 470, T_NOTEQUAL = 471, T_NOTEQUAL2 = 472, 
    T_GREATER = 473, T_GREATEREQUAL = 474, T_LESS = 475, T_LESSEQUAL = 476, 
    T_MUL = 477, T_OPEN_B = 478, T_OPEN_P = 479, T_OPEN_SB = 480, T_CLOSE_B = 481, 
    T_CLOSE_P = 482, T_CLOSE_SB = 483, T_SEMICOLON = 484, T_SUB = 485, T_AT_SIGN = 486, 
    T_POUND_SIGN = 487, T_PERIOD = 488, T_PERCENT = 489, T_EXCLAMATION = 490, 
    T_SLASH_SIGN = 491, T_UNDERLINE = 492, T_AND_SIGN = 493, T_EXPONENT = 494, 
    L_ID = 495, L_S_STRING = 496, L_D_STRING = 497, L_INT = 498, L_DEC = 499, 
    L_WS = 500, L_M_COMMENT = 501, L_S_COMMENT = 502, L_ALPHA = 503, L_DIGIT = 504
  };

  HqlsqlLexer(antlr4::CharStream *input);
  ~HqlsqlLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

