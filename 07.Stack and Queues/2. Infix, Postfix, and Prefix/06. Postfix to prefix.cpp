/*
QUESTION:
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Example:
Input: 
ABC/-AK/L-*
Output: 
*-A/BC-/AKL
Explanation: 
The above output is its valid prefix form.

APPROACH:
- We can use a stack to convert the postfix expression to prefix.
- We iterate through each character of the input string.
- If the character is an alphanumeric character, we push it onto the stack.
- If the character is an operator, we pop two operands from the stack, concatenate them with the operator in the proper order (operator + operand2 + operand1), and push the result back onto the stack.
- After iterating through all characters, the top of the stack will contain the final prefix expression.

1 - start from beginning as operators end mai honge
2 - if any operand then push it into stack
ab+ ko +ab
stack | a b + operator op2 op1

CODE:
*/

string POSTFIX_PREFIX(const string& s) {
    stack<string> st;

    for (char ch : s) {  // Use range-based for loop for clarity
        if (isalnum(ch)) {  // Check if the character is alphanumeric
            st.push(string(1, ch));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(ch + op2 + op1);  // Construct prefix expression
        }
    }

    return st.top();
}


/*
COMPLEXITY ANALYSIS:
- The time complexity of the postToPre function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operands.
*/
