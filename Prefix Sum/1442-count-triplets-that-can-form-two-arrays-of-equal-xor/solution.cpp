class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        unordered_map<int, vector<int>> ps;
        int xr = 0;
        ps[0].push_back(0);
          for(int i = 0; i < arr.size(); i++)
         {
                 xr ^= arr[i];
                ps[xr].push_back(i + 1);
                }
        for(auto it:ps)
        {
            
            if(it.second.size()>=2){
               for (int i = 0; i < it.second.size(); i++) {
                    for (int j = i + 1; j < it.second.size(); j++) {
                        int p = it.second[i];
                        int q = it.second[j];

                        ans += q - p - 1;
                }

            }
            
        }
        }
        return ans;


        
        
    }
};
