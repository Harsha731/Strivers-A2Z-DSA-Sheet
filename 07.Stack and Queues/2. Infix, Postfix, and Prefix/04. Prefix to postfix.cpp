/*
QUESTION:
You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Example:
Input: 
*-A/BC-/AKL
Output: 
ABC/-AK/L-*
Explanation: 
The above output is its valid postfix form.

APPROACH:
- We can use a stack to convert the prefix expression to postfix.
- We iterate through each character of the input string in reverse order.
- If the character is an alphanumeric character, we push it onto the stack.
- If the character is an operator, we pop two operands from the stack, concatenate them with the operator, and push the result back onto the stack.
- After iterating through all characters, the top of the stack will contain the final postfix expression.

1 - start from end as operators opening mai honge
2 - if any operand then push in stack
+ab ko ab+
stack | b a + op1 op2 operator ;

CODE:
*/
string PREFIX_POSTFIX(const string& s) {
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; i--) {  // Iterate from the end
        char ch = s[i];
        if (isalnum(ch)) {  // Check if the character is alphanumeric
            st.push(string(1, ch));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + ch);  // Construct postfix expression
        }
    }

    return st.top();  // Return the final expression directly
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the preToPost function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operands.
*/
