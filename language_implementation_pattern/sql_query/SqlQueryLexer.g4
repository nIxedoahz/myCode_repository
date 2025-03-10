lexer grammar SqlQueryLexer;

PERCENT : '%';
AMPERSAND : '&';
LEFT_PAREN : '(';
RIGHT_PAREN : ')';
ASTERISK : '*';
PLUS_SIGN : '+';
COMMA : ',';
MINUS_SIGN: '-';
PERIOD : '.';
SOLIDUS : '/';
COLON : ':';
SEMICOLON : ';';
LESS_THAN : '<';
GREATER_THAN : '>';
EQUALS : '=';
QUESTION_MARK : '?';
LEFT_BRACKET : '[';
RIGHT_BRACKET : ']';
CURCUMFLEX : '^';
BAR : '|';
LEFT_BRACE : '{';
RIGHT_BRACE : '}';

SPACES: [ \t\r\n]+ -> channel(HIDDEN);

fragment NEWLINE_EOF    : NEWLINE | EOF;
fragment NEWLINE        : '\r'? '\n';
fragment DIGIT          : [0-9];

fragment A		: 'A' | 'a';
fragment B		: 'B' | 'b';
fragment C		: 'C' | 'c';
fragment D		: 'D' | 'd';
fragment E		: 'E' | 'e';
fragment F		: 'F' | 'f';
fragment G		: 'G' | 'g';
fragment H		: 'H' | 'h';
fragment I		: 'I' | 'i';
fragment J		: 'J' | 'j';
fragment K		: 'K' | 'k';
fragment L		: 'L' | 'l';
fragment M		: 'M' | 'm';
fragment N		: 'N' | 'n';
fragment O		: 'O' | 'o';
fragment P		: 'P' | 'p';
fragment Q		: 'Q' | 'q';
fragment R		: 'R' | 'r';
fragment S		: 'S' | 's';
fragment T		: 'T' | 't';
fragment U		: 'U' | 'u';
fragment V		: 'V' | 'v';
fragment W		: 'W' | 'w';
fragment X		: 'X' | 'x';
fragment Y		: 'Y' | 'y';
fragment Z		: 'Z' | 'z';
fragment SIMPLE_LETTER  : [a-zA-Z];
fragment UNI_CHAR       : '\u2E80-\u2FD5' | '\u3190-\u319F' | '\u3400-\u4DBF' | '\u4E00'..'\u9FEF' | '\uF900'..'\uFAAD';