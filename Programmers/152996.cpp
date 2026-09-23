// https://school.programmers.co.kr/learn/courses/30/lessons/152996
// 152996 시소 짝꿍

#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
  long long answer = 0;
  vector<int> table(1001, 0);
  int light = 10000, heavy = 0;
  for (int w : weights) {
    table[w]++;
    light = min(w, light);
    heavy = max(w, heavy);
  }
  for (int i = light; i <= heavy; i++) {
    if (table[i] == 0) continue;
    int n = table[i];

    answer += (long long)n * (n - 1) / 2;     // 몸무게가 같은 사람들끼리 쌍 계산. nC2
    if (i * 2 <= 1000 && table[i * 2] > 0) {  // 몸무게가 2배인 사람들과 계산.
      answer += (long long)n * table[i * 2];
    }
    if (i % 2 == 0 && i / 2 * 3 <= 1000 &&
        table[i / 2 * 3] > 0) {  // 몸무게가 3/2배인 사람들과 계산
      answer += (long long)n * table[i / 2 * 3];
    }
    if (i % 3 == 0 && i / 3 * 4 <= 1000 &&
        table[i / 3 * 4] > 0) {  // 몸무게가 4/3배인 사람들과 계산
      answer += (long long)n * table[i / 3 * 4];
    }
  }
  return answer;
}