class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(char ch:address)
        {
            if(ch=='.')
            {
               /* s.push_back('[');
                s.push_back('.');
                s.push_back(']');*/
                s+="[.]";
                }
            else{
              //  s.push_back(ch);
              s+=ch;;
            }
        }
        return s;
        
    }
};