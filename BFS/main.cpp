#include<iostream>
using namespace std;
struct Neighbour
{
    int ver;
    char nmb;
    struct Neighbour *next;
};
typedef struct Neighbour Neighbour;
struct Vertex
{
    int visit;
    char name;
    Neighbour *head;
};
typedef struct Vertex Vertex;
Vertex *v[10];
void adjlist(int n)
{
    
    Neighbour *newnode, *temp;
    int i=0, j=0, choice;
    for(i=0; i<n; i++)
    {
        v[i]=new Vertex;
        cout<<"\nEnter name for vertex "<<i+1<<" --> ";
        cin>>v[i]->name;
        v[i]->visit=0;
        v[i]->head=NULL;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<"\nIs there an edge between "<<v[i]->name<<" and "<<v[j]->name<<"?\n1. Yes\n2. No\nYour choice --> ";
            cin>>choice;
            if(choice==1)
            {
                newnode=new Neighbour;
                newnode->ver=j;
                newnode->nmb=v[j]->name;
                if(v[i]->head==NULL)
                    v[i]->head=newnode;
                else
                    temp->next=newnode;
                temp=newnode;
            }
        }
    }
}
void display(int n)
{
    Neighbour *temp;
    int i=0;
    for(i=0; i<n; i++)
    {
        cout<<"["<<v[i]->name<<"]";
        temp=v[i]->head;
        while(temp!=NULL)
        {
            cout<<"->["<<temp->nmb<<"]";
            temp=temp->next;
        }
        cout<<endl;
    }
}
struct Q
{
    Vertex *vrt;
    struct Q *next;
};
typedef struct Q node;
class Queue
{
    public:
    node *top, *newnode, *temp;
    Queue()
    {
        top=NULL;
    }
    int isempty()
    {
        if(top==NULL)
            return 1;
        return 0;
    }
    void enqueue(Vertex *v)
    {
        newnode=new node;
        newnode->vrt=v;
        newnode->next=NULL;
        if(top==NULL)
            top=newnode;
        else
            temp->next=newnode;
        temp=newnode;
    }
    void dequeue()
    {
        node *tmp;
        tmp=top;
        top=top->next;
        delete tmp;
    }
    Vertex * gettop()
    {
        return top->vrt;
    }
}ob;
void BFS(Vertex *node)
{
    if(node->visit==0)
    {
        node->visit=1;
        cout<<node->name;
        Neighbour *temp;
        temp=node->head;
        while(temp!=NULL)
        {
            if(v[temp->ver]->visit==0)
            {
                v[temp->ver]->visit=1;
                cout<<v[temp->ver]->name;
                ob.enqueue(v[temp->ver]);
            }
            temp=temp->next;
        }
        node=ob.gettop();
        ob.dequeue();
        BFS(node);
    }
    else if(node->visit==1)
    {
        Neighbour *temp;
        temp=node->head;
        while(temp!=NULL)
        {
            if(v[temp->ver]->visit==0)
            {
                v[temp->ver]->visit=1;
                cout<<v[temp->ver]->name;
                ob.enqueue(v[temp->ver]);
            }
            temp=temp->next;
        }
        if(ob.isempty()==1)
            return;
        else
        {
            node=ob.gettop();
            ob.dequeue();
            BFS(node);
        }
    }
}
int main()
{
    int n;
    cout<<"Please enter the total number of vertices --> ";
    cin>>n;
    adjlist(n);
    display(n);
    BFS(v[0]);
    return 0;
}
