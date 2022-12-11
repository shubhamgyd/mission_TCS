#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int data;
    struct Array *next;
};

struct Array *pushBack(int val)
{
    struct Array *newNode = (struct Array *)malloc(sizeof(struct Array));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    struct Array *head = pushBack(-1);
    struct Array *dummy = head;
    while (1)
    {

        char ch[1000];
        fflush(NULL);
        if (NULL == fgets(ch, 1000, stdin))
        {
            break;
        }
        printf("%s ", ch);
        int num = 0;
        dummy->next = pushBack(num);
        dummy = dummy->next;
    }
    printf("Num");
}