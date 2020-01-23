//Shortest job first
#include<iostream>
using namespace std;
class scdl
{
    int no,pid[10],arrtm[10],burtm[10],i,j,val,tbs[10];
public:
    void getval();
    void display();
    void sjfdisplay();
    void swap(int &a,int &b);
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
     cout<<"process id\tarrival time\tburst time"<<endl;
    for(i=0;i<no;i++)
    {
    cout<<pid[i]<<"\t\t"<<arrtm[i]<<"\t\t"<<burtm[i]<<endl;
    }
}
void scdl::sjfdisplay()
{tbs[0]=burtm[0];
	for(i=1;i<no-1;i++)
	{
	 val=i;
		for(j=i;j<no-1;j++)
		{
			if(arrtm[j+1]<=tbs[i-1]&&burtm[j+1]<burtm[j])
			{val=j+1;}
		}
		tbs[i]=tbs[i-1]+burtm[val];
		if(val!=i)
		{
		swap(pid[val],pid[i]);
		swap(arrtm[val],arrtm[i]);
		swap(burtm[val],burtm[i]);}
	}
    tbs[no-1]=tbs[no-2]+burtm[no-1];
    cout<<"process id\tarrival time\tburst time\ttotal burst time\tturn around time\twaiting time "<<endl;
    for(i=0;i<no;i++)
    {
    cout<<pid[i]<<"\t\t"<<arrtm[i]<<"\t\t"<<burtm[i]<<"\t\t"<<tbs[i]<<"\t\t\t"<<tbs[i]-arrtm[i]<<"\t\t\t"<<tbs[i]-arrtm[i]-burtm[i]<<endl;
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
    S.sjfdisplay();
    return 0;
}
