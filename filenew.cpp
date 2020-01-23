#include<iostream>
using namespace std;
class file
{
    string filename;
    int sadd,siz;
public:
    void getval();
    void display();
    friend void srch(file f,string nam);
};
void file::getval()
{
        cout<<"enter filename, starting address of block and size of file "<<endl;
        cin>>filename>>sadd>>siz;
}
void file::display()
{
    cout<<"filename  starting address of block   size of file"<<endl;
            cout<<filename<<"\t\t"<<sadd<<"\t\t\t"<<siz<<endl;
}
void srch(file f,string name)
{
     if(f.filename==name)
        {
            f.display();
        }
}

int main()
{
    int no,i;
    string sfile;
    cout<<"enter total no of files"<<endl;
    cin>>no;
    file S[no];
    for(i=0;i<no;i++)
    {S[i].getval();}
    cout<<"Enter name of file you want to search"<<endl;
    cin>>sfile;
    for(i=0;i<no;i++)
    {
        srch(S[i],sfile);
    }
    return 0;
}
