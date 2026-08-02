class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k=k%(grid.size()*grid[0].size());
        if(k==0) return grid;
        /*while(k){
            int temp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {

            }
            
        }*/
        vector<int>help;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                help.push_back(grid[i][j]);
            }
        }
        reverse(help.begin(),help.end());
        reverse(help.begin(),help.begin()+k);
        reverse(help.begin()+k,help.end());
       /* while(k)
        {
            int a=help[help.size()-1];
            for(int i=help.size()-1;i>0;i--)
            {
                help[i]=help[i-1];
            }
            help[0]=a;
            k--;
        }*/
        int a=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                grid[i][j]=help[a++];
            }
        }
        return grid;

    }
};