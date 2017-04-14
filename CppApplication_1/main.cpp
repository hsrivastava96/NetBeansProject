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
	int isempty(node *top)
	{
		if(top==NULL)
		return 1;
		else
		return 0;
	}
	node * push(node *top, char chr)
	{
		node *new_node;
		new_node=new node;
		new_node->ch=chr;
		new_node->next=top;
		top=new_node;
		return top;
	}
	node * pop(node *top)
	{
		Stack ob;
		node *temp;
		int check;
		char copy_char='\0';
		check=ob.isempty(top);
		if(check==1)
		cout<<"\t\tEMPTY STACK!!!\n";
		else
		{
			copy_char=top->ch;
			temp=top;
			top=top->next;
			delete temp;
		}
		return top;
	}
	void display(node *top)
	{
		node *temp;
		temp=top;
		cout<<"\t*****Your STACK*****\n";
		do
		{
			cout<<temp->ch<<endl;
			temp=temp->next;
		}
		while(temp!=NULL);
	}
	char gettop(node *top)
	{
		return top->ch;
	}
};
class Conversion: public Stack
{
	public:
	int Precedence(char ch)
	{
		switch(ch)
		{
			case '(': return 0;
			case '+': return 1;
			case '-': return 1;
			case '*': return 2;
			case '/': return 2;
			case '$': return 3;
			case '^': return 3;
		}
	}	
	node * infixtopostfix(char ch[], node *operator_top,  node *operand_top)
	{
		char top_char, popped_char;
		int i, prio1, prio2;
		Stack ob;
		Conversion obj;
		for(i=0; ch[i]!='\0'; i++)
		{
			if(ch[i]>='A'&&ch[i]<='Z')
			operand_top=ob.push(operand_top, ch[i]);
			else
			operator_top=ob.push(operator_top, ch[i]);
		}
		ob.display(operator_top);
		return operand_top;
	}
};
int main()
{
	node *operand_top, *operator_top, *top;
	operand_top=NULL;
	operator_top=NULL;
	char c[20], popc;
	cout<<"Please enter your infix statement --> ";
	cin>>c;
	Conversion obj;
	Stack ob;
	top=obj.infixtopostfix(c, operator_top, operand_top);
	top=ob.pop(top);
	top=ob.pop(top);	
	ob.display(top);
	ob.display(top);
	return 0;
}