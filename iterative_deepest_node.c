#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void iterativeBFS(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }

    printf("DEEPEST = %d\n", queue[--front]->data);
}
int main()
{

    //          1
    //      2       3
    //    _   5   6   7
    //   _ _ 8 _ _ 10 _ 9
    // _ _ _ _ 11 _ _ _ _ _ _ _ _ _

    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->right->left = createNode(8);
    root->right->right->left = createNode(10);
    root->right->right->right = createNode(9);
    root->left->right->left->left = createNode(11);

    iterativeBFS(root);

    return 0;
}