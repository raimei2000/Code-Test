// https://school.programmers.co.kr/learn/courses/30/lessons/12924
// 12924 숫자의 표현

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int half = n / 2;
  for (int i = 1; i <= half; i++) {
    int sum = 0;
    int k = i;
    while (sum < n) sum += k++;
    if (sum == n) answer++;
  }    
  return answer + 1;
}