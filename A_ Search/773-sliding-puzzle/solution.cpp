class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                s+=to_string(board[i][j]);
            }
        }
        queue<string>q;
        q.push(s);
        int cnt=0;
        unordered_map<string,bool>vis;
        vis[s]=true;
        string temp;
        int pos,r,c,nr,nc,npos,n;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty())
        {   
            n=q.size();
            for(int k=0;k<n;k++){
            s=q.front();
            q.pop();
            if(s=="123450") return cnt;
            for(int i=0;i<6;i++)
            {
                if(s[i]=='0') 
                {
                    pos=i;
                    break;
                }
            }
            r=pos/3;
            c=pos%3;
            for(int i=0;i<4;i++)
            {
                temp=s;
                nr=r+dr[i];
                nc=c+dc[i];
                if(nr>=0&&nr<2&&nc>=0&&nc<3){
                   npos=nr*3+nc;
                   swap(temp[pos],temp[npos]);
                   if(!vis[temp]) {
                    vis[temp]=true;
                    q.push(temp);
                   }
                   
                }
            }
            }
            cnt++;
        }
       return -1;
    }
};
