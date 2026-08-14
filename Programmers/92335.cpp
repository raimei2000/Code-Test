// https://school.programmers.co.kr/learn/courses/30/lessons/92335
// 92335 k진수에서 소수 개수 구하기

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_prime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

int solution(int n, int k) {
  int answer = 0;
  vector<int> temp;
  while (n > 0) {
    temp.push_back(n % k);
    n /= k;
  }
  vector<int> k_nary(temp.rbegin(), temp.rend());
  long long target = 0;
  for (int n : k_nary) {
    if (n != 0) {
      target *= 10;
      target += n;
    } else {
      if (is_prime(target)) answer++;
      target = 0;
    }
  }
  if (is_prime(target)) answer++;
  return answer;
}