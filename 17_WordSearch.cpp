/*
 * Problem Statement: Check if a word exists in a 2D board of characters.
 * Algorithm: Depth First Search (DFS) with Backtracking
 * Pseudocode:
 * 1. Traverse each cell in the board.
 * 2. If the current cell matches the first character of the word, start DFS:
 *    a. If index k matches word length, return true.
 *    b. Check boundary conditions and if board[i][j] matches word[k].
 *    c. Temporarily mark the cell as visited (e.g., using '#').
 *    d. Recursively call DFS for all four adjacent directions (up, down, left, right).
 *    e. Backtrack by restoring the original character in the cell.
 * 3. Return false if no path is found.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size()) return true;

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board, word, i+1, j, k+1) ||
                     dfs(board, word, i-1, j, k+1) ||
                     dfs(board, word, i, j+1, k+1) ||
                     dfs(board, word, i, j-1, k+1);

        board[i][j] = temp;

        return found;
    }
};

int main(){
    WordSearch obj;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << obj.exist(board, word) << endl;
    word = "SEE";
    cout << obj.exist(board, word) << endl;
    word = "ABCB";
    cout << obj.exist(board, word) << endl;
    return 0;
}