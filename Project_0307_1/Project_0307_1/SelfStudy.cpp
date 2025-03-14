#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 1. 문자 리스트를 문자열로 변환하기
//string solution(vector<string> arr) {
//    string answer = "";
//    string* sp = &arr[0];
//
//    for (int i = 0; i < arr.size(); i++) {
//        answer.append(*(sp + i));
//    }
//
//    return answer;
//}


// 2. 문자열 곱하기
//string solution(string my_string, int k) {
//    string answer = "";
//
//    for (int i = 0; i < k; i++) {
//        answer.append(my_string);
//    }
//    return answer;
//}


// 3. 더 크게 합치기
//int solution(int a, int b) {
//    int answer = 0;
//
//    string rightSumS = "";
//    string leftSumS = "";
//
//    rightSumS = rightSumS.append(to_string(a));
//    rightSumS = rightSumS.append(to_string(b));
//    int rightSumI = stoi(rightSumS);
//
//    leftSumS = leftSumS.append(to_string(b));
//    leftSumS = leftSumS.append(to_string(a));
//    int leftSumI = stoi(leftSumS);
//
//    if (rightSumI >= leftSumI) answer = rightSumI;
//    else answer = leftSumI;
//
//    return answer;
//}


// 4. 두 수의 연산값 비교하기
//int solution(int a, int b) {
//    int answer = 0;
//    int sum, multiplies;
//
//    sum = stoi(to_string(a) + to_string(b));
//    multiplies = 2 * a * b;
//
//    if (sum >= multiplies) answer = sum;
//    else answer = multiplies;
//
//    return answer;
//}

// 5. n의 배수
//int solution(int num, int n) {
//    int answer = 0;
//
//    if (num % n == 0) answer = 1;
//    else answer = 0;
//
//    return answer;
//}

// 6. 공배수
//int solution(int number, int n, int m) {
//    int answer = 0;
//
//    if (number % n == 0 && number % m == 0) answer = 1;
//    else answer = 0;
//
//    return answer;
//}

// 7. 홀짝
//int solution(int n) {
//    int answer = 0;
//
//    if (n % 2 == 0) {
//        for (int i = 2; i <= n; i += 2) {
//            answer += i * i;
//        }
//    }
//    else {
//        for (int i = 1; i <= n; i += 2) {
//            answer += i;
//        }
//    }
//
//    return answer;
//}

// 8. 조건 문자열
//int solution(string ineq, string eq, int n, int m) {
//    int answer = 0;
//
//    if (ineq.compare("<") == 0) {
//        if (eq.compare("=") == 0) {
//            cout << "<=" << endl;
//            if (n <= m) answer = 1;
//            else answer = 0;
//        }
//        else {
//            if (n < m) answer = 1;
//            else answer = 0;
//        }
//    }
//    else {
//        if (eq.compare("=") == 0) {
//            if (n >= m) answer = 1;
//            else answer = 0;
//        }
//        else {
//            cout << ">!" << endl;
//            if (n > m) answer = 1;
//            else answer = 0;
//        }
//    }
//
//    return answer;
//}

// 9. flag
//int solution(int a, int b, bool flag) {
//    int answer = 0;
//
//    if (flag) {
//        answer = a + b;
//    }
//    else answer = a - b;
//
//    return answer;
//}
