#include <bits/stdc++.h>

#define MAXSIZE 50
#define ElemType int

typedef struct {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(const SqQueue Q) {
    if (Q.rear == Q.front) {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front) {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}

int main() {
    SqQueue Q;
    InitQueue(Q);

    /*
    
        ...
    
    */
    return 0;
}