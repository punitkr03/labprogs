#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}node;

node* root;
void inorder(node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(node *root) {
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n\n\n");
}


node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insertNode(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

node* createTree() {
    int i;
    int data[] = {8,3,10};
    for(i=0; i<3; i++) {
        root = insertNode(root, data[i]);
    }
    display(root);
    return root;
}

// Function to find the minimum value in a BST
node* minValueNode(node* root) {
    node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

//Delete a node from the tree
node* deleteNode(node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    createTree();
    insertNode(root, 1);
    display(root);
    insertNode(root, 6);
    display(root);
    insertNode(root, 14);
    display(root);
    insertNode(root, 4);
    display(root);
    insertNode(root, 7);
    display(root);
    deleteNode(root, 3);
    display(root);

    return 0;
}