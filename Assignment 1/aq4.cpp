#include <iostream>
using namespace std;
int sequenceSpecialty(int arr[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool special = false;
        for (int start = 0; start < n; start++) {
            int count = 0;
            for (int end = start; end < n; end++) {
                if (arr[end] > arr[i]) count++;
                if (count == k) {
                    special = true;
                    break;
                }
            }
            if (special) break;
        }
        if (special) sum += arr[i];
    }
    return sum;
}
int main() {
    int arr[] = {3, 1, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << "Specialty of sequence: " << sequenceSpecialty(arr, n, k) << endl;
    return 0;
}
