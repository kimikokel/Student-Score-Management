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
	printf("n: \n");
	int buff;
	scanf("%d",&buff);
	return buff;
}

Node* add_user() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	// printf("Enter student name and scores:\n");
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

Node* query(Node* user, int id){
	Node* ptr = user;
	int max = -1000;
	int min = 1000;
	// while(ptr != NULL){
	// 	if(max < ptr->std.score1){
	// 		max = ptr->std.score1;
	// 		ptr = ptr->next;
	// 	}
	// }
	// ptr = user;

///////fucking skipped the first user fuck this shit diu

	while(ptr != NULL){
		printf("min origin: %d, next is:\n",min);
		if(min > ptr->std.score1){
			min = ptr->std.score1;
			printf("min now: %d, next is:\n",min);
			ptr = ptr->next;
		}
	}
	printf("min: %d max: %d\n",min,max);
	// switch(id){
	// 	case 1:
	// 		while(ptr != NULL){
	// 			if(max < ptr->std.score1){
	// 				max = ptr->std.score1;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		while(ptr != NULL){
	// 			if(min > ptr->std.score1){
	// 				min = ptr->std.score1;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		printf("min: %d max: %d\n",min,max);
	// 		break;
	// 	case 2:
	// 		while(ptr != NULL){
	// 			if(max < ptr->std.score2){
	// 				max = ptr->std.score2;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		while(ptr != NULL){
	// 			if(min > ptr->std.score2){
	// 				min = ptr->std.score2;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		printf("min: %d max: %d\n",min,max);
	// 		break;
	// 	case 3:
	// 		while(ptr != NULL){
	// 			if(max < ptr->std.score3){
	// 				max = ptr->std.score3;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		while(ptr != NULL){
	// 			if(min > ptr->std.score3){
	// 				min = ptr->std.score3;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		printf("min: %d max: %d\n",min,max);
	// 		break;
	// 	case 4:
	// 		while(ptr != NULL){
	// 			if(max < ptr->std.score4){
	// 				max = ptr->std.score4;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		while(ptr != NULL){
	// 			if(min > ptr->std.score4){
	// 				min = ptr->std.score4;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		printf("min: %d max: %d\n",min,max);
	// 		break;
	// 	case 5:
	// 		while(ptr != NULL){
	// 			if(max < ptr->std.score5){
	// 				max = ptr->std.score5;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		while(ptr != NULL){
	// 			if(min > ptr->std.score5){
	// 				min = ptr->std.score5;
	// 				ptr = ptr->next;
	// 			}
	// 		}
	// 		printf("min: %d max: %d\n",min,max);
	// 		break;
	// }
	return user;
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
		scanf("%s %d",keyword,&id);
		printf("keyword: %s id: %d\n",keyword,id);

		if(strcmp(keyword,"query")){
			printf("no\n");
		}else{
			printf("yes\n");
			query(ptr,q);
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