#include<iostream>
using namespace std;
class file
{
    string filename[10],sfile;
    int sadd[10],siz[10],i,no;
public:
    void getval();
    void srch();
};
void file::getval()
{
    cout<<"enter total no of files"<<endl;
    cin>>no;
    for(i=0;i<no;i++)
    {
        cout<<"enter filename, starting address of block and size of file "<<endl;
        cin>>filename[i]>>sadd[i]>>siz[i];
    }
}
void file::srch()
{
    cout<<"Enter name of file you want to search"<<endl;
    cin>>sfile;
    for(i=0;i<no;i++)
    {
        if(filename[i]==sfile)
        {
            cout<<"filename  starting address of block   size of file"<<endl;
            cout<<filename[i]<<"\t\t"<<sadd[i]<<"\t\t\t"<<siz[i]<<endl;
        }
    }
}
int main()
{
    file S;
    S.getval();
    S.srch();
}
