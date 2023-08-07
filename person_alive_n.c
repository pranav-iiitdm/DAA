#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head=NULL;

void insert(int x);
void display();
void person_alive();

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        insert(i+1);
    }
    
    //display();
    person_alive();
    return 0;
}

void insert(int x)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->data=x;
        head->next=head;
    }
    
    else
    {
        temp=head;
        
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        
        struct node * ptr=(struct node *)malloc(sizeof(struct node));
        
        ptr->data=x;
        ptr->prev=temp;
        ptr->next=head;
        temp->next=ptr;
    }
}

void display()
{
    struct node * temp=head;
    
    while(temp->next!=head)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf(" %d ",temp->data);
}

void person_alive()
{
    
    struct node * ptr=head;
    
    while(ptr->next!=ptr->prev)
    {
        struct node *temp=ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
        ptr=temp->next;
        temp=NULL;
        free(temp);
    }
    
    printf("%d\n",ptr->data);
}
