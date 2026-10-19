// https://school.programmers.co.kr/learn/courses/30/lessons/12939
// 12939 최댓값과 최솟값

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
  istringstream iss(s);

  int min_value;
  iss >> min_value;
  int max_value = min_value;
  int i;
  while (iss >> i) {
    min_value = min(min_value, i);
    max_value = max(max_value, i);
  }

  return to_string(min_value) + " " + to_string(max_value);
}