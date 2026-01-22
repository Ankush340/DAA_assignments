#include<iostream>
using namespace std;
int binarysearch(int arr[],int start,int end,int target)
{
    while(start<=end){
       int mid=start+(end-start)/2;
       if(arr[mid]==target)
        return mid;
       if(arr[mid]<target)
        start=mid+1;
       else
        end=mid-1;
    }
    return -1;
}
int main()
{
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index = binarysearch(arr,0,size-1,23);
    if(index!=-1)
        cout<<"Found at "<<index;
    else 
        cout<<"Not Found";
}
