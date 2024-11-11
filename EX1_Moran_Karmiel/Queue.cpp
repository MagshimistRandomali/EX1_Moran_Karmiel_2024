#include <iostream>
#include "Queue.h"


void initQueue(Queue* q, unsigned int size) {
	q->arr = new int[size];
	q->maxSize = size;
	q->count = 0;
}


void cleanQueue(Queue* q) {
	delete[] q->arr;
}


void enqueue(Queue* q, unsigned int newValue) {
	if (isFull(q) != true) {
		q->arr[q->count] = newValue;
		q->count++;
	}
}


int dequeue(Queue* q) {
	int topValue = 0, i = 0, index = 1;

	if (isEmpty(q) == true) {
		return -1;
	}

	topValue = q->arr[0];
	for (i; i < q->count; i++) {
		q->arr[i] = q->arr[index];
		index++;
	}
	q->count--;
	return topValue;
}


bool isEmpty(Queue* s) {
	return (s->count == 0);
}


bool isFull(Queue* s) {
	return (s->count >= s->maxSize);
}
