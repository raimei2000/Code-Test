// https://school.programmers.co.kr/learn/courses/30/lessons/12978
// 12978 배달

#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
  const int INF = 1e9;

  vector<vector<pair<int, int>>> adj(N + 1);
  for (const auto& r : road) {
    adj[r[0]].push_back({r[1], r[2]});
    adj[r[1]].push_back({r[0], r[2]});
  }

  vector<int> dist(N + 1, INF);
  dist[1] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (d > dist[cur]) continue;

    for (const auto& [next, cost] : adj[cur]) {
      if (d + cost < dist[next]) {
        dist[next] = d + cost;
        pq.push({dist[next], next});
      }
    }
  }
  int answer = 0;
  for (int i = 1; i <= N; i++) {
    if (dist[i] <= K) answer++;
  }
  return answer;
}