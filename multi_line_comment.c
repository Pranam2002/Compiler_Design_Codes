#include <stdio.h>

int is_multi_line_comment(char *line) {
    if (line[0] == '/' && line[1] == '*') {
        int i = 2;
        while (line[i] != '\0') {
            if (line[i] == '*' && line[i + 1] == '/') {
                return 1;
            }
            if (line[i] == '\n') {
                return 0;
            }
            i++;
        }
    }
    return 0;
}

int main() {
    char line[100];

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    if (is_multi_line_comment(line)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}