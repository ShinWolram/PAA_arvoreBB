
#include "ABB.h"
/*
typedef struct ABB{
    struct NoABB *inicio;		// ponteiro para o primeiro n� da lista
    int tamanho_info;           // tamanho da informa��o contida nos n�s
}ABB;

typedef struct NoABB{
    void *dados;        		// ponteiro para os dados do n�
    struct NoABB *proximo;		// ponteiro para o pr�ximo elemento
    int tipo;
    int tamanho_info;
}NoABB;
*/

struct NoABB{
	void *dados;
	struct NoABB *pai; // (opcional)
	struct NoABB *esquerda;
	struct NoABB *direita;
	int id; //eu q add
};
