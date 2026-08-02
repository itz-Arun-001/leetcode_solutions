#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       /* int high=0;
        vector<int>alt;
        alt.push_back(0);
        int j=0;
        for(int i=0;i<gain.size()-1;i++)
        {
           alt.push_back(alt[j]+gain[i]);
           j++;
            high=max(high,alt[j]);
        }
       // high=max(high,alt[alt.size()-1]);*/
       int high=0;
       int cur=0;
       for(auto i:gain)
       {
        cur+=i;
        high=max(cur,high);
       }
        return high;
        
    }
};