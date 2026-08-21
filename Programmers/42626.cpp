// https://school.programmers.co.kr/learn/courses/30/lessons/42626
// 42626 더 맵게

#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

  int answer = 0;
  while (pq.size() > 1 && pq.top() < K) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    pq.push(a + b * 2);
    answer++;
  }
  return pq.top() >= K ? answer : -1;
}