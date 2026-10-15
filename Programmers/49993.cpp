// https://school.programmers.co.kr/learn/courses/30/lessons/49993
// 49993 스킬트리

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;
  unordered_map<char, int> umap;
  for (int i = 0; i < skill.length(); i++) {
    umap[skill[i]] = i;
  }

  for (const string& tree : skill_trees) {
    int order = 0;
    bool flag = true;
    for (const char c : tree) {
      if (umap.contains(c)) {
        if (umap[c] == order) {
          order++;
        } else {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      answer++;
    }
  }

  return answer;
}