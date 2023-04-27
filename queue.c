#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue {
  int front;
  int rear;
  int items[MAX_SIZE];
} queue;

void init_queue(queue* q) {
  q->front = -1;
  q->rear = -1;
}

int is_empty(queue* q) {
  return (q->front == -1 && q->rear == -1);
}

int is_full(queue* q) {
  return (q->rear == MAX_SIZE - 1);
}

void enqueue(queue* q, int data) {
  if (is_full(q)) {
    printf("Error: Queue is full\n");
    return;
  }
  if (is_empty(q)) {
    q->front = q->rear = 0;
  } else {
    q->rear++;
  }
  q->items[q->rear] = data;
  printf("Enqueued: %d\n", data);
}

int dequeue(queue* q) {
  if (is_empty(q)) {
    printf("Error: Queue is empty\n");
    return -1;
  }
  int data = q->items[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front++;
  }
  printf("Dequeued: %d\n", data);
  return data;
}

void display(queue* q) {
  if (is_empty(q)) {
    printf("Queue elements: \n");
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  for (int i = q->front; i <= q->rear; i++) {
    printf("%d ", q->items[i]);
  }
  printf("\n");
}

int main() {
  queue q;
  init_queue(&q);
  display(&q);

  enqueue(&q, 10);
  enqueue(&q, 20);
  enqueue(&q, 30);
  display(&q);

  dequeue(&q);
  display(&q);

  enqueue(&q, 40);
  display(&q);

  return 0;
}
