// https://school.programmers.co.kr/learn/courses/30/lessons/12985
// 12985 예상 대진표

#include <iostream>
#include <cmath>

using namespace std;

// int solution(int n, int a, int b)
// {
//     int answer = 1;
//     if (a > b) swap(a, b);
//     while ((a <= n/2 && b <= n/2) || (n/2 < a && n/2 < b)) { 
//         n /= 2;
//         if (n < a) {
//             a -= n;
//             b -= n;
//         }
//     }
//     while ((int)pow(2, answer) < n) answer++;

//     return answer;
// }

int solution (int n, int a, int b) {
    int answer = 0;
    // 2로 나눈 몫으로 대결 그룹을 만들어간다. a와 b가 같은 그룹에 속할 때까지 반복한다.
    a--;
    b--;
    while (a != b) {
        a /= 2;
        b /= 2;
        answer++;
    }
}