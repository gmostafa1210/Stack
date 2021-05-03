#include <stdio.h>
#include <stdlib.h>


/*Node*/
struct Node{
    int data;
    struct Node *next;
}*node;

/*Head*/
struct Head{
    int count;
    struct Node *p;
}*head1,*head2;

/*Create Head 1*/
void create_head1(){
    head1 = (struct Head*)malloc(sizeof(struct Head));
    head1->count = 0;
    head1->p = NULL;
}

/*Create Head 2*/
void create_head2(){
    head2 = (struct Head*)malloc(sizeof(struct Head));
    head2->count = 0;
    head2->p = NULL;
}

/*Display1*/
void display1(){
    struct Node *temp;
    temp = head1->p;
    printf("\nDisplay 1:\n");
    printf("-------\n");
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
    printf("-------\n\n");
}

/*Display2*/
void display2(){
    struct Node *temp;
    temp = head2->p;
    printf("\nDisplay 2:\n");
    printf("-------\n");
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
    printf("-------\n\n");
}

/*Display Top1*/
void display_top1(){
    if(head1->p == 0){
        printf("\nNothing to display.\n");
    }
    else{
        struct Node *top;
        top = head1->p;
        printf("Top data: %d\n",top->data);
    }
}

/*Display Top2*/
void display_top2(){
    if(head2->p == 0){
        printf("\nNothing to display.\n");
    }
    else{
        struct Node *top;
        top = head2->p;
        printf("Top data: %d\n",top->data);
    }
}

/*Push 1*/
void push1(){
 node = (struct Node*)malloc(sizeof(struct Node));
 printf("Enter data: ");
 scanf("%d",&node->data);
 node->next = head1->p;
 head1->p = node;
 head1->count++;
}

/*Push 2*/
void push2(int x){
 node = (struct Node*)malloc(sizeof(struct Node));
 node->data = x;
 node->next = head2->p;
 head2->p = node;
 head2->count++;
}

/*Pop*/
void pop(){
    if(head1->count == 0){
        printf("No data for pop.\n");
    }
    else{
        struct Node *temp;
        int d;
        temp = head1->p;
        head1->p = temp->next;
        d = temp->data;
        free(temp);
        push2(d);
        head1->count--;
    }
}

int main(){
    create_head1();
    create_head2();
    printf("Stack\n");
    int n;
    while(1){
        printf("\nPress 1 for push.\n");
        printf("Press 2 for pop.\n");
        printf("Press 3 for display.\n");
        printf("Press 4 for display top.\n");
        printf("Press 0 for close program.\n\n");

        scanf("%d",&n);

        if(n == 1){
            push1();
        }
        else if(n == 2){
            pop();
        }
        else if(n == 3){
            printf("Press 1 for display 1.\n");
            printf("Press 2 for display 2.\n");
            int d;
            scanf("%d",&d);
            if(d == 1){
                display1();
            }
            else if(d == 2){
                display2();
            }
        }
        else if(n == 4){
            printf("Press 1 for display top1.\n");
            printf("Press 2 for display top2.\n");
            int dt;
            scanf("%d",&dt);
            if(dt == 1){
                display_top1();
            }
            else if(dt == 2){
                display_top2();
            }
        }
        else if(n == 0){
            printf("Thank You.");
            break;
        }
        else{
            printf("Invalid Input!\n");
            printf("Try Again\n");
        }
    }
    return 0;
}
