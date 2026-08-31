// https://school.programmers.co.kr/learn/courses/30/lessons/131704
// 131704 택배상자

#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
  int answer = 0;
  int n = order.size();
  stack<int> stk;
  int i = 0;
  while (i < n && answer < n) {
    while (i < n && (i + 1) != order[answer]) {
      stk.push(i + 1);
      i++;
    }
    while ((i < n && order[answer] == (i + 1)) || (!stk.empty() && order[answer] == stk.top())) {
      if (order[answer] == (i + 1)) {
        i++;
        answer++;
      } else if (order[answer] == stk.top()) {
        stk.pop();
        answer++;
      }
    }
    if (answer < n && order[answer] < i + 1) break;
  }
  return answer;
}