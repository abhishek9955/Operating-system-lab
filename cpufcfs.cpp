//FIRST COME FIRST SERVE
#include<iostream>
using namespace std;
class scdl
{
    int no,pid[10],arrtm[10],burtm[10],waittm[10],i,tbs=0;float avgwt,wt=0;
public:
    void getval();
    void display();
    void waitcal();
    void avgwtcal();

};
void scdl::getval()
{
     cout<<"enter no. of processes"<<endl;
        cin>>no;
        for(i=0;i<no;i++)
        {
        pid[i]=i+1;
        cout<<"enter arrival time and burst time"<<endl;
        cin>>arrtm[i]>>burtm[i];
        }
}
void scdl::display()
{
    for(i=0;i<no;i++)
    {
    cout<<"the process id = "<<pid[i]<<" and arrival time = "<<arrtm[i]<<" and burst time = "<<burtm[i]<<" and waiting time = "<<waittm[i]<<endl;
}}
void scdl::waitcal()
{
    for(i=0;i<no;i++)
    {
        waittm[i]=tbs-arrtm[i];
        tbs=tbs+burtm[i];
    }
}
void scdl::avgwtcal()
{
    for(i=0;i<no;i++)
    {
        wt=wt+waittm[i];
    }
    avgwt=wt/no;
    cout<<"the average waiting time = "<<avgwt<<endl;
}
int main()
{
    scdl S;
    S.getval();
    S.waitcal();
    S.display();
    S.avgwtcal();
    return 0;
}
