/*
 * Problem Statement: Search for a target value in a sorted 2D matrix.
 * Algorithm: Binary Search on Virtual 1D Array
 * Pseudocode:
 * 1. Treat the m x n matrix as a sorted 1D array of size m*n.
 * 2. Set low = 0 and high = m*n - 1.
 * 3. While low <= high:
 *    a. Calculate mid index and map it back to 2D: row = mid / n, col = mid % n.
 *    b. Compare matrix[row][col] with target.
 *    c. If match, return true; else adjust low/high.
 * 4. Return false if not found.
 */
#include <iostream>
#include <vector>
using namespace std;

class SearchIn2DMatrix  {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    SearchIn2DMatrix obj;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << obj.searchMatrix(matrix, target) << endl;
    return 0;
}

/*
Leetcode: 74. Search a 2D Matrix
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 
Intuition:
    We need to search for a target value in a sorted 2D matrix.
    We can treat the matrix as a sorted 1D array and apply binary search.
    We need to map the mid index back to 2D coordinates to access the matrix elements.
    
Approach steps:
    Treat the matrix as a sorted 1D array of size m*n.
    Set low = 0 and high = m*n - 1.
    While low <= high:
        Calculate mid index and map it back to 2D: row = mid / n, col = mid % n.
        Compare matrix[row][col] with target.
        If match, return true; else adjust low/high.

        If matrix[row][col] < target, set low = mid + 1.
        Else, set high = mid - 1.
    Return false if not found.

    Complexity:
        - Time: O(log(m*n))
        - Space: O(1)
*/