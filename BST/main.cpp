#include<iostream>
using namespace std;
struct n
{
    int data;
    struct n *left, *right;
}*root=NULL, *p=NULL;
typedef struct n node;
void create()
{
    int value, n;
    do
    {
//        k=0;
        if(root==NULL)
        {
            root=new node;
            cout<<"Enter value --> ";
            cin>>root->data;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            int k=0;
            p=root;
            cout<<"Enter value to be inserted --> ";
            cin>>value;
            while(k==0)
            {
                if(value<p->data)
                {
                    if(p->left==NULL)
                    {
                        p->left=new node;
                        p=p->left;
                        p->data=value;
                        p->left=NULL;
                        p->right=NULL;
                        cout<<"Value entered in left\n";
                        k=1;
                    }
                    else //if(p->left!=NULL)
                        p=p->left;   
                }
                else //if(value>p->data)
                {
                    if(p->right==NULL)
                    {
                        p->right=new node;
                        p=p->right;
                        p->data=value;
                        p->left=NULL;
                        p->right=NULL;
                        break;
                    }
                    else //if(p->right!=NULL)
                        p=p->right;
                }
            }
        }
        cout<<"Another node? Yes --> 1 No --> 0\nEnter --> ";
        cin>>n;
    }
    while(n==1);
    //return root;
}
void preorder(node *p)
{
    if(p!=NULL)
    {
        cout<<p->data;
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data;
        inorder(p->right);
    }
}
void postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data;
    }
}
node * search(node *temp, int key)
{
    if(temp==NULL||temp->data==key)
        return temp;
    if(temp->data<key)
        return search(temp->right,key);
    return search(temp->left,key);
}
node * mirror(node *p)
{
    if(p==NULL)
        return p;
    node *mrr=new node;
    mrr->data=p->data;
    mrr->left=mirror(p->right);
    mrr->right=mirror(p->left);
    return mrr;
}
void del(int key)
{
    node *temp, *t;
    temp=search(root,key);
    if(temp==NULL)
        cout<<"Key not found\n";
    else
    {
        if(temp->left==NULL&&temp->right==NULL)
            delete temp;
        else if(temp->left==NULL&&temp->right!=NULL)
        {
            t=temp;
            temp=temp->right;
            delete t;
        }
        else if(temp->left!=NULL&&temp->right==NULL)
        {
            t=temp;
            temp=temp->left;
            delete t;
        }
        else
            cout<<"CANNOT BE DELETED\n";
    }
}
struct Q
{
    node *data;
    struct Q *next;
};
typedef struct Q nod;
class Queue
{
public:
    nod *top, *temp;
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
    void enqueue(node *vertex)
    {
        nod *newnode;
        newnode=new nod;
        newnode->data=vertex;
        if(top==NULL)
            top=newnode;
        else
            temp->next=newnode;
        temp=newnode;
    }
    void dequeue()
    {
        nod *tmp;
        tmp=top;
        top=top->next;
        delete tmp;
    }
    node * gettop()
    {
        return top->data;
    }
}ob;
void level(node *rt)
{
    if(rt->left==NULL&&rt->right==NULL)
        return;
    else
    {
        if(rt->left!=NULL)
            ob.enqueue(rt->left);
        if(rt->right!=NULL)
            ob.enqueue(rt->right);
        rt=ob.gettop();
        cout<<rt->data;
        ob.dequeue();
        level(rt);
    }
}
int main()
{
    node *r, *mir;
    r=NULL;
    create();
    cout<<"\nIN\n";
    preorder(root);
    cout<<"\nPre\n";
    inorder(root);
    cout<<"\nPost\n";
    postorder(root);
    /*r=search(root,4);
    if(r!=NULL)
        cout<<r->data;
    else
        cout<<"not present";
    del(2);
    inorder(root);
    mir=mirror(root);
    cout<<"\nMirror\n";
    inorder(mir);*/
    cout<<"\n"<<root->data;
    level(root);
    while(ob.isempty()!=1)
    {
        cout<<ob.gettop()->data;
        ob.dequeue();
    }
    return 0;
}