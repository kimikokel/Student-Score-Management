#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct user{
    char name[50];
    int score[100];
}student;

typedef struct Node{
    student std;
    struct Node* next;
}node;

node *head = NULL;

int num_exe(){
	//how many executions
	printf("How many students are there?\n");
	int buff;
	scanf("%d",buff);
	return buff;
}

void adduser() {
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->next = NULL;

	node* p = head;
	while (head != NULL && p->next != NULL)
	{
		p = p->next;
	}

	if (head == NULL) {
		head = NewNode;
	}
	else {
		p->next = NewNode;
	}

	printf("Enter student name and scores:\n");
	scanf("%s %d %d %d %d %d", NewNode->std.name, &NewNode->std.score[0], &NewNode->std.score[1], &NewNode->std.score[2], &NewNode->std.score[3], &NewNode->std.score[4]);
	//&NewNode->std.score->next

	printf("%s %d %d %d %d %d\n\n", NewNode->std.name, &NewNode->std.score[0], &NewNode->std.score[1], &NewNode->std.score[2], &NewNode->std.score[3], &NewNode->std.score[4]);
	printf("Success...\n\n");
}

int main(){
	// int loops = num_exe();
	adduser();
	// for(int i=0; i<loops; i++){
	// 	adduser();
	// }
    return 0;
}