// https://school.programmers.co.kr/learn/courses/30/lessons/12919
// 12919 서울에서 김서방 찾기

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
  auto it = find(seoul.begin(), seoul.end(), "Kim");
  string answer = "김서방은 " + to_string(distance(seoul.begin(), it)) + "에 있다";
  return answer;
}