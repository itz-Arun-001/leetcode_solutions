class Solution {
public:
    int maxareaofrow(vector<int> height)
    {
        stack<int>st;
        int maxarea=0;
        for(int i=0;i<height.size();i++)
        {
            while(!st.empty()&&height[st.top()]>height[i])
            {
                int index=st.top();
                st.pop();
                int nse=i;
                int pse=(!st.empty())?st.top():-1;
                maxarea=max(maxarea,height[index]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int index=st.top();
            st.pop();
            int nse=height.size();
            int pse=!st.empty()?st.top():-1;
            maxarea=max(maxarea,height[index]*(nse-pse-1));

        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxarea=0;
        int m=matrix.size();
        int n=matrix[0].size();
      
        vector<vector<int>> psum(m, vector<int>(n, 0));
        for(int j=0;j<n;j++)
        {
              int sum=0;
            for(int i=0;i<m;i++)
            {
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0')   sum=0;
                psum[i][j]=sum;
            }
        }
        for(int i=0;i<m;i++)
        {
            maxarea=max(maxarea,maxareaofrow(psum[i]));
        }
        return maxarea;
    }
};