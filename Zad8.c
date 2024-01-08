#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Structure for binary search tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure for binary search tree
struct BinarySearchTree {
    struct TreeNode* root;
};

typedef struct BinarySearchTree BST;
typedef struct TreeNode TreeNode;

// Function declarations
BST createBST();
TreeNode* createNode(int value);
TreeNode* insert(TreeNode* root, int value);
void inorder(TreeNode* root);
void preorder(TreeNode* root);
void postorder(TreeNode* root);
void levelOrder(TreeNode* root);
TreeNode* search(TreeNode* root, int value);
TreeNode* deleteNode(TreeNode* root, int value);
int replace(TreeNode* root);
int randomValue();

int main() {
    BST bst = createBST();
    BST bstRandom = createBST();

    // Insert elements into the binary search tree
    bst.root = insert(bst.root, 2);
    insert(bst.root, 5);
    insert(bst.root, 7);
    insert(bst.root, 8);
    insert(bst.root, 11);
    insert(bst.root, 1);
    insert(bst.root, 4);
    insert(bst.root, 2);
    insert(bst.root, 3);
    insert(bst.root, 7);

    // Display level order traversal
    printf("Level Order Traversal: ");
    levelOrder(bst.root);

    // Replace node values with the sum of their children
    replace(bst.root);

    printf("\nModified Level Order Traversal: ");
    levelOrder(bst.root);

    // Insert random elements into another binary search tree
    bstRandom.root = insert(bstRandom.root, randomValue());
    for (int i = 0; i < 10; i++) {
        insert(bstRandom.root, randomValue());
    }

    printf("\nRandom BST Level Order Traversal: ");
    levelOrder(bstRandom.root);

    // Additional menu-based operations can be added here

    return EXIT_SUCCESS;
}

// Function to create an empty binary search tree
BST createBST() {
    BST newBST;
    newBST.root = NULL;
    return newBST;
}

// Function to create a new tree node with the given value
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Can't allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value >= root->value)
        root->right = insert(root->right, value);

    return root;
}

// Function to perform inorder traversal of the binary search tree
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Function to perform preorder traversal of the binary search tree
void preorder(TreeNode* root) {
    if (root) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal of the binary search tree
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

// Function to perform level order traversal of the binary search tree
void levelOrder(TreeNode* root) {
    if (root == NULL)
        return;

    TreeNode* queue[100] = { 0 };
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        printf("%
