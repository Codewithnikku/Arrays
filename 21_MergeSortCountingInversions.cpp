/*
 * Problem Statement: Count the number of inversions in an array.
 * Algorithm: Merge Sort based counting
 * Pseudocode:
 * 1. Use the merge sort framework to divide the array into halves.
 * 2. In the merge step, when an element from the right half is smaller than an element from the left half:
 *    a. It forms inversions with all remaining elements in the left half (mid - i + 1).
 * 3. Recursively sum the inversions from left half, right half, and the merge step.
 * 4. Return the total count.
 */
#include <bits/stdc++.h>

using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    long long count = 0;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);
        count += merge(arr, temp, left, mid, right);
    }
    return count;
}

long long countInversions(vector<int> arr) {
    if (arr.empty()) return 0;
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char* output_path = getenv("OUTPUT_PATH");
    ostream *fout_ptr;
    ofstream fout_file;

    if (output_path) {
        fout_file.open(output_path);
        fout_ptr = &fout_file;
    } else {
        fout_ptr = &cout;
    }

    ostream &fout = *fout_ptr;

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        if (!(cin >> n)) break;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long result = countInversions(arr);
        fout << result << "\n";
    }

    if (output_path) {
        fout_file.close();
    }

    return 0;
}
