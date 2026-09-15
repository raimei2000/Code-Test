// https://school.programmers.co.kr/learn/courses/30/lessons/140107
// 140107 점 찍기

#include <vector>

using namespace std;

long long solution(int k, int d) {
  long long answer = 0;
  long long dd = (long long)d * d;
  long long b = (long long)d / k;
  for (long long a = 0; a * k <= d; a++) {
    long long x = a * k;
    while (b > 0 && x * x + (b * k) * (b * k) > dd) {
      b--;
    }
    answer += b + 1;
  }
  return answer;
}