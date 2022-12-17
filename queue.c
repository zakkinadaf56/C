/*
Queue:
Queue is a linear data structure in which insertion is done from one end 
and deletion is done from another end.
The end from which insertion ia done is called the rear end.
The end from which the deletion is done is called the front end.
It is first in first out(FIFO) structure

Queue ADT:
Data: a finite sequence of elements of any particular type.
1.Initialization
2.Check whether it is empty
3.Check whether it is full.
4.Insert an elementfrom the rear of the queue if it is not full.
5.Delete the element from the front of the queue if it is notnempty.
6.Sometimes referred as enqueue(insertion).
7.Sometimes referred as dequeue(deletion).

Implementation of queue using array:                     Name-Nadaf Zakki Noor Mohammed
                                                         Roll No.-20CO40
                                                         Year-2020-2021

                                                       
 0  1  2  3  4                                           
[5  7  8  9  6]
front=0
rear=4           index value.


Theory of the programme:1. A queue can be defined as an ordered list which enables 
insert operations to be performed at one end called REAR and delete operations to be 
performed at another end called FRONT.
2. Queue is referred to be as First In First Out list.
3. For example, people waiting in line for a rail ticket form a queue.
Application :1.Due to the fact that queue performs actions on first in first out basis
 which is quite fair for the ordering of actions. There are various applications of queues
  discussed as below.
2.Queues are widely used as waiting lists for a single shared resource like printer, disk, CPU.
3.Queues are used in asynchronous transfer of data (where data is not being transferred at the same rate between two processes) for eg. pipes, file IO, sockets.
4.Queues are used as buffers in most of the applications like MP3 media player, CD player, etc.
5.Queue are used to maintain the play list in media players in order to add and remove the songs from the play-list.
6.Queues are used in operating systems for handling interrupts.
*/
#include<stdio.h>
#include<stdlib.h>
#define Max 5
struct queue
{
    int data[Max];
    int front,rear;
};
void initialize(struct queue*q)
{
    q->front=q->rear=-1;
}
int isEmpty(struct queue *q)
{
    if(q->rear==-1)
    return 1;
    else 
    return 0;
}
int isFull(struct queue *q)
{
    if(q->rear==Max-1)
    return 1;
    else
    return 0;
}
void insert(struct queue *q,int d)
{
    if(isFull(q))
    printf("\nQueue is full..");
    else
    {
     q->rear++;
     q->data[q->rear]=d;
     if(q->front==-1)
     q->front=0;
     printf("\n Successfully inserted..");   
    }
}
void delete(struct queue *q)
{
    if(isEmpty(q))
    printf("\n Queue is empty ");
    else{
        printf("deleted elememt is %d",q->data[q->front]);
        if(q->front==q->rear)
        q->front=q->rear=-1;
        else
        q->front++;
    }
}
void display(struct queue *q)
{
    if(isEmpty(q)==1)
    printf("\nQueue is empty");
    else{
        printf("\n Queue content:\nFront=%d\tRear=%d",q->front,q->rear);
        for(int i=q->front;i<=q->rear;i++)
        printf("\n %d",q->data[i]);
    }
}
int main()
{
    struct queue q;
    int i,ch,d;
    while(1)
    {
          printf("\n\n\t\tMenu.\n1. initialize.\n2.insert\n3.delete  ");
    printf("\n4Display \n5exit.\n\tEnter your choice::");
    scanf("%d",&ch);
    switch(ch)
  {
      case 1:
      initialize(&q);
      break;
      
      case 2:
      printf("\nEnter data");
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
      break;
      default:
      printf("invalid choice");
      break;
  }
    }
    return 0;
}





/*
Conclution:In this programme we have implemented queue using array in this we have 2 
ends front end ad rear end from which we are inserting and deleting the data we have use 
the funtions such as isfull is empty to check whether our queue is empty or full and other 
functions such as insert(to insert data),delete function,display function ands intialize function
provides its intial value at the time of construction 
Output:               Menu.
1. initialize.
2.insert
3.delete
4Display
5exit.
        Enter your choice::4

 Queue content:
Front=0 Rear=2
 3
 4
 5
*/

/*
TYpes of queue
1.Linear
2.Circular
3.Double ended queue      //Input restricted and output restricted
4.Priority queue          //Higest priority element will be deleted 1st and lowest priority element
                           will be deleted last i.e data will be deleted according to their priority

Queue
 0  1  2  3  4 
[6  7  8  9  5]
front=0
rear=4     //max-1

Circular Queue:
 0  1  2  3  4    0  1  2  3  4    0  1  2  3  4
[            5]  [6  7  8  9  5]  [
front=4              front=(front+1) % MAX
rear = 3               rear=(rear+1) % MAX           //front==(rear+1) % MAX


*/