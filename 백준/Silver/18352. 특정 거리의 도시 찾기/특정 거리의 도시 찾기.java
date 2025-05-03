import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        boolean[] bVisited = new boolean[N + 1];
        int[] dist = new int[N + 1];
        ArrayList<Integer>[] graph = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        int src, dest;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            src = Integer.parseInt(st.nextToken());
            dest = Integer.parseInt(st.nextToken());

            graph[src].add(dest);
        }

        Queue<Integer> Q = new LinkedList<>();
        Q.add(X);
        bVisited[X] = true;

        /* BFS */
        int cur;
        while (!Q.isEmpty()) {
            cur = Q.poll();

            for (int next : graph[cur]) {
                if (!bVisited[next]) {
                    Q.add(next);
                    bVisited[next] = true;
                    dist[next] = dist[cur] + 1;
                }
            }
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 1; i<= N; i++) {
            if (dist[i] == K) {
                result.add(i);
            }
        }

        if (result.isEmpty()) {
            System.out.println(-1);
        } else {
            for (int city : result) {
                System.out.println(city);
            }
        }

        br.close();
    }
}