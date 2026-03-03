/*
 * Problem Statement: Find the Majority Element (appears more than n/2 times).

 intuition:
    - If we cancel out each occurrence of an element e with all the other elements that are different from e, then e will exist until the end if it is a majority element.
Approach:
    - Initialize candidate (ans) and frequency (freq) to 0.
    - Traverse the array:
        - If freq is 0, set current element as candidate.
        - If current element equals candidate, increment freq.
        - Else, decrement freq.
    - Return the candidate (ans).

 * Algorithm: Moore's Voting Algorithm
 * Pseudocode:
 * 1. Initialize candidate (ans) and frequency (freq) to 0.
 * 2. Traverse the array:
 *    a. If freq is 0, set current element as candidate.
 *    b. If current element equals candidate, increment freq.
 *    c. Else, decrement freq.
 * 3. Return the candidate (ans).

 Given:
 arr = [2, 2, 1, 1, 1, 2, 2]
 output = 2
 * 1. The array is non-empty.
 * 2. The majority element always exists in the array.
 time complexity = O(n)
 space complexity = O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class MajorityElement
{
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

int main()
{
    MajorityElement me;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << me.majorityElement(nums) << endl;
    return 0;
}