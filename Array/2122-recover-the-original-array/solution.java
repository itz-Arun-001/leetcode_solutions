class Solution {
    public int[] recoverArray(int[] nums) {
        Arrays.sort(nums);
        List<Integer>doubledif=new ArrayList<>();
        for(int num: nums)
        {
            int temp=num-nums[0];
            if(temp>0&&temp%2==0)
            {
                doubledif.add(temp);
            }
        }
        for( int d:doubledif)
        {
            List<Integer> arr=createarr(nums,d);
           if (arr.size() == nums.length / 2) {
                int[] ans = new int[arr.size()];

                for (int i = 0; i < arr.size(); i++) {
                    ans[i] = arr.get(i);
                }

                return ans;
            }
        }
        return new int[]{};
        
    }
    private List<Integer>createarr(int[] nums, int d)
    {
        Map<Integer,Integer>freq=new HashMap<>();
        for(int num: nums)
        {
            freq.put(num,freq.getOrDefault(num,0)+1);
        }
        List<Integer>arr=new ArrayList<>();
        for(int num:nums)
        {
            if(freq.get(num)>0&&freq.getOrDefault(num+d,0)>0)
            {
                arr.add(num+d/2);
                freq.put(num,freq.get(num)-1);
                freq.put(num+d,freq.get(num+d)-1);
            }
        }
        return arr;
    }
}
