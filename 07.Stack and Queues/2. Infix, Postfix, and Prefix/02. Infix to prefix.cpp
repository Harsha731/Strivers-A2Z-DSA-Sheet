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

/*  IMPORTANT  
-> When Changing to <:
The change from <= to < would prevent operators with equal precedence from being popped.
Left-associative operators should not prevent other operators with the same precedence from being popped, 
because they need to process from left to right.
So, if you use <, only operators with strictly higher precedence will be popped, ensuring that we don't prematurely pop the same precedence operators.

-> For instance, when processing the expression a + b + c:
After encountering the first +, it will be pushed onto the stack.
When the second + is encountered, we need to pop the previous + (since + is left-associative) to ensure that the operators are placed in the correct order.

-> In this case:
The first + will be pushed onto the stack.
The second + will trigger the loop, and the first + will be popped from the stack before the second + is pushed.
*/

bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(const string& infix) {
    string output;
    stack<char> charStack;
    string expr = '(' + infix + ')';
    
    for (char c : expr) {
        if (isalnum(c)) {
            output += c;
        } else if (c == '(') {
            charStack.push(c);
        } else if (c == ')') {
            while (charStack.top() != '(') {
                output += charStack.top();
                charStack.pop();
            }
            charStack.pop();
        } else if (isOperator(c)) {
            // Handle the '^' operator separately
            if (c == '^') {
                while (!charStack.empty() && getPriority(c) <= getPriority(charStack.top())) {
                    output += charStack.top();
                    charStack.pop();
                }
            } else {
                // Handle the other operators ('+', '-', '*', '/')
                while (!charStack.empty() && getPriority(c) < getPriority(charStack.top())) {
                    output += charStack.top();
                    charStack.pop();
                }
            }
            charStack.push(c);
        }
    }

    while (!charStack.empty()) {
        output += charStack.top();
        charStack.pop();
    }

    return output;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    
    for (char& c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

/*
COMPLEXITY ANALYSIS:
- The time complexity of the infixToPostfix function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operators.
*/
