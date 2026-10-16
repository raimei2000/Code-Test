// https://school.programmers.co.kr/learn/courses/30/lessons/12900
// 12900 2 x n 타일링

using namespace std;

int solution(int n) {
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }

  const int k = 1000000007;
  int n1 = 1, n2 = 2;

  for (int i = 3; i <= n; i++) {
    int new_n = ((n1 % k) + (n2 % k)) % k;
    n1 = n2;
    n2 = new_n;
  }

  return n2;
}