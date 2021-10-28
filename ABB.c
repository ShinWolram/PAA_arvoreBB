
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
	free(pp);
	return SUCESSO;
}

int reiniciaABB(pABB p){
	return 1;
}

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2)){
	//printf("Valor recebido: %i\n", *((int *)novo));
	//se estiver vazio insere
	if (testaVaziaABB(p)){
		//printf("Insere na vazia\n");
		
		p->id = *((int *)novo);
		p->dados = novo;
		//printf("Valor já inserido: %i\n", p->id);
		
		//printf("Cria esquerda e direita para esse nó\n");
		pABB ptrEsquerda;
		if((criaABB(&ptrEsquerda, sizeof(int)))==FRACASSO) {
			printf("Erro na criação da arvore esquerda\n");
			exit(1);
		}
		pABB ptrDireita;
		if((criaABB(&ptrDireita, sizeof(int)))==FRACASSO) {
			printf("Erro na criação da arvore direita\n");
			exit(1);
		}
		
		//printf("Coloca esse nó como pai dos outros\n");
		ptrEsquerda->pai = p;
		ptrDireita->pai = p;
		
		//printf("Coloca direita e esquerda desse nó\n");
		p->esquerda = ptrEsquerda;
		p->direita = ptrDireita;
	//senao
	}else{
		
		//Compara-se o rótulo do novo elemento com o rótulo da raiz:
		int diferenca = (* cmp)(novo, &p->id);
		//printf("diferença: %i\n", diferenca);
		//Se o rótulo do novo for menor que o rótulo da raiz o nó esquerdo será visitado;
		if (diferenca < 0){
			//printf("chama insere na esquerda\n");
			if (!insereABB(p->esquerda, novo, (* cmp)))
				return FRACASSO;		
		//Caso contrário, o nó da direito será visitado;
		}else if (diferenca > 0){
			//printf("chama insere na direita\n");
			if (!insereABB(p->direita, novo, (* cmp)))
				return FRACASSO;
		}else{
			//printf("FRACASSO\n");
			return FRACASSO;
		}	
	}	
	
	return SUCESSO;
}

int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)){
	//se está vazia não tem como...
	if (testaVaziaABB(p)){
		return FRACASSO;
	//senao
	}else{

		//Compara-se o rótulo do elemento a ser encontrado com o rótulo da raiz:
		int diferenca = (* cmp)(item, &p->id);
		//printf("diferença: %i\n", diferenca);
		//Se encontrou o item igual...
		if (diferenca==0){
			//inicia a remoção
			printf("achou quem remover\n");
			//se tem 0 filhos
				//altera pai trocando ele por null
				//if (p->pai->id < p->id)
			//senao se tem um filho
				//filho ocupa lugar dele no pai
			//senao é pq tem 2 filhos
				//pensar com calma depois kkkkk
			//exclui da memoria
		//senão é esse, se a diferença for negativa tenta remover na esquerda	
		}else if (diferenca < 0){
			printf("busca remover na esquerda\n");
			if (!removeABB(p->esquerda, item, (* cmp))){
				return FRACASSO;		
			}else{
				return SUCESSO;
			}		
		//Caso contrário, o nó da direito será visitado;
		}else if (diferenca > 0){
			printf("busca remover na direita\n");
			if (!removeABB(p->direita, item, (* cmp))){
				return FRACASSO;		
			}else{
				return SUCESSO;
			}		
		}		
	}	
	//printf("404 not found\n");
	return FRACASSO;
}

int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)){
	//printf("Valor recebido para buscar: %i\n", *((int *)item));
	//se estiver vazio insere
	if (testaVaziaABB(p)){
		return FRACASSO;
	//senao
	}else{
		//Compara-se o rótulo do elemento a ser encontrado com o rótulo da raiz:
		int diferenca = (* cmp)(item, &p->id);
		//printf("diferença: %i\n", diferenca);
		//Se o rótulo for igual ao valor a ser buscado;
		if (diferenca==0){
			//achou...
			return SUCESSO;
		//senão se a diferença for negativa	
		}else if (diferenca < 0){
			//printf("busca na esquerda\n");
			//se não achou, fracasso, se achou, sucesso!
			if (!buscaABB(p->esquerda, item, (* cmp))){
				return FRACASSO;		
			}else{
				return SUCESSO;
			}		
		//Caso contrário, o nó da direito será visitado;
		}else if (diferenca > 0){
			//printf("chama insere na direita\n");
			//se não achou, fracasso, se achou, sucesso!
			if (!buscaABB(p->direita, item, (* cmp))){
				return FRACASSO;		
			}else{
				return SUCESSO;
			}		
		}	
	}	
	//printf("404 not found\n");
	return FRACASSO;
}

int testaVaziaABB(pABB p){
	if (p->id != 0){
		//printf("Não está vazia\n");
		return FRACASSO;
	}
	//printf("Está vazia\n");
	return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (* processa)(void *p)){
//l Percorre em Ordem Impressao dos elementos em ordem: 1 2 10 20 23 
//l percorrer a subárvore da esquerda;
//l visitar a raiz;
//l percorrer a subárvore da direita.
	//se não estiver vazia
	if (testaVaziaABB(pa)){
		return FRACASSO;
	}else{	
	//	se tiver algo na esquerda
		if (pa->esquerda!=NULL){
	//		chama recursivo pra da esquerda
			percursoEmOrdem(pa->esquerda, (* processa));
		}
	//   chama o processa e mostra o valor daqui
		(* processa)(&pa->id);
	// 	se tiver algo na direita
		if (pa->direita!=NULL){
	//		chama recursivo pra da direita
			percursoEmOrdem(pa->direita, (* processa));
		}	
	}
	return SUCESSO;
}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)){
//l Percorre em Pré-ordem Impressao dos elementos em pre-ordem: 10 1 2 20 23 
//l visitar a raiz;
//l percorrer a subárvore da esquerda; e
//l percorrer a subárvore da direita.	
	//se não estiver vazia
	if (testaVaziaABB(pa)){
		return FRACASSO;
	}else{	
	//   chama o processa e mostra o valor daqui
		(* processa)(&pa->id);
	//	se tiver algo na esquerda
		if (pa->esquerda!=NULL){
	//		chama recursivo pra da esquerda
			percursoPreOrdem(pa->esquerda, (* processa));
		}
	// 	se tiver algo na direita
		if (pa->direita!=NULL){
	//		chama recursivo pra da direita
			percursoPreOrdem(pa->direita, (* processa));
		}	
	}
	return SUCESSO;
}

int percursoPosOrdem(pABB pa, void (* processa)(void *p)){
//l Percorre em Pós-ordem Impressao dos elementos em pos-ordem: 2 1 23 20 10 
//l percorrer a subárvore da esquerda; e
//l percorrer a subárvore da direita.	
	//se não estiver vazia
	if (testaVaziaABB(pa)){
		return FRACASSO;
	}else{	
	//	se tiver algo na esquerda
		if (pa->esquerda!=NULL){
	//		chama recursivo pra da esquerda
			percursoPosOrdem(pa->esquerda, (* processa));
		}
	// 	se tiver algo na direita
		if (pa->direita!=NULL){
	//		chama recursivo pra da direita
			percursoPosOrdem(pa->direita, (* processa));
	//   chama o processa e mostra o valor daqui
		(* processa)(&pa->id);
		}	
	}return SUCESSO;
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