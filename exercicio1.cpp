#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct arv {
	char nomeProd[20];
	int SKU;
	int quant;
	struct arv* dir;
	struct arv* esq;
};

typedef struct arv Arv;

int raiz;

Arv* init (void)
{
	return NULL;
}

Arv* insere (Arv* a, char* nomeProd, int SKU, int quant)
{
	if (a==NULL) {
		a = (Arv*)malloc(sizeof(Arv));
		strcpy(a->nomeProd, nomeProd);
		a->SKU = SKU;
		a->quant = quant;
		a->esq = a->dir = NULL;
	}
	else if (strcmp(nomeProd, a->nomeProd) < 0) {
		a->esq = insere(a->esq, nomeProd, SKU, quant);
}
	else
		a->dir = insere(a->dir, nomeProd, SKU, quant);
	return a;
}

Arv* buscaporNome (Arv* a, char* nomeProd)
{
	if (a == NULL || strcmp(nomeProd, a->nomeProd) == 0) {
	return a;
}
	else if (strcmp(nomeProd, a->nomeProd) < 0) { 
	return buscaporNome (a->esq, nomeProd);
}
	else {
	return buscaporNome(a->dir, nomeProd);
}
}

Arv* buscaporSKU (Arv* a, int SKU) 
{
	if (a == NULL || a->SKU == SKU) {
		return a;
	}
	else if (SKU < a->SKU) {
		return buscaporSKU(a->esq, SKU);
	}
	else {
		return buscaporSKU(a->dir, SKU);
	}
}
void imprime (Arv* a)
{
	if (a != NULL) {
		imprime(a->esq);
		printf("Produto: %s SKU: %d Quantidade: %d \n",a->nomeProd,a->SKU,a->quant);
		imprime(a->dir);
	}
}

int vazia(Arv* a)
{
	return a==NULL;
}

void libera (Arv* a)
{
	if (!vazia(a)){
		libera(a->esq); /* percorre sae */
		libera(a->dir); /* percorre sad */
		free(a); /* libera raiz */
	}
}




int main(void) {
	Arv* arv = init();
	
	arv = insere(arv, "Tenis1", 4020, 40);
	arv = insere(arv, "Tenis2", 4016, 50);
	arv = insere(arv, "Tenis3", 4018, 60);

	char buscaNome[20];
	int buscaSKU;
	int opcao;
	printf("Como voce deseja fazer a busca?\n");
	printf("\n1-Busca por nome do produto\n");
	printf("2-Busca por SKU\n");
	printf("\nDigite apenas 1 ou 2: ");
	scanf("%d",&opcao);
	
	system("cls");
	
	if (opcao == 1){
	printf("Digite o nome do produto a ser buscado: ");
	scanf("%s",buscaNome);
	system("cls");
	Arv* produtonome = buscaporNome(arv, buscaNome);
	if (produtonome != NULL) {
		printf("\n---Produto encontrado---\nNome: %s\nSKU: %d\nQuantidade: %d",produtonome->nomeProd, produtonome->SKU, produtonome->quant);
}	
	else {
	printf("\n---Produto nao encontrado--- \n");
}
}
	else if (opcao == 2){
		printf("Digite o SKU do produto a ser buscado: ");
	scanf("%d", &buscaSKU);
	system("cls");
	Arv* numeroSKU = buscaporSKU(arv, buscaSKU);
	if (numeroSKU != NULL) {
		printf("\n---Produto encontrado---\nNome: %s\nSKU: %d\nQuantidade: %d",numeroSKU->nomeProd, numeroSKU->SKU, numeroSKU->quant);
}	
	else {
	printf("\n---Produto nao encontrado--- \n");
		
	}
} 
	system("pause");
}

