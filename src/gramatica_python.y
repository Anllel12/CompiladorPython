%{

// ----------------------------- GLOSARIO DE IMPORTS -------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "AST_python.h"

// ----------------------------- DECLARACION DE VARIABLES Y ESTRUCTURAS -------------------------------------------

//Declaracion de variables "extern" sirve para declararlas como variables globales
FILE *yyout;
extern FILE* yyin;
extern int num_linea; //Almacena el numero de linea durante la ejecucion
extern tSimbolos tabla[256];
extern int indice; //Se almacena el índice de la tabla de tSimbolos
char* tipos[] = {"numero", "decimal", "texto", "boolean"}; //Para parsear el tipo que se detecta en flex al tipo del nodo
#define true 1
#define false 0


%}

/*Definicion de tipos y estructuras empleadas*/
%union {
  int intVal;
  float realVal;
  char* strVal;
  struct atributos{
    int numero;
    float decimal;
    char* texto;
    int boolean;
    char* tipo;             //Define el tipo que se esta usando
    struct ast *n;          //Para almacenar los nodos del AST
  }tr;
}

/*Declaración de los TOKENS*/
%token FALSE NONE TRUE AND AS ASSERT ASYNC AWAIT BREAK CONTINUE CLASS DEF DEL ELIF ELSE EXCEPT FINALLY 
%token FOR FROM GLOBAL IF IMPORT IN IS LAMBDA NONLOCAL NOT OR PASS RAISE RETURN TRY WHILE WITH YIELD END IMPRIMIR 
%token CADENA VECTOR LISTA TUPLA SET DICT INT FLOAT COMPLEX BOOLEAN RANGE
%token SUMA RESTA MULTIPLICACION DIVISION MODULO MENOR_QUE MAYOR_QUE AUMENTAR_VALOR IGUAL_QUE DISTINTO_QUE ASIGNACION PARENTESIS_IZQ PARENTESIS_DER DOS_PUNTOS
%token MENOR_IGUAL_QUE MAYOR_IGUAL_QUE

/*Declaración de los TOKENS que provienen de FLEX con su respectivo tipo*/
%token <intVal> NUMERO 
%token <realVal> DECIMAL 
%token <strVal> VARIABLE
%token <strVal> STRING

/*Declaración de los TOKENS NO TERMINALES con su estructura*/
%type <tr> sentencias sentencia tipos expresion asignacion imprimir if rescursivo_if while for

/*Declaración de la precedencia siendo menor la del primero y mayor la del último*/
%left SUMA RESTA
%left MULTIPLICACION DIVISION
%left MENOR_QUE MAYOR_QUE IGUAL_QUE DISTINTO_QUE MENOR_IGUAL_QUE MAYOR_IGUAL_QUE

%start codigo
%%

//GRAMATICA
//X --> S
//S --> D | S D
//D --> A | I | F | W | F
//A --> id = E 
//F --> if E: S RF
//RF--> elif E: S RF | else E | end
//W --> while E: S end
//FOR --> for E in range (E): S end
//E --> E op T | T
//T --> id | num | decimal | texto | true | false
//I --> imprimir ( E )

//-----------------------------------------------  PRODUCCIONES  -------------------------------------------------------

//PRODUCCION "codigo", formado por sentencias
//X --> S
codigo:
    sentencias  {
        printf("\nLlamando a comprobarAST\n");
        comprobarAST($1.n); 
        printf("\n[FINALIZADO]\n");     
    }
;

//PRODUCCION "sentencias", puede estar formado por una sentencia o un grupo de sentencias
//S --> D | S D
sentencias:
    sentencia { $$ = $1; }
    | sentencias sentencia { //para hacerlo recursivo
        $$.n = crearNodoNoTerminal($1.n, $2.n, 7);
    }
;

