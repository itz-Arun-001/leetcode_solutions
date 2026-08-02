static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;
int n = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[0] + pos - size);
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}




class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c=='{'||c=='['||c=='(')
                st.push(c);
            else{
                if((!st.empty())&&((st.top()=='('&&c==')')||(st.top()=='{'&&c=='}')||(st.top()=='['&&c==']')))
                {
                    st.pop();
                }
                else    return false;
                
            }
        }
        return(st.empty())? true:false;
       // else return false;
    }
};