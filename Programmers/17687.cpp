// https://school.programmers.co.kr/learn/courses/30/lessons/17687
// 17687 n진수 게임

#include <stack>
#include <string>

using namespace std;

string solution(int n, int t, int m, int p) {
  char af[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  int turn = 0;  // 첫 번째 순서가 0. 튜브 순서는 p - 1.
  int num = 0;
  string answer;

  while (answer.length() < t) {
    int target = num;
    if (target == 0) {
      if (turn == (p - 1)) {
        answer += to_string(0);
      }
      turn = (turn + 1) % m;
    }

    stack<int> st;
    while (target > 0) {
      st.push(target % n);
      target /= n;
    }

    while (!st.empty()) {
      int n = st.top();
      st.pop();
      if (turn == p - 1) {
        if (n < 10) {
          answer += to_string(n);
        } else {
          answer += af[n - 10];
        }
      }
      if (answer.length() >= t) {
        break;
      }
      turn = (turn + 1) % m;
    }
    num++;
  }

  return answer;
}