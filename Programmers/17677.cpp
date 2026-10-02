// https://school.programmers.co.kr/learn/courses/30/lessons/17677
// 17677 [1차] 뉴스 클러스터링

#include <algorithm>
#include <cctype>
#include <set>
#include <string>

using namespace std;

void make_set(string s, multiset<string>& chunkset) {
  int i = 0;
  while (i < s.length() - 1) {
    string chunk = s.substr(i, 2);
    i++;

    transform(chunk.begin(), chunk.end(), chunk.begin(), [](unsigned char c) {  // 소문자로
      return tolower(c);
    });

    if (!all_of(chunk.begin(), chunk.end(), [](unsigned char c) {  // 알파벳만 있는지 확인
          return ('a' <= c) && (c <= 'z');
        })) {
      continue;
    }

    chunkset.insert(chunk);
  }
}

int solution(string str1, string str2) {
  const int k = 65536;
  multiset<string> set1;
  multiset<string> set2;

  make_set(str1, set1);
  make_set(str2, set2);

  if (set1.size() == 0 && set2.size() == 0) return k;

  multiset<string> inter_set;
  multiset<string> union_set;

  set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(inter_set, inter_set.begin()));
  set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
            inserter(union_set, union_set.begin()));

  int answer = inter_set.size() * k / (float)union_set.size();
  return answer;
}