// https://school.programmers.co.kr/learn/courses/30/lessons/12936
// 12936 줄 서는 방법

#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
  vector<int> answer;
  vector<int> pool;
  for (int i = 1; i <= n; i++) {
    pool.push_back(i);
  }

  for (int i = 0; i < n; i++) {
    int rem = (int)pool.size() - 1;
    long long fact = 1;
    while (rem > 1) fact *= rem--;

    long long q = k / fact;
    long long r = k % fact;
    if (r == 0) {
      q--;
      r = fact;
    }

    answer.push_back(pool[q]);
    pool.erase(pool.begin() + q);

    k = r;
  }

  return answer;
}
