#include <iostream>
#include <climits>
using namespace std;
int maxSubArray(int nums[], int n) {
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];
        if (sum > maxSum)
            maxSum = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int nums[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int result = maxSubArray(nums, n);
    cout << "Maximum subarray sum is: " << result << endl;
    return 0;
}

