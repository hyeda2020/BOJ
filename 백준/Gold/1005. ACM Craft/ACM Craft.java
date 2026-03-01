import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] Cost;
    static int[] DP;
    static boolean[][] Graph;
    static int[] Indegree;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int T = Integer.parseInt(st.nextToken());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            Cost = new int[N + 1];
            Indegree = new int[N + 1];
            Graph = new boolean[N + 1][N + 1];

            st = new StringTokenizer(br.readLine());
            for (int n = 1; n <= N; n++) {
                Cost[n] = Integer.parseInt(st.nextToken());
            }

            int src, dest;
            for (int k = 0; k < K; k++) {
                st = new StringTokenizer(br.readLine());
                src = Integer.parseInt(st.nextToken());
                dest = Integer.parseInt(st.nextToken());
                Indegree[dest]++;
                Graph[src][dest] = true;
            }

            TopologicalSort(N);

            st = new StringTokenizer(br.readLine());
            int W = Integer.parseInt(st.nextToken());
            System.out.println(DP[W]);
        }
    }

    public static void TopologicalSort(int n) {
        Queue<Integer> queue = new LinkedList<>();
        DP = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            DP[i] = Cost[i];
            if (Indegree[i] == 0) {
                queue.add(i);
            }
        }

        int cur;
        while (!queue.isEmpty()) {
            cur = queue.poll();
            for (int next = 1; next <= n; next++) {
                if (Graph[cur][next]) {
                    DP[next] = Math.max(DP[next], DP[cur] + Cost[next]);
                    if (--Indegree[next] == 0) {
                        queue.add(next);
                    }
                }
            }
        }
    }
}