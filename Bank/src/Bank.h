#ifndef BANK_H
#define BANK_H

#include "queue.h"

// Function to simulate customer arrival based on arrival probability
bool isCustomerArrived(double arrival_prob);

// Function to simulate customer service time
int getServiceTime();

// Function to run bank simulation
void runBankSimulation(int num_cashiers, int service_time, double arrival_prob);

#endif
