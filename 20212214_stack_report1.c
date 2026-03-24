#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101]; 
    
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int length = strlen(input);

    char *stack = (char *)malloc(sizeof(char) * length);
    if (stack == NULL) {
        return 1; 
    }

    int top = -1;
    for (int i = 0; i < length; i++) {
        stack[++top] = input[i];
    }

    printf("거꾸로 출력된 문자열: ");
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    free(stack);

    return 0;
}
