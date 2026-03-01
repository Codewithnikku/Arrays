/*
 * Problem Statement: Find all unique quadruplets in the array that sum up to a target value.
 * Algorithm: Sorting, Two-level Nesting, and Two Pointers with Pruning
 * Pseudocode:
 * 1. Sort the array.
 * 2. Nested loops with pointers i and j (to fix first two numbers).
 * 3. Use two pointers p and q for the remaining two numbers.
 * 4. Apply pruning (min/max checks) to skip unnecessary iterations.
 * 5. Skip duplicate elements at each level to ensure unique quadruplets.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Pruning for i
            long long min1 = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (min1 > target) break;
            long long max1 = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if (max1 < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Pruning for j
                long long min2 = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (min2 > target) break;
                long long max2 = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if (max2 < target) continue;

                int p = j + 1, q = n - 1;

                while (p < q) {
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target) p++;
                    else if (sum > target) q--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++; 
                        q--;

                        while (p < q && nums[p] == nums[p - 1]) p++;
                        while (p < q && nums[q] == nums[q + 1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    FourSum fs;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fs.fourSum(nums, target);
    for (const auto& quad : result) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}