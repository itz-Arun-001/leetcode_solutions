class Solution {
public:
    void visit(vector<vector<int>>& rooms,vector<bool>& visited,int& r)
    {
        if(visited[r]) return;
        visited[r]=true;
        for(int i=0;i<rooms[r].size();i++)
        {
            visit(rooms,visited,rooms[r][i]);
        } 
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m=rooms.size();
        vector<bool>visited(m,false);
        // for (int i=0;i<m;i++)
        // {
        //     int n=rooms[i].size();
        //     for(int j=0;j<m;j++)
        //     {
        //         if(!visited[i])
        //         {
        //             visit(rooms,visited,i);
        //         }
        //     }
        // }
        int r=0;
        visit(rooms,visited,r);
        for(int i=0;i<m;i++)
        {
            if(!visited[i]) return false;
        }
        return true;
    }
};
