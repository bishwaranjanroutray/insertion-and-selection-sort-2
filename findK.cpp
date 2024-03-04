// Given an array, arr[] containing n integers, the task is to find an integer (say K) such that after
// replacing each and every index of the array by |ai – K| where ( i ∈ [1, n]), results in a sorted
// array. If no such integer exists that satisfies the above condition then return -1.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findInteger(vector<int>& arr) {
    int n = arr.size();
    int max_diff = INT_MIN;
    int min_diff = INT_MAX;
    
    // Find the maximum and minimum differences
    for (int i = 0; i < n; ++i) {
        max_diff = max(max_diff, arr[i]);
        min_diff = min(min_diff, arr[i]);
    }
    
    // Check if there is a possible K value
    for (int k = min_diff; k <= max_diff; ++k) {
        vector<int> sorted_arr(n);
        for (int i = 0; i < n; ++i) {
            sorted_arr[i] = abs(arr[i] - k);
        }
        // Check if the array is sorted
        if (is_sorted(sorted_arr.begin(), sorted_arr.end())) {
            return k;
        }
    }
    
    // If no such integer exists
    return -1;
}

int main() {
    // Example usage
    vector<int> arr = {10,5,4,3,2,1};
    int result = findInteger(arr);
    
    if (result != -1) {
        cout << "The integer K is: " << result << endl;
    } else {
        cout << "No such integer exists." << endl;
    }
    
    return 0;
}
