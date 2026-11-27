#include <stdio.h>
#define SIZE 50   
struct HalfAdder {
    int a,b,sum,carry;
};
struct HalfAdder stack[SIZE];
int top = -1;     
void push(struct HalfAdder h) {
    if (top == SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = h;
}

void pop() {
    if (top == -1) {
        printf("Nothing to remove, stack is empty\n");
        return;
    }
    printf("Removed: A=%d B=%d Sum=%d Carry=%d\n",
           stack[top].a, stack[top].b, stack[top].sum, stack[top].carry);
    top--;
}

void display() {
    int i;
    if (top == -1) {
        printf("No history yet\n");
        return;
    }
    printf("\nA B | Sum Carry\n");
    for (i = top; i >= 0; i--) {
        printf("%d %d |  %d    %d\n",
               stack[i].a, stack[i].b, stack[i].sum, stack[i].carry);
    }
}

void calculate(struct HalfAdder *h) {
    h->sum = h->a ^ h->b;     
    h->carry = h->a & h->b;  
}
int getBit(char name) {
    int x;
    printf("Enter %c (0 or 1): ", name);
    scanf("%d", &x);
    while (x != 0 && x != 1) {
        printf("Wrong input, enter only 0 or 1: ");
        scanf("%d", &x);
    }
    return x;
}

void main() {
    int choice;
    struct HalfAdder h;
    do {
        printf("\n--- HALF ADDER ---\n");
        printf("1. Calculate\n");
        printf("2. Show history\n");
        printf("3. Remove last result\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            h.a = getBit('A');
            h.b = getBit('B');
            calculate(&h);
            printf("Sum = %d, Carry = %d\n", h.sum, h.carry);
            push(h);
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            pop();
        }
        else if (choice != 4) {
            printf("Invalid choice\n");
        }
    } while (choice != 4);
}
