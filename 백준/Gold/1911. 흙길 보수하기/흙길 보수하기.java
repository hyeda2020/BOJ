import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        PriorityQueue<Pair> PQ = new PriorityQueue<>();

        int start, end;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            start = Integer.parseInt(st.nextToken());
            end = Integer.parseInt(st.nextToken());
            PQ.add(new Pair(start, end));
        }

        int answer = 0;
        int cnt = 0;
        int lastPos = 0;
        while (!PQ.isEmpty()) {
            Pair cur = PQ.poll();
            start = cur.start;
            end = cur.end;

            if (end < lastPos) {
                continue;
            }

            if (start < lastPos) {
                start = lastPos;
            }

            cnt = (end - start) / L;
            if ((end - start) % L != 0) {
                cnt++;
            }

            lastPos = start + cnt * L;
            answer += cnt;
        }

        System.out.println(answer);
    }

    static class Pair implements Comparable<Pair> {
        public int start;
        public int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Pair o) {
            if (this.start == o.start) {
                return o.end - this.end;
            }
            return this.start - o.start;
        }
    }
}