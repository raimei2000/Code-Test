// https://school.programmers.co.kr/learn/courses/30/lessons/64065
// 64065 튜플

#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> solution(string s) {
  // 양 끝 {} 지우기
  s.erase(s.size() - 1, 1);
  s.erase(0, 1);

  // 문자열 parsing
  vector<vector<int>> sets;
  size_t start = 0, end = 0;
  while (s.find('{', start) != string::npos) {
    start = s.find('{', start) + 1;
    end = s.find('}', start);
    string subset = s.substr(start, end - start);

    vector<int> current_set;
    stringstream ss(subset);
    string number;
    while (getline(ss, number, ',')) {
      current_set.push_back(stoi(number));
    }
    sets.push_back(current_set);
  }

  // subset 길이로 정렬
  sort(sets.begin(), sets.end(), [](const auto& a, const auto& b) { return a.size() < b.size(); });

  // 처음 보는 원소를 튜플에 삽입
  vector<int> answer;
  unordered_set<int> check;
  for (const vector<int>& subset : sets) {
    for (int n : subset) {
      if (check.insert(n).second) {
        answer.push_back(n);
        break;
      }
    }
  }

  return answer;
}