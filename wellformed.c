/*
Well formedness of brackets.
{[]}
Algorithm:
1.Read the symbol from the infix string left to right.
2.If its an opening symbol than push on stack.
3.If its closing symbol then pop on stack.
     a.If the pop symbol is not an equivalent opening sybol than its not wellformed and stop.
4.Goto step 1 if input string is not exhausted.
5.If stack is empty then its wellformed else not wellformed.
Eg. Step1:{ is encountered.
stack="{"
Step2:[ is encountered.
stack="{["
Step3:] is encountered.
popped el=[    stack="{"
    Step4:} is encountered
    popped el={   stack=""
    Since the stack is empty so given strin g is wellformed.


   Eg2. String="{[}]" 
   Step1:{ is encountered.
stack="{"
Step2:[ is encountered.
stack="{["
Step3:} is encountered.
popped el=[   
    Since the popped symbol is not an equivalent opening symbol so the given string is not wellformed.
*/


#include<stdio.h>
#include<stdlib.h>
#define Max 50
struct stack
{
    char data [Max];
    int top;
};
//int isempty(struct stack)
void push(struct stack *st,char d)
{
    if(st->top==Max-1)
    printf("\n Stack overflows..");
    else
    {
     st->top++;
     st->data[st->top]=d;
     //printf("\n Successfully pushed..");   
    }
}
char pop(struct stack *st)
{
    if(st->top==-1)
    return -1;
    else
    
       return st->data[st->top--];
    
}
int equivalent(char pe,char sym)
{
    if(sym=='}'&&pe==)
}

int wellformed(char*input)
{
char sym,pe;
int i,res;
struct stack s;
for(i=0;input[i]!='0';i++)
{
    sym=input[i];
    switch(sym)
    {
        case '{':
        case '(':
        case '[':
        push(&s,sym);
        break;
        case '}':
        case ')':
        case ']':
        if(s.top!=-1)
        pe=pop(&s);
        else
        return 0;
        res=equivalent(pe,sym);
       if(!res)
       return 0;
    }
}
if(s.top!=-1)
return 0;
}
int main()
{
    char *input;
    int res;
    input=(char*)malloc(1);
    printf("\n Enter the input expression");
    scanf("%s",input);
  res=wellformed(input);
  if(res)
  printf("\nGiven string is wellformed");
  else
  printf("\nGiven string is not wellformed");
  return 0;
}