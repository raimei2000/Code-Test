// https://school.programmers.co.kr/learn/courses/30/lessons/42839
// 42839 소수 찾기

#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

bool is_prime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}

int solution(string numbers) {
  unordered_set<int> primes;
  unordered_set<int> checked;
  sort(numbers.begin(), numbers.end());
  const int n = numbers.size();

  do {
    int target = 0;
    for (int i = 0; i < n; i++) {
      target = target * 10 + (numbers[i] - '0');
      if (!checked.insert(target).second) continue;
      if (is_prime(target)) primes.insert(target);
    }
  } while (next_permutation(numbers.begin(), numbers.end()));

  return primes.size();
}