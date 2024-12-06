import java.util.*;

class Solution {
    public int[] solution(int[][] symbolPairs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> degree = new HashMap<>();
        
        // Build graph
        for (int[] pair : symbolPairs) {
            if (pair.length == 2) {
                graph.computeIfAbsent(pair[0], k -> new ArrayList<>()).add(pair[1]);
                graph.computeIfAbsent(pair[1], k -> new ArrayList<>()).add(pair[0]);
                degree.merge(pair[0], 1, Integer::sum);
                degree.merge(pair[1], 1, Integer::sum);
            } else {
                graph.putIfAbsent(pair[0], new ArrayList<>());
                degree.put(pair[0], 0);
            }
        }

        // Validate degrees
        for (int deg : degree.values()) {
            if (deg % 2 != 0) return new int[0];
        }

        // Start vertex
        int start = graph.keySet().iterator().next();
        
        // Find circuit
        List<Integer> circuit = new ArrayList<>();
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(start);

        while (!stack.isEmpty()) {
            int current = stack.peek();
            List<Integer> neighbors = graph.get(current);
            
            if (neighbors.isEmpty()) {
                circuit.add(stack.pop());
            } else {
                int next = neighbors.remove(neighbors.size() - 1);
                graph.get(next).remove(Integer.valueOf(current));
                stack.push(next);
            }
        }

        if (circuit.size() != degree.size()) return new int[0];
        
        return circuit.stream().mapToInt(Integer::intValue).toArray();
    }
}