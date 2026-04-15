.section .data
    b: .byte 8      # b = 8
    c: .byte 2      # c = 2
    a: .byte 0      # a = 0 (will store result)

.section .text
    .globl _start

_start:
    # Load b into EAX
    movzbl b(%rip), %eax    # EAX = b (8)
    
    # Subtract c from EAX
    movzbl c(%rip), %ecx    # ECX = c (2)
    subl %ecx, %eax         # EAX = EAX - ECX = 8 - 2 = 6
    
    # Store result in a
    movb %al, a(%rip)       # a = AL = 6
    
    # Exit program (syscall 60)
    movl $60, %eax
    movl $0, %edi
    syscall
