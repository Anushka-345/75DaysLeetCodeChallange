#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks by the difference (minimum - actual) in descending order
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int currentEnergy = 0;
        int initialEnergy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If we don't have enough energy to start this task
            if (currentEnergy < minimum) {
                // Increase initial energy by the exact deficit
                initialEnergy += (minimum - currentEnergy);
                // After increasing, we have exactly the 'minimum' required
                currentEnergy = minimum;
            }
            
            // Perform the task and subtract the actual energy spent
            currentEnergy -= actual;
        }

        return initialEnergy;
    }
};