/*
QUESTION:-
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input:
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.


Example 2:

Input:
n = 5, arr1[] = {2, 2, 3, 4, 5}
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.
*/

/*
APPROACH:-
-> Take two pointer i and j where i is for arr1 and j is for arr2 and traverse
-> While travsersing 3 cases arises
    -> arr1[ i ] == arr2[ j ]
        Here we found a common element, so insert only one element in the union.
        Let’s insert arr[i] in union and whenever we insert element we increment pointer while pointer is not equal to the inserted element
    -> arr1[i]<arr2[j]
        Here insert arr[i]
    -> arr1[i]>arr2[j]
        Here insert arr2[j]
-> Now check if elements of any array is left to traverse then traverse that array
*/

// CODE:-

#include <vector>
using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;           // Pointers for arr1 and arr2
    vector<int> ans;            // Vector to store the union of arrays

    // Traverse both arrays
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) { // Case 1 and 2: arr1[i] is smaller or equal
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
        } else {                  // Case 3: arr2[j] is smaller
            if (ans.empty() || ans.back() != arr2[j]) {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    // Add remaining elements of arr1, if any
    while (i < n) {
        if (ans.empty() || ans.back() != arr1[i]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    // Add remaining elements of arr2, if any
    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}


// TIME COMPLEXITY = O(N+M)
// SPACE COMPLEXITY = O(0)
