#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Job {
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void printJobScheduling(vector<Job>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), comparison);

    int maxDead = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].dead > maxDead)
            maxDead = arr[i].dead;
    }

    vector<int> result(maxDead + 1, -1);
    vector<char> jobSequence(maxDead + 1, ' ');
    int countJobs = 0, totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].dead; j > 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                jobSequence[j] = arr[i].id;
                countJobs++;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    cout << "\nNumber of jobs done: " << countJobs << endl;
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Job Sequence: ";
    for (int i = 1; i <= maxDead; i++) {
        if (jobSequence[i] != ' ')
            cout << jobSequence[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Job Sequencing with Deadlines" << endl;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> arr(n);
    cout << "Enter Job ID (char), Deadline (int), and Profit (int) for each job:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    printJobScheduling(arr);
    return 0;
}