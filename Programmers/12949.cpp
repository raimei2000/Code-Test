// https://school.programmers.co.kr/learn/courses/30/lessons/12949
// 12949 행렬의 곱셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  int n = arr1.size();
  int m = arr2[0].size();
  int l = arr2.size();
  vector<vector<int>> answer(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < l; k++) {
        answer[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  return answer;
}