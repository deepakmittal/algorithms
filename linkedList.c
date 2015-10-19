#include <stdlib.h>
#include <stdio.h>
struct node	{
	int data;
	struct node *next;
};



void add(struct node ** root,int data){
	struct node* n = malloc( sizeof(struct node) );
	n->data = data;
	n->next = NULL;
	if(*root == NULL){
		*root = n;
		return;
	}
	struct node *temp = *root;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
}

void push(struct node **root,int data){
	struct node* n = malloc( sizeof(struct node) );
	n->data = data;
	n->next = *root;
	*root = n;
}

int pop(struct node **root){
	if(*root == NULL){
		return 0;
	}
	int rtn = (*root)->data;
	*root = (*root)->next;
	return rtn;
}

void traverse(struct node *root){
	struct node * temp = root;
	printf("\n");
	while(temp != NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
}

void reverse1(struct node **root){
	struct node * temp = *root;
	if(temp == NULL || temp->next == NULL) 
		return;
	struct node *a = NULL;
	struct node *b = temp;
	struct node *c = temp->next;
	struct node *d = NULL; // NULL
	do{
		d = c->next;
		b->next = a;
		c->next = b;
		
		a = b;
		b = c;
		c = d;

	}while(c != NULL);
	*root = b;
}

void reverse(struct node ** root){
	if(root==NULL || (*root)==NULL || (*root)->next == NULL){
		return;
 	}
 	struct node * a = *root;
	struct node * b = NULL;
	struct node * c = NULL;
	while(a !=NULL){
		c = a->next;
		a->next = b;
		b=a;
		a=c;			
	}

	*root = b;
	
}


int main(){
	printf("Hello");
	struct node* root = NULL;

	add(&root, 1);
	add(&root, 2);
	add(&root, 3);
	add(&root, 4);
	
	traverse(root);

	reverse(&root);
	traverse(root);
}



