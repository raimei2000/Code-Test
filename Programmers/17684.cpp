// https://school.programmers.co.kr/learn/courses/30/lessons/17684
// 17684 압축

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
  vector<int> answer;
  unordered_map<string, int> dict;

  for (int i = 0; i < 26; i++) {
    char c = static_cast<char>('A' + i);
    string s(1, c);
    dict.insert({s, i + 1});
  }
  int dict_num = 26;

  int i = 0;
  while (i < msg.length()) {
    string sub = string(1, msg[i]);
    while (dict.contains(sub) && i < msg.length()) {
      i++;
      sub += msg[i];
    }
    dict.insert({sub, ++dict_num});
    answer.push_back(dict[sub.substr(0, sub.length() - 1)]);
  }

  return answer;
}