import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] DP;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        DP = new int[N + 1][N + 1];
        List<City> Graph[] = new List[N + 1];
        for (int i = 0; i <= N; i++) {
            Graph[i] = new ArrayList<>();
        }

        int src, dest, cost;
        for (int i = 0; i < K;  i++) {
            st = new StringTokenizer(br.readLine());
            src = Integer.parseInt(st.nextToken());
            dest = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            if (src <= dest) {
                Graph[src].add(new City(dest, cost));
            }
        }

        int next;
        for (int i = 0; i < Graph[1].size(); i++) {
            next = Graph[1].get(i).number;
            cost = Graph[1].get(i).cost;
            DP[next][2] = Math.max(DP[next][2], cost);
        }

        for (int i = 2; i <= M; i++) {
            for (int cur = 1; cur <= N; cur++) {
                if (DP[cur][i] > 0) {
                    for (City c : Graph[cur]) {
                        next = c.number;
                        cost = c.cost;
                        DP[next][i + 1] = Math.max(DP[next][i + 1], DP[cur][i] + cost);
                    }
                }
            }
        }

        int answer = 0;
        for (int i = 2; i <= M; i++) {
            answer = Math.max(answer, DP[N][i]);
        }
        System.out.println(answer);
    }

    static class City {
        public int number;
        public int cost;

        public City(int number, int cost) {
            this.number = number;
            this.cost = cost;
        }
    }
}