# Queues in C

Queues are a type of linear data structure where elements are added at one end and removed from the other. They follow the First-In-First-Out (FIFO) principle, which means that the element that is added first is the first to be removed.

This repository contains an implementation of queues in C with the following functions:

enqueue: adds an element to the rear of the queue.
dequeue: removes and returns the element at the front of the queue.
display: prints all the elements in the queue.

## Output

```
Queue elements: 
Queue is empty
Enqueued: 10
Enqueued: 20
Enqueued: 30
Queue elements: 10 20 30 
Dequeued: 10
Queue elements: 20 30 
Enqueued: 40
Queue elements: 20 30 40 
```
In the output, we first create an empty queue and then enqueue three elements to it. We then display the elements in the queue, which prints 10 20 30 as expected. We dequeue the first element (10) and display the remaining elements, which prints 20 30. We then enqueue a new element (40) and display all the elements in the queue, which prints 20 30 40.


## Example Program

```
#include <stdio.h>
#include "queue.h"

int main() {
    queue q;
    init_queue(&q);
    display(&q);

    enqueue(&q, 10);
    printf("Enqueued: %d\n", 10);
    enqueue(&q, 20);
    printf("Enqueued: %d\n", 20);
    enqueue(&q, 30);
    printf("Enqueued: %d\n", 30);
    display(&q);

    int x = dequeue(&q);
    printf("Dequeued: %d\n", x);
    display(&q);

    enqueue(&q, 40);
    printf("Enqueued: %d\n", 40);
    display(&q);

    return 0;
}
```

