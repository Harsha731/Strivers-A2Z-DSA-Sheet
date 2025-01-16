/*

CODE:
*/

const int d = 256;      // ASCII contains 256 characters
const int q = 101;      // MOD type, choose any prime number. 

int strStr(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0) return 0;

    int p = 0, t = 0, h = 1;

    // Calculate h = (d^(m-1)) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Hash value of pattern and first window
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide pattern over text
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i; // Pattern found
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return -1; // Pattern not found
}
