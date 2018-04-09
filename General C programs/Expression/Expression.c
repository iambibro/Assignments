#include <stdio.h>
#include <string.h>
#include <stdint.h>

char closing(char open){
    return open == '(' ? ')' : open == '[' ? ']' : '}'; 
}

char opening(char closing){
    return closing == ')' ? '(' : closing == '}' ? '{' : '[';
}

int main(){
    char expr[100];
    printf("\nEnter the expression : ");
    fgets(expr, 98, stdin);
    size_t len = strlen(expr), i = 0;
    char stack[len];
    uint64_t sp = 0;
    while(i < len){
        switch(expr[i]){
            case '(':
            case '{':
            case '[':
                stack[sp++] = expr[i];
                break;
            case ')':
            case '}':
            case ']':
                if(sp == 0){
                    printf("\nUnexpected closing brace : '%c'\n", expr[i]);
                    sp = 1;
		break;
                }
                if(stack[sp - 1] != opening(expr[i])){
                    //printf("\nExpected closing : '%c'\nReceived : '%c'!\n", expected, recieved );
                    break;
                }
                else
                    sp--;
        }
        i++;
    }
    if(sp == 0) 
        printf("\nThe given expression is valid in terms of paranthesis!\n");
    else
        printf("\nThe given expression is not valid in terms of paranthesis!\n");
    return 0;
}

