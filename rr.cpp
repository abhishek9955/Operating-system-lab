//Round Robin
#include<iostream>
using namespace std;
class scdl
{
    int no,pid[10],arrtm[10],burtm[10],i,j,k,posi,tq,exit[10],remt[10],tat[10],wt[10];
	int tbs;
public:
    void getval();
    void display();
    void rr();
    void rrdisplay();
    void swap(int &a,int &b);
};
void scdl::getval()
{
     cout<<"enter no. of processes"<<endl;
        cin>>no;
        tbs=0;
        for(i=0;i<no;i++)
        {
        pid[i]=i+1;
        cout<<"enter arrival time and burst time"<<endl;
        cin>>arrtm[i]>>burtm[i];
        remt[i]=burtm[i];
        tbs=tbs+burtm[i];
        exit[i]=arrtm[i];
        }
        cout<<"enter time quantum "<<endl;
        cin>>tq;
}
void scdl::display()
{
     cout<<"process id\tarrival time\tburst time"<<endl;
    for(i=0;i<no;i++)
    {
    cout<<pid[i]<<"\t\t"<<arrtm[i]<<"\t\t"<<burtm[i]<<endl;
    }
}
void scdl::rr()
{
	int flag=0;
	i=0;
	while(i<tbs)
	{
		posi=flag;
		for(j=flag;j<no;j++)
		{
			if(exit[j]<=exit[posi])
			{
				posi=j;
			}
		}
		if(remt[posi]>tq)
				{
					remt[posi]=remt[posi]-tq;
					i=i+tq;
					exit[posi]=i;
					
				}
				else
				{
				i=i+remt[posi];
				remt[posi]=0;
				exit[posi]=i;
				if(posi!=flag)
				{
					swap(pid[posi],pid[flag]);
						swap(arrtm[posi],arrtm[flag]);
						swap(burtm[posi],burtm[flag]);
						swap(remt[posi],remt[flag]);
						swap(exit[posi],exit[flag]);
				}
				flag=flag+1;	
				}
	}
}
void scdl::rrdisplay()
{
	cout<<"process id  arrival time  burst time  exit time  turn around time  waiting time "<<endl;
    for(i=0;i<no;i++)
    {
    cout<<pid[i]<<"\t\t"<<arrtm[i]<<"\t\t"<<burtm[i]<<"\t"<<exit[i]<<"\t\t"<<exit[i]-arrtm[i]<<"\t\t"<<exit[i]-arrtm[i]-burtm[i]<<endl;
    }
}
void scdl::swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
    scdl S;
    S.getval();
    S.display();
    S.rr();
    S.rrdisplay();
    return 0;
}
