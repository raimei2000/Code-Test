// https://school.programmers.co.kr/learn/courses/30/lessons/154539
// 154539 뒤에 있는 큰 수 찾기

#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
  vector<int> answer(numbers.size(), -1);
  stack<int> stk;
  for (int i = 0; i < numbers.size(); i++) {
    while (!stk.empty() && numbers[stk.top()] < numbers[i]) {
      answer[stk.top()] = numbers[i];
      stk.pop();
    }
    stk.push(i);
  }
  return answer;
}