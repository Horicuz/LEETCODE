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

void dfs(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    dfs(root->left);
    dfs(root->right);
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void createDummies(Node *root, int height)
{
    if (root == NULL)
    {
        return;
    }

    if (height > 1)
    {
        if (root->left == NULL)
        {
            root->left = createNode(-1);
        }
        if (root->right == NULL)
        {
            root->right = createNode(-1);
        }
    }

    createDummies(root->left, height - 1);
    createDummies(root->right, height - 1);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    // root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8);

    //        1
    //    2       3
    //  _   5   6   7
    // _ _ 8 _ _ _ _ _

    dfs(root);
    printf("\n");
    createDummies(root, getHeight(root));
    dfs(root);

    return 0;
}