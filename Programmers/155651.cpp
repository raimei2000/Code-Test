// https://school.programmers.co.kr/learn/courses/30/lessons/155651
// 155651 호텔 대실

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int stotime(const string& s) {
  int hour = stoi(s.substr(0, 2));
  int min = stoi(s.substr(3, 2));
  return hour * 60 + min;
}
int solution(vector<vector<string>> book_time) {
  vector<int> table(1449);  // 23 * 60 + 59 = 1439 (+ 청소시간 10분)
  for (const vector<string>& bt : book_time) {
    int start = stotime(bt[0]);
    int end = stotime(bt[1]) + 10;
    table[start]++;
    table[end]--;
  }

  int answer = 0, cur = 0;
  for (int t : table) {
    cur += t;
    answer = max(answer, cur);
  }
  return answer;
}