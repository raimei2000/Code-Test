// https://school.programmers.co.kr/learn/courses/30/lessons/142085
// 142085 디펜스 게임

#include <queue>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
  priority_queue<int, vector<int>, greater<int>> min_heap;
  int answer = 0;
  long long acc_enemy = 0;
  long long ignored_enemy = 0;

  for (int i = 0; i < enemy.size(); i++) {
    acc_enemy += (long long)enemy[i];
    if (i < k) {
      min_heap.push(enemy[i]);
      ignored_enemy += (long long)enemy[i];
    } else if (min_heap.top() < enemy[i]) {
      ignored_enemy -= (long long)min_heap.top();
      min_heap.pop();
      ignored_enemy += (long long)enemy[i];
      min_heap.push(enemy[i]);
    }

    if (acc_enemy - ignored_enemy <= n) {
      answer++;
    } else {
      break;
    }
  }

  return answer;
}
