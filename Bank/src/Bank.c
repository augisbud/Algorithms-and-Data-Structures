#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Bank.h"

bool isCustomerArrived(double arrival_prob) {
    double p = (double) rand() / RAND_MAX;
    return p < arrival_prob;
}

int getServiceTime(int service_time) {
    return (rand() % (2 * service_time)) + 1;
}

int findShortestQueue(Queue *cashiers[], int num_cashiers) {
    int shortestQueueIndex = 0;
    int shortestQueueSize = getSize(cashiers[0]);
    for (int i = 1; i < num_cashiers; i++) {
        int queueSize = getSize(cashiers[i]);
        if (queueSize < shortestQueueSize) {
            shortestQueueIndex = i;
            shortestQueueSize = queueSize;
        }
    }
    return shortestQueueIndex;
}

void runBankSimulation(int num_cashiers, int service_time, double arrival_prob) {
    printf("Running Simulation (%d cashiers, %d average service time, %.2f arrival probability)\n", num_cashiers, service_time, arrival_prob);
    Queue *cashiers[num_cashiers];
    for (int i = 0; i < num_cashiers; i++) {
        cashiers[i] = createQueue();
    }

    Queue *waitingLine = createQueue();

    int totalCustomers = 0;
    int totalServiceTime = 0;
    int maxQueueSize = 0;
    int totalQueueSize = 0;

    for (int time = 0; time < 7 * 24 * 60; time++) {
        if (isCustomerArrived(arrival_prob)) {
            totalCustomers++;
            enqueue(waitingLine, time);
            totalQueueSize++;
            if (getSize(waitingLine) > maxQueueSize) {
                maxQueueSize = getSize(waitingLine);
            }
        }

        while (!isEmpty(waitingLine)) {
            int shortestQueueIndex = findShortestQueue(cashiers, num_cashiers);
            if (isEmpty(cashiers[shortestQueueIndex])) {
                int arrivalTime = dequeue(waitingLine);
                enqueue(cashiers[shortestQueueIndex], arrivalTime);
                totalQueueSize--;
            } else {
                break;
            }
        }

        for (int i = 0; i < num_cashiers; i++) {
            if (!isEmpty(cashiers[i])) {
                if (time - peek(cashiers[i]) >= getServiceTime(service_time)) {
                    dequeue(cashiers[i]);
                    totalServiceTime += getServiceTime(service_time);
                }
            }
        }

        totalQueueSize += getSize(waitingLine);
        for (int i = 0; i < num_cashiers; i++) {
            totalQueueSize += getSize(cashiers[i]);
        }
    }

    double avgServiceTime = (double)totalServiceTime / totalCustomers;
    double avgQueueSize = (double)totalQueueSize / (7 * 24 * 60);
    printf("Average Service Time: %.2f minutes\n", avgServiceTime);
    printf("Average Queue Size: %.2f customers\n", avgQueueSize);
    printf("Maximum Queue Size: %d customers\n\n", maxQueueSize);

    for (int i = 0; i < num_cashiers; i++) {
        destroyQueue(cashiers[i]);
    }
    destroyQueue(waitingLine);
}