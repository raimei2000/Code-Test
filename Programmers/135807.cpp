// https://school.programmers.co.kr/learn/courses/30/lessons/135807
// 135807 숫자 카드 나누기

#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
  int gcd_a = arrayA[0], gcd_b = arrayB[0];
  for (size_t i = 1; i < arrayA.size(); i++) {
    gcd_a = gcd(gcd_a, arrayA[i]);
  }
  for (size_t i = 1; i < arrayB.size(); i++) {
    gcd_b = gcd(gcd_b, arrayB[i]);
  }
  if (gcd_a == 1 && gcd_b == 1) return 0;
  bool flag_a = true;
  for (int n : arrayB) {
    if (n % gcd_a == 0) {
      flag_a = false;
      break;
    }
  }
  bool flag_b = true;
  for (int n : arrayA) {
    if (n % gcd_b == 0) {
      flag_b = false;
      break;
    }
  }
  if (flag_a && !flag_b) return gcd_a;
  else if (!flag_a && flag_b) return gcd_b;
  else if (flag_a && flag_b) return gcd_a > gcd_b ? gcd_a : gcd_b;
  else return 0;
}