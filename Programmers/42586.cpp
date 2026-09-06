// https://school.programmers.co.kr/learn/courses/30/lessons/42586
// 42586 기능개발

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  for (int i = 0; i < progresses.size(); i++) {
    int rest = 100 - progresses[i];
    int days =
        (rest % speeds[i] == 0) ? (rest / speeds[i]) : (rest / speeds[i] + 1);
    progresses[i] = days;
  }
  int last_day = progresses[0];
  int commit = 0;
  for (int day : progresses) {
    if (last_day >= day)
      commit++;
    else {
      answer.push_back(commit);
      last_day = day;
      commit = 1;
    }
  }
  answer.push_back(commit);
  return answer;
}