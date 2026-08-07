// https://school.programmers.co.kr/learn/courses/30/lessons/12914
// 12914 멀리 뛰기


#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
  long long a = 0;
  long long b = 1;
  for (int i = 1; i <= n; i++) {
    long long next = ((a % 1234567) + (b % 1234567)) % 1234567;
    a = b;
    b = next;
  }
  return b;
}