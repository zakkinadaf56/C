/*
Circular Queue using Array.                       Name-Nadaf Zakki Noor Mohammed
                                                  Roll No.-20CO40
                                                  Academic Year-2021-2022

Theory about the programme-There was one limitation in the array implementation of Queue.
If the rear reaches to the end position of the Queue then there might be possibility that
some vacant spaces are left in the beginning which cannot be utilized. So, to overcome 
such limitations, the concept of the circular queue was introduced
                                                     
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct cqueue
{
    int data[MAX];
    int front,rear;
};

void initialize(struct cqueue *q)
{
    q->front=q->rear=-1;
}

int isempty(struct cqueue *q)
{
    return q->front==-1?1:0;
}

int isfull(struct cqueue *q)
{
    return q->front==(q->rear+1) % MAX ? 1:0;
}

void insert(struct cqueue *q, int d)
{
    if(isfull(q))
        printf("\nCircular Queue is full.");
    else{
        q->rear=(q->rear+1) % MAX;
        q->data[q->rear]=d;
        if(q->front==-1)
            q->front=0;
        printf("\nData Inserted.");
    }
}

void delete(struct cqueue *q)
{
    if(isempty(q))
        printf("\nCircular Queue is empty.");
    else{
        printf("\n%d is Deleted.",q->data[q->front]);
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
            q->front=(q->front+1) % MAX;
    }
}

void display(struct cqueue *q)
{
    int i;
    if(isempty(q))
        printf("\nCircular Queue is empty.");
    else{
        printf("\nCircular Queue:\nFront = %d\tRear = %d\nContent:",q->front,q->rear);
        for(i=q->front;i!=q->rear;i=(i+1) % MAX)
            printf("\t%d",q->data[i]);
        printf("\t%d",q->data[i]);      // to display last element

    }
}

int main()
{
    struct cqueue q;
    int i,ch,d;
    while(1)
    {
        printf("\n\n\t\t\tMENU.\n1. Initialize.\n2. Insert.\n3. Delete.");
        printf("\n4. Display.\n5. Exit.\n\tEnter your Choice:: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            initialize(&q);
            break;
            case 2:
            printf("\nEnter the Data: ");
            scanf("%d",&d);
            insert(&q,d);
            break;
            case 3:
            delete(&q);
            break;
            case 4:
            display(&q);
            break;
            case 5:
            exit(0);
            default:
            printf("\nPlease enter the correct choice....");
        }
    }
    return 0;
}
/*
Conclution:   I understood that how circular queue is implemented by just doing some minor changes in 
linear queue functions and how it is  more usefull than linear queue 


Output:        MENU.
1. Initialize.
2. Insert.
3. Delete.
4. Display.
5. Exit.
        Enter your Choice::
*/