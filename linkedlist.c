/*
Linked List:
1. Singly Linked List (SLL)
2. Circular Linked List (CLL)
3. Doubly Linked List (DLL)

OPERATIONS ON LINKED LIST:
1. Insert
2. Delete
3. Display
Implementation of Singly Linked list               Name-Nadaf Zakki Noor Mohammed
                                                   Roll No.-20CO40
                                                   Academic Year-2021-2022

Theory about the programme-A linked list is a dynamic data structure where each element 
(called a node) is made up of two items: the data and a reference (or pointer), which points
 to the next node. A linked list is a collection of nodes where each node is connected to the 
 next node through a pointer.

*/
#include<stdio.h>
#include<stdlib.h>
/*struct student{
    int rollno;
    char name[20];
    float ptr;
    char addr[50];
}*/
struct node             // self referential structure
{
    int data;       // struct student data;
    struct node *next;      
};

struct node *insertAtEnd(struct node *h, int d)
{
    struct node *p,*tmp;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nNot Enough Memory...");
    }
    else
    {
        p->data=d;
        p->next=NULL;
        if(h==NULL)     
            h=p;        // list is empty so new node becomes first node
        else
        {               // list is not empty
            tmp=h;                                          //  i=0;
            while(tmp->next!=NULL)      // traversing a list    while(i+1!=5)
                tmp=tmp->next;                              //      i=i+1;
            tmp->next=p;
        }
    }
    return h;
}

struct node *insertAtBeg(struct node *h, int d)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nNot Enough Memory...");
    }
    else
    {
        p->data=d;
        p->next=h;
        h=p;
    }
    return h;
}

struct node *insertAfter(struct node *h, int key, int d)
{
    struct node *p,*tmp;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nNot Enough Memory...");
    }
    else
    {
        p->data=d;
        p->next=NULL;
        tmp=h;
        while(tmp!=NULL && tmp->data!=key)      // searching a given key
            tmp=tmp->next;
        if(tmp!=NULL)
        {                           // tmp is pointing to given node.
            p->next=tmp->next;      // next node of tmp becomes next node of p
            tmp->next=p;            // p becomes next node of tmp
            printf("\nNew Node inserted after a given Node.");
        }
        else
        {
            printf("\nGiven Node does not exist...");
            free(p);
        }
    }
    return h;
}

struct node *removeFirst(struct node *h)
{
    struct node *tmp;
    if(h==NULL)
        printf("\nLinked List is Empty.");
    else
    {
        tmp=h;
        h=h->next;
        free(tmp);
        printf("\nFirst Node Removed.");
    }
    return h;
}

struct node *removeLast(struct node *h)
{
    struct node *tmp,*prev;
    if(h==NULL)
        printf("\nLinked List is Empty.");
    else
    {
        tmp=h;
        if(h->next==NULL)       // only one node in linked list
            h=NULL;
        else
        {                       // multiple nodes in linked list
        while(tmp->next!=NULL)
        {
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=NULL;
        }
        free(tmp);
        printf("\nLast Node Deleted.");
    }
    return h;
}



void display(struct node *h)
{
    struct node *tmp;
    if(h==NULL)
        printf("\nLinked List is empty.");
    else{
        tmp=h;
        printf("\nLinked List :");
        while(tmp!=NULL)
        {
            printf("\t%d",tmp->data);
            tmp=tmp->next;
        }
    }
}

int main()
{
    struct node *head,*head1,*head2;
    int ch,el,k;
    head=NULL;          //initialization of list
    while(1)
    {
        printf("\n\n\t\t\tMENU\n1. Insert At End.\n2. Insert At Beginning.\n3. Insert After.\n4. Remove Last.\n5. Remove First.\n6. Display.\n7. Exit.");
        printf("\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&el);
            head=insertAtEnd(head,el);
            break;
            case 2:
            printf("\nEnter the data : ");
            scanf("%d",&el);
            head=insertAtBeg(head,el);
            break;
            case 3:
            printf("\nEnter the Key data : ");
            scanf("%d",&k);
            printf("\nEnter the data : ");
            scanf("%d",&el);
            head=insertAfter(head,k,el);
            break;
            case 4:
            head=removeLast(head);
            break;
            case 5:
            head=removeFirst(head);
            break;
            case 6:
            display(head);
            break;
            case 7:
            exit(0);
            break;
            default:
            printf("\nPlease enter correct choice...");
        }
    }
    return 0;
}

/*
Conclution:I understood that how to implement the concept of linked list and put
various functions into it like removelast ,removefirst etc  


Output:            MENU
1. Insert At End.
2. Insert At Beginning.
3. Insert After.
4. Remove Last.
5. Remove First.
6. Display.
7. Exit.
        Enter your choice :
*/