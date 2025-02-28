/**
    Reference : leetcode.cn
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* preorderTraversal(struct TreeNode* root, int* returnSize) {}

// 先序遍历 :
void PreOrder(struct TreeNode* root, int* seq, int* idx) {
    if (root) {
        seq[(*idx)++] = root->val;
        PreOrder(root->left, seq, idx);
        PreOrder(root->right, seq, idx);
    }   
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* seq = (int *) malloc (sizeof(int) * 105);
    *returnSize = 0;
    PreOrder(root, seq, returnSize);
    return seq;
}

// 中序遍历 :
void InOrder(struct TreeNode* root, int* seq, int* idx) {
    if (root) {
        InOrder(root->left, seq, idx);
        seq[(*idx)++] = root->val;
        InOrder(root->right, seq, idx);
    }   
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* seq = (int *) malloc (sizeof(int) * 105);
    *returnSize = 0;
    InOrder(root, seq, returnSize);
    return seq;
}

// 后序遍历 ：
void PostOrder(struct TreeNode* root, int* seq, int* idx) {
    if (root) {
        PostOrder(root->left, seq, idx);
        PostOrder(root->right, seq, idx);
        seq[(*idx)++] = root->val;
    }
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* seq = (int *) malloc (sizeof(int) * 105);
    *returnSize = 0;
    PostOrder(root, seq, returnSize);
    return seq;
}

// 求二叉树的高度 :
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return L > R ? L + 1 : R + 1;       
    }
}

// 二叉树的层次遍历
typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct LinkNode {
    BiTNode *data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *) malloc (sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(LinkQueue &Q, BiTNode *x) {
    LinkNode *p = (LinkNode *) malloc (sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue(LinkQueue &Q, BiTNode* &ans) {
    LinkNode *p = Q.front->next;
    ans = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
}

void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    BiTNode *p;
    EnQueue(Q, T);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL) {
            EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL) {
            EnQueue(Q, p->rchild);
        }
    }
}
