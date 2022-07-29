#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max){
  s->ptr=0;
  if((s->stk = calloc(max, sizeof(max))) == NULL){ //memory allocation fail
    s->max=0;
    return -1;
  }
  s->max = max;
  return 0;
}

int Push(IntStack *s, int x){
  if(s->ptr >= s->max){
    printf("StackOverFlow\n");
    return -1;
  }
  s->stk[s->ptr++] = x;
  return 0;
}

int Pop(IntStack *s, int *x){
  if(s->ptr<=0){
    printf("UnderFlow\n");
    return -1;
  }
  *x = s->stk[--s->ptr];
  return 0;
}

int Peek(const IntStack *s, int *x){
  if(s->ptr<=0){
    printf("Empty Stack\n");
    return -1;
  }
  printf("PEEK: %d\n", s->stk[s->ptr-1]);
  return 0;
}

void Clear(IntStack *s){
  s->ptr = 0;
}

int Capacity(const IntStack *s){
  printf("Capacity: %d\n", s->max);
  return 0;
}

int Size(const IntStack *s){
  printf("Size: %d\n", s->ptr);
  return 0;
}

int IsEmpty(const intStack *s){
  if(s->ptr==0){
    return 1;
  }
  return 0;
}

int IsFull(const IntStack *s){
  if(s->ptr>=s->max){
    return 1;
  }
  return 0;
}

int Search(const IntStack *s, int x){
  for(int i=0; i<s->ptr; i++){
    if(s->stk[i] == x){
      return i;
    }
  }
  return -1;
}

void Print(const IntStack *s){
  printf("Print\n----------\n");
  for(int i=s->ptr; i>=0; i--){
    printf("%d\n", s->stk[i]);
  }
  printf("----------\n");
}

void Terminate(IntStack *s){
  while(s->stk!=NULL){
    free(s->stk);
  }
  s->max=0; s->ptr=0;
}
