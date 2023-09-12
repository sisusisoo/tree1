#include <stdio.h> 
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    return node;
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}


void inorder(Node* root) {
    if (root) {
        inorder(root->leftChild);
        printf("%d ", root->data);
        inorder(root->rightChild);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

int main(void) {
    Node* n15 = initNode(11, NULL, NULL);
    Node* n14 = initNode(10, NULL, NULL);
    Node* n9 = initNode(5, NULL, NULL);
    Node* n8 = initNode(4, NULL, NULL);
    Node* n7 = initNode(9, n14,n15);
    Node* n6 = initNode(8, NULL, NULL);
    Node* n5 = initNode(6, NULL, NULL);
    Node* n4 = initNode(3, n8, n9);
    Node* n3 = initNode(7, n6, n7);
    Node* n2 = initNode(2, n4, n5);
    Node* n1 = initNode(1, n2, n3);

    printf("<Linked Tree>\n");
    printf("전위\n");
    preorder(n1);
    printf("\n");
    printf("중위\n");
    inorder(n1);
    printf("\n");
    printf("후위\n");
    postorder(n1);
    printf("\n");
}