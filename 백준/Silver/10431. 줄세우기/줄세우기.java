import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int P = Integer.parseInt(st.nextToken());
        int T, val, answer;
        for (int i = 1; i <= P; i++) {
            answer = 0;
            st = new StringTokenizer(br.readLine());
            T = Integer.parseInt(st.nextToken());
            List<Integer> list = new ArrayList<>();

            for (int j = 0; j < 20; j++) {
                val = Integer.parseInt(st.nextToken());
                list.add(val);
                answer += move(list);
            }

            System.out.println(T + " " + answer);
        }
        br.close();
    }
    private static int move(List<Integer> list) {
        int ret = 0;
        Integer last = list.get(list.size() - 1);
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) > last) {
                list.add(i, last);
                list.remove(list.size() - 1);
                ret += (list.size() - i - 1);
                break;
            }
        }
        return ret;
    }
}