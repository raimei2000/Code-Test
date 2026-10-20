// https://school.programmers.co.kr/learn/courses/30/lessons/17686
// 17686 [3차] 파일명 정렬

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

bool stable_compare(const string& s1, const string& s2) {
  string a = s1, b = s2;

  size_t a_num = 0, a_tail = 0, b_num = 0, b_tail = 0;  // 각 부분의 시작 인덱스
  for (size_t i = 1; i < a.length(); i++) {
    if (isdigit(a[i])) {
      a_num = i;
      break;
    }
  }
  for (size_t i = a_num + 1; i < a.length(); i++) {
    if (!isdigit(a[i]) || i >= a_num + 5) {  // NUMBER는 최대 5자리
      a_tail = i;
      break;
    }
  }
  if (a_tail == 0) {
    a_tail = a.length();
  }  // NUMBER로 끝나면 TAIL의 시작점을 문자열 끝으로

  for (size_t i = 1; i < b.length(); i++) {
    if (isdigit(b[i])) {
      b_num = i;
      break;
    }
  }
  for (size_t i = b_num + 1; i < b.length(); i++) {
    if (!isdigit(b[i]) || i >= b_num + 5) {  // NUMBER는 최대 5자리
      b_tail = i;
      break;
    }
  }
  if (b_tail == 0) {
    b_tail = b.length();
  }  // NUMBER로 끝나면 TAIL의 시작점을 문자열 끝으로

  string a_head = a.substr(0, a_num);
  string b_head = b.substr(0, b_num);

  transform(a_head.begin(), a_head.end(), a_head.begin(),
            [](unsigned char c) { return tolower(c); });
  transform(b_head.begin(), b_head.end(), b_head.begin(),
            [](unsigned char c) { return tolower(c); });

  if (a_head != b_head) {
    return a_head < b_head;
  } else {
    int num_a = stoi(a.substr(a_num, a_tail - a_num));
    int num_b = stoi(b.substr(b_num, b_tail - b_num));
    if (num_a != num_b) {
      return num_a < num_b;
    } else {
      return false;
    }
  }
}

vector<string> solution(vector<string> files) {
  stable_sort(files.begin(), files.end(), stable_compare);
  return files;
}