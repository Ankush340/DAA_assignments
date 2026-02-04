#include <iostream>
#include <algorithm>
using namespace std;
int minPlatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}
int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;
    int arr[n], dep[n];
    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter departure times:\n";
    for (int i = 0; i < n; i++)
        cin >> dep[i];
    cout << "Minimum platforms required = "
         << minPlatforms(arr, dep, n);
    return 0;
}
