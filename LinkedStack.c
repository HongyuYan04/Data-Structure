// include the headfile
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// LinkedStack`s structure definition is as follows :
#define ElemType int
typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkedStack;

// Initial the LinkedStack stack, which has a head node.
bool InitStack(LinkedStack **stack) {
    *stack = (LinkedStack *) malloc (sizeof(LinkedStack));
    if (*stack == NULL) {
        return false;
    }
    (*stack)->next = NULL;
    return true;
}

// If stack has not a head node, the InitStack function is :
bool InitStack(LinkedStack **stack) {
    *stack = NULL;
    return true;
}

// The Push function for LinkedStack, which has a head node.
bool Push(LinkedStack **stack, ElemType e) {
    LinkedStack* newNode = (LinkedStack *) malloc (sizeof(LinkedStack));
    if (newNode == NULL) {
        return false;
    }
    newNode->data = e;
    newNode->next = (*stack)->next;
    (*stack)->next = newNode;
    return true;
}

// If stack has not a head node, the Push function is :
bool Push(LinkedStack **stack, ElemType e) {
    LinkedStack* newNode = (LinkedStack *) malloc (sizeof(LinkedStack));
    if (newNode == NULL) {
        return false;
    }
    newNode->data = e;
    newNode->next = *stack;
    *stack = newNode;
    return true;
}

// The Pop function for LinkedStack, which has a head node.
bool Pop(LinkedStack **stack, ElemType *value) {
    if ((*stack)->next == NULL) {
        return false;
    }
    LinkedStack *temp = (*stack)->next;
    *value = temp->data;
    (*stack)->next = temp->next;
    free(temp);
    return true;
}

// If stack has not a head node, the Pop function is :
bool Pop(LinkedStack **stack, ElemType *value) {
    if (*stack == NULL) {
        return false;
    }
    LinkedStack *temp = *stack;
    *value = temp->data;
    *stack = temp->next;
    free(temp);
    return true;
}

// The Top function for LinkedStack, which has a head node.
bool Top(LinkedStack *stack, ElemType *value) {
    if (stack->next == NULL) {
        return false;
    }
    *value = stack->next->data;
    return true;
}

// If stack has not a head node, the Top function is :
bool Top(LinkedStack *stack, ElemType *value) {
    if (stack == NULL) {
        return false;
    }
    *value = stack->data;
    return true;
}

// The Empty function for LinkedStack, which has a head node.
bool Empty(LinkedStack *stack) {
    return stack->next == NULL;
}

// If stack has not a head node, the Empty function is :
bool Empty(LinkedStack *stack) {
    return stack == NULL;
}

// The Destroy function for LinkedStack, which has a head node.
void destroyStack(LinkedStack **stack) {
    LinkedStack *temp;
    while ((*stack)->next != NULL) {
        temp = (*stack)->next;
        (*stack)->next = temp->next;
        free(temp);
    }
    free(*stack);
}

// If stack has not a head node, the Destroy function is :
void destroyStack(LinkedStack **stack) {
    LinkedStack *temp;
    while (*stack != NULL) {
        temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}
