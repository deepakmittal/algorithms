#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
	int data;
	struct node * left;
	struct node * right;
};

struct listNode	{
	struct node* data;
	struct listNode *next;
};
void push(struct listNode **root,struct node* data){
        if(data == NULL)
            return;
        struct listNode *n = malloc( sizeof(struct listNode) );
	n->data = data;
	n->next = *root;
	*root = n;
}

struct node* pop(struct listNode **root){
	if(*root == NULL){
		return 0;
	}
        struct listNode * temp = *root;
	struct node * rtn = temp->data;
	*root = temp->next;
	return rtn;
}


void add(struct node **root,int data){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	if(*root == NULL){
		*root = newNode;
		return;
	}
	struct node *temp = *root;
	while(1){
		if(data <= temp->data){
			if(temp->left==NULL){
				temp->left = newNode;
				return;
			}
			temp=temp->left;
		}else{
			if(temp->right == NULL){
				temp->right = newNode;
				return;
			}
			temp=temp->right;
		}
	}
}

void inorder(struct node * root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d,",root->data);
	inorder(root->right);
}
struct node* find(struct node* root, int data){
	 if(root == NULL)
	 	return NULL;
	 if(root->data == data){
		return root;
	 }
	 struct node* rtn = find(root->left,data);
	 if(rtn != NULL){
		return rtn;
	 }
	 rtn = find(root->right, data);
	 if(rtn != NULL){
		return rtn;
	 }
	 return NULL;
}

struct node* commonAncestor(struct node *root, struct node *a, struct node *b){
	if(root == NULL){
		return NULL;
	}
	
	struct node *t1 = commonAncestor(root->left,a,b);
	struct node *t2 = commonAncestor(root->right,a,b);
	struct node *t3 = root == a  || root ==b ? root : NULL; 	

	int sum = (t1 == NULL ? 0 : 1) + (t2 == NULL ? 0 : 1) + (t3 == NULL ? 0 : 1);

	if(sum == 2)
		return root;
	return t1 != NULL ? t1 : (t2 != NULL ? t2 : t3);	
}

bool isSimilar(struct node * a, struct node *b){
	struct listNode* aStack=NULL;
	struct listNode* bStack=NULL;
	while(1){
		while(a != NULL){
			push(&aStack,a);
			a=a->left;
		}
		while(b != NULL){
			push(&bStack,b);
                        b=b->left;
                }
		if(aStack==NULL && bStack==NULL){
			return true;
		}
		//printf("--CULPRIT: %s",( aStack==NULL ?  "A" : ( bStack==NULL? "B": "NO" ) )  );
		if(aStack==NULL || bStack==NULL){
                        return false;
                }
		a=pop(&aStack);
		b=pop(&bStack);
		
		//printf("\n%d=%d\n", a->data, b->data);
		if(a->data != b->data){
			return false;
		}
		a=a->right;
		b=b->right;
	}

}

void postOrderStack(struct node * root){
	struct listNode * stack=NULL;
	struct node* temp = NULL;
	push(&stack,root);
	while(stack != NULL){
		root = pop(&stack);
		//printf("\nroot: %d\n",root->data);
		if(root->right == NULL && root->left == NULL){
			printf("%d ,",root->data);
			temp = root;
			continue;
		}
		if(temp != NULL && (root->right == temp || root->left ==temp)  ){
			printf("%d ,",root->data);
			temp = root;
		}else{
			push(&stack,root);
			if(root->right != NULL){
				push(&stack,root->right);
			}
			if(root->left != NULL){
                                push(&stack,root->left);
                        }
		}	
		
	}
}
	
void inorderStack(struct node * root){
        struct listNode * stack=NULL;
        struct node* temp = NULL;
        push(&stack,root);
        while(stack != NULL){
                root = pop(&stack);
                //printf("\nroot: %d\n",root->data);
                if(root->left == NULL){
                        printf("%d ,",root->data);
                        temp = root;
                        continue;
                }else{
			push(&stack,root);
			push(&stack,root->left);
		}
                if(temp != NULL && (root->right == temp || root->left ==temp)  ){
                        printf("%d ,",root->data);
                        temp = root;
                }else{
                        push(&stack,root);
                        if(root->right != NULL){
                                push(&stack,root->right);
                        }
                        if(root->left != NULL){
                                push(&stack,root->left);
                        }
                }

        }
}

void zigzag(struct node *root){
    if(root == NULL)
        return;
    struct listNode* odd = NULL;
    struct listNode* even = NULL;
    
    push(&odd,root);
    struct node *n = NULL;
    while(odd != NULL || even != NULL){
        while(odd != NULL){
            n = pop(&odd);
            printf("%d ..", n->data);
            push(&even,n->left);
            push(&even,n->right);
        }
        while(even != NULL){
            n = pop(&even);
            printf("%d ..", n->data);
            push(&odd,n->right);
            push(&odd,n->left);
        }
    }
}

int distance(struct node *root, struct node *a, struct node *b){
	if(root == NULL){
		return 0;
	}
	
	int t1 = distance(root->left,a,b);
	int t2 = distance(root->right,a,b);
	int t3 = root == a  || root ==b ? -1 : 0;

	if(t1 > 0)
            return t1;
        if(t2 > 0)
            return t2;
        
        if(t1 < 0){
            if(t2 < 0)
                return (0 - (t1 + t2));
            if(t3 == -1)
                return 0 - t1;
            return t1 - 1;
        }
        
        if(t2 < 0){
            if(t3 == -1)
                return 1 - t2;
            return t2 - 1;
        }
        
        return t3;
        
}

int main(){
	struct node *root = NULL;
	add(&root,4);
	add(&root,1);
	add(&root,3);
	add(&root,7);
	add(&root,9);
	add(&root,5);
	add(&root,8);
	add(&root,2);
	add(&root,6);
 
        struct node *b = NULL;
	add(&b,1);
	add(&b,2);
	add(&b,3);
	add(&b,4);
	add(&b,5);
	add(&b,6);
	add(&b,7);
	add(&b,8);
	add(&b,9);

	printf("\n\n Compare trees for similarity: %s \n\n", isSimilar(root,b) ? "true": "false");
	
        printf("\n\ninorder:");
        inorder(root);
//        printf("\nPREORDER: \n");
//	preorderStack(root);
	printf("\nPOSTORDER: \n");
	postOrderStack(root);
	struct node *lca_6_8 = commonAncestor(root,find(root,8),find(root,6));
	printf("\n\nleast common ancestor: 6,8: %d\n", lca_6_8->data);

	struct node *lca_2_8 = commonAncestor(root,find(root,8),find(root,2));
	printf("\n\nleast common ancestor: 2,8: %d\n", lca_2_8->data);

	struct node *lca_6_7 = commonAncestor(root,find(root,7),find(root,6));
	printf("\n\nleast common ancestor: 6,7: %d\n", lca_6_7->data);
        
        int distance_6_8 = distance(root,find(root,8),find(root,6));
	printf("\n\ndistance: 6,8: %d\n", distance_6_8);

	int distance_2_8 = distance(root,find(root,8),find(root,2));
	printf("\n\ndistance: 2,8: %d\n", distance_2_8);

	int distance_6_7 = distance(root,find(root,7),find(root,6));
	printf("\n\ndistance: 6,7: %d\n", distance_6_7);
        
        printf("\n\nzigazag:");
        zigzag(root);  
        printf("\n\n");
}
