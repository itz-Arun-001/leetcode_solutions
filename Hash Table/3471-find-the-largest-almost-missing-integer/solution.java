class Solution {
    public int largestInteger(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer,Integer>mp=new HashMap<>();
        int max =-1;
        for(int i=0;i<n;i++)
        {
            max=Math.max(max,nums[i]);
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
        int ans=-1;
        if(k==1)
        {
            for (Map.Entry<Integer, Integer> temp : mp.entrySet()) {
                if(temp.getValue()==1) {
                    ans=Math.max(ans,temp.getKey());
                    
                }
            }
            return ans;
        }
        else if(k==n) return max;
        else if(k>1&&k<n){
            if(mp.get(nums[0])>1&&mp.get(nums[nums.length-1])>1)  return -1;
            else if(mp.get(nums[0])>1) return nums[nums.length-1];
            else if(mp.get(nums[nums.length-1])>1) return nums[0];
            else return Math.max(nums[0],nums[nums.length-1]);

            
        }
        return -1;

        
    }
}
