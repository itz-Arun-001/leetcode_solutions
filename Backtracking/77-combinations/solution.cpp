class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>& temp,int& n,int& k,int idx)
    {
     
          if(temp.size()==k){
                ans.push_back(temp);
                return;
            }
        for(int i=idx;i<=n;i++)
        {
            
            temp.push_back(i);
          
            help(temp,n,k,i+1);
            temp.pop_back();
        }
       
    }
    vector<vector<int>> combine(int n, int k) {
           vector<int>temp;
      help(temp,n,k,1);
        return ans;
    }
};
