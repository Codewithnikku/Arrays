/*
 * Problem Statement: Merge two sorted arrays nums1 and nums2 into nums1.
 * 
 * intuition:
 *     - We can merge the two arrays in-place by using a three-pointer approach.
 *     - We start from the end of both arrays and compare the elements.
 *     - We place the larger element at the end of nums1 and decrement the corresponding pointer.
 *     - We continue this process until we have merged all elements from nums2 into nums1.
 * 
Approach:
    - Initialize three pointers:
        - i at the end of elements in nums1 (m-1).
        - j at the end of elements in nums2 (n-1).
        - idx at the end of nums1 (m+n-1).
    - Compare elements at i and j from end:
        - Place the larger element at nums1[idx] and decrement the corresponding pointer.
    - Copy any remaining elements from nums2 to nums1.

    complexity:
        - Time: O(m+n)
        - Space: O(1)

 * Algorithm: Three-pointer Merge (from end to start)
 * Pseudocode:
 * 1. Initialize three pointers:
 *    - i at the end of elements in nums1 (m-1).
 *    - j at the end of elements in nums2 (n-1).
 *    - idx at the end of nums1 (m+n-1).
 * 2. Compare elements at i and j from end:
 *    - Place the larger element at nums1[idx] and decrement the corresponding pointer.
 * 3. Copy any remaining elements from nums2 to nums1.
 */
#include <iostream>
#include <vector>
using namespace std;

class MergeSortedArray{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1;
        int i = m-1;
        int j = n-1;

        while(i>=0 && j>=0) {
            if(nums1[i]>nums2[j]){
                nums1[idx--] = nums1[i--];
            }
            else {
                nums1[idx--] = nums2[j--];
            }
        }
        while(j>=0) {
            nums1[idx--] = nums2[j--];
        }
    }
};

int main(){
    MergeSortedArray msa;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    msa.merge(nums1, 3, nums2, 3);
    for(int i=0; i<nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}