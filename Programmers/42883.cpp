// https://school.programmers.co.kr/learn/courses/30/lessons/42883
// 42883 큰 수 만들기

#include <string>

using namespace std;

string solution(string number, int k) {
  string stk;
  stk.reserve(number.length());
  for (char c : number) {
    while (k > 0 && !stk.empty() && stk.back() < c) {
      stk.pop_back();
      k--;
    }
    stk.push_back(c);
  }
  // k개를 다 못지웠을 경우
  stk.resize(stk.length() - k);
  return stk;
}

// #include <string>

// using namespace std;

// string::iterator max(string::iterator start, string::iterator end) {
//   string::iterator max = start;
//   if (*max == '9') return max;
//   for (auto it = start; it <= end; it++) {
//     if (*max < *it) {
//       max = it;
//       if (*max == '9') return max;
//     }
//   }
//   return max;
// }

// string solution(string number, int k) {
//   string answer = "";
//   int len = number.length() - k;
//   auto start = number.begin();
//   for (int i = 0; i < len; i++) {
//     auto next = max(start, number.end() - len + i);
//     answer += *next;
//     start = next + 1;
//   }
//   return answer;
// }