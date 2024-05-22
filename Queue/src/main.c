#include "Queue.h"

int main() {
    Queue * queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 6);
    enqueue(queue, 7);

    printf("Peeked: %d\n", peek(queue));

    return 0;
}