/*
 * Problem Statement: Calculate product of array except self for each element without using division.
 * Algorithm: Prefix and Suffix Products
 * Pseudocode:
 * 1. Initialize result array ans with 1s.
 * 2. Calculate prefix products: for each i, ans[i] = product of all elements before i.
 * 3. Use a suffix variable (initially 1) and traverse backwards:
 *    a. Multiply ans[i] by suffix.
 *    b. Update suffix by multiplying it with nums[i].
 * 4. Return ans.
 */
#include <iostream>
#include <vector>
using namespace std;

class ProductOfArrayExceptItself {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix product
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main(){
    ProductOfArrayExceptItself obj;     
    vector<int> nums = {1,2,3,4};
    vector<int> ans = obj.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}