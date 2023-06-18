#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 48

typedef struct Node
{
    int key;
    struct Node *next;
} node;

/*--scan and print linklist functions--*/

// Input n nodes of list and return head node
node *inputList(node *list)
{
    list = NULL;
    node *pre, *current;
    int listLen;
    scanf("%d", &listLen);

    for (int i = 0; i < listLen; i++)
    {
        current = (node *)malloc(sizeof(node));
        scanf("%d", &current->key);
        current->next = 0;
        if (list == NULL)
            list = current;
        else
            pre->next = current;
        pre = current;
    }
    return list;
}

// print n nodes of list from the head node
void printList(node *list)
{
    node *current = list;
    while (current)
    {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

/*--Operations with linked-list--*/

// Check if node with key = k contained inlist
int isContain(node *list, int k)
{
    node *current = list;
    while (current)
    {
        if (current->key == k)
            return 1;
        current = current->next;
    }
    return 0;
}

// Add a key to the first node of list and return list after add
node *addFisrt(node *list, int key)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = list;
    list = temp;
    return temp;
}

// Add a key to last node of list and return list after add
node *addBottom(node *list, int key)
{
    node *current = list;
    while (current->next)
        current = current->next;
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    current->next = temp;
    return list;
}

// Reverse the linked-list 's order
node *reverseList(node *list)
{
    node *current = list;
    node *reversed = (node *)malloc(sizeof(node));
    reversed = NULL;
    while (current)
    {
        reversed = addFisrt(reversed, current->key);
        current = current->next;
    }
    return reversed;
}

// Add after a node with key n a node with key m
node *addBefore(node *list, int n, int m)
{
    node *current = list;
    if (current->key == n)
    {
        list = addFisrt(current, m);
        current = list->next;
    }
    while (current->next)
    {
        if (current->next->key == n)
        {
            node *temp = addFisrt(current->next, m);
            current->next = temp;
            current = current->next;
        }
        current = current->next;
    }
    return list;
}

// Add a node with key m after a node with key n
node *addAfter(node *list, int n, int m)
{
    node *current = list;
    while (current)
    {
        if (current->key == n)
        {
            current->next = addFisrt(current->next, m);
            current = current->next;
        }
        current = current->next;
    }
    return list;
}

// Remove node with key = k
node *removeNode(node *list, int k)
{
    while (list->key == k)
    {
        list = list->next;
    }
    node *current = list;
    while (current)
    {
        node *temp = current->next;
        if (!temp)
            break;
        if (temp->key == k)
        {
            current->next = temp->next;
        }
        current = current->next;
    }
    return list;
}

int getCommand(char *s, int *arg)
{
    char *token = strtok(s, " ");
    if (*token == '#')
        return -1;
    int code;
    char runtask[6][10] = {"addfirst", "addlast", "addbefore", "addafter", "remove", "reverse"};
    for (int i = 0; i < 6; i++)
        if (strcmp(token, runtask[i]) == 0)
        {
            code = i;
            break;
        }
    // Lấy ra toàn bộ token
    int k = 0;
    while (token != NULL)
    {

        token = strtok(NULL, " ");
        if (token)
            *arg = atoi(token);
        else
            break;
        arg++;
    }
    return code;
}

int main()
{
    node *list;
    list = NULL;
    node *pre, *current;
    int listLen;
    scanf("%d", &listLen);

    for (int i = 0; i < listLen; i++)
    {
        current = (node *)malloc(sizeof(node));
        scanf("%d", &current->key);
        current->next = 0;
        if (list == NULL)
            list = current;
        else
            pre->next = current;
        pre = current;
    }
    char cmd[MAX_LEN];

    // Clean input cache
    char c;
    do
    {
        c = getchar();
    } while (c != '\n');

    // Input command and do operations
    int code;
    int *arg = (int *)malloc(sizeof(int) * 4);
    do
    {
        fgets(cmd, MAX_LEN, stdin);
        cmd[strlen(cmd) - 1] = 0;
        code = getCommand(cmd, arg);

        // runcode = {"addfirst", "addlast", "addbefore", "addafter", "remove", "reverse"};
        switch (code)
        {
        case 0:
            if (!isContain(list, *arg))
                list = addFisrt(list, *arg);
            break;
        case 1:
            if (!isContain(list, *arg))
                list = addBottom(list, *arg);
            break;
        case 2:
            if (!isContain(list, *arg) && isContain(list, *(arg + 1)))
                list = addBefore(list, *(arg + 1), *arg);
            break;
        case 3:
            if (!isContain(list, *arg) && isContain(list, *(arg + 1)))
                list = addAfter(list, *(arg + 1), *arg);
            break;
        case 4:
            if (isContain(list, *arg))
                list = removeNode(list, *arg);
            break;
        case 5:
            list = reverseList(list);
            break;
        default:
            break;
        }
        //printList(list);
    } while (cmd[0] != '#');

    printList(list);

    return 0;
}
