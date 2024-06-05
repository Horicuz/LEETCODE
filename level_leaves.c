// Se da un arbore binar oarecare, ın care frunzele se pot afla pe
// oricare nivel.
// Scrieti un algoritm care introduce noduri dummy ın arbore astfel
// ıncat frunzele sa ajunga toate pe acelasi nivel.
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

void print_level_for_everyleaf(TreeNode *root, int level, int *maxlevel)
{
    if (root->left == NULL)
    {
        if (root->right == NULL)
        {
            printf("Leaf %d is at level %d\n", root->val, level);
            if (level > *maxlevel)
            {
                *maxlevel = level;
            }
        }
        else
        {
            print_level_for_everyleaf(root->right, level + 1, maxlevel);
        }
    }
    else
    {
        if (root->right != NULL)
        {
            print_level_for_everyleaf(root->right, level + 1, maxlevel);
        }
        print_level_for_everyleaf(root->left, level + 1, maxlevel);
    }
}

void add_levels_to_leaves(TreeNode *root, int level, int maxlevel)
{
    if (root->left == NULL)
    {
        if (root->right == NULL)
        {
            while (level < maxlevel)
            {
                TreeNode *dummy = (TreeNode *)malloc(sizeof(TreeNode));
                dummy->val = -1;
                dummy->left = NULL;
                dummy->right = NULL;
                root->left = dummy;
                level++;
                root = root->left;
            }
        }
        else
        {
            add_levels_to_leaves(root->right, level + 1, maxlevel);
        }
    }
    else
    {
        if (root->right != NULL)
        {
            add_levels_to_leaves(root->right, level + 1, maxlevel);
        }
        add_levels_to_leaves(root->left, level + 1, maxlevel);
    }
}

void print_tree_on_levels(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    print_tree_on_levels(root->left);
    print_tree_on_levels(root->right);
}

void level_allleaves(TreeNode *root)
{
    int maxlevel = 0;
    print_level_for_everyleaf(root, 0, &maxlevel);
    printf("Max level is %d\n", maxlevel);
    add_levels_to_leaves(root, 0, maxlevel);
    print_tree_on_levels(root);
}

int main()
{
    int maxlevel = 0;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = 1;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->val = 3;
    root->right->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->left->val = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->val = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->right->val = 6;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;

    level_allleaves(root);
    return 0;
}