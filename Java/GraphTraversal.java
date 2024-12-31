import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
public class GraphTraversal 
{
    private static int[][] graph;
    private static int vertices;
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of vertices: ");
        vertices = scanner.nextInt();
        graph = new int[vertices+1][vertices+1];
        System.out.println("1. Add edge");
        System.out.println("2. BFS traversal");
        System.out.println("3. DFS traversal");
        System.out.println("4. Exit");
        while (true) 
        {
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            switch (choice) 
            {
                case 1: addEdge(scanner);
                        break;
                case 2: BFS(scanner);
                        break;
                case 3: DFS(scanner);
                        break;
                case 4: System.out.println("Exiting program");
                        break;
                default: System.out.println("Invalid choice. Enter correct option.");
            }
        }
    }
    private static void addEdge(Scanner scanner) 
    {
        System.out.print("Enter source vertex: ");
        int src = scanner.nextInt();
        System.out.print("Enter destination vertex: ");
        int dest = scanner.nextInt();
        if (src <= vertices && dest<= vertices)
        {
            graph[src][dest] = 1;
            graph[dest][src] = 1;  // For undirected graph
        }
        else System.out.println("Invalid vertices entered!");
    }
    private static void BFS(Scanner scanner) 
    {
        System.out.print("Enter starting vertex for BFS: ");
        int start = scanner.nextInt();
        boolean[] visited = new boolean[vertices+1];
        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;
        queue.add(start);
        System.out.print("BFS traversal: ");
        while (!queue.isEmpty()) 
        {
            int v = queue.poll();
            System.out.print(v + " ");
            for (int i = 0; i < vertices+1; i++) 
            {
                if (graph[v][i] == 1 && !visited[i]) 
                {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
        System.out.println();
    }
    private static void DFS(Scanner scanner) 
    {
        System.out.print("Enter starting vertex for DFS: ");
        int start = scanner.nextInt();
        boolean[] visited = new boolean[vertices+1];
        System.out.print("DFS traversal: ");
        dfsUtil(start, visited);
        System.out.println();
    }
    private static void dfsUtil(int v, boolean[] visited) 
    {
        visited[v] = true;
        System.out.print(v + " ");
        for (int i = 0; i < vertices+1; i++) 
        {
            if (graph[v][i] == 1 && !visited[i]) 
                dfsUtil(i, visited);
        }
    }
}