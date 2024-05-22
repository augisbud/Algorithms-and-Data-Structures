#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "Bank.h"

int main()
{
    srand(50);

    runBankSimulation(3, 5, 0.4);
    srand(50);
    runBankSimulation(6, 15, 0.4);
    srand(50);
    runBankSimulation(3, 5, 0.8);
    srand(50);
    runBankSimulation(6, 15, 0.8);
    return 0;
}