class Solution {
public:
    int lengthOfLastWord(string s) {
        long long cnt = 0;
        long long i = s.size() - 1;
        while(i>=0 && s[i] == ' '){
            i--;
        }

        while(i>=0 && s[i] != ' '){
            cnt++;
            i--;
        }
        return cnt;
    }
};