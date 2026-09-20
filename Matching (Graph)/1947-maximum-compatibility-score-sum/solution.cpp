/*class Solution {
public:
int tot=0;
    int maxans=0;
    void help(vector<vector<int>>& stud,vector<vector<int>>& ment,vector<bool>&
visited,int st,int &ass,int& temp,int& m,int& n)
    {
        if(ass==m||st>=m) {
            maxans=max(maxans,temp);
            return;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i*n+j]==false)
                {
                    if(stud[st][j]==ment[i][j]) temp++;
                    visited[i*n+j]= true;
                    ass++;
                    help(stud,ment,visited,st+1,ass,temp,m,n);
                    visited[i*n+j]=false;
                    ass--;
                    temp--;

                }
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>&
mentors) { int m=students.size(); int n=students[0].size();
        vector<bool>visited(m,false);
        int ass=0,temp=0;
        help(students,mentors,visited,ass,temp,m,n);
        return maxans;
    }
};*/

class Solution {
public:
    int maxans = 0;
    void help(vector<vector<int>>& stud, vector<vector<int>>& ment,vector<bool>& visited, int st, int& temp, int m, int n) {
        if (st==m) {
            maxans=max(maxans, temp);
            return;
        }
        for (int i=0;i<m;i++) {
            if (!visited[i]) {
                int score=0;
                for (int j=0;j<n;j++) {
                    if (stud[st][j]==ment[i][j])
                        score++;
                }
                visited[i]=true;
                temp+=score;
                help(stud,ment,visited,st+1,temp,m,n);
                temp-=score;
                visited[i]=false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students,vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<bool> visited(m,false);
        int temp = 0;
        help(students,mentors,visited,0,temp,m,n);
        return maxans;
    }
};
