#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define ElemType int
#define MAXSIZE 1000

typedef struct {
    int top0;
    int top1;
    ElemType data[MAXSIZE];
} SharedStack;

void InitSharedStack(SharedStack &S) {
    S.top0 = -1;
    S.top1 = MAXSIZE;
}

bool Push(SharedStack &S, int id, ElemType x) {
    assert(id == 0 || id == 1);

    if (S.top1 - S.top0 == 1) {
        return false;
    }

    if (id == 0) {
        S.data[++S.top0] = x;
    } else {
        S.data[--S.top1] = x;
    }

    return true;
}

bool Pop(SharedStack &S, int id, ElemType &x) {
    assert(id == 0 || id == 1);

    if (id == 0) {
        if (S.top0 == -1) {
            return false;
        } else {
            x = S.data[S.top0--];
            return true;
        }
    } else {
        if (S.top1 == MAXSIZE) {
            return false;
        } else {
            x = S.data[S.top1++];
            return true;
        }
    }
}

bool GetTop(SharedStack &S, int id, ElemType &x) {
    assert(id == 0 || id == 1);

    if (id == 0) {
        if (S.top0 == -1) {
            return false;
        } else {
            x = S.data[S.top0];
            return true;
        }
    } else {
        if (S.top1 == MAXSIZE) {
            return false;
        } else {
            x = S.data[S.top1];
            return true;
        }
    }
}

int main() {
    
    return 0;
}