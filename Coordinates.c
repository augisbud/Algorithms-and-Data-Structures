#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfunc (const void * a, const void * b) {
   return *(int*)a > *(int*)b;
}

bool isRightAngleTriangle(int c[3][2]) {
    int l[3] = 
    {
        (c[1][0] - c[0][0])*(c[1][0] - c[0][0]) + (c[1][1] - c[0][1])*(c[1][1] - c[0][1]),
        (c[2][0] - c[0][0])*(c[2][0] - c[0][0]) + (c[2][1] - c[0][1])*(c[2][1] - c[0][1]),
        (c[2][0] - c[1][0])*(c[2][0] - c[1][0]) + (c[2][1] - c[1][1])*(c[2][1] - c[1][1])
    };

    if(l[0] == 0 || l[1] == 0 || l[2] == 0)
        return false;
    
    qsort(l, 3, sizeof(int), cmpfunc);

    printf("%d %d %d\n", l[0], l[1], l[2]);

    if(l[0] + l[1] == l[2])
        return true;

    return false;
}

int main() {
    int data[3][2] =
    {
        {0, 0},
        {0, 0},
        {0, 0}
    };

    printf("%d", isRightAngleTriangle(data));

    return 0;
}

// sukurimas, sunaikinimas, patikrint ar pilnas ar tuscias, aktualios funckijos.