#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int remain = 0, start = 0, total = 0;
    for (int i = 0; i < gas.size(); ++i) {
        remain += gas[i] - cost[i];
        if (remain < 0) {
            remain = 0;
            start = i + 1;
        }
        total += gas[i] - cost[i];
    }
    if (total < 0) {
        return -1;
    } else {
        return start; 
    }
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5},
                cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
}