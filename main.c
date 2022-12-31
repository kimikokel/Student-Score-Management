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

int get_sum(Student* std){
	return std->score1 + 
		std->score2 + 
		std->score3 + 
		std->score4 + 
		std->score5;
}

void print_user(Node* user){
	printf("%s %d %d %d %d %d [%d]\n",
		user->std.name, 
		user->std.score1,
		user->std.score2, 
		user->std.score3, 
		user->std.score4, 
		user->std.score5,
		get_sum(&(user->std))
	);
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



int comparator(const void *p, const void *q) 
{
	Student* Studentp = (Student*)p;
	Student* Studentq = (Student*)q;

	int sump = get_sum(Studentp);
	int sumq = get_sum(Studentq);

    return (sumq - sump);
}

void printArr(Student arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i){
        printf("%s ", arr[i].name);
	}
		printf("\n");
}

void list(Node* head, int n){
	printf("hi\n");
	Student std[100];
	Node* ptr = head;
	int i = 0;
	while (ptr != NULL){
		std[i] = ptr->std;
		ptr = ptr->next;
		// printf("i: %d, std[i]: %d\n",i,std[i].score1);
		i++;
	}
	printArr(std, i);
	qsort((void*)std, i, sizeof(std[0]), comparator);
	printArr(std, i);
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
		if(strcmp(keyword,"list")==0){
			scanf("%d",&n);
			list(head,n);
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

/*
int cmp(student1, student2) {
	if ... return +1
	if ... return -1
	return 0
}

void list(k) {
	Student arr[100];
	...
	while ...:
		arr[i] = ptr
		ptr = ptr->next


	quicksort(arr, ..., cmp, ...)

	for i 0...k :
		print(arr[i].name)
}
*/