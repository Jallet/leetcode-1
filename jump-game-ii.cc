class Solution {
public:
    int jump(int A[], int n) {
        int maxx=0,temp=0,num=0;
        for(int i=0;i<n;)
        {
            if(temp>=n-1)break;
            while(i<=temp)
            {
                maxx=max(maxx,i+A[i]);
                ++i;
            }
            num++;
            temp=maxx;            
        }
        return num;
        
    }
};
