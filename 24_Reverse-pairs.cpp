/*
 * Problem Statement: Count the number of reverse pairs (nums[i] > 2 * nums[j] for i < j).
 * Algorithm: Brute Force (Current) / Merge Sort based (Optimal)
 * Pseudocode:
 * 1. Initialize count ans to 0.
 * 2. Nested loops with i from 0 to n-1 and j from i+1 to n-1.
 * 3. If nums[i] > 2 * nums[j], increment ans.
 * 4. Return ans.
 */
#include <iostream>
#include <vector>
using namespace std;



class ReversePairs {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > 2 * nums[j]) ans++;
            }
        }
        return ans;
    }
};

int main() {
    ReversePairs obj;
    vector<int> nums = {1,3,2,3,1};
    cout << obj.reversePairs(nums) << endl;
    return 0;
}
