#include<iostream>
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
	char op[40], x;
	int i=0, k=0;
	for(i=0; c[i]!='\0'; i++)
	{
		if(c[i]>='A'&&c[i]<='Z')
		op[k++]=c[i];
		else if(c[i]==')')
		{
			while(ob.gettop()!='(')
			{
				x=ob.pop();	//character to store the popped out operator
				op[k++]=x;
			}
			x=ob.pop();
		}
                else if(ob.isempty())
                    ob.push(c[i]);
                else if(c[i]=='(')
                       ob.push(c[i]); 
                else if(precedence(c[i])<=precedence(ob.gettop()))
                {
                    while(precedence(c[i])<=precedence(ob.gettop())||ob.isempty()!=1)
                    {
                        x=ob.pop();	//character to store the popped out operator
                        op[k++]=x;
                    }
                    ob.push(c[i]);
                }
		else 
		{
			while(precedence(c[i])<=precedence(ob.gettop())&&ob.gettop()!='('&&ob.isempty())
			{
				x=ob.pop();	//character to store the popped out operator
				op[k++]=x;				
			}
			ob.push(c[i]);
		}
        }
        while(ob.isempty()!=1)
        {
            x=ob.pop();
            op[k++]=x;
        }
	cout<<"Postix statement --> "<<op<<endl;
}
int main()
{
	char c[40];
	cout<<"Please enter your infix statement --> ";
	cin>>c;
	infixtopostfix(c);  
	return 0;
}