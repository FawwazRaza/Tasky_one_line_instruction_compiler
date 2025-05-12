%{
#include <stdio.h>
#include <string.h>
#include "astnode.h"
#include "tasky.tab.h"  // for YYSTYPE and tokens

#ifdef __cplusplus
extern "C" int yylex();
#endif
%}

%option noyywrap

%%

"make"                { return MAKE; }
"new"                 { return NEW; }
"folder"              { return FOLDER; }
"file"                { return FILEKW; }
"inside"              { return INSIDE; }
"named"               { return NAMED; }
"place"               { return PLACE; }
"add"                 { return ADD; }
"subtract"             { return SUBTRACT; }
"multiply"             { return MULTIPLY; }
"divide"               { return DIVIDE; }
"calculate"            { return CALCULATE; }
"store"                { return STORE; }
"result"               { return RESULT; }
"value"                { return VALUE; }
"print"                { return PRINT; }
"at"                  { return AT; }
"end"                 { return END; }
"remove"              { return REMOVE; }
"show"                { return SHOW; }
"in"                  { return IN; }
"all"                 { return ALL; }
"containing"          { return CONTAINING; }
"delete"              { return DELETE; }
"if"                  { return IF; }
"contain"             { return CONTAIN; }
"content"             { return CONTENT; }
"of"                  { return OF; }
"change"              { return CHANGE; }
"extension"           { return EXTENSION; }
"into"                { return INTO; }
"repeat"              { return REPEAT; }
"from"                { return FROM; }
"until"               { return UNTIL; }
"compress"            { return COMPRESS; }
"rename"              { return RENAME; }
"with"                { return WITH; }
"prefix"              { return PREFIX; }
"count"               { return COUNT; }
"write"               { return WRITE; }
"run"                 { return RUN; }
"to"                  { return TO; }
"append"              { return APPEND; }
"create"      	      {return CREATE;}
"search"              { return SEARCH; }
"for"                 { return FOR; }
"template"            { return TEMPLATE; }
"variables"           { return VARIABLES; }
"batch"               { return BATCH; }
"process"             { return PROCESS; }
"stats"               { return STATS; }
"larger"              { return LARGER; }
"than"                { return THAN; }
"transform"           { return TRANSFORM; }
"using"               { return USING; }
"regex"               { return REGEX; }
"replace"             { return REPLACE; }
"every"               { return EVERY; }
"lines"               { return LINES; }
"size"                { return SIZE; }
"when"                { return WHEN; }
"move"                { return MOVE; }
"sort"                { return SORT; }
"by"                  { return BY; }
"date"                { return DATE; }
"and"                  { return AND; }
"mod"                  { return MOD; }
"power"                { return POWER; }
"="                    { return EQUALS; }
"+"                    { return PLUS; }
"-"                    { return MINUS; }
"*"                    { return TIMES; }
"/"                    { return DIV; }
"%"                    { return MODULO; }
"^"                    { return POW; }
\"([^\"]*)\"          { 
    yylval.str = strdup(yytext+1); 
    yylval.str[strlen(yylval.str)-1] = 0; 
    return STRING; 
}

[0-9]+                { yylval.num = atoi(yytext); return NUMBER; }
[ \t\r\n]+            { /* skip whitespace */ }
"#".*                 { /* skip comments */ }
":"                   { return *yytext; }
.                     { return *yytext; }

%%
