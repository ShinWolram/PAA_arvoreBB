
#include "ABB_privado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criaABB(ppABB pp, int tamInfo){
	*pp = (pABB) (malloc(sizeof(struct NoABB)));
    if((*pp)==NULL)
    {
        return FRACASSO;
    }
    
	(*pp)->pai = NULL;
    (*pp)->esquerda = NULL;
    (*pp)->direita = NULL;
    
	(*pp)->dados = (malloc(tamInfo));
    if(((*pp)->dados)==NULL)
    {
        return FRACASSO;
    }
	(*pp)->id = 0;
	
	return SUCESSO;
}
	
int destroiABB(ppABB pp){
	return 1;
}

int reiniciaABB(pABB p){
	return 1;
}

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2)){
	printf("Valor recebido: %i\n", *((int *)novo));
	//se estiver vazio insere
	if (testaVaziaABB(p)){
		printf("Insere na vazia\n");
		
		p->id = *((int *)novo);
		p->dados = novo;
		printf("Valor já inserido: %i\n", p->id);
		
		printf("Cria esquerda e direita para esse nó\n");
		pABB ptrEsquerda;
		if((criaABB(&ptrEsquerda, sizeof(int)))==FRACASSO) {
			printf("Erro na criação da arvore pai\n");
			exit(1);
		}
		pABB ptrDireita;
		if((criaABB(&ptrDireita, sizeof(int)))==FRACASSO) {
			printf("Erro na criação da arvore direita\n");
			exit(1);
		}
		
		printf("Coloca esse nó como pai dos outros\n");
		ptrEsquerda->pai = p;
		ptrDireita->pai = p;
		
		printf("Coloca direita e esquerda desse nó\n");
		p->esquerda = ptrEsquerda;
		p->direita = ptrDireita;
	//senao
	}else{
		
		//l Compara-se o rótulo do novo elemento com o rótulo da raiz:
		int diferenca = (* cmp)(novo, &p->id);
		printf("diferença: %i\n", diferenca);
		//l Se o rótulo do novo for menor que o rótulo da raiz o nó esquerdo será visitado;
		if (diferenca < 0){
			printf("chama insere na esquerda\n");
			insereABB(p->esquerda, novo, (* cmp));
		//l Caso contrário, o nó da direito será visitado;
		}else{
			printf("chama insere na direita\n");
			insereABB(p->direita, novo, (* cmp));
		}
		
		//l Repete-se este procedimento até que a subárvore desejada (a ser visitada) não exista;
		//l Então, insere-se o novo nó.
	}	
	
	return SUCESSO;
}

int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)){
	return 1;
}

int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)){
	return 1;
}

int testaVaziaABB(pABB p){
	if (p->id != 0){
		printf("Não está vazia\n");
		return FRACASSO;
	}
	printf("Está vazia\n");
	return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (* processa)(void *p)){
	return 1;
}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)){
	return 1;
}

int percursoPosOrdem(pABB pa, void (* processa)(void *p)){
	return 1;
}

/*
// Imprime todos os elementos de um tipo específico da lista
void imprime_tipo(pABB p, void (* print)(void *p), int tipo) {
	//declarando variáveis
	int p_tipo;
	void *p_elemento;
	//verificando tipo a ser buscado
	int tamanho_busca;
	if (tipo==0)
		tamanho_busca = sizeof(int);
	else if (tipo==1)
		tamanho_busca = sizeof(char);
	
	printf("tipo dado a mostrar: (%i) \n", tipo);
    
	//para cada elemento,
	for (int i=1; i <= contaElementos(p); i++) {
		//busca ele na lista
		buscaPosicao(p, i, &p_elemento, &p_tipo, tamanho_busca);
		//se o tipo dele for igual ao tipo que precisa ser exibido
		if (tipo==p_tipo){
			//exibe o elemento
			(* print)(&p_elemento);
		}
		
	}	
		
	return;
}
*/