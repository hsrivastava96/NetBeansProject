#include<iostream>
#include<math.h>
using namespace std;
template<class T>
class Stack
{
    public:
        struct st
        {
            T data;
            struct st *next;
        };
        typedef struct st node;
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
        void push(T c)
        {
            node *newnode;
            newnode=new node;
            newnode->data=c;
            newnode->next=top;
            top=newnode;
        }
        T pop()
        {
            node *temp;
            temp=top;
            T topdata=top->data;
            top=top->next;
            delete temp;
            return topdata;
        }
        T gettop()
        {
            return top->data;
        }
};
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
void infixtoprefix(char c[])
{
    Stack<char> ob1;
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
                    if(precedence(c[i])<=precedence(ob1.top->data))
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
void infixtopostfix(char c[])
{
    Stack<char> ob2;
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
            if(c[i]=='('||ob2.isempty()==1)      //IF STACK is either empty or the operator is (
                ob2.push(c[i]);              // It means my stack won't be empty
            else
            {
                if(c[i]==')')
                {
                    while((x=ob2.pop())!='(')
                        postfix[k++]=x;
                }
                else
                {
                    if(precedence(c[i])<=precedence(ob2.top->data))
                    {
                            postfix[k++]=ob2.pop();
                        ob2.push(c[i]);
                    }
                    else
                        ob2.push(c[i]);
                }
            }
        }
    }
    while(ob2.isempty()!=1)
    postfix[k++]=ob2.pop();
    cout<<"\nPostfix statement -->";
    while(postfix[j]!='0')
    cout<<postfix[j++];
}
void postfixeval(char c[])
{
    Stack<int> ob3;
    int i=0, num, num1=0, num2=0, sum=0, final=0;
    for(i=0; c[i]!='0'; i++)
    {
        if((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))
        {
            cout<<"Enter value of "<<c[i]<<" --> ";
            cin>>num;
            ob3.push(num);
        }
        if(c[i]=='+')
        {
            num2=ob3.pop();
            num1=ob3.pop();
            sum=num1+num2;
            ob3.push(sum);
        }
        if(c[i]=='-')
        {
            num2=ob3.pop();
            num1=ob3.pop();
            sum=num1-num2;
            ob3.push(sum);
        }
        if(c[i]=='*')
        {
            num2=ob3.pop();
            num1=ob3.pop();
            sum=num1*num2;
            ob3.push(sum);
        }
        if(c[i]=='/')
        {
            num2=ob3.pop();
            num1=ob3.pop();
            sum=num1/num2;
            ob3.push(sum);
        }
        if(c[i]=='^')
        {
            num2=ob3.pop();
            num1=ob3.pop();
            sum=pow(num1,num2);
            ob3.push(sum);
        }
    }
    final=ob3.pop();
    cout<<"Evaluated value = "<<final<<endl;
}
void prefixeval(char c[])
{
    Stack<int> ob3;
    int i=0, num, num1=0, num2=0, sum=0, final=0;
    for(i=0; c[i]!='0'; i++);
    i--;
    while(i-->=0)
    {
        if((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z'))
        {
            cout<<"Enter value of "<<c[i]<<" --> ";
            cin>>num;
            ob3.push(num);
        }
        if(c[i]=='+')
        {
            num1=ob3.pop();
            num2=ob3.pop();
            sum=num1+num2;
            ob3.push(sum);
        }
        if(c[i]=='-')
        {
            num1=ob3.pop();
            num2=ob3.pop();
            sum=num1-num2;
            ob3.push(sum);
        }
        if(c[i]=='*')
        {
            num1=ob3.pop();
            num2=ob3.pop();
            sum=num1*num2;
            ob3.push(sum);
        }
        if(c[i]=='/')
        {
            num1=ob3.pop();
            num2=ob3.pop();
            sum=num1/num2;
            ob3.push(sum);
        }
        if(c[i]=='^')
        {
            num1=ob3.pop();
            num2=ob3.pop();
            sum=pow(num1,num2);
            ob3.push(sum);
        }
    }
    final=ob3.pop();
    cout<<"Evaluated value = "<<final<<endl;
}
int main()
{
    char c[40], d[40], e[40], f[40];   //Here c is to input infix statement, d is to send the reverse of c in prefix conversion and e and f are to take postfix and prefix statement for postfix and prefix evaluation respectively
    int i=0, choice, j=0, ch;
    while(i<40)
    {
        c[i]='0';
        d[i]='0';
        e[i]='0';
        f[i]='0';
        i++;
    }
    do
    {
        cout<<"\t*****MENU*****\n1. Infix-Prefix\n2. Infix-Postfix\n3. Postfix Evaluation\n4. Prefix Evaluation\n5. Exit\nYour choice --> ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your Infix statement --> ";
            cin>>c;
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
            cout<<"\n\n\tDo you want to continue? If\nYES press --> 1\nNO press --> 2\nYour response please --> ";
            cin>>ch;
        }
        else if(choice==2)
        {
            cout<<"Enter your Infix statement --> ";
            cin>>c;
            infixtopostfix(c);
            cout<<"\n\n\tDo you want to continue? If\nYES press --> 1\nNO press --> 2\nYour response please --> ";
            cin>>ch;
        }
        else if(choice==3)
        {
            cout<<"Enter your Postfix expression --> ";
            cin>>e;
            postfixeval(e);
            cout<<"\n\n\tDo you want to continue? If\nYES press --> 1\nNO press --> 2\nYour response please --> ";
            cin>>ch;
        }
        else if(choice==4)
        {
            cout<<"Enter your Prefix expression --> ";
            cin>>f;
            prefixeval(f);
            cout<<"\n\n\tDo you want to continue? If\nYES press --> 1\nNO press --> 2\nYour response please --> ";
            cin>>ch;
        }
        else
        {
            ch=2;
            cout<<"\t*****Thank You!!!*****\n";
        }
    }
    while(ch==1);
    if(ch==2)
        cout<<"\t*****Thank You!!!*****\n";
    return 0;
}