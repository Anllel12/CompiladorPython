
%option noyywrap

%{
#include "gramatica_python.tab.h"
extern YYSTYPE yylval;
int n_linea = 1; 
%}

%%

"and"                     {return AND; }                     
"or"                      {return OR; }                      
"while"                   {return WHILE; }     
"endWhile"                {return END_WHILE; }                    
"for"                     {return FOR; }  
"endFor"                  {return END_FOR; }
"in"                      {return IN; }                  
"range"                   {return RANGE; }                     
"if"                      {return IF; }
"elif"                    {return ELIF; }       
"else"                    {return ELSE; }              
"endIf"                   {return END_IF; }     

","                       {return COMA; }                   
"+"	                      {return SUMA; }          
"-"	                      {return RESTA; }                    
"*"                       {return MULTIPLICACION; }    
"/"                       {return DIVISION; }               
"("	                      {return PARENTESIS_IZQ; } 
")"	                      {return PARENTESIS_DER; } 
"["	                      {return CORCHETE_IZQ; }    
"]"	                      {return CORCHETE_DER; }      
">"                       {return MAYOR_QUE; }      
">="                      {return MAYOR_IGUAL_QUE; }
"<"                       {return MENOR_QUE; }      
"<="                      {return MENOR_IGUAL_QUE; }                  
"=="	                  {return IGUAL_QUE; }               
"!="	                  {return DISTINTO_QUE; }  
"="	                      {return ASIGNACION; }
":"                       {return DOS_PUNTOS; }             

"#"(.)*                                         
\"\"\"([^\"]|\"[^\"])*\"\"\"                    { int num_newlines = 0; char *p; for (p = yytext; *p; p++) { if (*p == '\n') { num_newlines++; } } int old_number = n_linea; n_linea += num_newlines; }
\"[^\"\n]*\"                                    {yylval.stringVal = strdup(yytext + 1); yylval.stringVal[strlen(yylval.stringVal) - 1] = '\0'; printf(yytext);return CADENA;}

print                                           return IMPRIMIR;
[0-9]+                                          {yylval.enteroVal = atoi(yytext); return NUMERO;}
[0-9]+.[0-9]+                                   {yylval.realVal   = atof(yytext); return DECIMAL;}
_?[a-zA-Z0-9_]+		                            {yylval.stringVal = strdup(yytext); return VARIABLE;}
                                        

\n                                              { printf("\n--------------- Numero de linea %d ----------------\n\n", n_linea); n_linea++;}
[ \t]                                           { /* no se hace nada */ }


%%
