// https://school.programmers.co.kr/learn/courses/30/lessons/43165
// 43165 타겟 넘버

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int index, int sum, int& answer, const int& target) {
  if (index == numbers.size() - 1) {
    if (sum + numbers[index] == target) answer++;
    if (sum - numbers[index] == target) answer++;
  } else {
    dfs(numbers, index + 1, sum + numbers[index], answer, target);
    dfs(numbers, index + 1, sum - numbers[index], answer, target);
  }
}

int solution(vector<int> numbers, int target) {
  int answer = 0;
  dfs(numbers, 0, 0, answer, target);
  return answer;
}