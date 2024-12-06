import java.util.*;

public class BeautifulPath {
    private static int helper(int curnode, ArrayList<Integer>[] adj, int[] charmap, boolean[] mystack, String s) {
        mystack[curnode] = true;
        charmap[s.charAt(curnode) - 'a']++;
        if (adj[curnode].size() == 0) {
            // leaf node
            int maxval = 0;
            for (int i = 0; i < 26; i++) {
                maxval = Math.max(maxval, charmap[i]);
            }
            mystack[curnode] = false;
            charmap[s.charAt(curnode) - 'a']--;
            return maxval;
        }
        int maxval = 0;
        for (int neigh : adj[curnode]) {
            if (mystack[neigh] == true) {
                return -1;
            }
            int res = helper(neigh, adj, charmap, mystack, s);
            if (res == -1)
                return -1;
            maxval = Math.max(maxval, res);
        }
        charmap[s.charAt(curnode) - 'a']--;
        mystack[curnode] = false;
        return maxval;
    }

    public static int beauty(int n, int m, String s, int[] x, int[] y) {
        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            adj[x[i] - 1].add(y[i] - 1);
        }
        int[] charmap = new int[26];
        int maxval = 0;
        boolean[] mystack = new boolean[n];
        for (int i = 0; i < n; i++) {
            int res = helper(i, adj, charmap, mystack, s);
            if (res == -1)
                return -1;
            maxval = Math.max(maxval, res);
        }
        return maxval;
    }
}