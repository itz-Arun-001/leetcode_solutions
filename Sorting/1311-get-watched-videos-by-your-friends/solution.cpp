class Solution {
public:

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool>vis(101,false);
        unordered_map<string,int>mp;
        queue<pair<int,int>>q;
        q.push({id,0});
        vis[id]=true;
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p.second==level)
            {
                for(string &x:watchedVideos[p.first])
                {
                    mp[x]++;
                }
                continue;
            }
            for(int& x:friends[p.first])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    q.push({x,p.second+1});
                }
            }

        }
        vector<pair<int,string>>temp;
        for(auto &x:mp)
        {
            temp.push_back({x.second,x.first});
        }
        sort(temp.begin(),temp.end());
        vector<string>ans;
        for(auto& x:temp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
