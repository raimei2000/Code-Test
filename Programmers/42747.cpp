// https://school.programmers.co.kr/learn/courses/30/lessons/42747
// 42747 H-Index

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;
  sort(citations.rbegin(), citations.rend());
  for (int i = 0; i < citations.size(); i++) {
    if (citations[i] >= i + 1)
      answer++;
    else
      break;
  }
  return answer;
}