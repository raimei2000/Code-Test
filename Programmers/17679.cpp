// https://school.programmers.co.kr/learn/courses/30/lessons/17679#
// 17679 [1차] 프렌즈4블록

#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
  int dx[] = {0, 1, 1};
  int dy[] = {1, 1, 0};

  int answer = 0;

  while (true) {
    set<pair<int, int>> pang;
    for (int i = 0; i < m - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        char target = board[i][j];
        if (target == ' ') {
          continue;
        }

        bool flag = true;
        for (int k = 0; k < 3; k++) {
          if (board[i + dx[k]][j + dy[k]] != target) {
            flag = false;
            break;
          }
        }
        if (flag) {
          pang.insert({i, j});
          pang.insert({i + dx[0], j + dy[0]});
          pang.insert({i + dx[1], j + dy[1]});
          pang.insert({i + dx[2], j + dy[2]});
        }
      }
    }
    if (pang.size() == 0) break;
    answer += pang.size();

    // 터진 자리 비우기
    for (const auto& p : pang) {
      board[p.first][p.second] = ' ';
    }

    // 비어있는 칸 채우기
    for (int j = 0; j < n; j++) {
      int write = m - 1;
      for (int i = m - 1; i >= 0; i--) {
        if (board[i][j] != ' ') {
          board[write--][j] = board[i][j];
        }
      }
      while (write >= 0) {
        board[write--][j] = ' ';
      }
    }
  }

  return answer;
}