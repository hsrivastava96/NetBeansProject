#include<iostream>
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

int main()
{
    Stack<int> ob1;
    Stack<char> ob2;
    Stack<double> ob3;
    int p, i=0;
    char q[40];
    double r;
    cout<<"Infix statement --> ";
    cin>>q;
    while(q[i]!='\0')
        ob2.push(q[i++]);
    while(ob2.isempty()!=1)
    {
        char chr=ob2.pop();
        cout<<chr;
    }
    return 0;
}