class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Sort asteroids in ascending order
        sort(asteroids.begin(), asteroids.end());
        
        // Use long long to prevent integer overflow
        long long currentMass = mass; 
        
        for (int asteroid : asteroids) {
            if (currentMass < asteroid) {
                return false;
            }
            currentMass += asteroid;
        }
        
        return true;
    }
};
