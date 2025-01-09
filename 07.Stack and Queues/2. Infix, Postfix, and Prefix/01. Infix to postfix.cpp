/*
QUESTION:
Given an infix expression in the form of string str, convert it to a postfix expression.

1-If we get any char then we straight up insert as all +- symbols go at the end
2-IF we get any opening bracket then we insert it
3-If we get any closing bracket we pop all the bw of opening and closing bracket
4-If we encounter any operators then we see the precedence and
if PRECEDENCE of ch <= st.top() then we pop else insert
example * < + this is not true hence stack + *
example + < * this is true hence stack +
5- While stack is not empty empty the stack and get the ans

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

int prec(char c) {
  if (c == '^') return 3;
  if (c == '/' || c == '*') return 2;
  if (c == '+' || c == '-') return 1;
  return -1;
}

void infixToPostfix(string s) {
  stack<char> st;
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    if (isalnum(c)) {
      result += c;
    } else if (c == '(') {
      st.push('(');
    } else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    } else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Prefix expression: " << result << endl;
}


/*
COMPLEXITY ANALYSIS:
- The time complexity of the infixToPostfix function is O(N), where N is the length of the input string.
- We iterate through each character once, and the operations performed inside the loop are all constant time.
- The space complexity is O(N) as we use a stack to store operators.
*/
