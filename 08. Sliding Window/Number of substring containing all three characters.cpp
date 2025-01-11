int count = 0;
for(int i=0 -> n) {
	hash[3] = {0};
	for(j=i -> n){
		hash[s[j]-'a'] = 1;
		if(hash[0] + hash[1] + hash[2] == 3) count++;
	}
}
return count;
	
TC is (N*N) and SC is O(1)
_____________________

		if(hash[0] + hash[1] + hash[2] == 3) count++;
can be written as 
		if(hash[0] + hash[1] + hash[2] == 3) {
			count = count + (n-j);
			break;
		}

some optimization happened
__________________________

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        int last[3] = {-1, -1, -1};
        for(int i=0;i<n;i++){
            last[s[i]-'a'] = i;
            if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1) {
                count += 1 + min(last[0], min(last[1], last[2]));
            }
        }
        return count;
    }
};
