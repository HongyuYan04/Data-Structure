#define MaxSize 50
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    // initial a queue Q
    Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.rear == Q.front;
}

bool Enqueue(SqQueue &Q) {
    // add an element
    if ((rear + 1) % MaxSize == front) {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
