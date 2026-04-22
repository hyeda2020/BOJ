import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static final int Dx[] = { 0, 0, 1, -1 };
    static final int Dy[] = { 1, -1, 0, 0 };
    static int N, M, K, Count;
    static boolean Matrix[][];

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Matrix = new boolean[N][M];
        for(int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            for(int y = y1; y < y2; y++) {
                for(int x = x1; x < x2; x++){
                    Matrix[y][x] = true;
                }
            }
        }

        ArrayList<Integer> resultList = new ArrayList<>();
        for(int i = 0; i< N; i++) {
            for(int j = 0; j < M; j++) {
                if(!Matrix[i][j]) {
                    Count = 0;
                    dfs(i, j);
                    resultList.add(Count);
                }
            }
        }

        Collections.sort(resultList);

        StringBuilder sb = new StringBuilder();
        sb.append(resultList.size()).append('\n');
        for(int cnt : resultList) {
            sb.append(cnt).append(" ");
        }
        System.out.println(sb.toString());
    }

    static void dfs(int x, int y) {
        Matrix[x][y] = true;
        Count++;

        for(int k = 0; k < 4; k++) {
            int nx = x + Dx[k];
            int ny = y + Dy[k];

            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                if(!Matrix[nx][ny]) {
                    dfs(nx,ny);
                }
            }
        }
    }
}