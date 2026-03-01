/*
 * Problem Statement: Find the element that appears only once in an array where every other element appears twice.
 * Algorithm: Bitwise XOR
 * Pseudocode:
 * 1. Initialize result to 0.
 * 2. Traverse the array and XOR each element with the result.
 * 3. Return the result.
 */
#include <iostream>
#include <vector>
using namespace std;

class SingleNumber{
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};

int main(){
    SingleNumber sn;
    vector<int> nums = {4,1,2,1,2};
    cout << sn.singleNumber(nums) << endl;
    return 0;
}