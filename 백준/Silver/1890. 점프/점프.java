import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[][] gameBoard = new int[n][n];
        long[][] dp = new long[n][n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                gameBoard[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int jump = gameBoard[i][j];
                if( jump == 0 ) break;
                if( j + jump < n ) dp[i][j + jump] += dp[i][j];
                if( i + jump < n ) dp[i + jump][j] += dp[i][j];
            }
        }

        System.out.println(dp[n - 1][n - 1]);
    }
}