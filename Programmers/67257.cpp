// https://school.programmers.co.kr/learn/courses/30/lessons/67257
// 67257 [카카오 인턴] 수식 최대화

#include <algorithm>
#include <list>
#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {
  long long answer = 0;
  vector<char> priority = {'+', '-', '*'};
  sort(priority.begin(), priority.end());

  list<long long> operands;
  list<char> operators;
  string temp = "";
  for (const char c : expression) {
    if (c == '+' || c == '-' || c == '*') {
      operands.push_back(stoll(temp));
      temp = "";
      operators.push_back(c);
    } else {
      temp += c;
    }
  }
  operands.push_back(stoll(temp));  // 마지막 피연산자

  do {
    list<long long> cycle_operands(operands);
    list<char> cycle_operators(operators);

    for (const char p : priority) {
      list<long long> temp_operands;
      list<char> temp_operators;

      while (!cycle_operators.empty()) {
        if (cycle_operators.front() == p) {
          long long a = cycle_operands.front();
          cycle_operands.pop_front();
          long long b = cycle_operands.front();
          cycle_operands.pop_front();
          long long n;
          switch (cycle_operators.front()) {
            case '+':
              n = a + b;
              break;
            case '-':
              n = a - b;
              break;
            case '*':
              n = a * b;
              break;
          }
          cycle_operands.push_front(n);
          cycle_operators.pop_front();
        } else {
          temp_operands.push_back(cycle_operands.front());
          cycle_operands.pop_front();
          temp_operators.push_back(cycle_operators.front());
          cycle_operators.pop_front();
        }
      }
      temp_operands.push_back(cycle_operands.front());
      cycle_operands.pop_front();

      cycle_operands.swap(temp_operands);
      cycle_operators.swap(temp_operators);
    }

    long long result =
        cycle_operands.front() > 0 ? cycle_operands.front() : -cycle_operands.front();
    if (answer < result) answer = result;

  } while (next_permutation(priority.begin(), priority.end()));

  return answer;
}