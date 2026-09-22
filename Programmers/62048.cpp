// https://school.programmers.co.kr/learn/courses/30/lessons/62048
// 62048 멀쩡한 사각형

#include <numeric>

using namespace std;
using int64 = long long;

long long solution(int w, int h) {
  int64 g = gcd(w, h);
  int64 answer = (int64)w * h;
  answer -= w + h - g;
  return answer;
}