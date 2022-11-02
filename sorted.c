#include <stdio.h>
#define MAX 100
int Stack[MAX],top=-1;
void push(int data)
{
    if(top==MAX-1)
        printf("\nStack Overflow");
    else if(top==-1)
        Stack[++top]=data;
    else
    {
        int tempStack[MAX],tempTop=-1;
        while(data>Stack[top]&&top!=-1)
        {
            int del=Stack[top--];
            tempStack[++tempTop]=del;
        }
        Stack[++top]=data;
        while(tempTop>=0)
        {
            int del=tempStack[tempTop--];
            Stack[++top]=del;
        }
    }    
}
void pop()
{
    int del;
    if(top==-1)
        printf("\nStack empty.");
    else
    {
        del=Stack[top--];
        printf("\nDeleted : %d",del);
    }    
}
void display()
{
    if(top==-1)
        printf("\nStack empty!!\n");
    else
    {
        printf("\n");
        for(int i=0;i<=top;i++)
        {
            printf("%d\n",Stack[i]);
        }
    }    
}
int main()
{
    int ch,el;
    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Display stack.");
        printf("\n4.Exit");
        printf("\n\nChoose operation : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter element to insert : ");
                scanf("%d",&el);
                push(el);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;    
        }
    }while(ch<4);
    return 0;
}
