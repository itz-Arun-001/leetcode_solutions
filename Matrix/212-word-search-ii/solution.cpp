/*class Solution {
public:
set<string>st;
vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        int x=words.size();
        string temp="";
        for(int a=0;a<x;a++){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==words[a][0])
                {
                    if(search(board,words[a],i,j,0,n,m))
                    {
                        st.insert(words[a]);
                    }
                }
            }
        }
        }
        for(auto s: st)
        {
            ans.push_back(s);
        }
        return ans;
    }
    bool search(vector<vector<char>>& board,string &word,int row,int col,int pos,int &n,int &m)
    {
        if(pos==word.size()) return true;
        if(row<0||col<0||row>=n||col>=m||board[row][col]!=word[pos]||board[row][col]=='@'){
             return false;
        }
        char temp=board[row][col];
        board[row][col]='@';
        bool left=search(board,word,row,col-1,pos+1,n,m);
        bool right=search(board,word,row,col+1,pos+1,n,m);
        bool up=search(board,word,row-1,col,pos+1,n,m);
        bool down=search(board,word,row+1,col,pos+1,n,m);
         board[row][col]=temp;
        if(left||right||up||down)
            return true;
        return false;
    }
};*/

class Solution {
public:

    vector<string> ans;

    bool search(vector<vector<char>>& board,string& word,int row,int col,int pos,int n,int m)
    {
        if(pos == word.size())
            return true;
        if(row < 0 || col < 0 ||
           row >= n || col >= m ||
           board[row][col] != word[pos] ||
           board[row][col] == '@')
            return false;
        char temp = board[row][col];
        board[row][col] = '@';
        bool found =
            search(board, word, row + 1, col, pos + 1, n, m) ||
            search(board, word, row - 1, col, pos + 1, n, m) ||
            search(board, word, row, col + 1, pos + 1, n, m) ||
            search(board, word, row, col - 1, pos + 1, n, m);
        board[row][col] = temp;
        return found;
    }
    vector<string> findWords(vector<vector<char>>& board,vector<string>& words){
        int n = board.size();
        int m = board[0].size();
        int freq[26] = {};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                freq[board[i][j] - 'a']++;
            }
        }
        for(string s : words)
        {
            int wf[26] = {};
            bool possible = true;
            for(char c : s)
            {
                wf[c - 'a']++;
                if(wf[c - 'a'] > freq[c - 'a'])
                {
                    possible = false;
                    break;
                }
            }
            if(!possible)
                continue;
            string word = s;
            if(freq[word.front() - 'a'] >
               freq[word.back() - 'a'])
            {
                reverse(word.begin(), word.end());
            }
            bool found = false;
            for(int i = 0; i < n && !found; i++)
            {
                for(int j = 0; j < m && !found; j++)
                {
                    if(board[i][j] == word[0])
                    {
                        if(search(board, word, i, j, 0, n, m))
                            found = true;
                    }
                }
            }
            if(found)
                ans.push_back(s);
        }
          return ans;
    }
};
