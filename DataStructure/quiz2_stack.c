#include <stdio.h>
#include <stdlib.h>
#define Empty 0

typedef struct node {
    int Data;
    struct node* Link;
}Stack;
Stack* GetNode() {
    Stack* tmp = (Stack*)malloc(sizeof(Stack));
    tmp->Link = Empty;
    return tmp;
}
void push(Stack** top, int Data) {
    Stack* tmp = *top;
    *top = GetNode();
    (**top).Link = tmp;
    (**top).Data = Data;
}
int pop(Stack** top) {
    Stack* tmp = (**top).Link;
    int Data = (**top).Data;
    free(*top);
    *top = tmp;
    return Data;
}

int main() {
    Stack* p = Empty;
    Stack* tmp = p;
    int result = 0, cnt = 0, flag = 0;
    while (flag == 0) {
        int Choose, Data;
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. data\n");
        printf("4. stop\n");
        printf(">> ");
        scanf_s("%d", &Choose);
        switch (Choose) {
        case 1:
            printf("Data >> ");
            scanf_s("%d", &Data);
            push(&p, Data);
            cnt++;
            break;
        case 2:
            result = pop(&p);
            printf("pop : %d\n", result);
            cnt--;
            break;
        case 3:
            
            tmp = p;
            for (int i = 0; i < cnt; i++) {
                printf("%d\n", (*tmp).Data);
                tmp = (*tmp).Link;
            }
            break;
        case 4:
            flag = 1;
            break;
        default:
            printf("");
        }
    }
    return 0;
}