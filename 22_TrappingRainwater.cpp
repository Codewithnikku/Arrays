/*
 * Problem Statement: Calculate how much rainwater can be trapped between bars.
 * Algorithm: Precomputed Left and Right Maxima
 * Pseudocode:
 * 1. Initialize LeftMax and RightMax arrays.
 * 2. Precompute LeftMax[i] as the max height from 0 to i.
 * 3. Precompute RightMax[i] as the max height from i to n-1.
 * 4. For each bar i, water trapped = min(LeftMax[i], RightMax[i]) - height[i].
 * 5. Sum the water trapped for all bars.
 */
#include <iostream>
#include <vector>
using namespace std;



class TrappingRainwater {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> LeftMax(n), RightMax(n);

        LeftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            LeftMax[i] = max(LeftMax[i - 1], height[i]);
        }

        RightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            RightMax[i] = max(RightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(LeftMax[i], RightMax[i]) - height[i];
        }

        return ans;
    }
};

int main() {
    TrappingRainwater obj;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << obj.trap(height) << endl;
    return 0;
}