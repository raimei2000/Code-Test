// https://school.programmers.co.kr/learn/courses/30/lessons/86051
// 86051 없는 숫자 더하기

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
  vector<int> mark(10, 0);

  for (int num : numbers) {
    mark[num]++;
  }

  int answer = 0;
  for (int i = 0; i < 10; i++) {
    if (mark[i] == 0) answer += i;
  }

  return answer;
}