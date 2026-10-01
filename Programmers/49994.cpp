// https://school.programmers.co.kr/learn/courses/30/lessons/49994
// 49994 방문 길이

#include <format>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool valid_trans(vector<int>& p, int dx, int dy) {
  int nx = p[0] + dx;
  int ny = p[1] + dy;
  if (-5 <= nx && nx <= 5 && -5 <= ny && ny <= 5) {
    p[0] = nx;
    p[1] = ny;
    return true;
  }
  return false;
}

int solution(string dirs) {
  unordered_set<string> paths;

  vector<int> point(2, 0);  // (0,0) 에서 시작
  vector<int> delta(2, 0);

  int answer = 0;
  for (char d : dirs) {
    vector<int> cached_point(point.begin(), point.end());
    switch (d) {
      case 'U': {
        delta[0] = 0;
        delta[1] = 1;
        break;
      }
      case 'D': {
        delta[0] = 0;
        delta[1] = -1;
        break;
      }
      case 'R': {
        delta[0] = 1;
        delta[1] = 0;
        break;
      }
      case 'L': {
        delta[0] = -1;
        delta[1] = 0;
        break;
      }
    }
    if (valid_trans(point, delta[0], delta[1])) {
      string path1 =
          format("({0},{1}) > ({2},{3})", cached_point[0], cached_point[1], point[0], point[1]);
      if (paths.insert(path1).second) {
        answer++;
        string path2 =
            format("({0},{1}) > ({2},{3})", point[0], point[1], cached_point[0], cached_point[1]);
        paths.insert(path2);
      }
    }
  }
  return answer;
}