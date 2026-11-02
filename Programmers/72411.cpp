// https://school.programmers.co.kr/learn/courses/30/lessons/72411
// 72411 메뉴 리뉴얼

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void combination(const string& order, string& s, vector<unordered_map<string, int>>& vecmap,
                 int index, int r) {
  if (s.length() == r) {
    string temp = s;
    sort(temp.begin(), temp.end());
    vecmap[r][temp]++;
    return;
  }

  for (int i = index; i < order.size(); i++) {
    s += order[i];
    combination(order, s, vecmap, i + 1, r);
    s.pop_back();
  }
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<unordered_map<string, int>> vecmap(11);

  for (const string& order : orders) {
    for (int r : course) {
      string s;
      combination(order, s, vecmap, 0, r);
    }
  }

  vector<int> most;
  for (int c : course) {
    int max = 0;
    for (const auto& [s, n] : vecmap[c]) {
      if (max < n) max = n;
    }
    most.push_back(max);
  }

  vector<string> answer;
  for (int i = 0; i < course.size(); i++) {
    for (const auto& [s, n] : vecmap[course[i]]) {
      if (n == most[i] && n >= 2) {
        answer.push_back(s);
      }
    }
  }

  sort(answer.begin(), answer.end());
  return answer;
}