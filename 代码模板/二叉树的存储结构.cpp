// 顺序存储
#define MaxSize 500
typedef struct {
    ElemType data;
    bool IsEmpty;
} TreeNode;
TreeNode T[MaxSize];

// 链式存储 (二叉链表)
struct ElemType {
    int value;    
};

typedef struct BiTNode {
    // 结构定义
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Root = NULL;
Root = (BiTree) malloc (sizeof(BiTNode));
Root->data = {1};
Root->lchild = NULL;
Root->rchild = NULL;

BiTNode *p = (BiTNode *) malloc (sizeof(BiTNode));
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
Root->lchild = p;
