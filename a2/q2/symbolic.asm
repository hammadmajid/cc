; Question 2: Assembly Translation of a = b - c
; Symbolic Assembly Code
; Variables: b = 8, c = 2, a = 0

section .data
    b db 8
    c db 2
    a db 0

section .text
    global main

main:
    ; MOV instruction: Load b into EAX (2 bytes)
    mov al, [b]
    
    ; SUB instruction: Subtract c from EAX (3 bytes)
    sub al, [c]
    
    ; MOV instruction: Store result in a (2 bytes)
    mov [a], al
    
    ; Exit program
    mov eax, 60
    mov edi, 0
    syscall
