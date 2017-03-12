; Name:         sigfpe.asm
;
; Build:        nasm "-felf64" sigfpe.asm -l sigfpe.lst -o sigfpe.o
;               ld -s -melf_x86_64 -o sigfpe sigfpe.o 
;
; Description:  Floating point exception signal handler demo
;
; Reference:    Beejs guide to IPC - http://beej.us/guide/bgipc/output/html/multipage/signals.html#catchsig
;               http://syprog.blogspot.be/2011/10/iterfacing-linux-signals.html for the 64 bit structures
;

bits 64
align 16

[list -]
    %include "unistd.inc"
    %include "signals.inc"
[list +]

section .bss
  
section .data

    SIGACTION   sigaction

    got_sigfpe:         db      0
    ; the messages
    msgDivisionByZero:  db      "Division by zero error", 10
    .length:            equ     $-msgDivisionByZero
    ; error message
    msgSignalError:     db      "sigaction error, terminating program.", 10
    .length:            equ     $-msgSignalError

section .txt
        global  _start

_start:
    ;Initialize SIGFPE handler
    mov     rax, HandlerSIGFPE                        ; set handler to pointer to procSigInt
    mov     qword [sigaction.sa_handler], rax         ; in sigaction structure
    mov     rax, SA_RESTORER | SA_SIGINFO            ; sa_flags
    mov     qword [sigaction.sa_flags], rax
    mov     rax, .exit
    mov     qword [sigaction.sa_restorer], rax

    mov     r10, NSIG_WORDS                           ; don't forget this, size of mask in 64 bit words
    syscall rt_sigaction, SIGFPE, sigaction, 0
    ;If rax < 0 , we got an error, rax should be zero
    and     rax, rax
    js      .error

    ;Here we will count down from 10 to 0 each time dividing the counter to itself.
    ;once zero is reached we should trigger the SIGFPE signal and execute the signal action
    ;defined in ProcSIGFPE indicating a division by zero occured.
    ;There we will dump all register contents as a demo.
    mov     rcx, 10
.repeat:
    mov     rax, rcx
    idiv    rax                 ;rax=rax/rax
    ;If no exception occured continue
    dec     rcx
    ;Here we check that rcx equals zero and we must exit the loop, however we will not exit and
    ;demonstrate a wrong compare with zero.
    and     rcx,rcx
    jge     .repeat            ;must be jg instead of jge

.done:    
    jmp     .exit
    ; in case we have an error
.error:
    syscall  write, stdout, msgSignalError, msgSignalError.length
    ; exit the program
.exit:
    syscall  exit, 0

; The SIGFPE Floating point exception handler
HandlerSIGFPE:
    ; rdi=signum, rsi=siginfo_t pointer, rdx=sigcontext*
    mov      rax,[rdx+UCONTEXT_STRUC.uc_mcontext+SIGCONTEXT_STRUC.rip]       ; get rip where error occured
    syscall  write,stderr,msgDivisionByZero,msgDivisionByZero.length
    ret
