#include<stdio.h>
#include<stdlib.h>

/*Node*/
struct Node{
    int data;

    struct Node *next;
}*node;

/*Head*/
struct Head{
    int count;
    struct Node *p;
}*head;

/*Create Head*/
void create_head(){
    head = (struct Head*)malloc(sizeof(struct Head));
    head->count = 0;
    head->p = NULL;
}

/*Create Node*/
void create_node(){
    node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &node->data);
    node->next = NULL;
}

/*Display*/
void display(){
    struct Node *temp;
    temp = head->p;
    printf("\nDisplay:\n");
    printf("-------\n");
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
    printf("-------\n\n");
}

/*Display Top*/
void display_top(){
    if(head->p == 0){
        printf("\nNothing to display.\n");
    }
    else{
        struct Node *top;
        top = head->p;
        printf("Top data: %d\n",top->data);
    }
}

/*Push*/
void push(){
    create_node();
    node->next = head->p;
    head->p = node;
    head->count++;
}

/*Pop*/
void pop(){
    if(head->count == 0){
        printf("\n\nNo data for pop.\n");
    }
    else{
        struct Node *temp;
        temp = head->p;
        head->p = temp->next;
        free(temp);
        head->count--;
    }
}

int main(){
    create_head();
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
            push();
        }
        else if(n == 2){
            pop();
        }
        else if(n == 3){
            display();
        }
        else if(n == 4){
            display_top();
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
