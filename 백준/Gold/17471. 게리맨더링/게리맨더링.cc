#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int N;
vector<int> populations;
vector<vector<int>> graph;

int calcDiff(const vector<int>& regions) {
    int total = 0;
    for (int region : regions) {
        total += populations[region];
    }
    return total;
}

bool isConnected(const vector<int>& regions) {
    vector<bool> visited(N, false);
    queue<int> q;

    q.push(regions[0]);
    visited[regions[0]] = true;

    int connected_count = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            if (!visited[next] && find(regions.begin(), regions.end(), next) != regions.end()) {
                visited[next] = true;
                q.push(next);
                connected_count++;
            }
        }
    }

    return connected_count == regions.size();
}

int solve() {
    int ans = INF;

    // 부분 집합을 이용하여 구역을 나눈다.
    for (int i = 1; i < (1 << N); ++i) {
        vector<int> A, B;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                A.push_back(j);
            }
            else {
                B.push_back(j);
            }
        }

        // A, B가 각각 최소 한 개의 구역을 가지고 있는지 확인한다.
        if (A.size() == 0 || B.size() == 0) continue;

        // A, B가 서로 연결되어 있는지 확인한다.
        if (!isConnected(A) || !isConnected(B)) continue;

        // 인구 수 차이를 계산하여 최솟값을 갱신한다.
        ans = min(ans, abs(calcDiff(A) - calcDiff(B)));
    }

    return (ans == INF) ? -1 : ans;
}

int main() {
    cin >> N;

    populations.resize(N);
    graph.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> populations[i];
    }

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor - 1);
        }
    }

    cout << solve() << endl;

    return 0;
}