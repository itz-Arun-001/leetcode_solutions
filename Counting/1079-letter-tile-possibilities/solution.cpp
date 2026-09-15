/*class Solution {
public:
    vector<string>ans;
    void help(string &tiles,int idx,string& temp)
    {
        if(temp.size()>0) ans.push_back(temp);
        if(idx==temp.size()-1) return;
        for(int i=idx;i<tiles.size();i++)
        {
            temp.push_back(tiles[i]);
            help(tiles,i+1,temp);
            temp.pop_back();
        }

    }
    int numTilePossibilities(string tiles) {
        string temp="";
        help(tiles,0,temp);
        return ans.size();
    }
};*/

class Solution { 
public: 
    vector<string>ans; 
    void help(string &tiles, vector<bool>& used, string& temp) 
    { 
        if(temp.size() > 0) 
            ans.push_back(temp); 
        for(int i = 0; i < tiles.size(); i++) 
        { 
            if(used[i]) 
                continue;
            bool dup= false;
            for(int j = 0; j < i; j++)
            {
                if(!used[j] && tiles[i] == tiles[j])
                {
                    dup = true;
                    break;
                }
            }
            if(dup)
                continue;
            used[i] = true;
            temp.push_back(tiles[i]);
            help(tiles, used, temp);
            temp.pop_back();
            used[i] = false;
        } 
    } 
    int numTilePossibilities(string tiles) { 
        string temp = ""; 
        vector<bool> used(tiles.size(), false);
        help(tiles, used, temp); 
        return ans.size(); 
    } 
};
