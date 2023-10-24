#include <stdio.h>
#include <stdlib.h>

// 定义 AVL 树节点结构体
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode* lchild;
    struct AVLNode* rchild;
} AVLNode, *AVLTree;

// 计算节点的高度
int nodeHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// 计算节点的平衡因子
int nodeBalanceFactor(AVLNode* node) {
    if (node == NULL)
        return 0;
    return nodeHeight(node->lchild) - nodeHeight(node->rchild);
}

// 更新节点的高度
void updateNodeHeight(AVLNode* node) {
    if (node == NULL)
        return;
    int lheight = nodeHeight(node->lchild);
    int rheight = nodeHeight(node->rchild);
    node->height = (lheight > rheight ? lheight : rheight) + 1;
}

// 创建新的 AVL 树节点
AVLNode* createNode(int key) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->height = 1;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
    }
    return newNode;
}

// 左旋操作
AVLNode* leftRotation(AVLNode* root) {
    // 变量定义
    AVLNode* newRoot = root->lchild;
    root->lchild = newRoot->rchild;
    newRoot->rchild = root;

    // 更新高度
    updateNodeHeight(root);
    updateNodeHeight(newRoot);

    return newRoot;
}

// 右旋操作
AVLNode* rightRotation(AVLNode* root) {
    AVLNode* newRoot = root->rchild;
    root->rchild = newRoot->lchild;
    newRoot->lchild = root;

    updateNodeHeight(root);
    updateNodeHeight(newRoot);

    return newRoot;
}

// LR 型平衡操作
AVLNode* lrRotation(AVLNode* root) {
    root->lchild = rightRotation(root->lchild);
    return leftRotation(root);
}

// RL 型平衡操作
AVLNode* rlRotation(AVLNode* root) {
    root->rchild = leftRotation(root->rchild);
    return rightRotation(root);
}

// 向 AVL 树中插入节点
AVLNode* insertNode(AVLNode* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->lchild = insertNode(root->lchild, key);
        int bf = nodeBalanceFactor(root);
        if (bf == 2 && nodeBalanceFactor(root->lchild) == 1) { // LL 型不平衡
            root = leftRotation(root);
        } else if (bf == 2 && nodeBalanceFactor(root->lchild) == -1) { // LR 型不平衡
            root = lrRotation(root);
        }
    } else if (key > root->key) {
        root->rchild = insertNode(root->rchild, key);
        int bf = nodeBalanceFactor(root);
        if (bf == -2 && nodeBalanceFactor(root->rchild) == -1) { // RR 型不平衡
            root = rightRotation(root);
        } else if (bf == -2 && nodeBalanceFactor(root->rchild) == 1) { // RL 型不平衡
            root = rlRotation(root);
        }
    }
    updateNodeHeight(root);
    return root;
}
// 中序遍历 AVL 树
void inorderTraversal(AVLNode* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->lchild);
    printf("%d ", root->key);
    inorderTraversal(root->rchild);
}

// 查找某个节点的后继节点
AVLNode* findSuccessor(AVLNode* node) {
    AVLNode* current = node->rchild;
    while (current != NULL && current->lchild != NULL) {
        current = current->lchild;
    }
    return current;
}

// 删除 AVL 树中的节点
AVLNode* deleteNode(AVLNode* root, int key) {
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->lchild = deleteNode(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = deleteNode(root->rchild, key);
    } else {
        if (root->lchild == NULL || root->rchild == NULL) {
            AVLNode* temp = root->lchild ? root->lchild : root->rchild;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* successor = findSuccessor(root);
            root->key = successor->key;
            root->rchild = deleteNode(root->rchild, successor->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    updateNodeHeight(root); 
    // 计算平衡因子，找到最小不平衡二叉树
    int bf = nodeBalanceFactor(root);
    if (bf == 2 && nodeBalanceFactor(root->lchild) >= 0) { // LL 型不平衡
        root = leftRotation(root);
    } else if (bf == 2 && nodeBalanceFactor(root->lchild) == -1) { // LR 型不平衡
        root = lrRotation(root);
    } else if (bf == -2 && nodeBalanceFactor(root->rchild) <= 0) { // RR 型不平衡
        root = rightRotation(root);
    } else if (bf == -2 && nodeBalanceFactor(root->rchild) == 1) { // RL 型不平衡
        root = rlRotation(root);
    }
    return root;
}

int main() {
    AVLNode* root = NULL;

    // 向 AVL 树中插入节点
    root = insertNode(root, 90);
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);
    root = deleteNode(root,3);

    printf("AVL Tree after insertion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
