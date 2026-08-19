/*class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        TreeMap<Integer,Integer>mp=new TreeMap<>();
        int n=nums1.length,m=nums2.length,i=0,j=0;
         for (int[] x : nums1) {
            int a = x[0];
            int b = x[1];
         mp.put(a, mp.getOrDefault(a, 0) + b);
        }
          for (int[] x : nums2) 
        {
             int a = x[0];
            int b = x[1];
         mp.put(a, mp.getOrDefault(a, 0) + b);
        }
        
        int[][] ans=new int[mp.size()][2];
        for(Map.Entry<Integer,Integer> temp:mp.entrySet())
        {
            ans[i][0]=temp.getKey();
            ans[i][1]=temp.getValue();
            i++;
        }
        return ans;

        
    }
}*/

class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int i = 0, j = 0;
        int n = nums1.length;
        int m = nums2.length;
        List<int[]> list = new ArrayList<>();
        while (i < n && j < m) {
            if (nums1[i][0] < nums2[j][0]) {
                list.add(new int[]{nums1[i][0], nums1[i][1]});
                i++;
            }
            else if (nums1[i][0] > nums2[j][0]) {
                list.add(new int[]{nums2[j][0], nums2[j][1]});
                j++;
            }
            else{
                list.add(new int[]{nums1[i][0],nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }
        while (i < n) {
            list.add(new int[]{nums1[i][0], nums1[i][1]});
            i++;
        }
        while (j < m) {
            list.add(new int[]{nums2[j][0], nums2[j][1]});
            j++;
        }
        return list.toArray(new int[list.size()][]);
    }
}
