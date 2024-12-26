// Given an integer, K. Generate all binary strings of size k without consecutive 1’s.

// Examples: 

// Input : K = 3  
// Output : 000 , 001 , 010 , 100 , 101 
// Input : K  = 4 
// Output :0000 0001 0010 0100 0101 1000 1001 1010

void generateBinaryStrings(int k, string str, vector<string> &result) {
    // Base case: If the size of the string is equal to k, add it to the result
    if (str.size() == k) {
        result.push_back(str);
        return;
    }

    // If the string ends with '1', we can only add '0'
    if (!str.empty() && str.back() == '1') {
        generateBinaryStrings(k, str + "0", result);
    } else {
        // If the string ends with '0', we can add both '0' and '1'
        generateBinaryStrings(k, str + "0", result);
        generateBinaryStrings(k, str + "1", result);
    }
}
