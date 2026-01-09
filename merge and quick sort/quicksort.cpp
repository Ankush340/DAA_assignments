#include<iostream>
using namespace std;
int partition(int A[],int p,int r)
{
	int x = A[r];
	int i= p-1;
	for (int j=p;j<r;j++)
	{
		if(A[j]<x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp2 = A[r];
	A[r] = A[i+1];
	A[i+1] = temp2;
	return (i+1);
}
void Quicksort(int A[],int p,int r)
{
	if(p<r){
		int q=partition(A,p,r);
		Quicksort(A,p,q-1);
		Quicksort(A,q+1,r);
	}
}
int main(){
	int A[9]={3,7,1,9,2,8,4,6,5};
	int size=sizeof(A)/sizeof(A[0]);
	Quicksort(A,0,size-1);
	for(int i=0;i<size;i++){
		cout<<A[i]<<",";
	}
}
