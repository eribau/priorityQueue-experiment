#include <stdlib.h>
#include <stdio.h>

static int *pq;
static int N;
static int max;

void printHeap() {
  for(int i = 1; i <= N; i++) {
    printf("%d\n", pq[i]);
  }
}

void exch(int a, int b) {
  int temp = pq[a];
  pq[a] = pq[b];
  pq[b] = temp;
}

void swim(int a[], int k) {
  while(k > 1 && (a[k/2] > a[k])) {
    exch(k, k/2);
    k = k/2;
  }
}

void sink(int a[], int k, int n) {
  int j;
  while(2*k <= n) {
    j = 2*k;
    if(j < n && (a[j] > a[j+1])) j++;
    if(!(a[k] > a[j])) break;
    exch(k, j);
    k = j;
  }
}

void heapInit(int maxN) {
  pq = malloc((maxN+1)*sizeof(int));
  max = maxN;
  N = 0;
}

void resize(int size) {
  int *temp = malloc((size+1)*sizeof(int));
  for(int i = 1; i <= size; i++) {
    temp[i] = pq[i];
  }
  free(pq);
  pq = temp;
  max = size;
}
void heapInsert(int v) {
  if(N == max) {
    resize(2*max); // if the array is full, double the array size
  }
  pq[++N] = v;
  swim(pq, N);
}
int heapDelmin() {
  exch(1, N);
  sink(pq, 1, N-1);
  if(N > 0 && N == max/4) { // if the array is quarter full, halve the size
    resize(max/2);
  }
  return pq[N--];
}
