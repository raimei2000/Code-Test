// https://school.programmers.co.kr/learn/courses/30/lessons/42577
// 42577 전화번호 목록

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
  sort(phone_book.begin(), phone_book.end());
  for (int i = 0; i < (int)phone_book.size() - 1; i++) {
    const string& current = phone_book[i];
    const string& next = phone_book[i + 1];
    if (next.find(current) == 0) return false;
  }
  return true;
}