/*
 * Problem Statement: Merge overlapping intervals.
 * Algorithm: Sorting and Merging
 * Pseudocode:
 * 1. Sort the intervals based on start times.
 * 2. Push the first interval to mergedIntervals.
 * 3. Traverse from the second interval:
 *    a. If current interval overlaps with the last in mergedIntervals (start <= end), update the end time of the last interval.
 *    b. Else, push current interval to mergedIntervals.
 * 4. Return mergedIntervals.
 */
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MergeIntervals {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0)
      return mergedIntervals;
    sort(intervals.begin(), intervals.end());
    mergedIntervals.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (mergedIntervals.back()[1] >= intervals[i][0]) {
        mergedIntervals.back()[1] =
            max(mergedIntervals.back()[1], intervals[i][1]);
      } else {
        mergedIntervals.push_back(intervals[i]);
      }
    }
    return mergedIntervals;
  }
};

int main() {
  MergeIntervals obj;
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> mergedIntervals = obj.merge(intervals);
  for (vector<int> interval : mergedIntervals) {
    cout << interval[0] << " " << interval[1] << endl;
  }
  return 0;
}


/*
Leetcode: 56. Merge Intervals
Write a function to merge overlapping intervals.

Intuition:
We need to merge overlapping intervals.
If an interval overlaps with the last merged interval, we need to update the end time of the last merged interval.
If an interval does not overlap with the last merged interval, we need to add it to the merged intervals.


Approach:
    Sort the intervals based on start times.
    Push the first interval to mergedIntervals.
    Traverse from the second interval:
        If current interval overlaps with the last in mergedIntervals (start <= end), update the end time of the last interval.
        Else, push current interval to mergedIntervals.
    Return mergedIntervals.

    Complexity:
        - Time: O(nlogn)
        - Space: O(n)3
*/