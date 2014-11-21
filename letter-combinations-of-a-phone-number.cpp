class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int s[]={0,0,0,3,6,9,12,15,19,22,26};
        vector<string> result(1);
        for(int i=0;i<digits.length();i++){
            vector<string> temp_vec;
            for(int j=0;j<result.size();j++){
                int n=digits[i]-'1'+1;
                for(int k=s[n];k<s[n+1];k++) temp_vec.push_back(result[j]+char('a'+k));
            }
            result=temp_vec;
        }
        return result;
    }
};
