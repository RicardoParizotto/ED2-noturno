#include <stdlib.h>
#include <stdio.h>

<<<<<<< HEAD
=======
//olá


>>>>>>> 70e5d96a14c163d5087140256ba5d690e1791e1f
struct node{
	int key;  							//chave de identificação do nodo	
	node * left, * right, * parent;		//ponteiros para os filhos
};

struct tree{
	node * raiz;
};

//busca por uma chave k na árvore com raiz r
//caso a chave não estiver na árvore retorna NULL

node * search (node * r, int key){
	if(!r || r->key == key ) return r;				//n encontrou a chave

	if(key <= r->key) return search (r->left, key);
	
	return search (r->right, key); 	
}


//mostra todas as chaves da árvore
void inorder (node * r){
	if(r){
		inorder(r->left);
		printf("%d ", r->key);
		inorder(r->right);
	}
}



//insere um nodo com chave key na árvore com raiz r
//retorna um ponteiro para a raiz da árvore

node * insert (node * r, int key){
	node * n = (node *)malloc(sizeof(node));		//cria um novo nodo
	n->left = n->right = n->parent = NULL;			//atualiza os valores dos ponteiros do nodo novo
	n->key = key;
			
	if(!r) return n;								// se a arvore estiver vazia

	node * it = r;	

	while(1){
		if(key < it->key){
			if(!it->left){
				it->left = n; 						//atualiza o filho da esquerda de r	
				break;		
			}
			it = it->left;	
		}else{
			if(!it->right){
				it->right = n;
				break;			
			}
			it = it->right;
		}		
	}
	
	n->parent = it; 										//atualiza o pai do novo nodo

	return r;
}

node * tree_min(node * r){
	return (!r->left)? r : tree_min(r->left);
}

//retorna o sucessor do nodo x
//quem não entender olha no livro do cormen :)
node * tree_sucessor(node * x){
	if(x->right) return tree_min(x->right);

	node * y = x->parent;

	while(y && x == y->right){
		x = y;
		y = y->parent;
	}
	return y;
}

void transplant(tree * T, node * u, node * v){
	if(!u->parent)
		T->raiz = v;
	else if( u == u->parent->left )
		u->parent->left = v;
	else u->parent->right = v;
	
	if(!v)
		v->parent = u->parent;
}

//remove o nodo da árvore com raiz r que possui chave igual a key
//(lembra que tem que dar free no nodo)
void tree_delete(tree * T, node * z){
	node * y;

	if(!z->left)
		transplant(T, z, z->right);
	else if(!z->right)
		transplant(T, z, z->left);
	else{
		y = tree_min(z->right);
		if(y->parent != z){
			transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}	
}



int main ( void ){

	int n;
	
	tree t;
	


	t.raiz = NULL;

	node * aux;

	
	while(scanf("%d", &n)){
		t.raiz = insert(t.raiz, n);
	}

	if((aux = search(t.raiz, 7))) {
		aux = tree_sucessor(aux);
		if(aux)
			printf("%d ", aux->key);
	}

	tree_delete(&t, aux);

	inorder(t.raiz);






	
	
	
	

	return 0;
}





