#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct student{
    char name[50];
    int score1;
	int score2;
	int score3;
	int score4;
	int score5;
}Student;

typedef struct node{
    Student std;
    struct node* next;
}Node;

Node *head = NULL;

int num_exe(){
	//how many executions
	printf("How many students are there?\n");
	int buff;
	scanf("%d",&buff);
	return buff;
}

Node* add_user() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	printf("Enter student name and scores:\n");
	scanf("%s %d %d %d %d %d", 
		node->std.name, 
		&(node->std.score1),
		&(node->std.score2), 
		&(node->std.score3), 
		&(node->std.score4), 
		&(node->std.score5));

	return node;
}

void print_user(Node* user){
	printf("%s %d %d %d %d %d\n",
	user->std.name, 
	user->std.score1,
	user->std.score2, 
	user->std.score3, 
	user->std.score4, 
	user->std.score5);
}

int main(){
	int num = num_exe();
	Node* ptr = NULL;
	Node* head = NULL;

	for(int i=0; i<num; i++){
		Node* user = add_user();		
		if (head == NULL){
			head = user;
			ptr = user;
		}else{
			ptr->next = user;
			ptr = ptr->next;
		}
	}
	printf("\noutput:\n");
	ptr = head;
	while (ptr != NULL){
		print_user(ptr);
		ptr = ptr->next;
	}

    return 0;
}