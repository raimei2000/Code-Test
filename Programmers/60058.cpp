// https://school.programmers.co.kr/learn/courses/30/lessons/60058
// 60058 괄호 변환

#include <string>
#include <vector>

using namespace std;

bool is_correct(const string& p) {
  int stack = 0;
  for (const char c : p) {
    if (c == '(') stack++;
    else stack--;

    if (stack < 0) {
      return false;
    }
  }
  return stack == 0;
}

string correct(string& p) {
  if (p == "") return p;
  string u = "";
  string v = "";
  int num_o = 0, num_c = 0;

  for (size_t i = 0; i < p.length(); i++) {
    if (p[i] == '(') num_o++;
    else if (p[i] == ')') num_c++;

    if (num_o == num_c) break;
  }

  u = p.substr(0, num_o + num_c);
  if (num_o + num_c < p.length()) {
    v = p.substr(num_o + num_c);
  }

  if (is_correct(u)) {
    return u + correct(v);
  } else {
    string result = "(";
    result += correct(v);
    result += ")";

    string edited_u = "";
    for (size_t i = 0; i < u.length(); i++) {
      if (i != 0 && i != (u.length() - 1)) {
        edited_u += u[i] == '(' ? ')' : '(';
      }
    }
    return result + edited_u;
  }
}

string solution(string p) { return correct(p); }