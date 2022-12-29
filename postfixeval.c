/*
Evaluation of postfix expression.                       Name-Nadaf Zakki Noor Mohammed
                                                        Roll No.-20CO40
                                                        Academic Year-2020-2021

Theory of the programme:As Postfix expression is without parenthesis and can be evaluated
as two operands and an operator at a time, this becomes easier for the compiler and the 
computer to handle.

Evaluation rule of a Postfix Expression states:

1)While reading the expression from left to right, push the element in the stack if it is an operand.
2)Pop the two operands from the stack, if the element is an operator and then evaluate it.
3)Push back the result of the evaluation. Repeat it till the end of the expression.
Algorithm
1) Add ) to postfix expression.
2) Read postfix expression Left to Right until ) encountered
3) If operand is encountered, push it onto Stack
[End If]
4) If operator is encountered, Pop two elements
i) A -> Top element
ii) B-> Next to Top element
iii) Evaluate B operator A
push B operator A onto Stack
5) Set result = pop
6) END
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20

struct stack
{
    int data[MAX];
    int top;
};

void push(struct stack *st, int d)
{
    if(st->top==MAX-1)
        printf("\nStack Overflows..");
    else
    {
        st->top++;
        st->data[st->top]=d;
    }
}

int pop(struct stack *st)
{
    if(st->top==-1)
        return -1;
    else
        return st->data[st->top--];
}

int eval(char *postfix)
{
    int i,res,op1,op2;
    char sym;
    struct stack s;
    s.top=-1;
    for(i=0;postfix[i]!='\0';i++)
    {
        sym=postfix[i];
        switch(sym)
        {
            case '+':
            op2=pop(&s);
            op1=pop(&s);
            res=op1+op2;
            push(&s,res);
            break;
            case '-':
            op2=pop(&s);
            op1=pop(&s);
            res=op1-op2;
            push(&s,res);
            break;
            case '*':
            op2=pop(&s);
            op1=pop(&s);
            res=op1*op2;
            push(&s,res);
            break;
            case '/':
            op2=pop(&s);
            op1=pop(&s);
            res=op1/op2;
            push(&s,res);
            break;
            case '$':
            case '^':
            op2=pop(&s);
            op1=pop(&s);
            res=pow(op1,op2);
            push(&s,res);
            break;
            default:
            push(&s,sym-'0');
            break;
        }
    }
    res=pop(&s);
    return res;
}


int main()
{
    char *postfix;
    int res;
    postfix=(char*)malloc(1);
    printf("\nEnter the Postfix Expression: ");
    scanf("%s",postfix);
    res=eval(postfix);
    printf("\nEvaluation of given postfix is %d",res);
}

/*
Conclution:Here we have implemented the programme to evaluate postfix expression 
its uses is its very it evaluates faster than infix notion as parenthesis are not required in this
and it is very convient for evaluating formulas on computer using stack
Here we have used push pop function but the fuction through which we evaluate the expression is 
eval function and we get the output as a algebric expression


Output:Enter the Postfix Expression: 12+59*-

Evaluation of given postfix is -42

*/