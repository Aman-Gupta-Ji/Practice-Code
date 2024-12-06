import java.util.*;

public class Solution {

    public static long getMaxRequests(int[] serverCapacity, int[] incomingRequests, int k) {
        int n = serverCapacity.length;
        int pulsServed[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            int deficit = serverCapacity[i] - incomingRequests[i];
            servers.add(new int[]{serverCapacity[i], incomingRequests[i], deficit});
        }
        
        // Sort servers by the deficit
        servers.sort(Comparator.comparingInt(a -> a[2]));
        
        // Double the capacity of k servers with the smallest deficits
        for (int i = 0; i < k; i++) {
            servers.get(i)[0] *= 2;
        }
        
        // Calculate the total maximum requests handled
        long total = 0;
        for (int[] server : servers) {
            total += Math.min(server[0], server[1]);
        }
        
        return total;
    }

    public static void main(String[] args) {
        // Example input
        int[] serverCapacity = {10, 4, 3, 7};
        int[] incomingRequests = {3, 10, 4, 5};
        int k = 2;

        long result = getMaxRequests(serverCapacity, incomingRequests, k);
        System.out.println(result); // Output: 20
    }
}
