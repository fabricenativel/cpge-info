#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node_s
{
    int value;
    struct node_s *leftchild;
    struct node_s *rightsibling;
};
typedef struct node_s node;
typedef node *tree;

tree create_tree(int value)
{
    tree new_tree = malloc(sizeof(node));
    new_tree->value = value;
    new_tree->leftchild = NULL;
    new_tree->rightsibling = NULL;
    return new_tree;
}

void add_leftchild(tree parent, tree child)
{
    assert(child->rightsibling == NULL);
    child->rightsibling = parent->leftchild;
    parent->leftchild = child;
}

int size(tree t)
{
    if (t == NULL)
        return 0;
    int cpt = 1;
    while (t->leftchild != NULL)
    {
        cpt += size(t->leftchild);
        t->leftchild = t->leftchild->rightsibling;
    }
    return cpt;
}

int main()
{
    tree t = create_tree(5);
    add_leftchild(t, create_tree(3));
    add_leftchild(t, create_tree(7));
    add_leftchild(t->leftchild, create_tree(2));
    add_leftchild(t->leftchild, create_tree(4));
    printf("Taille = %d\n", size(t));
    return 0;
}