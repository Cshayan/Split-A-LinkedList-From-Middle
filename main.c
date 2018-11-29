//Programme to split the link list from the middle
#include <stdio.h>
#include <stdlib.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
// function to create list
void create(struct node **start,int num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {
        curr=(*start);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
//print the linked list
void display(struct node *start)
{

    struct node *curr=start;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n\n");
}
// function to split the linked list
void splitLL(struct node *prev,struct node *slow,struct node *start,int n)
{
    struct node *start2;
    printf("\nAfter splitting two lists are:- \n");
    if(n%2==1)   //odd list
    {
        start2=slow->next;
        slow->next=NULL;
        display(start);
        display(start2);
    }
   else   // even list
   {
       prev->next=NULL;
       start2=slow;
       display(start);
       display(start2);
   }
   printf("\n\n\n\n");
}
// finds the middle element of the list to split it
void findMiddle(struct node *start,int n)
{
    struct node *slow=start, *fast=start,*prev;
    while(fast!=NULL&&fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    splitLL(prev,slow,start,n);
}
int main()
{
    struct node *start=NULL;
    int n,num;
    printf("Enter the no of nodes to be created:- ");
    scanf("%d",&n);
    int i;
    printf("\nEnter the elements:- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        create(&start,num);
    }
    printf("The given list is:-\n");
    display(start);
    findMiddle(start,n);
    return 0;
}
