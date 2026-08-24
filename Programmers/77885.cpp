// https://school.programmers.co.kr/learn/courses/30/lessons/77885
// 77885 2개 이하로 다른 비트

#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
  vector<long long> answer;
  answer.reserve(numbers.size());

  for (long long num : numbers) {
    if (num % 2 == 0) answer.push_back(num + 1);
    else {
      long long bit = ~num & (num + 1);
      answer.push_back(num + bit - (bit >> 1));
    }
  }

  return answer;
}