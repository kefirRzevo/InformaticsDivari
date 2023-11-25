;%include "st_io.inc"
global start


section .data
    A dd 254
    B dd 250

section .text

start:
    mov eax, [A]
    add eax, word[B]
    mov dword[A], eax

    mov eax, dd[A+2]
    adc eax, dd[B+2]
    mov dd[A+2], eax

    ;UNSINT[A]
    ;FINISH

;nasm -f macho64 Z1.asm
;ld -e start -static hello.o -o hello
