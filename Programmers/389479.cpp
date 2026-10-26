// https://school.programmers.co.kr/learn/courses/30/lessons/389479
// 389479 서버 증설 횟수

#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
  int answer = 0;
  int server_running = 0;
  queue<pair<int, int>> expire;  // 만료시간, 만료시킬 서버 개수

  for (int i = 0; i < 24; i++) {
    // 만료된 서버가 있으면 만료된 서버 내리기
    if (expire.size() > 0) {
      if (expire.front().first <= i) {
        server_running -= expire.front().second;
        expire.pop();
      }
    }

    int server_needed = players[i] / m;
    if (server_running < server_needed) {
      int delta = server_needed - server_running;
      expire.push({i + k, delta});
      server_running += delta;
      answer += delta;
    }
  }

  return answer;
}