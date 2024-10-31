/*
QUESTION:
Given an infix expression in the form of string str, convert it to a postfix expression.


_____________________________________________________________________

( ^ ) >  ( * , / )  > ( + , - )		=>  Precedence

Any expression like a + b ^ c - d / e
We do ^ and / first, so a + bc^ - de /
Then we do remaining, abc^+ de/-
We can observe that ^ is pushed first into answer instead of +

a ^ b + c - d / e
We do ^ first compared to +, so if the precedence is increasing we keep in the stack, else we pop out and add them to answer


CODE:
*/

int precedence(char ch) {
    if (ch == '^')    	return 3;
    if (ch == '*' || ch == '/')    	return 2;
    if (ch == '+' || ch == '-')    	return 1;
    return -1;
}

string INFIX_POSTFIX(const string &s) {
    stack<char> st;
    string ans;

    for (char ch : s) {
        if (isalnum(ch)) {  // check if alphanumeric
            ans += ch;
        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while (st.top() != '(') {
                ans += st.top(); st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                ans += st.top(); st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top(); st.pop();
    }

    return ans;
}


/*
COMPLEXITY ANALYSIS:
- The time complexity of the infixToPostfix function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operators.
*/
