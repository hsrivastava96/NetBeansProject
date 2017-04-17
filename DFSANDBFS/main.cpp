#include<iostream>
#include<ctime>
using namespace std;
struct Neighbour    //Structure to create the neighboring nodes of vertices
{
    int index;  //Integer to hold the index of neighboring vertex
    char nbnam; //Character to hold the name of the neighboring vertex
    struct Neighbour *next; //Next pointer to traverse the neighboring list
};
typedef struct Neighbour Neighbour;
struct Vertex   //Structure to create vertex nodes and input user info
{
    char name;
    int visit, comments, date, month, year;
    Neighbour *head;    //Neighbor type head to store the head of the neighbor list
};
typedef struct Vertex Vertex;
Vertex *v[10];  //Global array of pointer to store addresses of vertices
void adjlist(int n) //Function to input user info and create adjacency list
{
    int i=0, j=0, choice;
    char nam;
    Neighbour *newnode, *temp;
    cout<<"\t------------------------\n";
    cout<<"\t|INPUT USER INFORMATION|\n";
    cout<<"\t------------------------\n";
    for(i=0; i<n; i++)  //Loop to input user info
    {
        cout<<"\t>>>>>Enter Information about Vertex "<<i+1<<"<<<<<"<<endl;
        v[i]=new Vertex;
        cout<<"Name of vertex --> ";
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
    cout<<"\n\t------------------------\n";
    cout<<"\t|INPUT EDGE INFORMATION|\n";
    cout<<"\t------------------------\n";
    for(i=0; i<n; i++)  //Nested loop to create ADJACENCY LIST
    {
        for(j=0; j<n; j++)  //Loop for creating neighbors of ith vertex
        {
            cout<<"\nIs there an edge between "<<v[i]->name<<" and "<<v[j]->name<<"?\n1. Yes\n2. No\nYour choice --> ";
            cin>>choice;
            if(choice==1)
            {
                newnode=new Neighbour;
                newnode->nbnam=v[j]->name;
                newnode->index=j;
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
void display(int n) //Display module to display Adjacency list and Final Results
{
    time_t t=time(0);
    struct tm * now=localtime(&t);
    int i=0, maxf=-999, vmaxf=0, maxc=-999, minc=999, vmaxc=0, vminc=0, counter=0, mon=0;
    mon=(now->tm_mon +1);
    cout<<"\n\t------------------------\n";
    cout<<"\t*****ADJACENCY LIST*****\n";
    cout<<"\t------------------------\n";
    for(i=0; i<n; i++)  //Loop to get the person having maximum number of friends by traversing the adjacency list
    {
        Neighbour *temp=v[i]->head;
        cout<<"["<<v[i]->name<<"]";
        do  //Loop to traverse the neighboring list of vertex at ith index
        {
            cout<<" -> "<<"["<<temp->nbnam<<"]";
            temp=temp->next;
            counter++;
        }
        while(temp!=NULL);
        if(counter>maxf)
        {
            maxf=k;
            vmaxf=i;
        }
        counter=0;
        cout<<endl;
    }
    cout<<"\n\t------------------------------\n";
    cout<<"\t*****BIRTHDAYS THIS MONTH*****\n";
    cout<<"\t------------------------------\n";
    for(i=0; i<n; i++)  //Loop for traversing the vertex pointer array to get the user with maximum and minimum number of comment
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
    cout<<"\n\t------------------------------------\n";
    cout<<"\t*****CONCLUDED USER INFORMATION*****\n";
    cout<<"\t------------------------------------\n";
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
class Stack //ADT of Stack for Depth first search traversal
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
void DFS(Vertex *node)  //Depth first search main module
{
    if(node->visit==0)  //If node is not visited then print it and push it on to the stack simultaneously
    {
        node->visit=1;
        cout<<node->name;
        ob.push(node);
        node=ob.gettop();   //After pushing the node get the top of stack to continue with DFS
        DFS(node);
    }
    else if(ob.isempty()==1)
        return;
    else if(node->visit==1) //If node is visited then traverse it's neighbors to get the unvisited neighbor
    {
        int k=0;    //K is a flag to come out of the forthcoming while loop if an unvisited vertex is present in node's neighboring list
        Neighbour *temp=node->head;
        while(temp!=NULL&&k==0) //Loop to get the unvisited neighbor if there
        {
            if(v[temp->index]->visit==0)
                k=1;
            else
                temp=temp->next;
        }
        if(k==1)    //If an unvisited node is present then print it and push it on to the stack
        {
            v[temp->index]->visit=1;    //Set the node as visited
            cout<<v[temp->index]->name; //Print the node
            ob.push(v[temp->index]);    //Push the node on to the stack
            node=ob.gettop();   //Get top of the stack
            DFS(node);  //Again recursively call the DFS algorithm to continue the traversal
        }
        else    //If none of the neighbors of present node were unvisited
        {
            ob.pop();   //then pop the node from stack
            if(ob.isempty()==1) //Check if the stack is empty then return 
                return;
            else    //Otherwise get top of the stack and again call DFS algorithm
            {
                node=ob.gettop();
                DFS(node);
            }
        }
    }
}
struct Q
{
    Vertex *vrt;
    struct Q *next;
};
typedef struct Q nde;
class Queue //ADT of Queue for Breadth first search traversal
{
    public:
    nde *top, *newnode, *temp;
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
        newnode=new nde;
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
        nde *tmp;
        tmp=top;
        top=top->next;
        delete tmp;
    }
    Vertex * gettop()
    {
        return top->vrt;
    }
}obq;
void BFS(Vertex *node)  //Breadth first search main module
{
    if(node->visit==0)  //If node is not visited then print the node and print all it's neighbors and enqueue them simultaneously in queue
    {
        node->visit=1;
        cout<<node->name;
        Neighbour *temp;
        temp=node->head;
        while(temp!=NULL)   //Loop to traverse the neighbor list of present node
        {
            if(v[temp->index]->visit==0)    //If neighbor is not visited print it and simultaneously enqueue it in queue
            {
                v[temp->index]->visit=1;
                cout<<v[temp->index]->name;
                obq.enqueue(v[temp->index]);
            }
            temp=temp->next;
        }
        node=obq.gettop();  //Get top of of queue 
        obq.dequeue();  //Pop top of queue
        BFS(node);  //Repeat the same algorithm 
    }
    else if(node->visit==1) //If present node is visited, traverse it's neighbor list and print unvisited neighbors and simultaneously enqueue them in queue
    {
        Neighbour *temp;    //Temporary variable to traverse the neighbor list of present node
        temp=node->head;
        while(temp!=NULL)   //Loop to traverse the neighbor list
        {
            if(v[temp->index]->visit==0)    //Condition that if neighbor is not visited then print it and enqueue it
            {
                v[temp->index]->visit=1;
                cout<<v[temp->index]->name;
                obq.enqueue(v[temp->index]);
            }
            temp=temp->next;
        }
        if(obq.isempty()==1)    //Check if queue is empty then return
            return;
        else    //Condition if queue is not empty yet
        {
            node=obq.gettop();  //then get top of the queue
            obq.dequeue();  //dequeue the queue
            BFS(node);  //Repeat the same algorithm
        }
    }
}
int main()
{
    int n, i=0;
    cout<<"\t-----------------------------------------------------------"<<endl;
    cout<<"\t**********DEPTH & BREADTH First SEARCH TRAVERSALS**********"<<endl;
    cout<<"\t-----------------------------------------------------------"<<endl;
    cout<<"\n\t<<<<<Begin>>>>>\n";
    cout<<"Please enter the total number of nodes --> ";
    cin>>n;
    cout<<"\n\n\t\t   Hello...\n\t\tLet's Begin!!!\n"<<endl;
    adjlist(n);
    display(n);
    cout<<endl;
    cout<<"\t[DEPTH FIRST SEARCH]\n";
    DFS(v[0]);
    cout<<endl;
    for(i=0; i<n; i++)
        v[i]->visit=0;
    cout<<"\t[BREADTH FIRST SEARCH]\n";
    BFS(v[0]);
    cout<<endl;
    return 0;
}