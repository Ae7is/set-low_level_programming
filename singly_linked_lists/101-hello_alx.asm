section .data
    message db "Hello, Frontier", 10, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rdi, message
    xor eax, eax
    call printf

    mov eax, 0
    pop rbp
    ret
