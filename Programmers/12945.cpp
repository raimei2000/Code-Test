// https://school.programmers.co.kr/learn/courses/30/lessons/12945
// 12945 피보나치 수

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int prev1 = 0;
  int prev2 = 1;
  int mod = 1234567;
  for (int i = 2; i <= n; i++) {
    answer = (prev1 % mod + prev2 % mod) % mod;
    prev1 = prev2;
    prev2 = answer;
  }
  return answer;
}