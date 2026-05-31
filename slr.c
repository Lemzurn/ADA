#include <stdio.h>
#include <stdlib.h>

char input[20];
char stack[30];
int top = -1;
int input_pointer = 0;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void throw_error() {
    printf("\n\nSyntax Error: Parsing Failed\n");
    exit(1);
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

    push('0'); 
    
    printf("\nSTACK \t\t INPUT");
    printf("\n-----------------------------");

    while (1) {
        display_status();
        
        char current_state = stack[top];
        char current_input = input[input_pointer];

        switch (current_state) {
            case '0':
            case '2':
                if (current_input == 'a') {
                    input_pointer++; 
                    push('a'); 
                    push('2'); // Shift to state 2
                } else if (current_input == 'b') {
                    input_pointer++; 
                    push('b'); 
                    push('3'); 
                } else {
                    throw_error();
                }
                break;
                
            case '1':
                if (current_input == '$') {
                    printf("\n\nParsing Successful!\n");
                    exit(0);
                } else {
                    throw_error();
                }
                break;
                
            case '3':
                if (current_input == '$') {
                    pop(); pop(); 
                    push('S');
                    
                    if (stack[top - 1] == '0') push('1');
                    else if (stack[top - 1] == '2') push('4');
                    else throw_error();
                } else {
                    throw_error();
                }
                break;
                
            case '4':
                if (current_input == '$') {
                    pop(); pop(); pop(); pop(); 
                    push('S');
                    
                    if (stack[top - 1] == '0') push('1');
                    else if (stack[top - 1] == '2') push('4');
                    else throw_error();
                } else {
                    throw_error();
                }
                break;
                
            default:
                throw_error();
        }
    }
    
    return 0;
}
