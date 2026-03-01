/*
 * Problem Statement: Set matrix zeroes. If an element is 0, set its entire row and column to 0.
 * Algorithm: In-place with Constant Space
 * Pseudocode:
 * 1. Use the first row and first column as flags to store which rows/cols should be zero.
 * 2. Handle first row and first column separately with two boolean variables.
 * 3. Traverse the rest of the matrix (1 to m, 1 to n) and set flags in the first row/col if an element is 0.
 * 4. Traverse again to set elements to 0 based on the flags.
 * 5. Finally, zero out the first row and first column if their respective boolean variables are true.
 */
#include <iostream>
#include <vector>
using namespace std;

class SetMatrixZeroes {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }  
        return;
    }
};

int main(){
    SetMatrixZeroes obj;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    obj.setZeroes(matrix);
    for (vector<int> row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}