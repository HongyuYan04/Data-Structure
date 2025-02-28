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
