
#include <bits/stdc++.h>
using namespace std;

// ==================== IMPLEMENTATION ====================

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// ==================== BASIC OPERATIONS ====================

                                                    // BST INSERTION
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) return new TreeNode(value);

    if (value < root->val) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->val) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

                                                    // BST SEARCH
bool searchNode(TreeNode* root, int target) {
    if (root == NULL) return false;

    if (root->val == target) return true;

    if (target < root->val) {
        return searchNode(root->left, target);
    }

    return searchNode(root->right, target);
}

                                                    // INORDER: LEFT -> ROOT -> RIGHT
void inorder(TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

                                                    // PREORDER: ROOT -> LEFT -> RIGHT
void preorder(TreeNode* root) {
    if (root == NULL) return;

    cout << root->val << " ";

    preorder(root->left);
    preorder(root->right);
}

                                                    // POSTORDER: LEFT -> RIGHT -> ROOT
void postorder(TreeNode* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);

    cout << root->val << " ";
}

                                                    // LEVEL ORDER (BFS)
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if (cur->left != NULL) q.push(cur->left);
        if (cur->right != NULL) q.push(cur->right);
    }
}

                                                    // HEIGHT OF TREE (IN NODES)
int height(TreeNode* root) {
    if (root == NULL) return 0;

    return 1 + max(height(root->left), height(root->right));
}

                                                    // COUNT ALL NODES
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

                                                    // COUNT LEAF NODES
int countLeaves(TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeaves(root->left)
         + countLeaves(root->right);
}

                                                    // FIND MINIMUM VALUE IN BST
TreeNode* minimumNode(TreeNode* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

                                                    // FIND MAXIMUM VALUE IN BST
TreeNode* maximumNode(TreeNode* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

                                                    // BST DELETION
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) return NULL;

    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    }

    else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    }

    else {
        // No left child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;

            return temp;
        }

        // No right child
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;

            return temp;
        }

        // Two children
        TreeNode* temp = minimumNode(root->right);

        root->val = temp->val;

        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

                                                    // DELETE ENTIRE TREE
void deleteTree(TreeNode* root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

/*
    QUICK USAGE:

    TreeNode* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    inorder(root);
    cout << endl;

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    levelOrder(root);
    cout << endl;

    cout << searchNode(root, 40) << endl;
    cout << height(root) << endl;
    cout << countNodes(root) << endl;
    cout << countLeaves(root) << endl;

    root = deleteNode(root, 30);

    deleteTree(root);
*/

/*
    IMPORTANT:

    Insertion, searching, minimum/maximum and deletion above
    are BST operations, not general binary tree operations.

    LeetCode often provides TreeNode already.
    In that case, do not define TreeNode again.
*/
