// https://school.programmers.co.kr/learn/courses/30/lessons/12935
// 12935 제일 작은 수 제거하기

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  if (arr.size() == 1) return vector<int>(1, -1);

  vector<int> answer(arr);
  auto min = min_element(answer.begin(), answer.end());
  answer.erase(min);

  return answer;
}