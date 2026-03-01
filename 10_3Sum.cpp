/*
 * Problem Statement: Find all unique triplets in the array that sum up to zero.
 * Algorithm: Sorting and Two Pointers
 * Pseudocode:
 * 1. Sort the array.
 * 2. Traverse the array with pointer i:
 *    a. Skip duplicates of nums[i].
 *    b. Use two pointers, left = i + 1 and right = size - 1.
 *    c. While left < right:
 *       i. Calculate sum = nums[i] + nums[left] + nums[right].
 *       ii. If sum is zero, add to result, skip duplicates of nums[left] and nums[right], and move both pointers.
 *       iii. If sum < 0, increment left.
 *       iv. Else, decrement right.
 * 3. Return the result.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left;  
                    while (left < right && nums[right] == nums[right - 1]) --right; 
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};
int main(){
    ThreeSum ts;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = ts.threeSum(nums);
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}