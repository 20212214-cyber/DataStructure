#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int len = strlen(input);
    char* stack = (char*)malloc(sizeof(char) * len);
    int top = -1;
    int isValid = 1;

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                isValid = 0;
                break;
            }

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                isValid = 0;
                break;
            }
        }
    }

    if (top != -1) isValid = 0;

    if (isValid) {
        printf("유효한 괄호\n");
    }
    else {
        printf("유효하지 않은 괄호\n");
    }

    free(stack);
    return 0;
}
