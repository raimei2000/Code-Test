// https://school.programmers.co.kr/learn/courses/30/lessons/12948
// 12948 핸드폰 번호 가리기

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
  int asterisk = phone_number.length() - 4;
  string answer(asterisk, '*');
  answer.append(phone_number.substr(asterisk));

  return answer;
}