// https://school.programmers.co.kr/learn/courses/30/lessons/68645
// 68645 삼각 달팽이

#include <vector>

using namespace std;

int index(int row, int col) {
  int idx = (row - 1) * row / 2;
  return idx + (col - 1);
}

vector<int> solution(int n) {
  int size = n * (n + 1) / 2;
  vector<int> answer(size);
  int row = 1, col = 1, direction = 0;
  int dr[] = {1, 0, -1};
  int dc[] = {0, 1, -1};
  for (int i = 1; i <= size; i++) {
    answer[index(row, col)] = i;

    int new_row = row + dr[direction];
    int new_col = col + dc[direction];

    // 방향전환
    if (new_row < 1 || n < new_row || new_col < 1 || new_row < new_col ||
        answer[index(new_row, new_col)] != 0) {
      direction = (direction + 1) % 3;
      new_row = row + dr[direction];
      new_col = col + dc[direction];
    }
    row = new_row;
    col = new_col;
  }
  return answer;
}