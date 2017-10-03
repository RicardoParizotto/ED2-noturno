//baseado no livro do cormen

#include <stdio.h>
#include <stdlib.h>


#define RED false
#define BLACK true

struct node{
	int key;
	node * left, * right, *parent;
	bool color;
};


struct rbtree{
	node * root;
	node * nil;
};



rbtree * Tree_inicia (){
	rbtree * nova = (rbtree *)malloc(sizeof(rbtree));
	nova->nil = (node *)malloc(sizeof(node));	
	nova->nil->color = BLACK;
	nova->root = nova->nil;
	return nova;
} 

void left_rotate(rbtree * T, node * x){
	node * y = x->right;

	x->right = y->left;
	
	if ( y->left != T->nil )
		y->left->parent = x;

	y->parent = x->parent;

	if ( x->parent == T->nil )
		T->root = y;
	else if( x == x->parent->left )
		x->parent->left = y;
	else x->parent->right = y;
	
	y->left = x;
	x->parent = y;
}

void right_rotate (rbtree * T, node * x){
	node * y = x->left;
	
	x->left = y->right;
	
	if ( y->right != T->nil )
		y->right->parent = x;
	
	y->parent = x->parent;
	
	if ( x->parent == T->nil )
		T->root = y;
	else if ( x == x->parent->left )
		x->parent->left = y;
	else x->parent->right = y;
	
	y->right = x;
	x->parent = y;
}



void Fixup ( rbtree * T, node * k ){
	//caso 0 - k é a raiz
	while ( k != T->root && k->parent->color==RED ){
		//caso o avô seja filho à esquerda
		if (k->parent == k->parent->parent->left ){
			node * t = k->parent->parent->right; //tio
			//caso 1 -- o tio é vermelho
			if ( t->color == RED ){
				t->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent; 		//sobe o problema para o avô de k
			}else{
				//caso 2 -- o tio é preto e k é filho à direita: transforma no caso 3
				if(k == k->parent->right ){
					k = k->parent;
					left_rotate(T, k);
				}
				//caso 3 - o tio é preto e k é filho à esquerda: rotate e termina
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				right_rotate(T, k->parent->parent);			
			}		
		}else{ 
			//caso o avô seja filho à direita
			node * t = k->parent->parent->left; //tio
			//caso 1 -- o tio é vermelho
			if ( t->color == RED ){
				t->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent; 		//sobe o problema para o avô de k
			}else{
				//caso 2 -- o tio é preto e k é filho à direita: transforma no caso 3
				if(k == k->parent->left ){
					k = k->parent;
					right_rotate(T, k);
				}
				//caso 3 - o tio é preto e k é filho à esquerda: rotate e termina
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				left_rotate(T, k->parent->parent);			
			}
		}
	}
	T->root->color = BLACK;
}

void insert ( rbtree * T, int k ){
	node * n = (node *)malloc(sizeof(node));
	n->parent = n->left = n->right = T->nil;
	n->key = k;
	n->color = RED;

	node * ant, * x;
	
	ant = T->nil;
	x = T->root;

	while ( x != T->nil ){
		ant = x;
		if ( k < x->key )
			x = x->left;
		else x = x->right;
	}

	n->parent = ant;

	if(ant == T->nil)
		T->root = n;
	else if (k < ant->key)
		ant->left = n;
	else ant->right = n;

	Fixup(T, n);
}


//copiei daqui:: https://github.com/lauradacol/DataStructure2/tree/master/RBtree
void drawTree(rbtree * t, node * n, int h){
	if(n->left != t->nil)
		drawTree(t, n->left, h+1);	

	int i;
	for(i=0; i<h; i++){
		printf("    ");
	}
	
	if(n->color == RED)
		printf("R-%d\n", n->key);	
	else
		printf("B-%d\n", n->key);		
	
	if(n->right != t->nil)
		drawTree(t, n->right, h+1);	
}





int main ( void ){

	rbtree * T = Tree_inicia();
	int d;

	while(scanf("%d", &d)){
		insert(T, d); 
	} 

	drawTree(T, T->root, 0);
	
	return 0;
}
























