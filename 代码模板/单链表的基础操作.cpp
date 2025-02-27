#include <stdio.h>
#include <stdlib.h>

#define ElemType int    // 数据类型定义

typedef struct LNode {    // 结构定义
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

bool InitLinkList(LinkList &L) {    // 初始化
    /*
        L = NULL;
        return true;
    */
    L = (LNode *) malloc (sizeof(LNode));
    L->next = NULL;
    return true;
}

int Length(LinkList L) {    // 求表长操作 (带头结点)
    int len = 0;
    LNode* cur = L;
    while (cur->next != NULL) {
        ++len;
        cur = cur->next;
    }
    return len;
}

bool ListInsert(LinkList &L, int i, ElemType e) {    // 在第 i 个位置插入新节点 (data 为 e)
    if (i < 1) {
        return false;
    }
    /*
        若链表 L 不带头结点, 特判 i = 1 的 Case
        if (i == 1) {
            LNode* ptr = (LNode *) malloc (sizeof(LNode));
            if (ptr == NULL) {
                return false;
            }
            ptr->data = e;
            ptr->next = L;
            L = ptr;
            return true;
        }
    */
    LNode* p = L;
    int j = 0;                        // 若链表 L 不带头结点, j 初始化为 1
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == NULL) {
        return false;
    }
    LNode* q = (LNode *) malloc (sizeof(LNode));
    if (q == NULL) {
        return false;
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool InsertNextNode(LNode* p, ElemType e) {    // 后插操作
    if (p == NULL) {
        return false;
    }
    LNode* q = (LNode *) malloc (sizeof(LNode));
    if (q == NULL) {
        return false;
    }
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool InsertPriorNode(LNode* p, ElemType e) {    // 前插操作 (fake)
    if (p == NULL) {
        return false;
    }
    LNode* q = (LNode *) malloc (sizeof(LNode));
    if (q == NULL) {
        return false;
    }
    q->next = p->next;
    p->next = q;
    q->data = p->data;
    p->data = e;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e) {    // 删除单链表 L 的第 i 个结点
    LNode* p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        ++j;
        p = p->next;
    }
    if (p->next == NULL || j > i - 1) {
        return false;
    }
    LNode* ptr = p->next;
    e = ptr->data;
    p->next = ptr->next;
    free(ptr);
    return true;
}

bool Del(LNode* p) {    // 删除结点 p
    if (p == NULL) {
        return false;
    }
    LNode* q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
