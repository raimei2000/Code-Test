// https://school.programmers.co.kr/learn/courses/30/lessons/131701
// 131701 연속 부분 수열 합의 개수

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
  unordered_set<int> uns;
  int n = elements.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < i + n; j++) {
      sum += elements[j % n];
      uns.insert(sum);
    }
  }
  return uns.size();
}