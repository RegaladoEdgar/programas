/*
   @@
    @@ Instituto Tecnologico de Tijuana
    @@ Depto de Sistemas y Computación
    @@ Ing. En Sistemas Computacionales
    @@   
    @@ Autor : Edgar Regalado @nickname RegaladoEdgar
    @@ Repositorio: http://github.com/RegaladoEdgar/programas
    @@ Fecha de revisión: ____
    @@ 
    @
    @ Objetivo del programa:
    @	
    @
    @ Entradas, procesos y salidas:
    @   Thumb-2, ARM64, ...
    @
    @ Errores a reportar / retroalimentar
    @   Para .....
    @
    @ 
*/

.data

/* Segmento de Datos: define el mensaje y calula el tramaño de la cadena. */
msg:
    .ascii        "Hello, ARM64!\n"
len = . - msg

.text

/* Cuerpo del programa para desplegar la variable anterior. */
.globl _start
_start:
    /* syscall write(int fd, const void *buf, size_t count) */
    mov     x0, #1      /* fd := STDOUT_FILENO */
    ldr     x1, =msg    /* buf := msg */
    ldr     x2, =len    /* count := len */
    mov     w8, #64     /* write is syscall #64 */
    svc     #0          /* invoke syscall */

    /* syscall exit(int status) */
    mov     x0, #0      /* status := 0 */
    mov     w8, #93     /* exit is syscall #1 */
    svc     #0          /* invoke syscall */
