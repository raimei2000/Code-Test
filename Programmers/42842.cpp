// https://school.programmers.co.kr/learn/courses/30/lessons/42842
// 42842 카펫

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  long long area = brown + yellow;
  long long i = 3;
  int x, y;
  while (i * i <= area) {
    if (area % i == 0) {
      x = i;
      y = area / i;
      if ((x - 2) * (y - 2) == yellow) break;
    }
    i++;
  }
  return vector<int> {max(x, y), min(x, y)};
}