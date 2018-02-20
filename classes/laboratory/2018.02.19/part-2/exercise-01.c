#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int n, i = 0, m = -1;
    float a, b;
    scanf("%d", &n);
    for (; i < n; i++) {
        scanf("%f %f", &a, &b);
        
        if (a != b) {
            m = a > b;
            break;
        }
    }
    
    printf((m == -1) 
            ? "As sequências são iguais.\n" 
            : (m) 
                ? "Sequência A é maior que a B.\n" 
                : "Sequência A é menor que a B.\n");

    return EXIT_SUCCESS;
}
