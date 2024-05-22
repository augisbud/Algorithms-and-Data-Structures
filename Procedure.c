#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b, int c) {
    return a + b + c;
}

int * divisor(int a, int b) {
    int * result = malloc(2 * sizeof(int));
    
    result[0] = a / b;
    result[1] = a % b;

    return result;
}

int main() {
    printf("%d\n", sum(5, 15, 12));

    int * divided = divisor(9, 2);
    printf("%d %d", (*divided), *(divided + 1));
    free(divided);
    
    return 0;
}