#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyMap[10][10] = {"Zero", "One", "Two",   "Three", "Four",
                       "Five", "Six", "Seven", "Eight", "Nine"};

bool kiemTraSoNguyenTo(int number) {
    int i;
    for (i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int numberInput(char message[]) {
    int number;
reInput:
    printf("%s: ", message);
    if (!scanf("%d", &number)) {
        while (getchar() != '\n')
            ;
        goto reInput;
    }
    return number;
}

void bai1() {
    int a, b;
    a = numberInput("Nhập số A");
    b = numberInput("Nhập số B");

    printf("Các số nguyên tố trong khoảng A -> B là: \n");

    for (int i = a; i < b; i++) {

        bool isPass = true;
        for (int j = 2; j < sqrt(i); j++) {
            if (i % j == 0) {
                isPass = false;
                break;
            }
        }

        if (isPass && i > 1) {
            printf("%d ", i);
        }
    }
}

void bai2_5() {
    char* str;
    char* strRevert = malloc(1);
    int i = 0;

    printf("Mời nhập một chuỗi số:");
    scanf(" %[^\n]", str);

    char* session = strtok(str, " ");

    while (session != NULL) {
        int newLenth = strlen(strRevert) + strlen(session) + 1;
        char* concatStr = malloc(newLenth);

        strcpy(concatStr, session);
        strcat(concatStr, " ");
        strcat(concatStr, strRevert);

        strRevert = realloc(strRevert, newLenth);
        strcpy(strRevert, concatStr);

        free(concatStr);
        session = strtok(NULL, " ");
    }

    printf("Thứ tự đã được đảo ngược: %s", strRevert);
}

void bai3() {
    int i, input = numberInput("Nhập số cần tìm giai thừa");
    int result = input;

    for (i = input - 1; i > 0; i--) {
        result *= i;
    }

    printf("Giai thừa của %d là: %d ", input, result);
}

void bai4() {
    int i, j, result = 0, input = numberInput("Nhập số cần tính");

    for (i = 1; i <= input; i++) {
        for (j = 1; j <= i; j++) {
            result += j;
        }
    }

    printf("Kết quả là: %d \n", result);
}

void bai6() {
    char* str;
    int i;

    printf("Mời nhập một chuỗi số:");
    scanf(" %[^\n]", str);

    for (i = 0; i < strlen(str); i++) {
        printf("%s ", keyMap[(str[i] - '0')]);
    }
}

void bai7() {
    char* str;

    printf("Mời nhập một chuỗi số:");
    scanf(" %[^\n]", str);

    while (strlen(str) > 1) {
        const int mark = strlen(str) / 2;
        char *firstStr, *lastStr;

        strncpy(lastStr, str + mark, -1);
        strncpy(firstStr, str + 0, mark);

        int calc = atoi(lastStr) + atoi(firstStr);
        sprintf(str, "%d", calc);

        printf("Chuỗi đầu: %s\n", firstStr);
        printf("Chuỗi cuối: %s\n", lastStr);
        printf("Chuỗi hiện tại: %s\n", str);
    }
}

void bai8() {
    int core, number;
    for (core = 1; core < 10; core++) {
        for (number = 1; number <= 10; number++) {
            printf("%d * %d = %d\n", core, number, core * number);
        }
    }
}

void bai9() {
    int indexA, a = numberInput("Nhập số A");
    int indexB, b = numberInput("Nhập số B");
    int ucln, bcnn;

    for (indexA = a; indexA >= 1; indexA--) {
        if (a % indexA == 0) {
            for (indexB = b; indexB >= 1; indexB--) {
                if (b % indexB == 0 && indexA == indexB) {
                    ucln = indexB;
                    goto breakLoop;
                }
            }
        }
    }
breakLoop:
    bcnn = (a * b) / ucln;

    printf("Ước chung lớn nhất là: %d \n", ucln);
    printf("Bội chung nhỏ nhất là: %d \n", bcnn);
}

void bai10() {
    int input = numberInput("Nhập số nguyên dương");
    int i = 2;

    printf("Các thừa số nguyên tố của %d là: \n", input);

    while (input > 1 && i <= input) {
        if (input % i == 0) {
            printf("%d ", i);
            input /= i;
        } else {
            do {
                i++;
            } while (!kiemTraSoNguyenTo(i));
        }
    }
}

int main(int argc, const char* argv[]) {
    int i, input;

    for (i = 1; i <= 10; i++) {
        printf("[%d] Bài số: %d\n", i, i);
    }

reInput:
    input = numberInput("Nhập số bài");

    if (input > 10 || input < 1) {
        goto reInput;
    }

    switch (input) {
    case 1:
        bai1();
        break;

    case 2:
        bai2_5();
        break;
    case 3:
        bai3();
        break;
    case 4:
        bai4();
        break;
    case 5:
        bai2_5();
        break;
    case 6:
        bai6();
        break;
    case 7:
        bai7();
        break;
    case 8:
        bai8();
        break;
    case 9:
        bai9();
        break;
    case 10:
        bai10();
        break;
    default:
        break;
    }

    return 0;
}
