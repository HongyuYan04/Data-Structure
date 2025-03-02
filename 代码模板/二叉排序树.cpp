/* 
    结构定义如下 : 

      typedef struct BSTNode {
          ElemType data;
          struct BSTNode *lchild, *rchild;
      } BSTNode, *BSTree;

*/ 

BSTNode* BST_Search(BSTree T, ElemType key) {
    //    二叉排序树的查找 (非递归)
    while (T != NULL && key != T->value) {
        if (key < T->value) {
            T = T->lchild;
        } else {
            T = T->rchild;
        }
    }
    return T;
}

BSTNode* BST_Search(BSTree T, ElemType key) {
    //    二叉排序树的查找 (递归)
    if (T == NULL || key == T->value) {
        return T;
    }
    if (key < T->key) {
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
        T->value = x;
        T->lchild = NULL;
        T->rchild = NULL;
        return true;
    }
    if (k == T->
}
