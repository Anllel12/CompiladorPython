bison -d -v -o gramatica_python.tab.c gramatica_python.y       
flex -o python.lex.c lexico_python.flex 
gcc -o COMPILADO gramatica_python.tab.c python.lex.c
./COMPILADO ./test.python
