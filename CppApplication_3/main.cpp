/******************************************************************************/
/*ASSIGNMENT 2: IMPLEMENTATION OF PRIORITY QUEUE*/
/*NAME: HARSHIT SRIVASTAVA */
/*ROLL no.: 2326*/
/******************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
struct Prio
{
	char name[40];
	int priority;
	struct Prio *next;
};
typedef struct Prio node;
class Queue
{
	public:
	node *head;
	Queue()
	{
		head=NULL;
	}
	void push()
	{
            int n, t=0, K=0;        //Here n is for newnode, t is for swapping priorities and K is used as a flag to come out of the loop
            char chtmp[40];
            do
            {
                cout<<"\n\tPRIORITIES\nSERIOUS CASE --> '1'\nMEDIUM ILLNESS --> '2'\nGENERAL --> '3'\n";
                node *newnode, *ptemp;
                newnode=new node;
                cout<<"Patient Name --> ";
                cin>>newnode->name;
                cout<<"Priority --> ";
                cin>>newnode->priority;
                if(head==NULL)
                    head=newnode;
                else
                {
                    if(newnode->priority<head->priority)    //Condition to insert node at the head
                    {
                        t=head->priority;
                        head->priority=newnode->priority;
                        newnode->priority=t;
                        strcpy(chtmp, head->name);
                        strcpy(head->name, newnode->name);
                        strcpy(newnode->name, chtmp);
                        newnode->next=head->next;
                        head->next=newnode;
                    }
                    else
                    {
                        while(ptemp->next!=NULL&&K!=1)  //Condition to insert node in between
                        {
                            if(newnode->priority<ptemp->priority)
                            {
                                K=1;
                                t=ptemp->priority;
                                ptemp->priority=newnode->priority;
                                newnode->priority=t;
                                strcpy(chtmp, ptemp->name);
                                strcpy(ptemp->name, newnode->name);
                                strcpy(newnode->name, chtmp);
                                newnode->next=ptemp->next;
                                ptemp->next=newnode;
                            }
                            ptemp=ptemp->next;
                        }
                        if(ptemp->next==NULL)   //Condition to insert node at the end
                        {
                            ptemp->next=newnode;
                            newnode->next=NULL;
                        }
                    }
                }
                ptemp=head;
                cout<<"Continue with a new entry? 1(YES) or 0(NO) --> ";
                cin>>n;
            }
            while(n==1);
	}
        void pop()
        {
            node *temp;
            temp=head;
            cout<<"Patient Name --> "<<temp->name<<"Priority --> "<<temp->priority<<endl;
            head=head->next;
            delete(temp);
        }
        void gettop()
        {
            cout<<"Patient Name --> "<<head->name<<"Priority --> "<<head->priority<<endl;
        }
	void display()
	{
		node *temp;
                temp=head;
		while(temp!=NULL)
                {
                    cout<<temp->name<<"\t"<<temp->priority<<endl;
                    temp=temp->next;
                }
	}
};
int main()
{
    Queue ob;
    int ch, n;
    do
    {
        cout<<"\n\t*****MENU*****\n1). Push\n2). Pop\n3). Display\n4). Gettop\nPlease Enter your choice --> ";
        cin>>ch;
        if(ch==1)
        ob.push();
        else if(ch==2)
        ob.pop();
        else if(ch==3)
        ob.display();
        else if(ch==4)
        ob.gettop();
        else
            cout<<"\n\t************INVALID INPUT!!!************\n";
        cout<<"\tDo you want to continue?\n\tIf YES Press 1 if NO Press 0 --> ";
        cin>>n;
    }
    while(n==1);
}
/*       *****MENU*****
1). Push
2). Pop
3). Display
4). Gettop
Please Enter your choice --> 1

        PRIORITIES
SERIOUS CASE --> '1'
MEDIUM ILLNESS --> '2'
GENERAL --> '3'
Patient Name --> Harshit
Priority --> 3
Continue with a new entry? 1(YES) or 0(NO) --> 1

        PRIORITIES
SERIOUS CASE --> '1'
MEDIUM ILLNESS --> '2'
GENERAL --> '3'
Patient Name --> Asif
Priority --> 3
Continue with a new entry? 1(YES) or 0(NO) --> 1

        PRIORITIES
SERIOUS CASE --> '1'
MEDIUM ILLNESS --> '2'
GENERAL --> '3'
Patient Name --> Abhash
Priority --> 1
Continue with a new entry? 1(YES) or 0(NO) --> 1

        PRIORITIES
SERIOUS CASE --> '1'
MEDIUM ILLNESS --> '2'
GENERAL --> '3'
Patient Name --> Nelson
Priority --> 2
Continue with a new entry? 1(YES) or 0(NO) --> 0
        Do you want to continue?
        If YES Press 1 if NO Press 0 --> 1

        *****MENU*****
1). Push
2). Pop
3). Display
4). Gettop
Please Enter your choice --> 3
Abhash  1
Nelson  2
Harshit 3
Asif    3
        Do you want to continue?
        If YES Press 1 if NO Press 0 --> 1

        *****MENU*****
1). Push
2). Pop
3). Display
4). Gettop
Please Enter your choice --> 2
Patient Name --> AbhashPriority --> 1
        Do you want to continue?
        If YES Press 1 if NO Press 0 --> 1

        *****MENU*****
1). Push
2). Pop
3). Display
4). Gettop
Please Enter your choice --> 3
Nelson  2
Harshit 3
Asif    3
        Do you want to continue?
        If YES Press 1 if NO Press 0 --> 1

        *****MENU*****
1). Push
2). Pop
3). Display
4). Gettop
Please Enter your choice --> 4
Patient Name --> NelsonPriority --> 2
        Do you want to continue?
        If YES Press 1 if NO Press 0 --> 0

RUN FINISHED; exit value 0; real time: 1m 36s; user: 0ms; system: 0ms*/