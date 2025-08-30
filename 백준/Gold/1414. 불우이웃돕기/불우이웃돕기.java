import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Node>[] Graph;
    static boolean[] bVisited;

    public static class Node implements Comparable<Node> {
        int dest;
        int cost;

        public Node(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    public static boolean checkAllVisited(int n) {
        boolean ret = true;
        for (int i = 0; i < n; i++) {
            if (!bVisited[i]) {
                ret = false;
                break;
            }
        }
        return ret;
    }

    static public int prim(int n) {
        int ret = 0;

        PriorityQueue<Node> PQ = new PriorityQueue<>();
        PQ.add(new Node(0, 0));

        int cur, cost;
        while (!PQ.isEmpty()) {
            Node curNode = PQ.poll();
            cur = curNode.dest;
            cost = curNode.cost;
            if (bVisited[cur]) {
                continue;
            }

            bVisited[cur] = true;
            ret += cost;

            for (Node next : Graph[cur]) {
                if (cur != next.dest && next.cost > 0) {
                    PQ.add(new Node(next.dest, next.cost));
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        String input;
        int val;

        bVisited = new boolean[N];
        Graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            Graph[i] = new ArrayList<>();
            bVisited[i] = false;
        }


        int totLength = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            input = st.nextToken();
            for (int j = 0; j < input.length(); j++) {
                if (input.charAt(j) >= 'a' && input.charAt(j) <= 'z') {
                    val = input.charAt(j) - 96;
                } else if (input.charAt(j) == '0') {
                    val = 0;
                } else {
                    val = input.charAt(j) - 38;
                }

                Graph[i].add(new Node(j, val));
                Graph[j].add(new Node(i, val));
                totLength += val;
            }
        }

        int minLength = prim(N);
        int answer = 0;
        if (minLength > 0 && checkAllVisited(N)) {
            answer = totLength - minLength;
        } else if (N == 1) {
            answer = Graph[0].get(0).cost;
        } else {
            answer = -1;
        }

        System.out.println(answer);
    }
}