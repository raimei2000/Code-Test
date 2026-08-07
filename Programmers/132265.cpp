// https://school.programmers.co.kr/learn/courses/30/lessons/132265
// 132265 롤케이크 자르기

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;
  unordered_map<int, int> cheolsu;
  unordered_map<int, int> brother;
  cheolsu[topping[0]]++;
  for (int i = 1; i < topping.size(); i++) {
    brother[topping[i]]++;
  }
  for (int i = 1; i < topping.size(); i++) {
    int t = topping[i];
    cheolsu[t]++;
    brother[t]--;
    if (brother[t] == 0) brother.erase(t);
    if (cheolsu.size() == brother.size()) answer++;
  }
  return answer;
}