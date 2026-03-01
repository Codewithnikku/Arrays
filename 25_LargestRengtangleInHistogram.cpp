/*
 * Problem Statement: Find the area of the largest rectangle in a histogram.
 * Algorithm: Monotonic Stack (Next Smaller Element)
 * Pseudocode:
 * 1. Find the index of the next smaller element to the right for each bar.
 * 2. Find the index of the next smaller element to the left for each bar.
 * 3. For each bar i, width of the largest rectangle using bar i as height is (right[i] - left[i] - 1).
 * 4. Area for bar i = heights[i] * width.
 * 5. Return the maximum area.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;



class LargestRectangleInHistogram
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Next smaller element to the right
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear stack
        while (!s.empty()) s.pop();

        // Previous smaller element to the left
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};

int main() {
    LargestRectangleInHistogram obj;
    vector<int> heights = {2,1,5,6,2,3};
    cout << obj.largestRectangleArea(heights) << endl;
    return 0;
}