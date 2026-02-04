#include <iostream>
#include <algorithm>
using namespace std;
struct Activity {
    int start, finish;
};
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}
void activitySelection(Activity arr[], int n) {
    sort(arr, arr + n, compare);
    cout << "\nSelected activities:\n";
    int count = 1;
    int lastFinish = arr[0].finish;
    cout << "(" << arr[0].start << ", " << arr[0].finish << ")\n";
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";
            lastFinish = arr[i].finish;
            count++;
        }
    }
    cout << "Maximum activities = " << count << endl;
}
int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    Activity arr[n];
    cout << "Enter start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }
    activitySelection(arr, n);
    return 0;
}
