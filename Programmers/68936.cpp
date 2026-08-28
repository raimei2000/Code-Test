// https://school.programmers.co.kr/learn/courses/30/lessons/68936
// 68936 쿼드압축 후 개수 세기

#include <vector>

using namespace std;

void compress(const vector<vector<int>>& arr, int start_x, int end_x, int start_y, int end_y,
              vector<int>& answer) {
  int cnt0 = 0;
  int cnt1 = 0;
  for (int i = start_x; i <= end_x; i++) {
    for (int j = start_y; j <= end_y; j++) {
      (arr[i][j] == 0) ? cnt0++ : cnt1++;
      if (cnt0 * cnt1 == 0) continue;      // 영역에 하나의 수만 존재
      if (end_x - start_x == 1) continue;  // 더 이상 쪼갤 수 없음
      // 4개의 영역으로 나눔
      int half_x = (start_x + end_x) / 2;
      int half_y = (start_y + end_y) / 2;
      compress(arr, start_x, half_x, start_y, half_y, answer);      // 좌상단
      compress(arr, start_x, half_x, half_y + 1, end_y, answer);    // 우상단
      compress(arr, half_x + 1, end_x, start_y, half_y, answer);    // 좌하단
      compress(arr, half_x + 1, end_x, half_y + 1, end_y, answer);  // 우하단
      return;
    }
  }
  if (cnt0 * cnt1 == 0) (cnt0 >= 1) ? answer[0]++ : answer[1]++;
  else if (end_x - start_x == 1) {
    answer[0] += cnt0;
    answer[1] += cnt1;
  }
}

vector<int> solution(vector<vector<int>> arr) {
  vector<int> answer(2, 0);
  int n = arr.size();
  compress(arr, 0, n - 1, 0, n - 1, answer);
  return answer;
}