#include <stdio.h>
#include <string.h>

char* reverse(char str1[]);

int main() {
    char text[50];

    printf("Enter str1 : ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    char *output = reverse(text);

    printf("MAIN : %s\n", output);

    return 0;
}
char* reverse(char str1[]) {
    int len = strlen(str1);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    printf("FUNC : %s\n", str1);
    return str1;
}
