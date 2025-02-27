typedef struct LNode {  // 单链表的结构定义
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

void Head_Build(LinkList &L, ElemType e[], int n) {    // 头插法建立单链表
    L = (LNode *) malloc (sizeof(LNode));
    L->next = NULL;
    LNode* p;
    for (int i = 0; i < n; i++) {
        p = (LNode *) malloc (sizeof(LNode));
        p->data = e[i];
        p->next = L->next;
        L->next = p;
    }
}

void Tail_Build(LinkList &L, ElemType e[], int n) {    // 尾插法建立单链表
    L = (LNode *) malloc (sizeof(LNode));
    L->next = NULL;
    LNode* r = L;
    LNode* p;
    for (int i = 0; i < n; i++) {
        p = (LNode *) malloc (sizeof(LNode));
        p->data = e[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

// 对于不带头结点的单链表, 建表代码如下：
void Head_Build(LinkList &L, ElemType e[], int n) {    // 头插法
    L = NULL;
    LNode* p;
    for (int i = 0; i < n; i++) {
        p = (LNode *) malloc (sizeof(LNode));
        p->data = e[i];
        p->next = L;
        L = p;
    }
}

void Tail_Build(LinkList &L, ElemType e[], int n) {    // 尾插法
    L = NULL;
    LNode* r = NULL;
    LNode* p;
    for (int i = 0; i < n; i++) {
        p = (LNode *) malloc (sizeof(LNode));
        p->data = e[i];
        p->next = NULL;
        if (L == NULL) {
            L = p;
        } else {
            r->next = p;
        }
        r = p;
    }
}
