#include <stdio.h>

int main() {
    unsigned char b = 8;
    unsigned char c = 2;
    unsigned char a = 0;
    
    printf("Initial values:\n");
    printf("  b = %d\n", b);
    printf("  c = %d\n", c);
    printf("  a = %d\n\n", a);
    
    printf("Executing: a = b - c\n");
    a = b - c;
    
    printf("Result:\n");
    printf("  a = %d\n\n", a);
    
    printf("Memory representation:\n");
    printf("  b at memory address ~offset: %d bytes\n", (int)sizeof(b));
    printf("  c at memory address ~offset: %d bytes\n", (int)sizeof(c));
    printf("  a at memory address ~offset: %d bytes\n", (int)sizeof(a));
    
    return 0;
}
