// https://school.programmers.co.kr/learn/courses/30/lessons/178870
// 178870 연속된 부분 수열의 합

#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer(2);
  int length = 1e9, sum = 0;
  for (int start = 0, end = 0; end < sequence.size(); end++) {
    sum += sequence[end];
    while (sum > k) {
      sum -= sequence[start];
      start++;
    }
    if (sum == k && end - start < length) {
      length = end - start;
      answer[0] = start;
      answer[1] = end;
    }
  }
  return answer;
}