/*
Application of SLL:
1. Representation of Polynomial Equation
2. Addition of Polynomial Equation.
2x2 + 5x + 10           => one polynomial equation will become one linked list
15x3 - 10x2 + 50
-----------------
15x3 - 8x2 + 5x + 60



*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int power;
    struct node *next;
};

//creating polynomial equation by inserting the term at the beginning of list
struct node *create(struct node *poly,int c, int pow)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("\nNot enough memory..");
        return poly;
    }
    p->coeff=c;
    p->power=pow;
    p->next=poly;
    poly=p;
    return poly;
}

struct node *add(struct node *pe1, struct node *pe2)
{
    struct node *p,*tmp1,*tmp2,*res,*tmpr;
    res=NULL;
    tmp1=pe1;
    tmp2=pe2;
    while(tmp1!=NULL && tmp2!=NULL)
    {
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
        printf("\nNot enough memory..");
    else{
        p->next=NULL;
              
        if(tmp1->power > tmp2->power)
        {
            p->coeff=tmp1->coeff;
            p->power=tmp1->power;
            tmp1=tmp1->next;
        }
        else
        if(tmp2->power > tmp1->power)
        {
            p->coeff=tmp2->coeff;
            p->power=tmp2->power;
            tmp2=tmp2->next;
        }
        else
        {
            p->coeff=tmp1->coeff + tmp2->coeff;
            p->power=tmp1->power;
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        if(res==NULL)
            res=p;
        else
        {
            tmpr=res;
            while(tmpr->next!=NULL)
                tmpr=tmpr->next;
            tmpr->next=p;
        }
        }


    }
    while(tmp1!=NULL)        //copying the remaining terms of pe1 if any
    {
        p->next=tmp1;
        p=tmp1;
        tmp1=tmp1->next;
    }
    while(tmp2!=NULL)         //copying the remaining terms of pe2 if any
    {
        p->next=tmp2;
        p=tmp2;
        tmp2=tmp2->next;
    }
    return res;
}

void display(struct node *poly)
{
    struct node *tmp;
    if(poly==NULL)
        printf("\nNo Equation.");
    else{
        tmp=poly;
        printf("\nPolynomial Equation : ");
        while(tmp!=NULL)
        {
            if(tmp!=poly && tmp->coeff>0 && tmp->power!=0)
                printf(" + %dx%d",tmp->coeff,tmp->power);
            else
                if(tmp->power!=0)
                    printf(" %dx%d",tmp->coeff,tmp->power);
                else
                    if(tmp->coeff>0)
                    printf(" + %d",tmp->coeff);
                    else
                    printf(" %d",tmp->coeff);
            tmp=tmp->next;
        }
    }
}

int main()
{
    struct node *pe1,*pe2,*res;
    pe1=pe2=NULL;
    // 2x2 + 5x + 10 
    pe1=create(pe1,10,0);
    pe1=create(pe1,5,1);
    pe1=create(pe1,2,2);
    display(pe1);
    // 15x3 - 10x2 + 50
    pe2=create(pe2,50,0);
    pe2=create(pe2,-10,2);
    pe2=create(pe2,15,3);
    display(pe2);
    res=add(pe1,pe2);
    display(res);
    return 0;
}