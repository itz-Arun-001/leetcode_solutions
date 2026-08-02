class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        return (a + b) > (b + a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(), temp.end(), cmp);
        if (temp[0] == "0")
            return "0";
        /*  for(int i=1;i<nums.size();i++)
          {
               string a=temp[i];
              string b=to_string(nums[i]);
              ans.append(to_string(max(stoi(a+b),stoi(b+a))));
          }*/
        for (int i = 0; i < temp.size(); i++) {
            ans.append(temp[i]);
        }
        //return (stoi(ans) == 0) ? "0" : ans;
        return ans;
    }
};