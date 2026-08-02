class Solution {
public:
    static bool cmp(const int& a, const int& b) {
        return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
    }
    string largestNumber(vector<int>& nums) {
        //vector<string> temp;
        string ans = "";
      //  for (int i = 0; i < nums.size(); i++) {
        //    temp.push_back(to_string(nums[i]));
       // }
        sort(nums.begin(), nums.end(), cmp);
        if (to_string(nums[0])== "0")
            return "0";
        /*  for(int i=1;i<nums.size();i++)
          {
               string a=temp[i];
              string b=to_string(nums[i]);
              ans.append(to_string(max(stoi(a+b),stoi(b+a))));
          }*/
        for (int i = 0; i < nums.size(); i++) {
            ans.append(to_string(nums[i]));
        }
        //return (stoi(ans) == 0) ? "0" : ans;
        return ans;
    }
};