/*
 * Problem Statement: Sort an array of 0s, 1s, and 2s (Dutch National Flag problem).
 * Algorithm: Counting Sort (Two-pass)
 * Pseudocode:
 * 1. Count the occurrences of 0, 1, and 2.
 * 2. Overwrite the array with the appropriate number of 0s, then 1s, and finally 2s.
 */
#include <iostream>
#include <vector>
using namespace std;

class SortColors {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) count0++;
            else if (nums[i] == 1) count1++;
            else count2++;
        }

        int idx = 0;
        for (int i = 0; i < count0; i++) {
            nums[idx++] = 0;
        }
        for (int i = 0; i < count1; i++) {
            nums[idx++] = 1;
        }
        for (int i = 0; i < count2; i++) {
            nums[idx++] = 2;
        }
    }
};

int main(){
    SortColors sc;
    vector<int> nums = {2,0,2,1,1,0};
    sc.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}