// https://school.programmers.co.kr/learn/courses/30/lessons/12913
// 12913 땅따먹기

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
  size_t n = land.size();
  for (size_t i = 1; i < n; i++) {
    land[i][0] += max({land[i - 1][1], land[i - 1][2], land[i - 1][3]});
    land[i][1] += max({land[i - 1][0], land[i - 1][2], land[i - 1][3]});
    land[i][2] += max({land[i - 1][0], land[i - 1][1], land[i - 1][3]});
    land[i][3] += max({land[i - 1][0], land[i - 1][1], land[i - 1][2]});
  }

  return max({land[n - 1][0], land[n - 1][1], land[n - 1][2], land[n - 1][3]});
}