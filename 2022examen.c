#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{

    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    char culoare; // r sau a sau v;
};

typedef struct TreeNode TreeNode;

void color_tree(TreeNode *root, int parent_nr_of_kids)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        root->data++;
    }
    if (root->right != NULL)
    {
        root->data++;
    }

    if (root->data > parent_nr_of_kids)
    {
        root->culoare = 'v';
    }
    else if (root->data < parent_nr_of_kids)
    {
        root->culoare = 'r';
    }
    else
    {
        root->culoare = 'a';
    }
    color_tree(root->left, root->data);
    color_tree(root->right, root->data);
}

int isLeaf(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;
    return 0;
}

int e_plin(TreeNode *root)
{
    int ok = 1;
    if (isLeaf(root))
        return 1;
    TreeNode *current = root;
    if (current->left != NULL && current->right != NULL)
    {
        TreeNode *queue[100];
        int rear = 0, front = 0;
        queue[rear++] = current->left;
        queue[rear++] = current->right;
        while (front < rear)
        {
            current = queue[front++];
            if (isLeaf(current) == 0)
            {
                if (current->culoare != 'a')
                {
                    ok = 0;
                    break;
                }
                queue[rear++] = current->left;
                queue[rear++] = current->right;
            }
        }

        if (ok == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        return 0;
    }
}
// determinarea numarului de componente conexe

void populate(int mat[8][8], int viz[8], int nod)
{
    viz[nod] = 1;
    for (int i = 0; i < 8; i++)
    {
        if (mat[nod][i] == 1 && viz[i] == 0)
        {
            populate(mat, viz, i);
        }
    }
}

int nrconexe(int MatriceDeAdiacenta[8][8])
{
    int viz[8] = {0};
    int nr = 0;
    for (int i = 0; i < 8; i++)
    {
        if (viz[i] == 0)
        {
            nr++;
            populate(MatriceDeAdiacenta, viz, i);
        }
    }
    return nr;
}

void GetPathToTreeNode(TreeNode *root, int arr[], int searchedValue)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == searchedValue)
    {
        arr[0] = root->data;
        // arr[arr[0]] = root->data;
        return;
    }
    GetPathToTreeNode(root->left, arr, searchedValue);
    GetPathToTreeNode(root->right, arr, searchedValue);
    if (arr[0] != -1)
    {

        arr[++arr[0]] = root->data;
    }
}

// int Dijkstra(int mat[8][8])
// {
//     int frec[8] = {0};
//     int a = 0;
//     for (int i = 0; i < 8; i++)
//     {
//         if (frec[i] == 0)
//         {
//             a++;
//             frec[i] = 1;
//             for (int j = 0; j < 8; j++)
//             {
//                 if (frec[j] == 0 && mat[i][j] == 1)
//                 {
//                     frec[j] = 1;
//                 }
//             }
//         }
//     }

//     return a;
// }

int main()
{

    // 1 -> 2;
    // 2 -> 1, 4, 6;
    // 3 -> 4;
    // 4 -> 2, 3, 5;
    // 5 -> 4, 6;
    // 6 -> 2, 5, 7;
    // 7 -> 6, 8;
    // 8 -> 7;
    int MatriceDeAdiacenta[8][8] = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0}};

    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    //        1
    //    2       3
    //  8   5   _   7
    // _ _ 12 13 _ _ 20 21

    root->data = 1;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->right = (TreeNode *)malloc(sizeof(TreeNode));

    root->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->left->data = 8;
    root->left->right->data = 5;

    root->right->right->data = 7;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->right->left->data = 12;
    root->left->right->right->data = 13;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;

    root->right->right->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->left->data = 20;
    root->right->right->right->data = 21;
    root->right->right->left->left = NULL;
    root->right->right->left->right = NULL;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;

    root->culoare = 'v';
    color_tree(root, -1);
    e_plin(root) ? printf("Arborele este plin\n") : printf("Arborele nu este plin\n");

    int nr = nrconexe(MatriceDeAdiacenta);
    printf("Numarul de componente conexe este %d\n", nr);
    int punti = 0;
    for (int i = 1; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (MatriceDeAdiacenta[i][j] == 1)
            {
                MatriceDeAdiacenta[i][j] = 0;
                MatriceDeAdiacenta[j][i] = 0;
                printf("%d ", nrconexe(MatriceDeAdiacenta));
                if (nrconexe(MatriceDeAdiacenta) > nr)
                {
                    punti++;
                }
                MatriceDeAdiacenta[i][j] = 1;
                MatriceDeAdiacenta[j][i] = 1;
            }
        }
    }

    printf("Numarul de puncte de articulatie este %d\n", punti);

    int arr[100];
    arr[0] = -1;
    GetPathToTreeNode(root, arr, 12);
    for (int i = 1; i <= arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }

    // for (int i = arr[0]; i >= 12; i--)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    return 0;
}
