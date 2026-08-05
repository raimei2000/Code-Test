// https://school.programmers.co.kr/learn/courses/30/lessons/12951
// 12951 JadenCase 문자열 만들기

#include <cctype>
#include <string>

using namespace std;

string solution(string s) {
  int idx = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ')
      idx = 0;
    else {
      idx++;
      if (idx == 1) {
        s[i] = toupper(s[i]);
      } else if (isupper(s[i])) {
        s[i] = tolower(s[i]);
      }
    }
  }
  return s;
}