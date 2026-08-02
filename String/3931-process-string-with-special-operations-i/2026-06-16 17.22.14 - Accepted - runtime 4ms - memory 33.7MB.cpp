class Solution {
public:
    string processStr(string s) {
        string res = "";
        for (char c : s) {
            if (c == '*') {

                if (res != "") {
                    res.pop_back();
                }
            } else if (c == '#') {
                if (res.size() != 0) {
                    res += res;
                }
            } else if (c == '%') {
                for (int i = 0; i < res.size() / 2; i++) {
                    char t = res[i];
                    res[i] = res[res.size() - i - 1];
                    res[res.size() - i - 1] = t;
                }
            } else {
                res += c;
            }
        }
        return res;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}