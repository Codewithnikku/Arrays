/*
 * Problem Statement: Find the maximum element in each sliding window of size k.
 * Algorithm: Monotonic Deque
 * Pseudocode:
 * 1. Initialize a deque to store indices and a result vector.
 * 2. Traverse the array:
 *    a. Remove index from front if it's out of the current window (front == i - k).
 *    b. While deque is not empty and nums[back] is smaller than current element, pop from back (to maintain decreasing order).
 *    c. Push current index to back.
 *    d. If current index is at least k-1, add nums[front] to result.
 * 3. Return result.
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;



class SlidingWindowMaximum {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {
    SlidingWindowMaximum obj;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = obj.maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}