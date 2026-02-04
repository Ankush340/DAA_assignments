#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int value, weight;
};
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(Item arr[], int n, int W) {
    sort(arr, arr + n, compare);
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    Item arr[n];
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].value >> arr[i].weight;
    }
    cout << "Enter knapsack capacity: ";
    cin >> W;
    cout << "Maximum value = "
         << fractionalKnapsack(arr, n, W);
    return 0;
}
