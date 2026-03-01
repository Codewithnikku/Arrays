/*
 * Problem Statement: Find the length of the longest substring without repeating characters.
 * Algorithm: Sliding Window (Two Pointers) with Hash Map
 * Pseudocode:
 * 1. Initialize left pointer to 0 and maxLen to 0.
 * 2. Use a charMap to store the last seen index of each character.
 * 3. Traverse the string with right pointer:
 *    a. If current character was seen and its index is within current window, move left to seen_index + 1.
 *    b. Update character's last seen index.
 *    c. Update maxLen as max(maxLen, current window size).
 * 4. Return maxLen.
 */
#include <iostream>
using namespace std;
#include <vector>

class LongestSubstringWithoutrepeating {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        vector<int> charMap(128, -1);
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (charMap[s[right]] != -1) {
                left = max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main(){
    LongestSubstringWithoutrepeating obj;
    string s = "abcabcbb";
    cout << obj.lengthOfLongestSubstring(s) << endl;
    return 0;
}