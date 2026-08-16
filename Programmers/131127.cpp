// https://school.programmers.co.kr/learn/courses/30/lessons/131127
// 131127 할인 행사

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  unordered_map<string, int> idx;
  for (int i = 0; i < want.size(); i++) idx[want[i]] = i;
  vector<int> count(want.size(), 0);
  for (int i = 0; i < 10; i++) {
    if (idx.contains(discount[i])) count[idx[discount[i]]]++;
  }
  auto IsMeet = [](const vector<int>& a, const vector<int>& b) -> bool {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) return false;
    }
    return true;
  };
  if (IsMeet(number, count)) answer++;
  int start = 1;
  int end = 10;
  while (end < discount.size()) {
    if (idx.contains(discount[start - 1])) count[idx[discount[start - 1]]]--;
    if (idx.contains(discount[end])) count[idx[discount[end]]]++;
    if (IsMeet(number, count)) answer++;
    start++;
    end++;
  }
  return answer;
}