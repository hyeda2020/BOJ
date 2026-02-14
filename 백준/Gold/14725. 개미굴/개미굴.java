import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Trie trie = new Trie("ROOT");
        int N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int K = Integer.parseInt(st.nextToken());

            List<String> inputList = new ArrayList<>();
            for (int k = 0; k < K; k++) {
                inputList.add(st.nextToken());
            }
            trie.insert(trie.root, inputList, 0);
        }
        trie.print(trie.root, -1);
    }

    public static class Trie {
        Node root;

        public Trie() {
            this.root = null;
        }

        public Trie(String val) {
            this.root = new Node(val);
        }

        public void insert(Node pos, List<String> inputList, int idx) {
            if (idx >= inputList.size()) {
                return;
            }

            String val =  inputList.get(idx);
            if (pos.child.get(val) == null) { // 없을 경우 새로 생성하여 자식에 추가
                pos.child.put(val, new Node(val));
            }
            insert(pos.child.get(val), inputList, idx + 1);
        }

        public void print(Node pos, int depth) {
            if (pos.val != "ROOT") {
                for (int i = 0; i < depth; i++) {
                    System.out.print("--");
                }
                System.out.println(pos.val);
            }
            for (Node child : pos.child.values()) {
                print(child, depth + 1);
            }
        }
    }

    public static class Node {
        String val;
        Map<String, Node> child;

        public Node(String val) {
            this.val = val;
            this.child = new TreeMap<>();
        }
    }
}