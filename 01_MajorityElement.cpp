/*
 * Problem Statement: Find the Majority Element (appears more than n/2 times).
 * Algorithm: Moore's Voting Algorithm
 * Pseudocode:
 * 1. Initialize candidate (ans) and frequency (freq) to 0.
 * 2. Traverse the array:
 *    a. If freq is 0, set current element as candidate.
 *    b. If current element equals candidate, increment freq.
 *    c. Else, decrement freq.
 * 3. Return the candidate (ans).
 */
#include <iostream>
#include <vector>
using namespace std;

class MajorityElement
{
public:
    int majorityElement(vector<int> &nums)
    {
        int freq = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq == 0)
            {
                ans += nums[i];
            }
            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};

int main()
{
    MajorityElement me;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << me.majorityElement(nums) << endl;
    return 0;
}