import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int[] Drow = { 0, -1, 0, 1 };
    static int[] Dcol = { -1, 0, 1, 0 };

    static int N, M;
    static int[][] iceBerg;
    static int[][] tmpIceBerg;
    static boolean[][] bVisited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int maxHeight = 0;
        int curHeight = 0;

        iceBerg = new int[N][M];
        tmpIceBerg = new int[N][M];
        bVisited = new boolean[N][M];

        for (int r = 0; r < N; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 0; c < M; c++) {
                curHeight = Integer.parseInt(st.nextToken());
                iceBerg[r][c] = curHeight;
                maxHeight = Math.max(maxHeight, curHeight);
            }
        }

        System.out.println(solution(maxHeight));
    }

    static int solution(int maxHeight) {
        int depth = 0;
        int cnt = 0;
        int iceBergCnt = 0;
        while (!checkAllMelted()) {
            for (int r = 0; r < N; r++) {
                Arrays.fill(bVisited[r], false);
            }

            deepCopyToTmp();
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < M; c++) {
                    if (iceBerg[r][c] > 0 && !bVisited[r][c]) {
                        dfs(r, c);
                        cnt++;
                    }
                }
            }
            iceBergCnt = Math.max(iceBergCnt, cnt);
            if (iceBergCnt >= 2) {
                break;
            }
            cnt = 0;
            meltIceBerg();
            depth++;
        }

        if (iceBergCnt < 2) {
            depth = 0;
        }

        return depth;
    }

    static void dfs(int r, int c) {
        bVisited[r][c] = true;
        int nr, nc;
        for (int i = 0; i < 4; i++) {
            nr = r + Drow[i];
            nc = c + Dcol[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }
            if (iceBerg[nr][nc] > 0 && !bVisited[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }

    static void meltIceBerg() {
        int nr, nc;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (tmpIceBerg[r][c] > 0) {
                    for (int i = 0; i < 4; i++) {
                        nr = r + Drow[i];
                        nc = c + Dcol[i];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                            continue;
                        }
                        if (tmpIceBerg[nr][nc] == 0) {
                            iceBerg[r][c] -= 1;
                        }
                    }
                    iceBerg[r][c] = Math.max(iceBerg[r][c], 0);
                }
            }
        }
    }

    static void deepCopyToTmp() {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                tmpIceBerg[r][c] = iceBerg[r][c];
            }
        }
    }

    static boolean checkAllMelted() {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (iceBerg[r][c] > 0) {
                    return false;
                }
            }
        }
        return true;
    }
}