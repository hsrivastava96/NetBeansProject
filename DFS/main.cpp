#include<iostream>
#include<ctime>
using namespace std;
struct Neighbour
{
    int ver;
    char nbnam;
    struct Neighbour *next;
};
typedef struct Neighbour Neighbour;
struct Vertex
{
    char name;
    int visit, comments, date, month, year;
    Neighbour *head;
};
typedef struct Vertex Vertex;
Vertex *v[10];
void Acceptvertices(int n)
{
    int i=0, j=0, ch;
    char nam;
    Neighbour *newnode, *temp;
    for(i=0; i<n; i++)
    {
        v[i]=new Vertex;
        cout<<"Name of vertex "<<i+1<<" --> ";
        cin>>nam;
        cout<<"Number of comments --> ";
        cin>>v[i]->comments;
        cout<<"Enter your date of birth\n";
        cout<<"Date --> ";
        cin>>v[i]->date;
        cout<<"\nMonth --> ";
        cin>>v[i]->month;
        cout<<"\nYear --> ";
        cin>>v[i]->year;
        v[i]->name=nam;
        v[i]->head=NULL;
        v[i]->visit=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cout<<"\nIs there an edge between "<<v[i]->name<<" and "<<v[j]->name<<"?\n1. Yes\n2. No\nYour choice --> ";
            cin>>ch;
            if(ch==1)
            {
                newnode=new Neighbour;
                newnode->nbnam=v[j]->name;
                newnode->ver=j;
                if(v[i]->head==NULL)
                {
                    v[i]->head=newnode;
                    temp=v[i]->head;
                }
                else
                    temp->next=newnode;
                temp=newnode;
            }
        }
    }
}
void display(int n)
{
    time_t t=time(0);
    struct tm * now=localtime(&t);
    int i=0, maxf=-999, vmaxf=0, maxc=-999, minc=999, vmaxc=0, vminc=0, k=0, mon=0;
    mon=(now->tm_mon +1);
    for(i=0; i<n; i++)
    {
        Neighbour *temp=v[i]->head;
        cout<<"["<<v[i]->name<<"]";
        do
        {
            cout<<" -> "<<"["<<temp->nbnam<<"]";
            temp=temp->next;
            k++;
        }
        while(temp!=NULL);
        if(k>maxf)
        {
            maxf=k;
            vmaxf=i;
        }
        k=0;
        cout<<endl;
    }
    for(i=0; i<n; i++)
    {
        if(v[i]->comments>maxc)
        {
            maxc=v[i]->comments;
            vmaxc=i;
        }
        if(v[i]->comments<minc)
        {
            minc=v[i]->comments;
            vminc=i;
        }
        if(mon==v[i]->month)
            cout<<v[i]->name<<" is having his birthday in this month on "<<v[i]->date<<".\n";
    }
    cout<<"Vertex with max comments --> "<<v[vmaxc]->name<<" with number of comments --> "<<maxc<<endl;
    cout<<"Vertex with min comments --> "<<v[vminc]->name<<" with number of comments --> "<<minc<<endl;
    cout<<"Vertex with max friends --> "<<v[vmaxf]->name<<" with number of friends --> "<<maxf<<endl;
}
struct St
{
    Vertex *vrt;
    struct St *next;
};
typedef struct St node;
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
    void push(Vertex *v)
    {
        node *newnode;
        newnode=new node;
        newnode->vrt=v;
        newnode->next=top;
        top=newnode;
    }
    void pop()
    {
        node *temp;
        temp=top;
        top=top->next;
        delete temp;
    }
    Vertex * gettop()
    {
        return top->vrt;
    }
}ob;
void DFS(Vertex *node)
{
    if(node->visit==0)
    {
        node->visit=1;
        cout<<node->name;
        ob.push(node);
        node=ob.gettop();
        DFS(node);
    }
    else if(ob.isempty()==1)
        return;
    else if(node->visit==1)
    {
        int k=0;
        Neighbour *temp=node->head;
        while(temp!=NULL&&k==0)
        {
            if(v[temp->ver]->visit==0)
                k=1;
            else
                temp=temp->next;
        }
        if(k==1)
        {
            v[temp->ver]->visit=1;
            cout<<v[temp->ver]->name;
            ob.push(v[temp->ver]);
            node=ob.gettop();
            DFS(node);
        }
        else
        {
            ob.pop();
            if(ob.isempty()==1)
                return;
            else
            {
                node=ob.gettop();
                DFS(node);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Please enter the total number of nodes --> ";
    cin>>n;
    Acceptvertices(n);
    display(n);
    DFS(v[0]);
    return 0;
}