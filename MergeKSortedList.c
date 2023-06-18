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

node *mergeKLists(node **lists, int listsSize)
{
    node *list, *pre, *cur;
    list = pre = 0;
    int l = 0;
    for (int i = 0; i < listsSize; i++)
        l += (lists[i]!= NULL);
    
    int minKey;
    while (l)
    {
        cur = 0;
        for (int i = 0; i < listsSize; i++)
        {
            if (lists[i])
            {
                if (!cur)
                {
                    cur = (node *)malloc(sizeof(node));
                    cur->val = lists[i]->val;
                    minKey = i;
                }
                else if (cur->val > lists[i]->val)
                {
                    cur->val = lists[i]->val;
                    minKey = i;
                }
            }
        }
        // cur->next = NULL;
        if (lists[minKey])
            lists[minKey] = lists[minKey]->next;
        if (!lists[minKey])
            l--;
        if (list == NULL)
            list = cur;
        else
            pre->next = cur;
        pre = cur;
    }
    return list;
}

int main()
{
    node **lists;
    int n;
    scanf("%d", &n);
    lists = (node **)malloc(sizeof(node *) * n);
    for (int i = 0; i < n; i++)
        lists[i] = inputNode(lists[i]);
    node *list = mergeKLists(lists, n);
    printNode(list);
}