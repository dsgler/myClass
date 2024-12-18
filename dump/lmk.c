#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 10
#define MAX_VAR_LEN 21

void remove_whitespace_and_vars(FILE *input, FILE *output, char vars[MAX_VARS][MAX_VAR_LEN], int var_count) {
    char ch;
    char buffer[MAX_VAR_LEN];
    int buf_index = 0;
    int in_var = 0;

    while ((ch = fgetc(input)) != EOF) {
        if (isspace(ch)) {
            // in_var=0;
            if (in_var) {
                buffer[buf_index] = '\0';
                int is_var = 0;
                for (int i = 0; i < var_count; i++) {
                    if (strcmp(buffer, vars[i]) == 0) {
                        is_var = 1;
                        break;
                    }
                }
                if (!is_var) {
                    fprintf(output, "%s", buffer);
                }
                buf_index = 0;
                in_var = 0;
            }
            continue; // 跳过所有空白字符
        }

        if (isalpha(ch) || ch == '_') {
            buffer[buf_index++] = ch;
            in_var = 1;
        } else if (isdigit(ch) && in_var) {
            buffer[buf_index++] = ch;
        } else {
            if (in_var) {
                buffer[buf_index] = '\0';
                int is_var = 0;
                for (int i = 0; i < var_count; i++) {
                    if (strcmp(buffer, vars[i]) == 0) {
                        is_var = 1;
                        break;
                    }
                }
                if (!is_var) {
                    fprintf(output, "%s", buffer);
                }
                buf_index = 0;
                in_var = 0;
            }
            if (ch != ' ' && ch != '\t' && ch != '\n') {
                fputc(ch, output);
            }
        }
    }
}

int main() {
    FILE *input = fopen("input.c", "r");
    FILE *output = fopen("output.c", "w");

    if (!input || !output) {
        printf("Error opening file.\n");
        return 1;
    }

    char vars[MAX_VARS][MAX_VAR_LEN];
    int var_count = 0;
    char word[MAX_VAR_LEN];

    while (fscanf(input, "%s", word) != EOF) {
        if (strcmp(word, "int") == 0) {
            while (fscanf(input, "%s", word) != EOF && strcmp(word, ";") != 0) {
                if (strcmp(word, ",") != 0) {
                    strcpy(vars[var_count++], word);
                }
            }
            break;
        }
    }

    fseek(input, 0, SEEK_SET);
    remove_whitespace_and_vars(input, output, vars, var_count);

    fclose(input);
    fclose(output);

    return 0;
}