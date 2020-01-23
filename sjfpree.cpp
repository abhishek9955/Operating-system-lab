//SHORTEST JOB FIRST PREEMPTIVE
#include<iostream>
using namespace std;
class scdl
{
    int no,pid[10],arrtm[10],burtm[10],i,j,k,posi,exit[10],remt[10],tat[10],wt[10],arrmax;
public:
    void getval();
    void display();
    void srjf();
    void srjfdisplay();
    void swap(int &a,int &b);
    int getmax();
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
        remt[i]=burtm[i];
        }
}
void scdl::display()
{
     cout<<"process id\tarrival time\tburst time"<<endl;
    for(i=0;i<no;i++)
    {
    cout<<pid[i]<<"\t\t"<<arrtm[i]<<"\t\t"<<burtm[i]<<endl;
    }
}
void scdl::srjf()
{
arrmax=getmax();
int flag=0;
for(i=0;i<arrmax;i++)
{
	posi=flag;
for(j=flag+1;j<no;j++)
{
if(arrtm[j]<=i)
{
	if(remt[j]<remt[posi])
	posi=j;
}
}
remt[posi]=remt[posi]-1;
if(remt[posi]==0)	
{
	if(posi!=flag)
	{
	swap(pid[posi],pid[flag]);
	swap(arrtm[posi],arrtm[flag]);
	swap(burtm[posi],burtm[flag]);
	swap(remt[posi],remt[flag]);
    }
	exit[flag]=i+1;
	flag=flag+1;
}   
}
for(j=flag;j<=no;j++)
{
	posi=flag;
if(flag!=no)
{
	for(k=flag+1;k<no;k++)
	{
		if(remt[k]<remt[posi])
		posi=k;
	}
}
if(posi!=flag)
{
swap(pid[flag],pid[posi]);
swap(arrtm[flag],arrtm[posi]);
swap(burtm[flag],burtm[posi]);
swap(remt[flag],remt[posi]);
}
exit[flag]=i+remt[flag];
i=exit[flag];
remt[flag]=0;
flag=flag+1;
}
}
void scdl::srjfdisplay()
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
int scdl::getmax()
{
	int pos=0;
	for(i=1;i<no;i++)
	{
		if(arrtm[i]>arrtm[pos])
		pos=i;
	}
	return arrtm[pos];
}
int main()
{
    scdl S;
    S.getval();
    S.display();
    S.srjf();
    S.srjfdisplay();
    return 0;
}
