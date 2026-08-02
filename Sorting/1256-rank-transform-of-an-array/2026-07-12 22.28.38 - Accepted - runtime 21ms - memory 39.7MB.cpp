class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>temp;
        for(int i=0;i<arr.size();i++)
        {
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());
        int r=1,pl;
         for(int i=0;i<temp.size();i++)
        {
            if(i>0 && temp[i].first != temp[i-1].first)
                r++;

            arr[temp[i].second] = r;
        }
        return arr;
        
    }
};