// https://school.programmers.co.kr/learn/courses/30/lessons/154538
// 154538 숫자 변환하기

#include <algorithm>
#include <vector>

using namespace std;

int solution(int x, int y, int n) {
  const int INF = 1e9;
  vector<int> dp(y + 1, INF);
  dp[x] = 0;
  for (int v = x; v < y; v++) {
    if (dp[v] == -1) continue;

    int count = dp[v] + 1;
    if (v + n <= y) dp[v + n] = min(count, dp[v + n]);
    if (v * 2 <= y) dp[v * 2] = min(count, dp[v * 2]);
    if (v * 3 <= y) dp[v * 3] = min(count, dp[v * 3]);
  }
  if (dp[y] == INF) dp[y] = -1;
  return dp[y];
}