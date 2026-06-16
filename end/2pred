#include <stdio.h>
#include <stdlib.h>

char input[20];
char stack[20];
int top = -1;
int input_pointer = 0;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void display_status() {
    printf("\n");
    for (int i = 0; i <= top; i++) printf("%c", stack[i]);
    printf("\t\t");
    for (int i = input_pointer; input[i] != '\0'; i++) printf("%c", input[i]);
}

int main() {
    printf("Enter string ending with $ (e.g., aab$): ");
    scanf("%s", input);

    // Initialize the top-down parser
    push('$'); 
    push('S'); 

    printf("\nSTACK \t\t INPUT");
    printf("\n-----------------------------");

    while (1) {
        display_status();
        
        char stack_top = stack[top];
        char current_input = input[input_pointer];

        // 1. ACCEPT
        if (stack_top == '$' && current_input == '$') {
            printf("\n\nParsing Successful!\n");
            break;
        }
        // 2. MATCH
        else if (stack_top == current_input) {
            pop();
            input_pointer++;
        }
        // 3. PREDICTIVE RULE for 'S'
        else if (stack_top == 'S') {
            if (current_input == 'a') {
                // Rule: S -> aS (push in reverse order)
                pop();
                push('S');
                push('a');
            } else if (current_input == 'b') {
                // Rule: S -> b
                pop();
                push('b');
            } else {
                printf("\n\nSyntax Error: Unexpected character!\n");
                break;
            }
        }
        // 4. INVALID
        else {
            printf("\n\nSyntax Error!\n");
            break;
        }
    }
    
    return 0;
}
