#include <stdio.h>

int is_single_line_comment(char *line) {
    return (line[0] == '/' && line[1] == '/');
}

int main() {
    char line[100];

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);

    if (is_single_line_comment(line)) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}