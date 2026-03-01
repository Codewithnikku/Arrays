/*
 * Problem Statement: Find the duplicate number in an array of size n+1 with elements from 1 to n.
 * Algorithm: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
 * Pseudocode:
 * 1. Initialize slow and fast pointers to the first element.
 * 2. Find the meeting point inside the cycle:
 *    a. Move slow one step and fast two steps until they meet.
 * 3. Find the entrance to the cycle (the duplicate number):
 *    a. Reset fast pointer to the start.
 *    b. Move both pointers one step at a time until they meet.
 * 4. Return the meeting point.
 */
#include <iostream>
#include <vector>
using namespace std;

class FindDuplicates {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main(){
    FindDuplicates obj;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,10};
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}