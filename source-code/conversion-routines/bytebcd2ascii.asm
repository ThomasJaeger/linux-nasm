;name: bytebcd2ascii.asm
;
;build: nasm -felf64 bytebcd2ascii.asm -o bytebcd2ascii.o
;
;description: Convert a 8 bit packed bcd in lower 8 bits of rdi to ascii in rax.
;             
;example macro:
;%macro 1
;    mov    rax,%1
;    and    rax,0xFF             ;keep lower 8 bits
;    mov    ah,0x33              ;0x33 into ah
;    rol    ax,4                 ;ah = ascii high 4 bcd
;    rol    al,4                 ;al = ascii low 4 bit bcd
;%endmacro

bits 64

global bytebcd2ascii

section .text

bytebcd2ascii:
    mov     rax,rdi
    and     rax,0xFF            ;keep lower 8 bits
    mov     ah,0x33             ;0x33 into ah
    rol     ax,4                ;ah = ascii high 4 bcd
    rol     al,4                ;al = ascii low 4 bit bcd
    ret
