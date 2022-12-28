/*
Implementation of Linear and Binary Search        Name-Nadaf Zakki Noor Mohammed
                                                  Roll No.-20CO40
                                                  Academic Year-2021-2022

Theory about the programme:-Binary search and Linear search are two types of
searching techniques used in arrays.

Binary Search:-In Binary search in the array is sorted
and hence the element to be search is compared to the middle
element of the array and if element is lesser than middle
then the array to be searching array is divided into 
lower half.
If element is greater than middle element then
searching array is divided into upper half.

*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int arr[MAX];

void create()
{
    
    printf("Enter the elements of the array\n");
    for(int i=0;i<=MAX-1;i++)
    {
        printf("At index %d == ",i);
        scanf("%d",&arr[i]);
        
    }
}

int LinearS(int d)
{
    for(int i=0;i<=MAX-1;i++)
    {
        if(arr[i]==d)
        {
            return i;
        }
    }
    return -1;

}

int BinaryS(int d)
{
    int low,upp,mid;
    low=0;
    upp=MAX-1;
    for(mid=(low+upp)/2;low<=upp;mid=(low+upp)/2)
    {
        if(d==arr[mid])    //Element is found at middle
            return mid;
        if(d>arr[mid])   //Element is greater so element is present in upper half
            low=mid+1;   
        else
            upp=mid-1;    //Element is present in lower half
    }
    return -1;
}

int main()
{
    int ch,d,key;
    printf("\t\t\tMENU\n");
    while(1)
    {
        printf("\n\t\t\tMENU\n1. Linear Search .\n2. Binary Search .\n3. Exit .");
        printf("\n\tEnter your choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            create();
            getchar();
            printf("Enter the element to be searched ");
            scanf("%d",&d);
            key=LinearS(d);
            if(key==-1)
               printf("\nElement not found");
            else
                printf("nElement %d found at index %d",d,key);
            break;

            case 2:
            printf("Enter Sorted elements\n");
            create();
            getchar();
            printf("Enter the element to be searched ");
            scanf("%d",&d);
            key=BinaryS(d);
            if(key==-1)
               printf("\nElement not found");
            else
                printf("\nElement %d found at index %d",d,key);
            break;

            case 3:
            exit(0);
            break;

            default:
            printf("\nInvalid Input");
        }
    }

    return 0;
}
/*
Conclution: I understood that how to implement linear and binary search and I
            also understood that 

Output:             MENU
1. Linear Search .
2. Binary Search .
3. Exit .
        Enter your choice :: 1
Enter the elements of the array
At index 0 == 12
At index 1 == 7
At index 2 == 9
At index 3 == 11
At index 4 == 13
Enter the element to be searched 9
nElement 9 found at index 2
                        MENU
1. Linear Search .
2. Binary Search .
3. Exit .
        Enter your choice :: 2
Enter Sorted elements
Enter the elements of the array
At index 0 == 2
At index 1 == 8
At index 2 == 14
At index 3 == 18
At index 4 == 22
Enter the element to be searched 18

Element 18 found at index 3
*/