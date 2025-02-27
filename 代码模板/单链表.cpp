typedef struct LNode { // 结构定义
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

bool InitLinkList(LinkList &L) { // 初始化
    /*
      L = NULL;
      return true;
    */
    L = (LNode *) malloc (sizeof(LNode));
    L->next = NULL;
    return true;
}

int Length(LinkList L) { // 求表长操作 (带头结点)
    int len = 0;
    LNode* cur = L;
    while (cur->next != NULL) {
        ++len;
        cur = cur->next;
    }
    return len;
}

bool ListInsert(LinkList &L, int i, ElemType e) { // 在第 i 个位置插入新节点 (data 为 x)
    LNode* p = L;
    int j = 0;
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
