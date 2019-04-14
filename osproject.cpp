#include<iostream> 
#include<windows.h>
#define max 10000000
using namespace std;
int main()
{
	int n,i,j,k,temp,temp2,total,count=0,avgW=0,avgT=0;
	cout<<"ENTER THE NUMBER OF THE PROCESS-: "<<endl<<endl;
	cin>>n;
	int p[n],at[n],bt[n];
	int wt[n+1]={0};
	int tt[n+1]={0};
	int r[n]={0};
	cout<<"\t\tARRIVAL TIME-:\n";
	for(i=0;i<n;i++)
	{
		cout<<"\tP"<<i+1<<"\t";
		cin>>at[i];
		p[i]=i+1;
	}
	cout<<"\t\tBURST TIME-:\n";
		for(i=0;i<n;i++)
	{
		cout<<"\tP"<<i+1<<"\t";
		cin>>bt[i];
		p[i]=i+1;
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(at[j]>at[j+1])
			{
				int c=at[j];
				at[j]=at[j+1];
				at[j+1]=c;
				c=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=c;
				c=p[j];
				p[j]=p[j+1];
				p[j+1]=c;
			}
		}
	}
	for(i=0;i<n;i++)
	{ 
		Sleep(2500);
		if(at[i]==0)
		{
			cout<<"DISCARD PROCESS"<<p[i]<<endl<<endl;
		}
		else
		{
			
			cout<<"\tP"<<p[i]<<"\t-->\t";
			
		}
	}
	cout<<endl;
	
	cout<<"PROCESS\tARRIVAL TIME\tBURST TIME"<<endl<<endl;
	
	for(i=0;i<n;i++)
	{
		Sleep(1500);
		cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t\t"<<bt[i]<<endl<<endl;;
	}
	
	
	for(i=0;i<n;i++)
	{
		if(at[i]!=0)
		break;
		wt[p[i]]=-1;
		count++;
	}
	k=count;
	for(total=1;n-count>0;)
	{
		for(i=k;i<n;i++)
		{
			if(at[i]>total)
			{
				total++;
				i=i-1;
				continue;
			}
			temp=max;temp2=i;
			for(j=i;j<n && at[j]<=total;j++)
			{
				if(bt[j]<temp&&r[j]!=1)
				{
					temp=bt[j];
					temp2=j;
				}
			}
			wt[p[temp2]]=total-at[temp2];
			tt[p[temp2]]=wt[p[temp2]]+temp;
			total=total+bt[temp2]+2;
			r[temp2]=1;
			count++;
			break;
		}
	}
	
	cout<<"PROCESS\tWAITING TIME\t TURNAROUND TIME\n\n";
	
	for(i=1;i<=n;i++)
	{
		if(wt[i]==-1)
		cout<<"P"<<i<<"\t"<<"DISCARD"<<"\t\t"<<"DISCARD"<<endl<<endl;
		else
		{
			cout<<"P"<<i<<"\t"<<wt[i]<<"\t\t"<<tt[i]<<endl<<endl;;
			avgW+=wt[i];avgT+=tt[i];
		}
		
	}
	
	cout<<"\tAVERAGE WAITING TIME-:\t";
	cout<<(avgW*1.0)/(n-k)<<endl<<endl;
	
	cout<<"\tAVERAGE TURNAROUNG TIME-:\t";
	cout<<(avgT*1.0/(n-k))<<endl;
	
	return 0;
}
