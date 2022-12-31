#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int n_num(){
	int buff;
	scanf("%d",&buff);
	return buff;
}

Node* add_user() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

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
int get_score(Node* ptr, int id){
	switch(id){
		case 1: return ptr->std.score1;
		case 2: return ptr->std.score2;
		case 3: return ptr->std.score3;
		case 4: return ptr->std.score4;
		case 5: return ptr->std.score5;
	}
}

void query(Node* head, int id){
	Node* ptr = head;
	int max = INT_MIN;
	int min = INT_MAX;
	while(ptr != NULL){
		int score = get_score(ptr, id);
		if(max < score){
			max = score;
		}
		if(min > score){
			min = score;
		}
		ptr = ptr->next;
	}
	printf("%d %d\n",min,max);
}

int main(){
	int n = n_num();
	Node* ptr = NULL;
	Node* head = NULL;

	for(int i=0; i<n; i++){
		Node* user = add_user();		
		if (head == NULL){
			head = user;
			ptr = user;
		}else{
			ptr->next = user;
			ptr = ptr->next;
		}
	}
	int q = n_num();

	for(int i=0; i<q; i++){
		int id;
		char keyword[6];
		scanf("%s",keyword);

		if(strcmp(keyword,"query")==0){
			scanf("%d",&id);
			query(head,id);
		}
		if(strcmp(keyword,"add")==0){
			Node* user = add_user();		
			if (head == NULL){
				head = user;
				ptr = user;
			}else{
				ptr->next = user;
				ptr = ptr->next;
			}
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