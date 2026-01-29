#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& arr,int n,int m,int limit){
    int count = 1;
    int value = 0;
    for (int i=0; i< n;i++) {
        if ((value|arr[i])<=limit) {
            value|=arr[i];
        } else {
            count++;
            value=arr[i];
        }
    }
    return count<=m;
}
int findMinMaxOR(vector<int>& arr, int n, int m) {
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        low = max(low, arr[i]);
        high |= arr[i];
    }
    int answer = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, n, m, mid)) {
            answer = mid;
            high = mid - 1;
        } 
		else 
            low = mid + 1;
    }
    return answer;
}
int main() {
    int n, m;
    cout<<"Enter values of n and m "<<endl;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findMinMaxOR(arr, n, m);
    return 0;
}
