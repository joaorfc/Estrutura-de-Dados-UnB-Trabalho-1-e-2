#include <stdio.h>
#include <stdlib.h>

int main(){
	float *vet, soma = 0, media;
	int i, n;

	printf("Digite o numero de elementos do vetor:\n");
	scanf("%d", &n);

	vet = malloc(n*sizeof(int));

	for(i=0;i<n;i++){
		printf("Digite o valor do vetor [%d]:", i);
		scanf("%f", &vet[i]);
	}
	for(i=0;i<n;i++){
		soma= soma + vet[i];
	}
	media = soma/n;

	printf("\nA media dos elementos do vetor eh: %0.f", media);

	return 0;
}
