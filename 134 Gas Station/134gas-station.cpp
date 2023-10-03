class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                // If we run out of gas, reset and start from the next station
                currentGas = 0;
                startStation = i + 1;
            }
        }

        // If total gas is greater than or equal to total cost, a solution is possible
        if (totalGas >= totalCost) {
            return startStation;
        } else {
            return -1;
        }
    }
};