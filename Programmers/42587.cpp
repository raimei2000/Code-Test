// https://school.programmers.co.kr/learn/courses/30/lessons/42587
// 42587 프로세스

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  vector<int> counts(10, 0);
  for (int n : priorities) counts[n]++;

  int i = 0;
  while (true) {
    int wait = priorities[i];
    if (wait == 0) {
      i = (i + 1) % priorities.size();
      continue;
    };
    bool good_to_ex = true;
    for (int j = wait + 1; j <= 9; j++) {
      if (counts[j] > 0) {
        good_to_ex = false;
        break;
      }
    }
    if (good_to_ex) {
      priorities[i] = 0;
      answer++;
      counts[wait]--;
      if (i == location) break;
    }
    i = (i + 1) % priorities.size();
  }
  return answer;
}