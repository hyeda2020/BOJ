import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] parents = new int[N + 1];
        boolean[] bVisited = new boolean[N + 1];

        ArrayList<Integer>[] graph = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }

        int src, dest;
        StringTokenizer st;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            src = Integer.parseInt(st.nextToken());
            dest = Integer.parseInt(st.nextToken());

            graph[src].add(dest);
            graph[dest].add(src);
        }

        Queue<Integer> Q = new LinkedList<>();
        Q.add(1);
        bVisited[1] = true;

        int cur;
        while (!Q.isEmpty()) {
            cur = Q.poll();
            bVisited[cur] = true;

            for (int child : graph[cur]) {
                if (!bVisited[child]) {
                    parents[child] = cur;
                    Q.add(child);
                }
            }
        }

        for (int i = 2; i <= N; i++) {
            System.out.println(parents[i]);
        }
    }
}