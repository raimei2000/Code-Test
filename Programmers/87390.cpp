// https://school.programmers.co.kr/learn/courses/30/lessons/87390
// 87390 n^2 배열 자르기

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
  vector<int> answer(right - left + 1);
  for (long long i = left; i <= right; i++) {
    int q = i / n;
    int r = i % n;
    int value = (q + 1) + ((r > q) ? r - q : 0);
    answer[i - left] = value;
  }
  return answer;
}