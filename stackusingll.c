/*
Stack using linked list.                          Name-Nadaf Zakki Noor Mohammed
                                                  Roll No.-20CO40
                                                  Academic Year-2021-2022

Theory about the programme-In linked list implementation of stack,
the nodes are maintained non-contiguously in the memory. Each node contains a pointer
to its immediate successor node in the stack. Stack is said to be overflown if 
the space left in the memory heap is not enough to create a node.Linked list allocates
the memory dynamically. However, time complexity in both the scenario is same for all the 
operations i.e. push, pop and peek.
*/

#include<stdio.h>
#include<stdlib.h>

struct node             // self referential structure
{
    int data;       // struct student data;
    struct node *next;      
};

struct node *push(struct node *top, int d)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nStack Overflow...");
    }
    else
    {
        p->data=d;
        p->next=top;
        top=p;
    }
    return top;
}

struct node *pop(struct node *top)
{
    struct node *tmp;
    if(top==NULL)
        printf("\nStack is Empty.");
    else
    {
        tmp=top;
        top=top->next;
        printf("\n%d is popped.",tmp->data);
        free(tmp);
    }
    return top;
}

void peek(struct node *top)
{
    if(top==NULL)
        printf("\nStack is Empty.");
    else
        printf("\n%d is on peak.",top->data);
}

void display(struct node *top)
{
    struct node *tmp;
    if(top==NULL)
        printf("\nStack is empty.");
    else{
        tmp=top;
        printf("\nStack Content :");
        while(tmp!=NULL)
        {
            printf("\t%d",tmp->data);
            tmp=tmp->next;
        }
    }
}


int main()
{
    struct node *top,*top1,*top2;
    int ch,el,k;
    top=NULL;          //initialization of stack
    while(1)
    {
        printf("\n\n\t\t\tMENU\n1. Push.\n2. Pop.\n3. Peek.\n4. Display.\n5. Exit.");
        printf("\n\tEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&el);
            top=push(top,el);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            peek(top);
            break;
            case 4:
            display(top);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\nPlease enter correct choice...");
        }
    }
    return 0;
}


/*
Conclution:In this i experiment I understood how to implement stack using ll and we have also implemented
functions such as push,pop,peek and display.I also learned that IN LINKED LIST IMPLEMENTATION OF STACK,
THE NODES ARE MAINTAINED NON-CONTIGUOUSLY IN THE MEMORY.
EACH NODE CONTAINS A POINTER TO ITS IMMEDIATE SUCCESSOR NODE IN THE STACK 

OUTPUT:                  MENU
1. Push.
2. Pop.
3. Peek.
4. Display.
5. Exit.
        Enter your choice :

*/