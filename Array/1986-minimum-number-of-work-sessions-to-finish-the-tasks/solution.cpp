/*class Solution {
public:
    int ans=INT_MAX;
    int cnt=1;
    void help(vector<int>& tasks,int &t,int &currsum,int &size,int& n,vector<bool>& visited){
        if(cnt >= ans) return;
        if(size==n)
        {
            ans=min(ans,cnt);
            return ;
        }
        for (int i=0;i<n;i++)
        {
            if(currsum+tasks[i]<=t&&!visited[i]){
            int temp=currsum;
            currsum+=tasks[i];
            visited[i]=true;
                size++;
            help(tasks,t, currsum,size,n,visited);
            currsum=temp;
                size --;
            visited[i]=false;
            }
        }
        cnt++;
        for(int i=0;i<n;i++){
         if(!visited[i]){
                int temp=currsum;
                currsum=tasks[i];
                visited[i]=true;  
             size++;
            help(tasks,t,currsum,size,n, visited);
                currsum=temp;
             size --;
                visited[i]=false;
            }
        }
        cnt--;
    }
    int minSessions(vector<int>& tasks, int T) {
        int n=tasks.size();
        vector<bool>visited(n,false);
        int cur=0;
        int s=0;
        help(tasks,T,cur,s,n,visited);
        return ans;
        
    }
};*/
class Solution {
public:
    int ans=INT_MAX;

    void help(vector<int>& tasks,int &t,int idx,int &n,vector<int>& sessions){
        if(sessions.size()>=ans) return;

        if(idx==n){
            ans=min(ans,(int)sessions.size());
            return;
        }

        set<int> used;

        for(int i=0;i<sessions.size();i++){
            if(sessions[i]+tasks[idx]>t) continue;

            if(used.count(sessions[i])) continue;
            used.insert(sessions[i]);

            sessions[i]+=tasks[idx];

            help(tasks,t,idx+1,n,sessions);

            sessions[i]-=tasks[idx];
        }

        sessions.push_back(tasks[idx]);

        help(tasks,t,idx+1,n,sessions);

        sessions.pop_back();
    }

    int minSessions(vector<int>& tasks,int T){
        int n=tasks.size();

        sort(tasks.rbegin(),tasks.rend());

        vector<int> sessions;

        help(tasks,T,0,n,sessions);
        return ans;
    }
};
