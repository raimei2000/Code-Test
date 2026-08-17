// https://school.programmers.co.kr/learn/courses/30/lessons/42578
// 42578 의상

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  unordered_map<string, int> table;
  for (const vector<string>& row : clothes) table[row[1]]++;
  for (const auto& [type, num] : table) answer *= num + 1;
  return answer - 1;
}