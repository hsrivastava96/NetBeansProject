#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct stk
{
	char ch;
	struct stk *next;
};
typedef struct stk node;
class Stack
{
	public:
	node *top;
	Stack()
	{
		top=NULL;	
	}
	int isempty()
	{
		if(top==NULL)
		return 1;
		return 0;	
	}
	void push(char c)
	{
		node *newnode;
		newnode=new node;
		newnode->ch=c;
		newnode->next=top;
		top=newnode;
	}
	char pop()
	{
		node *temp;
		temp=top;
		char topchar=top->ch;
		top=top->next;
		delete(temp);
		return topchar;
	}
	char gettop()
	{
		return top->ch;
	}
}ob;
int precedence(char chr)
{
	switch(chr)
	{
		case '+': return 1;
		case '-': return 1;
		case '(': return 0;
		case '*': return 2;
		case '/': return 2;
		case '$': return 3;
		case '^': return 3;
		default : return 0;
	}
}
void infixtopostfix(char c[])
{
    char postfix[40], x;
    int i=0, k=0, j=0;
    for(i=0; i<40; i++)
        postfix[i]='0';
    for(i=0; c[i]!='0'; i++)
    {
        if(c[i]>='A'&&c[i]<='Z')    //OPERAND
            postfix[k++]=c[i];
        else            //OPERATOR
        {
            if(c[i]=='('||ob.isempty()==1)      //IF STACK is either empty or the operator is (
                ob.push(c[i]);              // It means my stack won't be empty
            else
            {
                if(c[i]==')')
                {
                    while((x=ob.pop())!='(')
                        postfix[k++]=x;
                }
                else
                {
                    if(precedence(c[i])<=precedence(ob.top->ch))
                    {
                            postfix[k++]=ob.pop();
                        ob.push(c[i]);
                    }
                    else
                        ob.push(c[i]);
                }
            }
        }
    }
    while(ob.isempty()!=1)
    postfix[k++]=ob.pop();
    cout<<"\nPostfix statement -->";
    while(postfix[j]!='0')
    cout<<postfix[j++];
}
void infixtoprefix(char c[])
{
    Stack ob1;
    char prefix[40], x;
    int i=0, k=0, j=0;
    for(i=0; i<40; i++)
        prefix[i]='0';
    for(i=0; c[i]!='0'; i++)
    {
        if(c[i]>='A'&&c[i]<='Z')    //OPERAND
            prefix[k++]=c[i];
        else            //OPERATOR
        {
            if(c[i]=='('||ob1.isempty()==1)      //IF STACK is either empty or the operator is (
                ob1.push(c[i]);              // It means my stack won't be empty
            else
            {
                if(c[i]==')')
                {
                    while((x=ob1.pop())!='(')
                        prefix[k++]=x;
                }
                else
                {
                    if(precedence(c[i])<=precedence(ob1.top->ch))
                    {
                            prefix[k++]=ob1.pop();
                        ob1.push(c[i]);
                    }
                    else
                        ob1.push(c[i]);
                }
            }
        }
    }
    while(ob1.isempty()!=1)
    prefix[k++]=ob1.pop();
    while(prefix[j]!='0')
        j++;
    j--;
    cout<<"\nPREFIX STATEMENT --> ";
    while(j>=0)
        cout<<prefix[j--];
    
}
/*void postfixeval(char c[])
{
    Stack ob2;
    int i=0, n1=0, n2=0, val=0;
    char c1, c2, chr[5];
    for(i=0; c[i]!='0'; i++)
    {
        if(c[i]>='A'&&c[i]<='Z')
            ob2.push(c[i]);
        else
        {
            if(c[i]=='^'||c[i]=='$')
            {
                c2=ob2.pop();
                c1=ob2.pop();
                n1=atoi(c1);
                n2=atoi(c2);
                val=pow(n1,n2);
                itoa(val, chr, 10);
                ob2.push(chr);
            }
            if(c[i]=='+')
            {
                c2=ob2.pop();
                c1=ob2.pop();
                n1=atoi(c1);
                n2=atoi(c2);
                val=n1+n2;
                itoa(val, chr, 10);
                ob2.push(chr);
            }
            if(c[i]=='-')
            {
                c2=ob2.pop();
                c1=ob2.pop();
                n1=atoi(c1);
                n2=atoi(c2);
                val=n1-n2;
                itoa(val, chr, 10);
                ob2.push(chr);
            }
            if(c[i]=='*')
            {
                c2=ob2.pop();
                c1=ob2.pop();
                n1=atoi(c1);
                n2=atoi(c2);
                val=n1*n2;
                itoa(val, chr, 10);
                ob2.push(chr);
            }
            if(c[i]=='/')
            {
                c2=ob2.pop();
                c1=ob2.pop();
                n1=atoi(c1);
                n2=atoi(c2);
                val=n1/n2;
                itoa(val, chr, 10);
                ob2.push(chr);
            }      
        }
    }   
}*/
int main()
{
    char c[40], d[40];
    int i=0, j=0;
    for(int k=0; k<40; k++)
    {d[k]='0';c[k]='0';}
    cout<<"Please enter your infix statement --> ";
    cin>>c;
    infixtopostfix(c);
    for(i=0; c[i]!='\0'; i++);
    i--;
    while(i>=0)
    {
        if(c[i]=='(')
            d[j]=')';
        else if(c[i]==')')
            d[j]='(';
        else
            d[j]=c[i];
        j++;
        i--;
    }
    infixtoprefix(d);
    //cout<<"Please enter your postfix expression for evaluation --> ";
    //cin>>c;
    //postfixeval(c);
    return 0;
}
