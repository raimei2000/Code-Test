// https://school.programmers.co.kr/learn/courses/30/lessons/81302
// 81302 거리두기 확인하기

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> dist_one = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> dist_dia = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
vector<vector<int>> dist_two = {{-2, 0}, {0, 2}, {2, 0}, {0, -2}};

bool is_valid(int i, int j) {
  if (i < 0 || 5 <= i || j < 0 || 5 <= j) {
    return false;
  } else {
    return true;
  }
}

bool check(const vector<string>& room) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (room[i][j] == 'P') {
        for (const vector<int>& d : dist_one) {  // 바로 옆자리 확인
          int a = i + d[0];
          int b = j + d[1];
          if (is_valid(a, b)) {
            if (room[a][b] == 'P') {
              return false;
            }  // 바로 옆자리에 있는 경우
          }
        }
        for (const vector<int>& d : dist_dia) {  // 대각선 자리 확인
          int a = i + d[0];
          int b = j + d[1];
          if (is_valid(a, b)) {
            if (room[a][b] == 'P') {  // 대각선에 있는 경우
              if (room[i][b] != 'X' || room[a][j] != 'X') {
                return false;
              }
            }
          }
        }
        for (const vector<int>& d : dist_two) {  // 직선 거리 2 확인
          int a = i + d[0];
          int b = j + d[1];
          if (is_valid(a, b)) {
            if (room[a][b] == 'P') {  // 직선 거리 2에 있는 경우
              if (room[i + d[0] / 2][j + d[1] / 2] != 'X') {
                return false;
              }
            }
          }
        }
      }
    }
  }
  return true;
}

vector<int> solution(vector<vector<string>> places) {
  vector<int> answer;
  for (const vector<string>& room : places) {
    if (check(room)) answer.push_back(1);
    else answer.push_back(0);
  }
  return answer;
}