/*
QUESTION:
Given an infix expression in the form of string str. Convert this infix expression to prefix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -.

Example:
Input: str = "((A-(B/C))*((A/K)-L))"
Output: "*-A/BC-/AKL"
Explanation:
After converting the infix expression into prefix expression, the resultant expression will be *-A/BC-/AKL.

1-We reverse the string and change the brackets direction
2- Apply inifx to postfix with
3- One changed condition PRECEDENCE of ch < st.top()
4- Reverse the ans
CODE:
*/

string INFIX_PREFIX(string s) {
    reverse(s.begin(), s.end());
    for (char &ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    stack<char> st;
    string ans;

    for (char ch : s) {
        if (isalnum(ch)) {
            ans += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (st.top() != '(') {
                ans += st.top(); st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(ch) < precedence(st.top())) {
                ans += st.top(); st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


/*
COMPLEXITY ANALYSIS:
- The time complexity of the infixToPostfix function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operators.
*/
