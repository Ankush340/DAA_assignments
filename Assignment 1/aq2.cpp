#include <bits/stdc++.h>
using namespace std;
int maxGoodSubsequenceLength(vector<int>& a,int n) {
    sort(a.begin(),a.end());
    int left = 0;
    int maxLen = 1;
    for (int right = 0;right<n;right++) {
        while (a[right]-a[left] > 10) {
            left++;
        }
        maxLen = max(maxLen,right-left+1);
    }
    return maxLen;
}
int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>a(n);
    cout<<"Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = maxGoodSubsequenceLength(a, n);
    cout<<"Maximum length of good subsequence = "<<result;
    return 0;
}
