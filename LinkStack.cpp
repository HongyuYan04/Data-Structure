#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ElemType int

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

void InitStack(LinkStack &S) {
    S = NULL;
}

bool Push(LinkStack &S, ElemType x) {
    LinkNode* Node = (LinkNode *) malloc (sizeof(LinkNode));
    if (!Node) {
        return false;
    }
    Node->data = x;
    Node->next = S;
    S = Node;
    return true;
}

bool Pop(LinkStack &S, ElemType &x) {
    if (!S) {
        return false;
    }
    LinkNode *p = S;
    x = p->data;
    S = p->next;
    free(p);
    return true;
}

bool getTop(LinkStack S, ElemType &x) {
    if (!S) {
        return false;
    }
    x = S->data;
    return true;
}

bool isEmpty(LinkStack S) {
    return S == NULL;
}

void clear(LinkStack &S) {
    ElemType tmp;
    while (Pop(S, tmp)) {}
}

int main() {
    LinkStack S;
    InitStack(S);
    
    /* 
        ...
    
    */
    return 0;
}