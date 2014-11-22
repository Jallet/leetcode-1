class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        bool d[1100][1100];
        memset(d,false,sizeof(d));
        string r;
        int max_len = 0;
        for(int i = s.size() - 2; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(s[j] == s[i] && (d[i + 1][j - 1] || (j - i < 2))){
                    d[i][j] = true;
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1;
                        r = s.substr(i, j - i + 1);
                    }
                    
                }
            }
        }
        return r;
    }
};
