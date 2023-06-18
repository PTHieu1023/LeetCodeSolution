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

node* mergeTwoLists(node* list1, node* list2)
{
    node *list = NULL, *current, *pre;
    pre = list;
    while(list1 && list2)
    {
        if(list1->val > list2->val)
        {
            current = list2;
            list2 = list2->next;
        }else
        {
            current = list1;
            list1 = list1->next;
        }
        if (list == NULL)
            list = current;
        else
            pre->next = current;
        pre = current;
    }
    if(list1)
        if(pre)
            pre->next = list1;
        else
            list = list1;
    if(list2)
        if(pre)
            pre->next = list2;
        else
            list = list2;
    
    return list;
}

int main()
{
    node* l1,*l2;
    l1 = inputNode(l1);
    l2 = inputNode(l2);
    node* l = mergeTwoLists(l1, l2);
    printNode(l);
}