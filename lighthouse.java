import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class lighthouse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();

        if (n <= 0) {
            System.out.println(0);
            return;
        }
        
        List<Set<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new HashSet<>());
        }
        
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            if (u >= 0 && u < n && v >= 0 && v < n) {
                graph.get(u).add(v);
                graph.get(v).add(u);
            } else {
                System.out.println((u + 1) + " " + (v + 1));
                return;
            }
        }
        
        boolean[] visited = new boolean[n];
        int componentCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                componentCount++;
                explore(graph, visited, i);
            }
        }
        
        System.out.println(componentCount - 1);
    }

    private static void explore(List<Set<Integer>> graph, boolean[] visited, int node) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        while (!stack.isEmpty()) {
            int current = stack.pop();
            if (!visited[current]) {
                visited[current] = true;
                for (int neighbor : graph.get(current)) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }
}
