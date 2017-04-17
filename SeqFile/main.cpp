#include<iostream>
#include<fstream>
using namespace std;
class SQF
{
public:
    int roll;
    char address[40], name[40];
    void accept()
    {
        cout<<"Name --> ";
        cin>>name;
        cout<<"Roll no. --> ";
        cin>>roll;
        cout<<"Address --> ";
        cin>>address;        
    }
    int getroll()
    {
        return roll;
    }
}ob;
void add(int n)
{
    SQF st[n];
    int i=0;
    fstream file1;
    file1.open("f1.txt", ios::in|ios::out|ios::app);
    while(i<n)
    {
        st[i].accept();
        file1.write((char*)&st[i], sizeof(st[i]));
        i++;
    }
    file1.close();
}
void display()
{
    fstream file1;
    file1.open("f1.txt", ios::in|ios::out);
    while(file1.read((char*)&ob,sizeof(ob)))
        cout<<ob.name<<"\t"<<ob.roll<<"\t"<<ob.address<<endl;
    file1.close();
}
void del()
{
    int n;
    cout<<"Please enter the roll no. to be deleted --> ";
    cin>>n;
    fstream file1, file2;
    file1.open("f1.txt", ios::in);
    file2.open("f2.txt", ios::out);
    while(file1.read((char*)&ob, sizeof(ob)))
    {
        if(ob.getroll()!=n)
            file2.write((char*)&ob, sizeof(ob));
    }
    file1.close();
    file2.close();
    file1.open("f1.txt", ios::out);
    file2.open("f2.txt", ios::in);    
    while(file2.read((char*)&ob, sizeof(ob)))
        file1.write((char*)&ob, sizeof(ob));
    file1.close();
    file2.close();
}
int main()
{
    //add(3);
    display();
    del();
    display();
    return 0;
}