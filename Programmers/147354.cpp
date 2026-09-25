// https://school.programmers.co.kr/learn/courses/30/lessons/147354
// 147354 테이블 해시 함수

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
  sort(data.begin(), data.end(), [&](const vector<int>& a, const vector<int>& b) -> bool {
    if (a[col - 1] != b[col - 1]) return a[col - 1] < b[col - 1];
    else return a[0] > b[0];
  });

  int answer = 0;
  for (int i = row_begin; i <= row_end; i++) {
    int sum = 0;
    for (int d : data[i - 1]) {
      sum += d % i;
    }
    answer ^= sum;
  }
  return answer;
}