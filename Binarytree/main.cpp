#include<iostream>
#include<ctype.h>
using namespace std;
struct n
{
    int data;
    struct n *left, *right;
};
typedef struct n node;
class Btree
{
public:
    node *root;
    Btree()
    {
        root=NULL;
    }
    void create()
    {
        node *temp=new node;
        cout<<"\nEnter value --> ";
        cin>>temp->data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
            root=temp;
        else
            insert(root,temp);
    }
    void insert(node *temp, node *nptr)
    {
        int n;
        cout<<"\nLeft --> 1, Right --> 2. \nYour choice --> ";
        cin>>n;
        if(n==1)
        {
            if(temp->left==NULL)
                temp->left=nptr;
            else
                insert(temp->left,nptr);
        }
        else
        {
            if(temp->right==NULL)
                temp->right=nptr;
            else
                insert(temp->right,nptr);
        }
    }
   int depth(node *root)
    {
        int leftdepth, rightdepth, d=1;
        if(root!=NULL)
        {
            if(root->left==NULL&&root->right==NULL)
                d=1;
            else
            {
                leftdepth=depth(root->left);
                rightdepth=depth(root->right);
                if(leftdepth>=rightdepth)
                    return leftdepth+1;
                else
                    return rightdepth+1;
            }    
        }        
    }
    void leaf(node *root)
    {
        if(root!=NULL)
        {
            if(root->left==NULL&&root->right==NULL)
                cout<<root->data;
            leaf(root->left);
            leaf(root->right);
        }
    }
    node * copy(node *root)
    {
        if(root==NULL)
            return root;
        node *cpy=new node;
        cpy->data=root->data;
        cpy->left=copy(root->left);
        cpy->right=copy(root->right);
        return cpy;
    }
    node * getroot()
    {
        return root;
    }
    void preorder(node *temp)
    {
        if(temp!=NULL)
        {
            cout<<temp->data;
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void inorder(node *temp)
    {
        if(temp!=NULL)
        {
            inorder(temp->left);
            cout<<temp->data;
            inorder(temp->right);
        }
    }
    void postorder(node *temp)
    {
        if(temp!=NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data;
        }
    }
}ob;
int main()
{
    node *r, *c;
    int i=0, dpth=0;
    while(i++<5)
    ob.create();
    r=ob.getroot();
    cout<<"\n\nPREORDER\n";
    ob.preorder(r);
    cout<<"\n\nINORDER\n";
    ob.inorder(r);
    cout<<"\n\nPOSTORDER\n";
    ob.postorder(r);
    cout<<"\n\nLeaves\n";
    ob.leaf(r);
    cout<<"\n\nCOPY\n";
    c=ob.copy(r);
    ob.preorder(c);
    dpth=ob.depth(r);
    cout<<dpth;
    return 0;
}