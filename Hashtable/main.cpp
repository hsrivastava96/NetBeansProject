#include<iostream>
using namespace std;
class Hash
{
public:
    int n, chain;
    char name[40], number[10];
    Hash(int x)
    {
        n=x;
        chain=-1;
        int i=0;
        while(i++<40)
            name='0';
        for(i=0; i<10; i++)
            number[i]='0';
    }
    int index(int key)
    {
        int index=0;
        index=key%n;
        return index;
    }
    void display()
    {
        
    }
};