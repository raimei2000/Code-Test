// https://school.programmers.co.kr/learn/courses/30/lessons/86971
// 86971 전력망을 둘로 나누기

#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int dfs(int cur, int cut_a, int cut_b, const vector<vector<int>>& adj, vector<bool>& visited) {
  visited[cur] = true;
  int count = 1;

  for (int next : adj[cur]) {
    if (visited[next]) continue;
    if ((cur == cut_a && next == cut_b) || (cur == cut_b && next == cut_a)) continue;
    count += dfs(next, cut_a, cut_b, adj, visited);
  }

  return count;
}

int solution(int n, vector<vector<int>> wires) {
  vector<vector<int>> adj(n + 1);
  for (const auto& w : wires) {
    adj[w[0]].push_back(w[1]);
    adj[w[1]].push_back(w[0]);
  }

  int answer = n;
  for (const auto& w : wires) {
    vector<bool> visited(n + 1, false);
    int count = dfs(w[0], w[0], w[1], adj, visited);
    answer = min(answer, abs(count - (n - count)));
  }
  return answer;
}