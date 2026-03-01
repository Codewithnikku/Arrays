/*
 * Problem Statement: Find the total number of subarrays whose sum equals k.
 * Algorithm: Prefix Sum and Hash Map
 * Pseudocode:
 * 1. Initialize count = 0, currentSum = 0, and a hash map with {0: 1}.
 * 2. Traverse the array:
 *    a. Update currentSum by adding the current element.
 *    b. Check if currentSum - k exists in the hash map.
 *    c. If yes, add its frequency to the count.
 *    d. Increment frequency of currentSum in the map.
 * 3. Return the count.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SubArraySumEqualsK {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};

int main() {
    SubArraySumEqualsK obj;
    vector<int> nums = {1,2,3,4};
    int k = 5;
    cout << obj.subarraySum(nums, k) << endl;
    return 0;
}