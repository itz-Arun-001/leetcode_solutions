class Solution {
public:
    int maxArea(vector<int>& height) {
    
        int left=0;
        int right = height.size()-1;
        int maxarea=0;
        while (left<right)
        {
            //int h=min(height[left],height[right]);
            //int width = right-left;
            //int area=width*h;
            //if(maxarea<area)
             //   maxarea=area;
            if(height[left]<height[right])
            {
                maxarea=max(maxarea,min(height[left],height[right])*(right-left));
                left++;
            }
            else{
                maxarea=max(maxarea,min(height[left],height[right])*(right-left));
                right--;
            }
        }
        return maxarea;        
    }
};