/*
Problem Statement: Given an expression, A, with operands and operators (OR, AND, XOR), in how many ways can you evaluate 
the expression to be true, by grouping it in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.

Example 1:
Input : expression = “T|T&F”
Output : 1
Explanation : The only way to get the result as true is:
(T) | (T&F) = T|F = T 

Example 2:
Input : expression = “F|T^F”
Output : 2
Explanation : There are 2 possible ways to get the result as true:
		i) (F|T) ^ F = T ^ F = T
		ii) F | (T^F) = F | T = T

Time Complexity: O(N*N*2 * N) ~ O(N3) There are a total of 2*N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
Space Complexity: O(2*N2) + Auxiliary stack space of O(N), 2*N2 for the dp array we are using.
*/

/*
Mod has to be applied in all the positions
long long had to be used
i=j is one base case
separate for &, |, ^
separate for True, False. So, N*N*2 SC

Do write i-=2 and j+=2 for 2* TC

else if(exp[ind] == '^') {
for better TC if we are writing i-- and j++
*/
_____________________________________________________

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    if (i > j) return 0;
    
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  
        ll lF = f(i, ind - 1, 0, exp, dp);  
        ll rT = f(ind + 1, j, 1, exp, dp);  
        ll rF = f(ind + 1, j, 0, exp, dp);  

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    // Store the result in the DP table and return it.
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}
_________________________________________________________

#define ll long long
const int mod = 1000000007;

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    
    for (int i = n - 1; i >= 0; i-=2) {
        for (int j = i; j <= n - 1; j+=2) {
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character.
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic:
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

