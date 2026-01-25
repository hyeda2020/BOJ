import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static boolean[][] chessMap;
    static int[] Drow = { -1, -2, -2, -1, 1, 2, 2, 1 };
    static int[] Dcol = { -2, -1, 1, 2, 2, 1, -1, -2 };

    public static void main(String[] args) throws IOException {

        chessMap = new boolean[301][301];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int testCase = Integer.parseInt(st.nextToken());
        int length;
        int startRow, startCol, destRow, destCol;
        for (int t = 0; t < testCase; t++) {
            st = new StringTokenizer(br.readLine());
            length = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            startRow = Integer.parseInt(st.nextToken());
            startCol = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            destRow = Integer.parseInt(st.nextToken());
            destCol = Integer.parseInt(st.nextToken());

            System.out.println(bfs(startRow, startCol, destRow, destCol, length));
            resetChessMap(length);
        }
    }

    static int bfs(int startRow, int startCol, int destRow, int destCol, int length) {
        Queue<Night> queue = new LinkedList<>();
        queue.add(new Night(startRow, startCol, 0));
        chessMap[startRow][startCol] = true;

        Night cur;
        int nrow, ncol;
        int ret = 0;
        while (!queue.isEmpty()) {
            cur = queue.poll();
            if (cur.row == destRow && cur.col == destCol) {
                ret = cur.cnt;
                break;
            }

            for (int i = 0; i < 8; i++) {
                nrow = cur.row + Drow[i];
                ncol = cur.col + Dcol[i];
                if (nrow < 0 || nrow >= length || ncol < 0 || ncol >= length) {
                    continue;
                }
                if (!chessMap[nrow][ncol]) {
                    chessMap[nrow][ncol] = true;
                    queue.add(new Night(nrow, ncol, cur.cnt + 1));
                }
            }

        }
        return ret;
    }

    static void resetChessMap(int length) {
        for (int r = 0; r < length; r++) {
            for (int c = 0; c < length; c++) {
                chessMap[r][c] = false;
            }
        }
    }

    public static class Night {
        int row;
        int col;
        int cnt;

        public Night(int row, int col, int cnt) {
            this.row = row;
            this.col = col;
            this.cnt = cnt;
        }
    }
}