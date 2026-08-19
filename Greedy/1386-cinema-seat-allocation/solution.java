class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, Set<Integer>> mp = new HashMap<>();

        for (int[] x : reservedSeats) {
            int r = x[0];
            int s = x[1];

        mp.putIfAbsent(r, new HashSet<>());
        mp.get(r).add(s);
        }
        int ans=2 * (n - mp.size());
        for (Map.Entry<Integer, Set<Integer>> entry : mp.entrySet()) {
            int row = entry.getKey();
            Set<Integer> s = entry.getValue();
            boolean left=true;
            boolean mid=true;
            boolean right=true;
            for(int v:s)
            {
                if(v>=2&&v<=5) left=false;
                if(v>=4&&v<=7) mid=false;
                if(v>=6&&v<=9) right=false;
            }
            if(left&&right)
            {
                ans+=2;
            }
            else if(left||right||mid) ans+=1;
            else ans+=0;
            
        }
        return ans;
    }
}
