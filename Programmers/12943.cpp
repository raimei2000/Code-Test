// https://school.programmers.co.kr/learn/courses/30/lessons/12943
// 12943 콜라츠 추측

#include <string>
#include <vector>

using namespace std;

int solution(int num) {
  if (num == 1) return 0;

  long n = num;

  int i;
  for (i = 1; i <= 500; i++) {
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;

    if (n == 1) return i;
  }
  return -1;
}