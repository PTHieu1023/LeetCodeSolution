#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *inputNode(struct ListNode *list)
{
    struct ListNode *cur, *pre;
    list = NULL;
    int n;
    printf("Number of node: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cur = (struct ListNode *)malloc(sizeof(struct ListNode));
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

void printNode(struct ListNode *list)
{
    struct ListNode *cur = list;
    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *current[4];
    int k =0;
    current[k] = head;
    while (current[k])
    {
        k++;
        current[k] = current[k-1]->next;
    }
    current[k-n-1]->next = current[k-n+1];
    return head;
}

int main()
{
    struct ListNode *list;
    list = inputNode(list);
    printNode(list);
    removeNthFromEnd(list, 1);
    printNode(list);
}