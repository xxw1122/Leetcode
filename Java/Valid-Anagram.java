public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] vis = new int[26];
        for (int i = 0; i < s.length(); i ++) {
            vis[s.charAt(i) - 'a'] ++;
        }
        for (int i = 0; i < t.length(); i ++) {
            if (-- vis[t.charAt(i) - 'a'] < 0) return false;
        }
        for (int i = 0; i < 26; i ++) {
            if (vis[i] != 0) return false;
        }
        return true;
    }
}