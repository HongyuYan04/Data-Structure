#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// include the headfile

// LinkedStack`s structure definition is as follows :
#define ElemType int
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkedStack;

// Initial the LinkedStack L, which has a head node.
bool InitStack(LinkedStack **stack) {
    *stack = (LinkedStack *) malloc (sizeof(LinkedStack));
    if (*stack == NULL) {
        return false;
    }
    (*stack)->next = NULL;
    return true;
}

// If L has not a head node, the InitStack function is :
bool InitStack(LinkedStack **stack) {
    *stack = NULL;
    return true;
}


