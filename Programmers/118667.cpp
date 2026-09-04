// https://school.programmers.co.kr/learn/courses/30/lessons/118667
// 118667 두 큐 합 같게 만들기

#include <deque>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
  queue<int> q1(deque<int>(queue1.begin(), queue1.end()));
  queue<int> q2(deque<int>(queue2.begin(), queue2.end()));

  long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
  long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
  if ((sum1 + sum2) % 2 != 0) return -1;

  int answer = 0;
  bool flag = false;
  int limit = queue1.size() * 3;
  while (!q1.empty() && !q2.empty() && sum1 != sum2) {
    if (sum1 > sum2) {
      int pop = q1.front();
      sum1 -= pop;
      q1.pop();
      q2.push(pop);
      sum2 += pop;
      answer++;
    } else {
      int pop = q2.front();
      sum2 -= pop;
      q2.pop();
      q1.push(pop);
      sum1 += pop;
      answer++;
    }
    if (answer > limit) break;
  }
  if (sum1 == sum2) flag = true;
  return flag ? answer : -1;
}