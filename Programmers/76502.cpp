// https://school.programmers.co.kr/learn/courses/30/lessons/76502
// 76502 괄호 회전하기

#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int solution(string s) {
  stack<char> st;
  auto Check = [&st](const string& s) -> bool {
    while (!st.empty()) st.pop();
    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') st.push(c);
      else {
        if (st.empty()) return false;
        char target = st.top();
        st.pop();
        if (abs(c - target) > 2) return false;
      }
    }
    return st.empty();
  };
  int answer = Check(s) ? 1 : 0;
  for (int i = 1; i < s.length(); i++) {
    s += s[0];
    s.erase(s.begin());
    if (Check(s)) answer++;
  }
  return answer;
}