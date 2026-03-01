/*
 * Problem Statement: Find the repeating and missing number in a given grid/array of size n*n containing elements from 1 to n*n.
 * Algorithm: Hash Set and Summation
 * Pseudocode:
 * 1. Initialize repeated and missing to -1.
 * 2. Calculate the expected sum of numbers from 1 to n*n using the formula: totalSum = (n^2 * (n^2 + 1)) / 2.
 * 3. Traverse the grid:
 *    a. Keep track of the actual sum of elements.
 *    b. Use a hash set to identify the repeated element.
 * 4. Calculate missing = totalSum - (actualSum - repeated).
 * 5. Return the repeated and missing numbers.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class RepeatAndMissingNumber {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeated = -1, missing = -1;

        int totalSum = n * n * (n * n + 1) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;
                if (seen.count(val)) repeated = val;
                else seen.insert(val);
            }
        }

        missing = totalSum - (actualSum - repeated);
        return {repeated, missing};
    }
};

int main(){
    RepeatAndMissingNumber rm;
    vector<vector<int>> grid = {
        {9, 1, 7},
        {8, 9, 2},
        {3, 4, 6} 
    };
    vector<int> result = rm.findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;

}