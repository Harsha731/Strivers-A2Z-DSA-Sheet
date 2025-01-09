/*
Number of greater elements to the right

Given an array of N integers and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly 
greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :

Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.

Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
Output:  [3, 0]
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.
*/

/*  Brute force
  Here, for every element, do calculate how many elements have more value than the element.
  TC : O(q*n), q is no. of queries
  SC : O(q)
*/

class Solution{
public:
    int nextGreaterElements(vector<int>& a, int index){
    int count = 0, N = a.size();

    for (int i = index + 1; i < N; i++) {
        if (a[i] > a[index])    count++;
    }
    return count;
    }

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> ans;
        for(int i = 0;i<queries;i++){
            ans.push_back(nextGreaterElements(arr,indices[i]));
        }
        return ans;
    }

};
_______________________________________

/*  Optimal
  Here, we keep inserting each element into multiset one by one and we use ipper_bound to know how many elements are more than this at each iteration
  So, logN for upper bound function
  We use multiset, as duplicate elements are also possible
  Also, the upper_bound fucntion can be used in it
  TC : O(NlogN + Q)
  SC : O(N)
*/

vector<int> count_NGE(int n, vector<int>& arr, int queries, vector<int>& indices) {
    multiset<int> st;
    vector<int> nges(n);

    for (int i = n - 1; i >= 0; i--) {
        auto it = st.upper_bound(arr[i]);

        // Count elements greater than arr[i] directly
        int count = 0;
        for (auto itr = it; itr != st.end(); itr++) {
            count++;
        }
        nges[i] = count;
        st.insert(arr[i]);
    }

    vector<int> ans;
    for (int i = 0; i < indices.size(); i++) {
        ans.push_back(nges[indices[i]]);
    }

    return ans;
}
