``` cpp
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> state(n, -1);
        helper(state, 0);
        return res;
    }
    
    void helper(vector<int> &state, int row){
        int n = state.size();
        if(row == n)
        {
            vector<string>tmpres(n, string(n,'.'));
            for(int i = 0; i < n; i++)
                tmpres[i][state[i]] = 'Q';
            res.push_back(tmpres);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(isValid(state, row, col))
            {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
        }
    }

    bool isValid(vector<int> &state, int row, int col)
    {
        for(int i = 0; i < row; i++)
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;
    }
private:
    vector<vector<string> > res;
};
```
