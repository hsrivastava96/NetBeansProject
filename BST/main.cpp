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
            p=root;
            cout<<"Enter value to be inserted --> ";
            cin>>value;
            while(1)
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
                        break;
                    }
                    else if(p->left!=NULL)
                        p=p->left;   
                }
                else if(value>p->data)
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
                    else if(p->right!=NULL)
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
int main()
{
    node *r;
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
        cout<<"not present";*/
    del(2);
    preorder(root);
    return 0;
}