import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;

    static int[][] Matrix;
    static int[][] Dist;
    static boolean[][] bVisited;

    static int[] Drow = { 0, -1, 0, 1 };
    static int[] Dcol = { -1, 0, 1, 0 };

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Matrix = new int[N][M];
        Dist = new int[N][M];
        bVisited = new boolean[N][M];

        int startR = 0;
        int startC = 0;

        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; c++) {
                Matrix[r][c] = Integer.parseInt(st.nextToken());
                if (Matrix[r][c] == 2) {
                    startR = r;
                    startC = c;
                }

                Dist[r][c] = 0;
                bVisited[r][c] = false;
            }
        }

        BFS(startR, startC);

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (Matrix[r][c] == 1 && Dist[r][c] == 0) {
                    Dist[r][c] = -1;
                }
            }
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                System.out.print(Dist[r][c]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    private static void BFS(int startR, int startC) {
        Queue<int[]> Q = new LinkedList<>();

        Q.add(new int[]{startR, startC});
        bVisited[startR][startC] = true;

        int r, c, nr, nc;
        int cur[];
        while (!Q.isEmpty()) {
            cur = Q.poll();
            r = cur[0];
            c = cur[1];

            for (int i = 0; i < 4; i++) {
                nr = r + Drow[i];
                nc = c + Dcol[i];
                if (nr >= N || nr < 0 || nc >= M || nc < 0) {
                    continue;
                }
                if (Matrix[nr][nc] == 1 && !bVisited[nr][nc]) {
                    Q.add(new int[]{nr, nc});
                    bVisited[nr][nc] = true;
                    Dist[nr][nc] = Dist[r][c] + 1;
                }
            }
        }
    }
}