#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} node;

node *inputNode(node *list)
{
    node *cur, *pre;
    list = NULL;
    int n;
    printf("Number of node: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cur = (node *)malloc(sizeof(node));
        scanf("%d", &cur->val);
        cur->next = NULL;
        if (list == NULL)
            list = cur;
        else
            pre->next = cur;
        pre = cur;
    }
    return list;
}

void printNode(node *list)
{
    node *cur = list;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}
node *addTwoNumbers(node *l1, node *l2)
{
    node *add = NULL, *pre;
    node *current;
    int miss = 0, unitSum;
    while (l1 || l2 || miss)
    {
        current = (node *)malloc(sizeof(node));
        int a = l1 == NULL ? 0 : l1->val;
        int b = l2 == NULL ? 0 : l2->val;
        unitSum = a + b + miss;
        current->val = unitSum % 10;
        current->next = NULL;
        miss = unitSum / 10;
        if (add == NULL)
            add = current;
        else
            pre->next = current;
        pre = current;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return add;
}

int main()
{
    node *list, *l1, *l2;
    l1 = inputNode(l2);
    l2 = inputNode(l2);
    list = addTwoNumbers(l1, l2);
    printNode(list);
}