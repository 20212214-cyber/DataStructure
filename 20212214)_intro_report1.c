#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int grades[10];
    int sum = 0;
    float average = 0.0;

    srand(time(NULL));

    printf("--- 학생 성적 생성 및 입력 ---\n");

    for (int i = 0; i < 10; i++) {
        grades[i] = rand() % 101;
        sum += grades[i];
        printf("학생 %2d: %3d점\n", i + 1, grades[i]);
    }

    average = (float)sum / 10;

    printf("----------------------------\n");
    printf("전체 합계: %d점\n", sum);
    printf("전체 평균: %.2f점\n", average);

    return 0;
}
