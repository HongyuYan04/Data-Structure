// 类型定义
struct ElemType {

};

// 双亲表示法
#define MAX_TREE_SIZE 100
typedef struct {
    ElemType data;
    int parent;  // 记录父节点的下标, 对于根节点, parent = -1
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;  // 节点数
} PTree;

// 孩子表示法

// 孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
