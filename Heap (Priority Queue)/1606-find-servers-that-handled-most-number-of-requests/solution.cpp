class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<int>st;
        for(int i=0;i<k;i++)
        {
            st.insert(i);
        }
        pq.push({arrival[0]+load[0],0});
        st.erase(0);
        int n=arrival.size();
        vector<int>temp(k,0);
        temp[0]++;
        int i=1;
        //int time=INT_MIN;
        while(i<n)
        {
            //time=max(time,arrival[i-1]);
            while(!pq.empty()&&pq.top().first<=arrival[i])
            {
                auto p=pq.top();
                pq.pop();
                st.insert(p.second);
            }
            if(st.find(i%k)!=st.end())
            {
                pq.push({arrival[i]+load[i],i%k});
                st.erase(i%k);
                temp[i%k]++;
                i++;
            }
            else if(!st.empty())
            {
                // int j=i%k;
                // while(st.find(j)==st.end())
                // {
                //       j=(j+1)%k;
                // }
                auto it=st.lower_bound(i%k);
                if(it==st.end())
                    it=st.begin();
                int j=*it;
                st.erase(j);
                temp[j]++;
                pq.push({arrival[i]+load[i],j});
                i++;
            }
            else if(st.empty()){
                i++;
                continue;
            }
        }
        int mx=*max_element(temp.begin(),temp.end());
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            if(temp[i]==mx) ans.push_back(i);

        }
        return ans;


    }
};
