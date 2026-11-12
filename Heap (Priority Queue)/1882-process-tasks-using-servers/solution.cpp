/*
//RAN ALL test cases but not efficient !

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int m=servers.size();
        int n=tasks.size();
        for(int  i=0;i<m;i++)
        {
            pq.push({servers[i],i});
        }
        int i=0;
        long long time=0;
        vector<int>ans(n);
        unordered_map<long long,vector<pair<int,int>>>mp;
        int w,idx;
        while(i<n)
        {
            time = max(time,(long long)i);
            if(mp.find(time)!=mp.end())
                {
                    for(auto& x:mp[time])
                    {
                        pq.push({x.first,x.second});
                    }
                    mp.erase(time);
                }
            if(!pq.empty())
            {
                auto p=pq.top();
                pq.pop();
                w=p.first;
                idx=p.second;
                mp[time+tasks[i]].push_back({w,idx});
                ans[i]=idx;
                i++;
            }
            else {
                long long nxtt=LLONG_MAX;
                for(auto& t:mp)
                {
                    nxtt=min(nxtt,t.first);
                }
                time=nxtt;
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>busy;
        int m=servers.size();
        int n=tasks.size();
        for(int i=0;i<m;i++)
        {
            pq.push({servers[i],i});
        }
        int i=0;
        long long time=0;
        vector<int>ans(n);
        int w,idx;
        while(i<n)
        {
            time=max(time,(long long)i);
            while(!busy.empty() && busy.top().first<=time)
            {
                auto p=busy.top();
                busy.pop();
                w=p.second.first;
                idx=p.second.second;
                pq.push({w,idx});
            }
            if(pq.empty())
            {
                time=busy.top().first;
                while(!busy.empty() && busy.top().first<=time)
                {
                    auto p=busy.top();
                    busy.pop();
                    w=p.second.first;
                    idx=p.second.second;
                    pq.push({w,idx});
                }
            }
            auto p=pq.top();
            pq.pop();
            w=p.first;
            idx=p.second;
            ans[i]=idx;
            busy.push({time+tasks[i],{w,idx}});
            i++;
        }
        return ans;
    }
};
