![](https://github.com/RegaladoEdgar/programas/blob/main/unidad2/imagenes/cooltext366383391593318%20(1).png)

ARM es una arquitectura CISC(*Computadora de conjunto de instrucciones reducidas*). 

Algunos dipositivos que la usan:

  * Game Boy Advance
  * iPad
  * iPhone
  * Raspberry Pi

## Registros

Existen 16 registros principales más uno de estado.

  * **Generales**: almacenamiento temporal de datos. 13 regsitros de R0 a R12.
  * **Especiales**: R13 a R15, son 3:
	  * **SP/R13**: Stack Pointer. Puntero de varaibles locales y llamadas a funciones.
	  * **LR/R14**: Link Register: Dirección de retorno cuando BL o BLX llaman una rutina.
	  * **PC/R15**: Program Counter: Posición del procesador en la secuencai de instrucciones, se incrementa de 4 en 4.
	
El registro CPSR contiene Banderas condicionales y bits de control.
 
![](https://github.com/RegaladoEdgar/programas/blob/main/unidad2/imagenes/imagen_registros.png)

Existen 8 modos de operación ,se usa el modo usuario, los demás son modos privilegiados para el sistema operativo.
Desde el modo usuario sólo se puede acceder a banderas condicionales de información de estado sobre la última operación realizada por la ALU.

Si ponemos una s detrás de un nemotécnic la instrucción actualizará las banderas condicionales en ARMv6.

Existen 4 banderas:
  * **N**: Resultado negativo
  * **Z**: Resultado cero o comparación es TRUE
  * **C**: Acarreo de operaciones aritméticas
  * **V**: Desbordamiento aritmético

Los procesadores basados en ARMv6 utilizan el Bi-Endian, que es un híbrido entre el Little Endian y el Big Endian. Lo que significa que los byte menos significativo ocupa la posición más alta.

![](https://github.com/RegaladoEdgar/programas/blob/main/unidad2/imagenes/endian.png)

### Aspecto de un programa en ensamblador (Lenguaje ensamblador).

El ensamblador es un lenguajes de bajo nivel para interactuar directamente con el CPU. El proceso para obtener un ejecutable se divide en 2 pasos:
1. Primero compilar, checar que todo funcione.
2. Luego enlazar, traducir todo y generar ejecutable, enlazando instrucciones a librerías.

El ensamblador **se usa cuando**:
  * Operaciones que se repitan muchas veces
  * Se requiere una velocidad enorme de procesamiento
  * Se necesita aprovechar los recursos del dispositivo al máximo.

El **entorno de desarrollo** consisten en:
  * **editor**: nano
  * **traductor linker y debugger**: as
  * **compilador**: gcc
  * **debugger**: gdb

### Aspecto de un programa en ensamblador:
![](https://github.com/RegaladoEdgar/programas/blob/main/unidad2/imagenes/aspecto.png)

Un programa en ensamblador se divide en 2 secciones:
  * **Sección de datos**: .data, variables se definen. Hay que tener cuidado de que los datos sean en múltiplos de 4, rellenar con 0s si no lo son.
  * **Sección de código**: .text, instrucciones de 32 bits, no hay que tener cuidado de dque no estén alineadas *(sección obligatoria)*.

## Elementos de un programa en ensamblador. 
  * **instrucciones**: representaciones del juego de instrucciones del procesador.
  * **3 tipos de simbolos**: etiquetas, macros y constantes simbólicas.
  * **Dato**: entidad que aporta un valor.
  * **Directivas**: delimitar secciones, insertar datos, crear macros, constantes simbólicas, etc.

### Instrucciones
Las instrucciones son aplicadas en tiempo de ejecución.
### Directivas
Se dan en el tiempo de ensamblado.Son instrucciones para el compilador, compienzan con un punto .directiva. Varían de compilador en compilador.

#### Tipos de directivas:
  * **De asignación**: para dar valores a constantes o reservar memoria para variables: .byte, .hword, .word, .ascii, .asciz, .zero, .space.

ejemplo: .equ (o .set) se usa para asignar un valor a una constante simbólica.
  * **De control**: .text y .data; delimitan secciones del módulo, .align para alinear el siguiente dato rellenando con ceros; .include para incluir otro archivo fuente;
ejemplo: .global hace visible al enlazador el simbolo que se ha definido bajo esta etiqueta.
  * **De operando**: operaciones lógicas, aritméticas y de desplazamiento.
  * **De macros**: .macro es un conjunto de sentencias en ensamblador que pueden repetirse en un programa.

Macro para n² + 1:

![](https://github.com/RegaladoEdgar/programas/blob/main/unidad2/imagenes/macro.png)

Los macros no sin iguales a los procedimientos. Un macro expande su código cada vez que se utiliza, un procedimiento siempre tiene el mismo código, pero un macro es más rápido

### Datos.

  * **numéricos**: En 4 bases:
    * **decimal**: Sin delimitador.
    * **hexadecimal**: Delimitarodr '0x'.
    * **binaria**: Delimitador '0b'.
    * **octal**: 0 → 015 es 13 en decimal.
  * **Caracteres**: Letras y símbolos unitarios ascii, ejemplo: ‘a’.
  * **Cadenas**: Las conocidas *strings* en lenguajes de alto nivel, conjuntos de caracteres, ejemplo: “aa”.

### Símbolos:

zona de datos o código. 
  * **Macros**: .macro
  * **constantes simbólicas**: .equ

### Instrucciones:
	formato {etiqueta: nemotécnico opearando/s /* comentario */}

  * etiqueta: opcional, no palabras reservadas
  * nemotécnico: abreviatura de una instrucción del procesador (1 a 11 caracteres)
  * operando/s: 0, 1 o más operandos. Si hay más de uno, el primero es destino y los demás son fuentes.
  
Pueden ser registros, etiquetas, valores, elementos complejos, deben medir una palabra de 32 bits, aunque un par miden 16 o 8.

#### tipos de instrucciones:
  * **de transferencia de datos**: mov, ldr, ldm, stm, push, pop.
  * **aritméticas**: add, cmp, adc, sbc, mul.
  * **manejo de bits**: and, tst, eor, orr, LSL, LSR, ASR, ROR, RRX.
  * **transferencia de control**: para controlar flujo del programa: b, bl, bx, blx.

### Ensamblar y linkar
  * **as** -o intro.o intro.s
  * **gcc** -o intro intro.o


#### usando gdb

1. gdb intro
2. quit → salir
3. start → inicia el debug
4. disassemble → desensamblado del programa
5. info registers r0 r1 r2 r3 → da direccioens a los registros y sus valores
6. info register r0 → lo mismo para el registro
7. print $r0 = 2 → asigna el valor al registros, y muestra un identificador “$1 = 2”
8. print $1 → ahorra tiempo al representar a un registro, en este caso a r0
9. stepi → da un paso en la ejecución.
10. Print $var1 → donde var1 es un puntero
11. continue → continuar hasta el final

*todos los comandos se pueden abreviar → (i r r1) → infor register *1*

#### Eenteros y naturales


##### Instrucciones lógicas
  * and r0, r1, r2 → r0 = r1 and r2
  * orr r0, r1, r2 → r0 = r1 or r2

flags → info register cpsr → 0x60000010 → 6hex → 0110 → NZCV
N = 0, Z = 1, C 0 1, V = 0

tst → hace operación and enre un registro y una máscara.

#### Desplazamientos

  * **desplazamientos lógicos**→ desplaza los bits del registro fuente introduciendo ceros. El último bit que sale del registro fuentes se almacena en la flag C

  * **desplazamientos aritméticos** → lo mismo, pero se respeta el signo.

#### Rotaciones
También desplazane pero el bit que sale del valor se realimenta. Sólo se puede rotar hacía la derecha de forma normal, pero si se quiere rotar al a izquierda se puede emular con esta rotación (ROR → derecha)

  * adcs → para sumar un registro consigo mismo, lo mismo que multipplicar por 2 o desplazar un bit hacia la izquierda.

  * LSRs r0, r0, #1 → igual a → movs r0, r0, LSR #1 → igual a add r0, r0, r0, LSL #2

####  instrucciones de multiplicación
  * mul → 32x 32  → truncada
  * umull → 32x32 → sin signo 32 bits
  * smull →32x32 → con signo de 32 bits
  * smulw* → 32x16 → con signo de 32x16 bits
  * smul** → 16x16 → con signo de 16x16 bits

 
la mutliplicacion truncada solo nos da como resultado la parte baja del producto.

Naturales → umull
enteros → smull

  * umull r0, r1, r2, r3 → (r2xr3) → parte baja se almacena en r0, parte alta en r1

  * smulw* → el asterisco puede ser una ‘b’  → seleccionar parte baja, o una ‘t’ → parte alta

  * smulwb r0, r1, r2 → r0 = r1 * parte_baja(r2)

  * smultb r0, r1, r2 → r0 = parte_alta(r1) * parte_baja(r2)

  * smulw* y smul** → no permiten sufijos para actualizar flags

(programas van de intro1 a intro5)
