#include <iostream>
#include <algorithm>
using namespace std;
struct Job {
    char id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}
void jobSequencing(Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    sort(jobs, jobs + n, compare);
    bool slot[maxDeadline + 1] = {false};
    char result[maxDeadline + 1];
    int totalProfit = 0, jobCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
        }
    }
    cout << "\nSelected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }
    cout << "\nNumber of jobs completed = " << jobCount;
    cout << "\nMaximum Profit = " << totalProfit;
}
int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    Job jobs[n];
    cout << "Enter job id, deadline and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    jobSequencing(jobs, n);
    return 0;
}
