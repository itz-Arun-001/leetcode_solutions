class CombinationIterator {
public:
vector<string>ans;
int idx=0;
int size;
    void help(string &chars,int& n,int& l,int size,string temp,int pos)
    {
        if(size==l) {
            ans.push_back(temp);
            return;
        }
        for(int i=pos;i<n;i++)
        {
            temp.push_back(chars[i]);
            help(chars,n,l,size+1,temp,i+1);
            temp.pop_back();
        }
    }
    CombinationIterator(string chars, int combinationLength) {
        int n=chars.size();
        string s="";
        help(chars,n,combinationLength,0,s,0);
        size=ans.size();
        
    }
    
    string next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        return idx<size;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
