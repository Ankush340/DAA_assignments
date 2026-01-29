#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void removeFirstOccurrence(vector<int> &arr, int val) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == val) {
            arr.erase(arr.begin() + i);
            break;
        }
    }
}
int add(int x, int y) {
    return x + y;
}
int sumAfterMedianRemoval(vector<int> &A) {
    sort(A.begin(), A.end());
    while (A.size() > 2) {
        int medIndex = A.size() / 2;
        int med = A[medIndex];
        removeFirstOccurrence(A, med);
    }
    return add(A[0], A[1]);
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int result = sumAfterMedianRemoval(A);
    cout << "Sum of remaining elements = " << result << endl;
    return 0;
}
