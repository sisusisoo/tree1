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

int arrayIndex=1;

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

void preorderArray(int tree[],int nowIndex) {
    //treeA=tree[1]; �Ƚ�
    int z = tree[nowIndex];
 
    if (z != -1 && nowIndex<16 && nowIndex >0) {
       
        printf("%d  ", tree[nowIndex]);
        printf("nowIndex: %d\n  ", nowIndex);
        nowIndex = nowIndex * 2;
        preorderArray(tree,nowIndex);
        nowIndex++;
        preorderArray(tree,nowIndex);
       }
    

    
}

void inorderArray(int tree[], int nowIndex) {
    //treeA=tree[1]; �Ƚ�
    int z = tree[nowIndex];
    int index = nowIndex;// 2*i ������ ����Ǳ����� �� 

    if (z != -1 && nowIndex < 16 && nowIndex >0) {

       
     
        nowIndex = nowIndex * 2;
        inorderArray(tree, nowIndex);
        printf("%d  ", tree[index]);
        printf("Index: %d\n  ", index);
        nowIndex++;
        inorderArray(tree, nowIndex);

    }



}

void postorderArray(int tree[], int nowIndex) {
    //treeA=tree[1]; �Ƚ�
    int z = tree[nowIndex];
    int index = nowIndex;// 2*i���̳� (2*n)+1 ������ ����Ǿ� �Ѿ������ �� 

    if (z != -1 && nowIndex < 16 && nowIndex >0) {



        nowIndex = nowIndex * 2;
        postorderArray(tree, nowIndex);
     
        nowIndex++;
        postorderArray(tree, nowIndex);
        printf("%d  ", tree[index]);
        printf("Index: %d\n  ", index);

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

  

    int tree[16] = {-1,1,2,7,3,6,8,9,4,5,-1,-1,-1,-1,10,11};
  

    printf("<Linked Tree>\n");
    printf("����\n");
    preorder(n1);
    printf("\n");
    printf("����\n");
    inorder(n1);
    printf("\n");
    printf("����\n");
    postorder(n1);
    printf("\n");



    printf("<Array Tree>\n");
    printf("����\n");
    preorderArray(tree,1);

    printf("����\n");
    inorderArray(tree, 1);


    printf("����\n");
    postorderArray(tree, 1);






}