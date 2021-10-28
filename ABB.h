#define SUCESSO 1
#define FRACASSO 0


typedef struct NoABB *pABB, **ppABB;

int criaABB(ppABB pp, int tamInfo);
int destroiABB(ppABB pp);
int reiniciaABB(pABB p);
int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2));
int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
int testaVaziaABB(pABB p);
int percursoEmOrdem(pABB pa, void (* processa)(void *p));
int percursoPreOrdem(pABB pa, void (* processa)(void *p));
int percursoPosOrdem(pABB pa, void (* processa)(void *p));

/*
int criaABB(ppABB pp);
int destroiABB(ppABB pp);
int reiniciaABB(pABB p);

int insereInicio(pABB p, void *elemento, int tipo, int ttipo);
int insereFim(pABB p, void *elemento, int tipo, int ttipo);
int inserePosicao(pABB p, int N, void *elemento, int tipo, int ttipo);

int removeInicio(pABB p, void *elemento, int *tipo, int *ttipo);
int removeFim(pABB p, void *elemento, int *tipo, int *ttipo);
int removePosicao(pABB p, int N, void *elemento, int *tipo, int *ttipo);

int buscaPosicao(pABB p, int N, void *elemento, int *tipo, int ttipo);
int buscaFim(pABB p, void *elemento, int *tipo, int ttipo);
int buscaInicio(pABB p, void *elemento, int *tipo, int ttipo);

int testaVazia(pABB p);
int contaElementos(pABB p);
void imprime(pABB p, void (* print)(void *p));
void imprime_tipo(pABB p, void (* print)(void *p), int tipo);

// tipos pares, insere-se no início e, impares, no fim.
int insereTipo(pABB p, void *elemento, int tipo, int ttipo);

*/