#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * head=NULL;

void insert(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    if (head == NULL)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void person_alive()
{
    struct node *ptr = head;
    while (ptr->next != ptr->prev)
    {
        struct node *temp = ptr->next;

        if (temp->data != 0)
        {
            ptr->next = temp->next;
            temp->next->prev = ptr;
            ptr = temp->next;
            temp->data = 0;
        }

        else
        {
            temp = temp->next;
            ptr->next = temp->next;
            temp->next->prev = ptr;
            ptr = temp->next;
            temp->data = 0;
        }
    }

    printf("%d", ptr->data);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        insert(i+1);
    }

    person_alive();

    return 0;
}