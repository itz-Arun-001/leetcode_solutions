class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int a=pow(n,2);
        vector<vector<int>>ans(n,vector<int>(n));
        int top=0,bot=n-1,left=0,right=n-1;
        int x=1;
        while(left<=right&&top<=bot)
        {
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=x++;
            }
            top++;
            for(int i=top;i<=bot;i++)
            {
                ans[i][right]=x++;
            }
            right--;
            if(top<=bot)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bot][i]=x++;
                }
                bot--;
            }
            if(left<=right)
            {
                for(int i=bot;i>=top;i--)
                {
                    ans[i][left]=x++;
                }
                left++;
            }
        }
        return ans;

        
    }
};