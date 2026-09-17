// https://school.programmers.co.kr/learn/courses/30/lessons/148653
// 148653 마법의 엘리베이터

int solution(int storey) {
  int answer = 0;

  while (storey > 0) {
    int digit = storey % 10;

    if (digit >= 6) {
      answer += (10 - digit);  // 올림
      storey = storey / 10 + 1;
    } else if (digit <= 4) {
      answer += digit;  // 내림
      storey /= 10;
    } else {  // digit == 5. 올리든 내리든 비용은 같음.
      answer += 5;
      storey /= 10;
      if (storey % 10 >= 5) storey += 1;  // 윗자리가 5이상이면 올림.
    }
  }
  return answer;
}