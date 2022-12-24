/*
Implementation of Queue using linked list.        Name-Nadaf Zakki Noor Mohammed
                                                  Roll No.-20CO40
                                                  Academic Year-2021-2022

Theory about the programme:-



*/

#include<stdio.h>
#include<stdlib.h>

struct node             // self referential structure
{
    int data;       // struct student data;
    struct node *next;      
};

struct queue
{
struct node *front;
struct node *rear;
};

struct queue *insert(struct queue *q, int d)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nQueue is full...");
    }
    else
    {
        p->data=d;
        p->next=NULL;
        if(q->front==NULL)     
            q->front=p;        // queue is empty so new node becomes first node
        else
            q->rear->next=p;    // queue is not empty so new node becomes next node of last node.
        q->rear=p;              // new node becomes last node.
    }
    return q;
}

struct queue *delete(struct queue *q)
{
    struct node *tmp;
    if(q->front==NULL || q->rear==NULL)
        printf("\nQueue is Empty.");
    else
    {
        tmp=q->front;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
        printf("\nNode with data %d Removed.",tmp->data);
        free(tmp);
        
    }
    return q;
}

void display(struct queue *q)
{
    struct node *tmp;
    if(q->front==NULL)
        printf("\nQueue is empty.");
    else{
        tmp=q->front;
        printf("\nQueue Content :");
        while(tmp!=NULL)
        {
            printf("\t%d",tmp->data);
            tmp=tmp->next;
        }
    }
}

int main()
{
    struct queue *q;
    int ch,el,k;
           
    q=(struct queue *)malloc(sizeof(struct queue));
    q->front=q->rear=NULL;          //initialization of queue
    while(1)
    {
        printf("\n\n\t\t\tMENU\n1. Insert.\n2. Delete.\n3. Display.\n4. Exit.");
        printf("\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&el);
            q=insert(q,el);
            break;
            case 2:
            q=delete(q);
            break;
            case 3:
            display(q);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nPlease enter correct choice...");
        }
    }
    return 0;
}


/*
Conclution:I understood that how we can implement queue using linked list
           and how it is different from queue using array.

Output:              MENU
1. Insert.
2. Delete.
3. Display.
4. Exit.
        Enter your choice :


*/