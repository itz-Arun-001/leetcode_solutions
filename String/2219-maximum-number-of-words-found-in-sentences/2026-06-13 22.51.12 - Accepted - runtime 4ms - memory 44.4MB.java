class Solution {
    public int mostWordsFound(String[] sent) {
        int max = 0;
        for (int i = 0; i < sent.length; i++) {
            String s = sent[i];
            int x = 0;

            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ')
                    x++;
                if (x+1 > max)
                    max = x+1;
            }
        }
        return max;

    }
}