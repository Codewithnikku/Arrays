/*
 * Problem Statement: Implement next permutation (lexicographically next).
 * Algorithm: Three-Step Single Pass
 * Pseudocode:
 * 1. Find the first decreasing element nums[i] from the end.
 * 2. If such i exists, find the first element nums[j] from the end such that nums[j] > nums[i].
 * 3. Swap nums[i] and nums[j].
 * 4. Reverse the subarray after index i (from i+1 to end).
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NextPermutation {
public:
     void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        while (i >=  0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap (nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main() {
    NextPermutation obj;
    vector<int> nums = {1, 2, 3};
    obj.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}