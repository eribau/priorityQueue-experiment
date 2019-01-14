#include <stdlib.h>
#include <stdio.h>

static double *pq;
static int N;
static int max;

void printHeap() {
  for(int i = 1; i <= N; i++) {
    printf("%f\n", pq[i]);
  }
}

void exch(int a, int b) {
  double temp = pq[a];
  pq[a] = pq[b];
  pq[b] = temp;
}

void swim(double a[], int k) {
  while(k > 1 && (a[k/2] > a[k])) {
    exch(k, k/2);
    k = k/2;
  }
}

void sink(double a[], int k, int n) {
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
  pq = malloc((maxN+1)*sizeof(double));
  max = maxN;
  N = 0;
}

void resize(int size) {
  double *temp = malloc((size+1)*sizeof(double));
  for(int i = 1; i < N; i++) {
    temp[i] = pq[i];
  }
  free(pq);
  pq = temp;
  max = size;
}
void heapInsert(double v) {
  if(N == max) {
    resize(2*max); // if the array is full, double the array size
  }
  pq[++N] = v;
  swim(pq, N);
}

double heapDelmin() {
  exch(1, N);
  sink(pq, 1, N-1);
  if(N > 0 && N == max/4) { // if the array is quarter full, halve the size
    resize(max/2);
  }
  return pq[N--];
}
