#include<iostream>
using namespace std;
int partition(int A[],int p,int r)
{
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(A[j]<x)
		{
			i++;
			int temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
		
	}
	int a=A[r];
	A[r]=A[i + 1];
	A[i + 1]=a;
	return i+1;
}
void quicksort(int A[],int p,int r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}
int main()
{
	int A[]={4,2,6,9,2};
	int n=sizeof(A)/sizeof(A[0]);
	quicksort(A,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}
