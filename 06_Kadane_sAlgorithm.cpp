/*
 * Problem Statement: Find the maximum sum subarray (Kadane's Algorithm).
 * Algorithm: Dynamic Programming (One-pass)
 * Pseudocode:
 * 1. Initialize max_so_far and max_ending_here to the first element.
 * 2. Traverse from the second element:
 *    a. Update max_ending_here as max(current element, max_ending_here + current element).
 *    b. Update max_so_far as max(max_so_far, max_ending_here).
 * 3. Return max_so_far.
 */
#include <iostream>
#include <vector>
using namespace std;

class KadanesAlgorithm{
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_ending_here = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        return max_so_far;
    }
};

int main(){
    KadanesAlgorithm ka;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << ka.maxSubArray(nums) << endl;
    return 0;
}