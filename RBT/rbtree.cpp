#include <stdio.h>
#include <stdlib.h>


#define RED false
#define BLACK true

struct node{
	int key;
	node * left, * right, *p;
	bool c;
};


struct rbtree{
	node * root;
	node * nil;
};



void left_rotate(rbtree * T, node * x){
	node * y = x->right;

	x->right = y->left;
	
	if ( y->left != T->nil )
		y->left->p = x;

	y->p = x->p;

	if ( x->p == T->nil )
		T->root = y;
	else if( x == x->p->left )
		x->p->left = y;
	else x->p->right = y;
	
	y->left = x;
	x->p = y;
}



void right_rotate (rbtree * T, node * x){
	node * y = x->left;
	
	x->left = y->right;
	
	if ( y->right != T->nil )
		y->right->p = x;
	
	y->p = x->p;
	
	if ( x->p == T->nil )
		T->root = y;
	else if ( x == x->p->left )
		x->p->left = y;
	else x->p->right = y;
	
	y->right = x;
	x->p = y;
}


rbtree * dinossauro_inicia (){
	rbtree * nova = (rbtree *)malloc(sizeof(rbtree));
	nova->nil = (node *)malloc(sizeof(node));

	(nova->nil)->p = (nova->nil)->left = (nova->nil)->right = NULL;
	
	nova->root = nova->nil;
	return nova;
} 


void insert ( rbtree * T, int k ){
	node * n = (node *)malloc(sizeof(node));
	n->p = n->left = n->right = T->nil;
	n->key = k;
	n->c = RED;

	node * y;
	node * x;
	
	y = T->nil;
	x = T->root;


	while ( x != T->nil ){
		y = x;
		if ( k < x->key )
			x = x->left;
		else x = x->right;
	}

	n->p = y;

	if(y == T->nil)
		T->root = n;
	else if (k < y->key)
		y->left = n;
	else y->right = n;


	//arruma a arvore
	

}

int main ( void ){

	return 0;
}
























