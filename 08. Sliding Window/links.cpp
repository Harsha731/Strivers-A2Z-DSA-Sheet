// https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template!

// https://leetcode.com/problems/count-vowel-substrings-of-a-string/solutions/1563765/C++-O(N)-Time-Sliding-Window-+-"At-Most-to-Equal"-trick


// (Shrinkable)
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[i]
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;

// ** There must be a maximum window of size `j - i`. and not 'j-i+1'
// ** Write int j at start and not in the for loop
// ** Use erase(nums[i]) when we got 0 after subtractions
// ** In some problems, we need to add i<j or i<=j in inside while loop of shrinkable approach

// (Non-shrinkable)
int i = 0, j = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    if (invalid()) { // Increment the left edge ONLY when the window is invalid. In this way, the window GROWs when it's valid, and SHIFTs when it's invalid
        // CODE: update state using A[i]
        ++i;
    }
    // after `++j` in the for loop, this window `[i, j)` of length `j - i` MIGHT be valid.
}
return j - i; // There must be a maximum window of size `j - i`. and not 'j-i+1'
// Write int j at start and not in the for loop

// Here, we don't use 2 for loops instead one for loop is enough and it actually saves TC

// sum -= A[i++];
// This helps a lot, as we are able to write 2 lines in 1 line as well, regarding TC both are same