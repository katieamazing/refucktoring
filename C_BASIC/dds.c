#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *subroutine_stack_pointer;
int subroutine_line_number_stack[999];
int for_loop_beginning_line_number[999];
int for_loop_maximum_index_value[999];
int program_variable_value[999];
int current_line;
int i;
int j;
char command_input_buffer[999];
char temporary_search_string[2];
char* program[12 * 999];
char* p;
char* q;
char* x;
char* y;
char* z;
char* s;
char* d;
FILE* f;

char* get_line() {
  if (fgets(command_input_buffer, sizeof(command_input_buffer), stdin) != 0) {
    size_t len = strlen(command_input_buffer);
    if (len > 0 && command_input_buffer[len-1] == '\n') {
      command_input_buffer[len-1] = '\0';
    }
    return command_input_buffer;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  program[11 * 999] = "E"; /* END */
  while (puts("Ok"), get_line()) {
    switch (*command_input_buffer) {
      case 'R': /* "RUN" command */
        subroutine_stack_pointer = subroutine_line_number_stack;
        current_line = 1;
        for (i = 0; i < 999; i++) {
          program_variable_value[i] = 0;
        }
        while (current_line) {
          while (!(s = program[current_line])) {
            current_line++;
          }
          if (!strstr(s, "\"")) {
            while (p = strstr(s, "<>")) {
              *p++ = '#';
              *p = ' ';
            }
            while (p = strstr(s, "<=")) {
              *p++ = '$';
              *p = ' ';
            }
            while (p = strstr(s, ">=")) {
              *p++ = '!';
              *p = ' ';
            }
          }
          d = command_input_buffer;
          while (*temporary_search_string = *s) {
            if (*s == '"') {
              j++;
            }
            if (j & 1 || !strstr(" \t", temporary_search_string)) {
              *d++ = *s;
            }
            s++;
          }
          *d-- = j = 0;
          if (command_input_buffer[1] != '=')
            switch (*command_input_buffer) {
              case 'E': /* "END" */
                current_line = -1;
                break;
              case 'R': /* "REM" or "RETURN" */
                if (command_input_buffer[2] != 'M') { /* "RETURN" */
                  current_line = *--subroutine_stack_pointer;
                }
                break;
              case 'I':
                if (command_input_buffer[1] == 'N') { /* "INPUT" */
                  p = command_input_buffer;
                  get_line();
                  program_variable_value[*d] = evaluate_expression();
                } else { /* "IF" */
                  *(q = strstr(command_input_buffer, "TH")) = 0; /* "THEN" */
                  p = command_input_buffer + 2;
                  if (evaluate_expression()) {
                    p = q + 4;
                    current_line = evaluate_expression() - 1;
                  }
                }
                break;
              case 'P': /* "PRINT" */
                if (command_input_buffer[5] == '"') {
                  *d = 0;
                  puts(command_input_buffer + 6);
                } else {
                  p = command_input_buffer + 5;
                  printf("%d\n", evaluate_expression());
                }
                break;
              case 'G': /* "GOTO" */
                p = command_input_buffer + 4;
                if (command_input_buffer[2] == 'S') { /* "GOSUB */
                  *subroutine_stack_pointer++ = current_line;
                  p++;
                }
                current_line = evaluate_expression() - 1;
                break;
              case 'F': /* "FOR" */
                *(q = strstr(command_input_buffer, "TO")) = 0;
                p = command_input_buffer + 5;
                program_variable_value[i = command_input_buffer[3]] = evaluate_expression();
                p = q + 2;
                for_loop_maximum_index_value[i] = evaluate_expression();
                for_loop_beginning_line_number[i] = current_line;
                break;
              case 'N': /* "NEXT" */
                if (++program_variable_value[*d] <= for_loop_maximum_index_value[*d]) {
                  current_line = for_loop_beginning_line_number[*d];
                }
            }
          else {
            p = command_input_buffer + 2;
            program_variable_value[*command_input_buffer] = evaluate_expression();
          }
          current_line++;
        };
        break;
      case 'L': /* "LIST" */
        for (i = 0; i < 11 * 999; i++) {
          if (program[i]) {
            printf("%d %s\n", i, program[i]);
          }
        }
        break;
      case 'N': /* "NEW" */
        for (i = 0; i < 11 * 999; i++) {
          if (program[i]) {
            free(program[i]);
          }
          program[i] = 0;
        }
        break;
      case 'B': /* "BYE" */
        return 0;
        break;
      case 'S': /* "SAVE" */
        f = fopen(command_input_buffer + 5, "w");
        for (i = 0; i < 11 * 999; i++) {
          if (program[i]) {
            fprintf(f, "%d %s\n", i, program[i]);
          }
        }
        fclose(f);
        break;
      case 'O': /* "OLD" */
        f = fopen(command_input_buffer + 4, "r");
        while (fgets(command_input_buffer, 999, f)) {
          *strstr(command_input_buffer, "\n") = 0;
          get_program_line_from_buffer();
        };
        fclose(f);
        break;
      case 0:
      default:
        get_program_line_from_buffer();
    }
  }
  return 0;
}

int get_program_line_from_buffer() {
  current_line = atoi(command_input_buffer);
  if (program[current_line]) {
    free(program[current_line]);
  }
  p = strstr(command_input_buffer, " ");
  if (p) {
    return strcpy(program[current_line] = malloc(strlen(p)), p + 1);
  } else {
    program[current_line] = 0;
    return 0;
  }
}

int evaluate_expression() {
  int output = evaluate_comparison();
  switch (*p++) {
    case '=':
      return output == evaluate_expression();
      break;
    case '#':
      return output != evaluate_expression();
    default:
      p--;
      return output;
  }
}

int evaluate_comparison() {
  int output = evaluate_non_strict_comparison();
  switch (*p++) {
    case '<':
      return output < evaluate_comparison();
      break;
    case '>':
      return output > evaluate_comparison();
    default:
      p--;
      return output;
  }
}

int evaluate_non_strict_comparison() {
  int output = evaluate_additive_expression();
  switch (*p++) {
    case '$':
      return output <= evaluate_non_strict_comparison();
      break;
    case '!':
      return output >= evaluate_non_strict_comparison();
    default:
      p--;
      return output;
  }
}

int evaluate_additive_expression() {
  int output = evaluate_multiplicative_expression();
  switch (*p++) {
    case '+':
      return output + evaluate_additive_expression();
      break;
    case '-':
      return output - evaluate_additive_expression();
    default:
      p--;
      return output;
  }
}

int evaluate_multiplicative_expression() {
  int output = evaluate_leaf_expression();
  switch (*p++) {
    case '*':
      return output * evaluate_multiplicative_expression();
    case '/':
      return output / evaluate_multiplicative_expression();
    default:
      p--;
      return output;
  }
}

int evaluate_leaf_expression() {
  int output;

  if (*p == '-') {
    p++;
    return -evaluate_leaf_expression();
  } else if (*p >= '0' && *p <= '9') {
    return strtol(p, &p, 0);
  } else if (*p == '(') {
    p++;
    output = evaluate_expression();
    p++;
    return output;
  } else {
    return program_variable_value[*p++];
  }
}
