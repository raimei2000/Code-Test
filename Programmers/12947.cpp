// https://school.programmers.co.kr/learn/courses/30/lessons/12947
// 12947 하샤드 수
using namespace std;

bool solution(int x) {
  int og = x;
  int sum = 0;

  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }

  return og % sum == 0 ? true : false;
}