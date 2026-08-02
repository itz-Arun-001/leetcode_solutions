class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(char ch:address)
        {
            if(ch=='.')
            {
                s.push_back('[');
                s.push_back('.');
                s.push_back(']');
            }
            else{
                s.push_back(ch);
            }
        }
        return s;
        
    }
};