
#-------------- Declaracion de variables --------------
.data 
saltoLinea: .asciiz "\n"
zero: .float 0.0
uno: .float 1.0
resultado: .space 100
var_0: .float 5.000
var_2: .float 5.000
var_4: .float 234.000
var_6: .float 5.000
var_8: .float 13.000
var_11: .float 8.000

#--------------------- Ejecuciones ---------------------
.text
lwc1 $f31, zero
lwc1 $f0, var_0
lwc1 $f8, var_8
li $v0, 2
add.s $f12, $f31, $f8
mov.s $f30, $f12  #Movemos el registro 12 al 30 iniciado a false
syscall #Llamada al sistema
li $v0, 4
la $a0, saltoLinea
syscall #Llamada al sistema
li $v0, 2
add.s $f12, $f31, $f0
mov.s $f30, $f12  #Movemos el registro 12 al 30 iniciado a false
syscall #Llamada al sistema
li $v0, 4
la $a0, saltoLinea
syscall #Llamada al sistema
