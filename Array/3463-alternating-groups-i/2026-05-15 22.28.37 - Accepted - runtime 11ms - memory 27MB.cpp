class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(colors[i]!=colors[n-1]&&colors[i]!=colors[i+1]) 
                c++;
            }
            else if(i==n-1)
            {
                if(colors[i]!=colors[i-1]&&colors[i]!=colors[0])  c++;

            }
            else {
                if(colors[i]!=colors[i-1]&&colors[i]!=colors[i+1])  
                c++;
            }
        }
        return c;

        
    }
};