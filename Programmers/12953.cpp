// https://school.programmers.co.kr/learn/courses/30/lessons/12953
// 12953 N개의 최소공배수

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
  int answer = arr[0];
  for (int i = 1; i < arr.size(); i++) answer = lcm(answer, arr[i]);
  return answer;
}