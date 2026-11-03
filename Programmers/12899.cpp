// https://school.programmers.co.kr/learn/courses/30/lessons/12899
// 124 나라의 숫자

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";

  while (n > 0) {
    if (n % 3 == 0) {
      answer += "4";
      n = n / 3 - 1;
    } else {
      answer += to_string(n % 3);
      n = n / 3;
    }
  }

  return string(answer.rbegin(), answer.rend());
}
