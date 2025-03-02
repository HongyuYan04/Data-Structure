/* 
    结构定义如下 : 

      typedef struct BSTNode {
          ElemType data;
          struct BSTNode *lchild, *rchild;
      } BSTNode, *BSTree;

*/ 

BSTNode* BST_Search(BSTree T, ElemType key) {
    //    二叉排序树的查找 (非递归)
    while (T != NULL && key != T->data) {
        if (key < T->data) {
            T = T->lchild;
        } else {
            T = T->rchild;
        }
    }
    return T;
}

BSTNode* BST_Search(BSTree T, ElemType key) {
    //    二叉排序树的查找 (递归)
    if (T == NULL || key == T->data) {
        return T;
    }
    if (key < T->data) {
        return BST_Search(T->lchild, key);
    } else {
        return BST_Search(T->rchild, key);
    }
    return T;
}

bool BST_Insert(BSTree &T, ElemType x) {
    //    二叉排序树的插入 (递归)
    if (T == NULL) {
        T = (BSTNode *) malloc (sizeof(BSTNode));
        T->data = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    if (x == T->data) {
        return false;
    } else if (x < T->data) {
        return BST_Insert(T->lchild, x);
    } else {
        return BST_Insert(T->rchild, x);
    }
}

bool BST_Insert(BSTree *T, ElemType x) {
    //    二叉排序树的插入 (非递归)
    BSTNode *p = *T;      // p 用来在树中遍历
    BSTNode *parent = NULL; // parent 用来记录 p 的父结点

    // 1. 找到插入位置（或判断是否已存在）
    while (p != NULL) {
        parent = p;
        if (x < p->data) {
            p = p->lchild;
        } else if (x > p->data) {
            p = p->rchild;
        } else {
            // 若 x == p->data，则表示已经存在该值，不再插入
            return false;
        }
    }

    // 2. 创建新结点
    BSTNode *newNode = (BSTNode *)malloc(sizeof(BSTNode));
    newNode->data = x;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    // 3. 若原树为空，则新结点即为根结点
    if (parent == NULL) {
        *T = newNode;
    } else {
        // 根据大小挂到相应的父结点左右孩子
        if (x < parent->data) {
            parent->lchild = newNode;
        } else {
            parent->rchild = newNode;
        }
    }
    return true;
}

