#include<iostream>
#include<stdlib.h>
using namespace std;
struct Vert
{
    char data;
    struct Vert *left, *right;
};
typedef struct Vert Vertex;
struct Stknd
{
    Vertex *data;
    int flag;
};
typedef struct Stknd stknode;
template<class T>
class Stack
{
public:
    struct St
    {
        T *data;
        struct St *next;
    };
    typedef struct St node;
    node *top;
    Stack()
    {
        top=NULL;
    }
    int isempty()
    {
        return (top==NULL)?1:0;                          
    }
    void push(T *newval)
    {
        node *newnode=new node;
        newnode->data=newval;
        newnode->next=top;
        top=newnode;
    }
    void pop()
    {
        node *temp=top;
        top=top->next;
        delete temp;
    }
    T * gettop()
    {
        return top->data;
    }
};
Vertex * create(char c[])
{
    Stack<Vertex> ob;
    int i=0;
    for(i=0; c[i]!= 0; i++)
    {
        Vertex *newnode=new Vertex;
        newnode->data=c[i];
        if(c[i]>='A'&&c[i]<='Z')
        {            
            newnode->left=NULL;
            newnode->right=NULL;            
        }
        else
        {            
            newnode->right=ob.gettop();
            ob.pop();
            newnode->left=ob.gettop();
            ob.pop();
        }
        ob.push(newnode);
    }
    Vertex *t;
    t=ob.gettop();
    ob.pop();
    return t;
}
void inorder(Vertex *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<temp->data;
        inorder(temp->right);
    }
}
void preorder(Vertex *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(Vertex *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data;
    }
}
void nrpreorder(Vertex *temp)
{
    Stack<Vertex> ob;
    while(temp!=NULL)
    {
        cout<<temp->data;
        ob.push(temp);
        temp=temp->left;
    }
    while(ob.isempty()!=1)
    {
        temp=ob.gettop();
        ob.pop();
        temp=temp->right;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->left;
        }
    }
}
void nrinorder(Vertex *temp)
{
    Stack<Vertex> ob;
    
    while(temp!=NULL)
    {
        ob.push(temp);
        temp=temp->left;
    }
    while(ob.isempty()!=1)
    {
        temp=ob.gettop();
        ob.pop();
        cout<<temp->data;
        temp=temp->right;
        while(temp!=NULL)
        {
            ob.push(temp);
            temp=temp->left;
        }
    }
}
class Stak
{
public:
    stknode data[30];
    int top;
    Stak()
    {
        top=-1;
    }
    int isempty()
    {
        if(top==-1)
            return 1;
        return 0;
    }
    void push(stknode val)
    {
        data[++top]=val;
    }
    stknode pop()
    {
        return(data[top--]);
    }
};
void nrpostorder(Vertex *temp)
{
    Stak ob;
    stknode stnode;
    Vertex *p;
    while(temp!=NULL)
    {
        stnode.data=temp;
        stnode.flag=0;
        ob.push(stnode);
        temp=temp->left;
    }
    while(ob.isempty()!=1)
    {
        stnode=ob.pop();
        if(stnode.flag==0)
        {
            stnode.flag=1;
            ob.push(stnode);
            temp=stnode.data;
            temp=temp->right;
            while(temp!=NULL)
            {
                stnode.data=temp;
                stnode.flag=0;
                ob.push(stnode);
                temp=temp->left;
            }
        }
        else
        {
            p=stnode.data;
            cout<<p->data;
        }
    }
}
int main()
{
    Vertex *root;
    char c[40];    
    cout<<"Please enter your postfix statement --> ";
    cin>>c;
    root=create(c);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Non-Recursive traversals\n";
    nrpreorder(root);
    cout<<endl;
    nrinorder(root);
    cout<<endl;
    nrpostorder(root);
    cout<<endl;
    return 0;
}