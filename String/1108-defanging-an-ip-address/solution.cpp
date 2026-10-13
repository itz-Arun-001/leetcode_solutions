class Solution {
public:
    string defangIPaddr(string add) {
        string result = "";
        for (char c : add) {
            if (c == '.') {
                result += "[.]";
            } else {
                result += c;
            }
        }
        return result;
    }
};
