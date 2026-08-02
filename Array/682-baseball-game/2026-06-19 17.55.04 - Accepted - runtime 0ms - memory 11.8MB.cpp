class Solution {
public:
    int calPoints(vector<string>& s) {
        vector<int>v;
       // int j=0;
        for(string c:s)
        {
            if(c=="+")
            {
               v.push_back(v[v.size()-1] + v[v.size()-2]);
                
            }
            else if(c=="D")
            {
                v.push_back(2*(v[v.size()-1]));
            
            }
            else if(c=="C")
            {
                v.pop_back();
        
            }
            else{
                v.push_back(stoi(c));
            
            }
        }
        int sum=0;
        for(int num:v)
        {
            sum+=num;
        }
        return sum;
        
    }
};