//PRODUCCION "sentencia", puede estar formado por asignaciones, condicionales, bucles whiles, imprimir
//D --> A | I | F | W
sentencia:   //Por defecto bison, asigna $1 a $$ por lo que no es obligatoria realizar la asignacion
    asignacion
    | imprimir
    | if
    | while
    | for
;

//-------------------------------------------------------- ASIGNACION --------------------------------------------------------
//PRODUCCION "asignacion", formado por un identificador, un igual y una expresion
//A --> id = E 
asignacion:
    VARIABLE ASIGNACION expresion {
        printf("> [SENTENCIA] - Asignacion\n");

        //Para crear un nuevo simbolo de tipo numero
        if(strcmp($3.tipo, tipos[0]) == 0){ //comprobacion si es numero
            printf("Asignado el valor %d a la variable\n",$3.numero);

            tabla[indice].nombre = $1; 
            tabla[indice].tipo = tipos[0]; 
            tabla[indice].numero = $3.numero; 
            tabla[indice].registro = $3.n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo decimal
        else if(strcmp($3.tipo, tipos[1]) == 0){ //comprobacion si es decimal
            printf("Asignado el valor %d a la variable\n",$3.decimal);

            tabla[indice].nombre = $1; 
            tabla[indice].tipo = tipos[1]; 
            tabla[indice].decimal = $3.decimal; 
            tabla[indice].registro = $3.n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo string
        else if(strcmp($3.tipo, tipos[2]) == 0){ //comprobacion si es string
            printf("Asignado el valor %s a la variable\n",$3.texto);

            tabla[indice].nombre = $1; 
            tabla[indice].tipo = tipos[2]; 
            tabla[indice].texto = $3.texto; 
            tabla[indice].registro = $3.n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo boolean
        else if(strcmp($3.tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("Asignado el valor %d a la variable\n",$3.boolean);

            tabla[indice].nombre = $1; 
            tabla[indice].tipo = tipos[2]; 
            tabla[indice].boolean = $3.boolean; 
            tabla[indice].registro = $3.n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }

        // Control de errores
        else{
            yyerror("> [ERROR] - NO ES NINGUNO DE LOS TIPOS DEFINIDOS\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
            
        }

        $$.n=crearNodoNoTerminal($3.n, crearNodoVacio(), 15);
    }
;

//-------------------------------------------------- IF ---------------------------------------------------
//F --> if E: S RF
if:
    IF expresion DOS_PUNTOS sentencias rescursivo_if {
        if(strcmp($2.tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [IF] - ESTAMOS COMPARANDO\n");
            $$.n=crearNodoNoTerminalIf($2.n, $4.n, $5.n, 12);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
;

//-------------------------------------------------- RECURSIVO IF ---------------------------------------------------
//RF --> elif E: S RF | else S | end
rescursivo_if:
    ELIF expresion DOS_PUNTOS sentencias rescursivo_if {
        if(strcmp($2.tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [ELIF] - ESTAMOS COMPARANDO\n");
            $$.n=crearNodoNoTerminalIf($2.n, $4.n, $5.n, 13);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    | ELSE DOS_PUNTOS sentencias rescursivo_if{
        printf("> [ELSE] - SI NO\n");
        $$.n=crearNodoNoTerminal($3.n, $4.n, 14);
    }
    | END{
        $$.n = crearNodoEnd(23);
    }
;

//-------------------------------------------------- WHILE ---------------------------------------------------
//W --> while E: S end
while:
    WHILE expresion DOS_PUNTOS sentencias END {
        if(strcmp($2.tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [WHILE] - ESTAMOS EN UN BUCLE\n");
            $$.n=crearNodoNoTerminal($2.n, $4.n, 11);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
;

//-----------------------------------------------  BUCLE FOR ---------------------------------------------
//FOR --> for E in range (E): S end
for:
    FOR VARIABLE IN RANGE PARENTESIS_IZQ expresion PARENTESIS_DER DOS_PUNTOS sentencias END {
        printf("> [FOR] - ESTAMOS EN UN BUCLE\n");
        $$.n = crearNodoNoTerminal($6.n, $9.n, 25);
    }

;

//-----------------------------------------------  EXPRESION ---------------------------------------------
//PRODUCCION "expresion", en esta gramática se representa la suma, resta y otros terminos
//E --> E op T | T
expresion:
    
    //SUMA
    expresion SUMA tipos {

        //SUMA de numero + numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) { //comprobacion del tipo
            printf("> [OPERACION] - SUMA {numero / numero}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 2);
            $$.tipo = tipos[0]; 
            $$.numero = $1.numero + $3.numero;
        }

        //SUMA de decimal + decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - SUMA {decimal / decimal}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 2);
            $$.tipo = tipos[1]; 
            $$.decimal = $1.decimal + $3.decimal;
        }

        //SUMA de str + str
        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - SUMA {texto / texto}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 2);
            $$.tipo = tipos[2];
            $$.texto = (char*)malloc(strlen($1.texto) + strlen($3.texto) + 1);
            if ($$.texto != NULL) {
                // Concatenar las cadenas
                strcpy($$.texto, $1.texto);
                strcat($$.texto, $3.texto);
            }
            else {
                yyerror("Error al asignar memoria para la concatenacion de cadenas.\n");
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - SUMA\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //RESTA
    | expresion RESTA tipos {
        
        //RESTA de numero - numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [OPERACION] - RESTA {numero / numero}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 3);
            $$.tipo = tipos[0]; 
            $$.numero = $1.numero + $3.numero;
        }

        //RESTA de decimal - decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - RESTA {decimal / decimal}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 3);
            $$.tipo = tipos[1]; 
            $$.decimal = $1.decimal + $3.decimal;
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - RESTA\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //MULTIPLICACION
    | expresion MULTIPLICACION tipos {
        
        //MULTIPLICACION de numero * numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [OPERACION] - MULTIPLICACION {numero / numero}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 4);
            $$.tipo = tipos[0]; 
            $$.numero = $1.numero * $3.numero;
        }

        //MULTIPLICACION de decimal * decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - MULTIPLICACION {decimal / decimal}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 4);
            $$.tipo = tipos[1]; 
            $$.decimal = $1.decimal * $3.decimal;
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MULTIPLICACION\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //DIVISION
    | expresion DIVISION tipos {
        
        //DIVISION de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            if ($3.numero == 0.0) {
                yyerror("> [ERROR] - DIVISION {numero / 0}\n");
                printf("ERROR EN LA LINEA %d\n", num_linea);
            }
            else {
                printf("> [OPERACION] - DIVISION {numero / numero}\n");

                $$.n = crearNodoNoTerminal($1.n, $3.n, 5);
                $$.tipo = tipos[0]; 
                $$.numero = $1.numero / $3.numero;
            }  
        }

        //DIVISION de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            if ($3.numero == 0.0) {
                yyerror("> [ERROR] - DIVISION {numero / 0}\n");
                printf("ERROR EN LA LINEA %d\n", num_linea);
            }
            else {
                printf("> [OPERACION] - DIVISION {decimal / decimal}\n");
                $$.n = crearNodoNoTerminal($1.n, $3.n, 5);
                $$.tipo = tipos[1]; 
                $$.decimal = $1.decimal / $3.decimal;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - DIVISION\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //IGUAL_QUE
    | expresion IGUAL_QUE tipos {
        
        //IGUAL_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - IGUAL_QUE {numero / numero}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 17);
            $$.tipo = tipos[3]; 
            if ($1.numero == $3.numero) {
                printf("Verdadero %d es igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }
        //IGUAL_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - IGUAL_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 17);
            $$.tipo = tipos[3]; 
            if ($1.decimal == $3.decimal) {
                printf("Verdadero %d es igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //DISTINTO_QUE
    | expresion DISTINTO_QUE tipos {
        
        //DISTINTO_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - DISTINTO_QUE {numero / numero}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 18); 
            $$.tipo = tipos[3]; 
            if ($1.numero != $3.numero) {
                printf("Verdadero %d es distinto que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es distinto que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }
        //DISTINTO_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - DISTINTO_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 18);
            $$.tipo = tipos[3]; 
            if ($1.decimal != $3.decimal) {
                printf("Verdadero %d es distinto que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es distinto que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - DISTINTO_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //MENOR QUE
    | expresion MENOR_QUE tipos {
        
        //MENOR_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_QUE {numero / numero}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 19);
            $$.tipo = tipos[3]; 
            if ($1.numero < $3.numero) {
                printf("Verdadero %d es menor que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }
        //MENOR_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 19);
            $$.tipo = tipos[3]; 
            if ($1.decimal < $3.decimal) {
                printf("Verdadero %d es menor que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MENOR_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //MENOR IGUAL QUE
    | expresion MENOR_IGUAL_QUE tipos {
        
        //MENOR_IGUAL_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_IGUAL_QUE {numero / numero}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 20);
            $$.tipo = tipos[3]; 
            if ($1.numero < $3.numero || $1.numero == $3.numero) {
                printf("Verdadero %d es menor o igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor o igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }
        //MENOR_IGUAL_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_IGUAL_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 20);
            $$.tipo = tipos[3]; 
            if ($1.decimal < $3.decimal || $1.decimal == $3.decimal) {
                printf("Verdadero %d es menor o igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor o igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MENOR_IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //MAYOR QUE
    | expresion MAYOR_QUE tipos {
        
        //MAYOR_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_QUE {numero / numero}\n");

            $$.n = crearNodoNoTerminal($1.n, $3.n, 21);
            $$.tipo = tipos[3]; 
            if ($1.numero > $3.numero) {
                printf("Verdadero %d es mayor que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }
        //MAYOR_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 21);
            $$.tipo = tipos[3]; 
            if ($1.decimal > $3.decimal) {
                printf("Verdadero %d es mayor que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MAYOR_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    //MAYOR IGUAL QUE
    | expresion MAYOR_IGUAL_QUE tipos {
        
        //MAYOR_IGUAL_QUE de numero / numero
        if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_IGUAL_QUE {numero / numero}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 22);
            $$.tipo = tipos[3]; 
            if ($1.numero > $3.numero || $1.numero == $3.numero) {
                printf("Verdadero %d es mayor o igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor o igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        //MAYOR_IGUAL_QUE de decimal / decimal
        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_IGUAL_QUE {decimal / decimal}\n");
            $$.n = crearNodoNoTerminal($1.n, $3.n, 22);
            $$.tipo = tipos[3]; 
            if ($1.decimal > $3.decimal || $1.decimal == $3.decimal) {
                printf("Verdadero %d es mayor o igual que %d\n", $1, $3);
                $$.boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor o igual que %d\n", $1, $3);
                $$.boolean = 0;
            }
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[0]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[1]) == 0 && strcmp($3.tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp($1.tipo, tipos[2]) == 0 && strcmp($3.tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    }
    | tipos {$$ = $1;} //la produccion operacion puede ser tipos, un subnivel para realizar la jerarquia de operaciones
;

//-----------------------------------------------  TIPOS  ---------------------------------------------
/*PRODUCCION "tipos", en esta gramática se represetan los tipos de datos:
- identificadores (variables) - numeros enteros o decimales positivos o negativos
- cadenas de texto - estructura parentesis
T --> id | num | decimal | texto | true | false*/
tipos:

    //Identificador
    VARIABLE {
        printf(" VARIABLE %s\n",$1);
        //Buscamos en la tabla el VARIABLE
        if(buscarTabla(indice, $1, tabla) != -1){     //En este IF entra si buscarTabla devuelve la posicion
            int pos = buscarTabla(indice, $1, tabla);
            //Para si es de tipo numero
            if(tabla[pos].tipo==tipos[0]){
                $$.tipo = tabla[pos].tipo; 
                $$.numero=tabla[pos].numero; 
                $$.n = crearVariableTerminalInt(tabla[pos].numero, tabla[pos].registro);  //Creamos un nodo terminal con los numeros   
            }
            //Para si es de tipo decimal
            else if(tabla[pos].tipo==tipos[1]){
                $$.tipo = tabla[pos].tipo; 
                $$.decimal=tabla[pos].decimal;
                $$.n = crearVariableTerminalDouble(tabla[pos].decimal, tabla[pos].registro); //Creamos un nodo terminal con los numeros        
            }
            //Para si es de tipo texto
            else if(tabla[pos].tipo==tipos[2]){
                $$.tipo = tabla[pos].tipo; 
                $$.texto=tabla[pos].texto;
                $$.n = crearVariableTerminalString(tabla[pos].texto, tabla[pos].registro); //Creamos un nodo terminal con el texto        
            }
            //Para si es de tipo boolean
            else if(tabla[pos].tipo==tipos[3]){
                $$.tipo = tabla[pos].tipo; 
                $$.texto=tabla[pos].boolean;
                $$.n = crearVariableTerminalBoolean(tabla[pos].boolean, tabla[pos].registro); //Creamos un nodo terminal con el boolean        
            }
        }
    }

    //Numero entero normal
    | NUMERO {
        $$.numero = $1;
        printf("\n> [TIPO] - Numero Positivo: %ld\n", $$.numero);
        $$.tipo = tipos[0]; 
        $$.n = crearNodoTerminalInt($1); 
    }

    //Numero decimal normal
    | DECIMAL {
        $$.decimal = $1;
        printf("\n> [TIPO] - Decimal: %.3f\n", $$.decimal); 
        $$.tipo = tipos[1];  
        $$.n = crearNodoTerminalDouble($1);
    }

    //Cadena de caracteres
    | STRING {
        $$.texto = $1;
        printf("\n> [TIPO] - Texto: %s\n", $$.texto);
        $$.tipo = tipos[2];
        $$.n = crearNodoTerminalString($1); 
    }

    //Boleanos
    | TRUE {
        $$.boolean = 1;
        printf("\n> [TIPO] - Boleano True: %d\n", $$.boolean); 
        $$.tipo = tipos[3];
        $$.n = crearNodoTerminalBoolean($$.boolean);
    }

    | FALSE {
        $$.boolean = 0;
        printf("\n> [TIPO] - Boleano False: %d\n", $$.boolean); 
        $$.tipo = tipos[3];
        $$.n = crearNodoTerminalBoolean($$.boolean);
    }
;

//-----------------------------------------------  IMPRIMIR  ---------------------------------------------
//Representa la estructura del print en lenguaje latino
//I --> imprimir ( E ) 
imprimir: 
    IMPRIMIR PARENTESIS_IZQ expresion PARENTESIS_DER { 
        printf("> [SENTENCIA] - Imprimir\n");
        $$.n = crearNodoNoTerminal($3.n, crearNodoVacio(), 16); 
    }
;

%% 

//--------------------------------------------------- METODO MAIN -----------------------------------------------
int main(int argc, char** argv) {
    yyin = fopen(argv[1], "rt");            //Apertura del archivo test.py
    yyout = fopen( "./python.asm", "wt" );
    if (yyout == NULL) {
        perror("Error abriendo el archivo de salida");
        return 1;
    }
    printf("Archivo de salida abierto correctamente.\n");  //Para el archivo .ASM con nombre "python.asm"
	yyparse();
    fclose(yyin);
    return 0;
}

//Metodo yyerror, generado por defecto
void yyerror(const char* s) {
    fprintf(stderr, "----- ERROR EN LA LINEA %d: %s -----", num_linea, s);
}