/*
 * Problem Statement: Find the maximum amount of water a container can store.
 * Algorithm: Two Pointers
 * Pseudocode:
 * 1. Initialize maxWater to 0, left pointer to 0, and right pointer to size-1.
 * 2. While left < right:
 *    a. Calculate area = min(height[left], height[right]) * (right - left).
 *    b. Update maxWater if current area is larger.
 *    c. Move the pointer pointing to the shorter height (if height[left] < height[right], left++, else right--).
 * 3. Return maxWater.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ContainerWithMostWater {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            if(height[left] < height[right]) {
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};

int main(){
    ContainerWithMostWater cwmw;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << cwmw.maxArea(height) << endl;
    return 0;
}