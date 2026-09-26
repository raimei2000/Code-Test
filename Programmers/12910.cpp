// https://school.programmers.co.kr/learn/courses/30/lessons/12910
// 12910 나누어 떨어지는 숫자 배열

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
  vector<int> answer;
  for (int element : arr) {
    if (element % divisor == 0) answer.push_back(element);
  }

  if (answer.size() == 0) {
    answer.push_back(-1);
  }
  sort(answer.begin(), answer.end());
  return answer;
}