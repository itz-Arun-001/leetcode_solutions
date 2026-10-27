class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<bool>key(n,false);
        vector<bool>box(n,false);
        vector<bool>visited(n,false);
        queue<int>q;
        int tot=0;
        for(int a: initialBoxes)
        {
            //key[a]=true;
            box[a]=true;
            q.push(a);
        }
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            if(visited[a]) continue;
            if(status[a]==0&&key[a]==false)
            {
                box[a]=true;
                continue;
            }
            tot+=candies[a];
            visited[a]=true;
            for(int x:containedBoxes[a])
            {
                box[x]=true;
                if(!visited[x])
                    q.push(x);
            }
            for(int x: keys[a])
            {
                key[x]=true;
                if(box[x]&&!visited[x]) q.push(x);
            }

        }
        // for(int i=0;i<n;i++)
        // {
        //     if(!visited[i]&&box[i]&&key[i])
        //         tot+=candies[i];
        // }

        return tot;
    }
};
