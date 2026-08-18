// https://school.programmers.co.kr/learn/courses/30/lessons/84512
// 84512 모음사전

#include <string>
#include <vector>

using namespace std;

int solution(string word) {
  vector<char> dict(5);
  vector<char> aeiou = {'A', 'E', 'I', 'O', 'U'};

  auto compare = [&]() -> bool {
    for (int i = 0; i < word.size(); i++) {
      if (dict[i] != word[i]) return false;
    }
    return true;
  };

  int answer = 0;
  for (char c0 : aeiou) {
    dict[0] = c0;
    answer++;
    if (compare()) {
      return answer;
    }
    for (char c1 : aeiou) {
      dict[1] = c1;
      answer++;
      if (compare()) {
        return answer;
      }
      for (char c2 : aeiou) {
        dict[2] = c2;
        answer++;
        if (compare()) {
          return answer;
        }
        for (char c3 : aeiou) {
          dict[3] = c3;
          answer++;
          if (compare()) {
            return answer;
          }
          for (char c4 : aeiou) {
            dict[4] = c4;
            answer++;
            if (compare()) {
              return answer;
            }
          }
          dict[4] = '\0';
        }
        dict[3] = '\0';
      }
      dict[2] = '\0';
    }
    dict[1] = '\0';
  }
  return answer;
}