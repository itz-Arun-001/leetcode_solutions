class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for (auto c : text) {
            freq[c - 'a']++;
        }
        int x = 0;
        while (freq['b' - 'a'] > 0 && freq['a' - 'a'] > 0 &&
               freq['l' - 'a'] > 1 && freq['o' - 'a'] > 1 &&
               freq['n' - 'a'] > 0) {
            x++;
            freq['b' - 'a'] -= 1;
            freq['a' - 'a'] -= 1;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a'] -= 1;
        }
        return x;
    }
};
/*
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char c:text){
            freq[c]++;
        }
        return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
    }
};*/