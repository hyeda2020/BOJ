import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        ArrayList<Integer> provinceBudgetList = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            provinceBudgetList.add(Integer.parseInt(st.nextToken()));
        }
        int totalBudget = Integer.parseInt(br.readLine());

        int answer = 0;
        int begin = 1;
        int end = Collections.max(provinceBudgetList);

        int mid;
        int tmpMaxBudget;

        while (begin <= end) {
            mid = (begin + end) / 2;
            tmpMaxBudget = getMaxBudget(provinceBudgetList, mid);

            if (tmpMaxBudget > totalBudget) {
                end = mid - 1;
            } else {
                begin = mid + 1;
                answer = mid;
            }
        }

        System.out.println(answer);
    }

    private static int getMaxBudget(ArrayList<Integer> provinceBudgetList, int value) {
        int ret = 0;
        for (int cur : provinceBudgetList) {
            if (cur < value) {
                ret += cur;
            } else {
                ret += value;
            }
        }
        return ret;
    }
}