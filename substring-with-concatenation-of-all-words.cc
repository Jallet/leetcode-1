class Solution {
public:
   vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> dict, add;
        int total_length = 0, word_length = 0;
        for (int i = 0; i<L.size(); i++) {
            total_length += L[i].length();
            word_length = L[i].length();
            dict[L[i]] ++;
        }
 
        vector<int> res;
        for (int i = 0; i+total_length-1<S.length(); i++) {
            add.clear();
            int flag = true;
            for(int j = i; j<i+total_length; j+=word_length) {
                string s = S.substr(j, word_length);
                if(dict.find(s) == dict.end()) {
                    flag = false;
                    break;
                }    
                add[s] ++;
                if(add[s] > dict[s]) {
                    flag = false;
                    break;
                }
            }
 
            if(flag) {
                res.push_back(i);
            }
             
        }
        return res;
   }
};
