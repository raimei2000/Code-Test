// https://school.programmers.co.kr/learn/courses/30/lessons/42746
// 42746 가장 큰 수

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b) { return a + b > b + a; }

string solution(vector<int> numbers) {
  vector<string> strings;
  strings.reserve(numbers.size());
  for (int n : numbers) strings.push_back(to_string(n));

  sort(strings.begin(), strings.end(), compare);
  string answer = "";
  if (strings[0] == "0") return "0";
  for (const string& s : strings) {
    answer += s;
  }
  return answer;
}