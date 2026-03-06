#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // If operand
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/') {
            int val1 = pop();
            int val2 = pop();
            int result;

            switch(exp[i]) {
                case '+': result = val2 + val1; break;
                case '-': result = val2 - val1; break;
                case '*': result = val2 * val1; break;
                case '/': result = val2 / val1; break;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}
