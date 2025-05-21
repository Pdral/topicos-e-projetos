#include <stdio.h>

int main(void){
	int vet[5], aux, c;
	for(int i=0;i<5;i++){
		printf("Digite o %dº número: ", i+1);
		scanf("%d", &vet[i]);
	}
	puts("Ordenar de forma crescente? (1 para sim e 0 para não)");
	scanf("%d", &c);
	if(c == 1){
		for(int i=4; i>=0; i--){
			for(int j=0; j<i; j++){
				if(vet[j] > vet[i]){
					aux = vet[j];
					vet[j] = vet[i];
					vet[i] = aux;
				}
			}
		}
	}
	else{
		for(int i=4; i>=0; i--){
			for(int j=0; j<i; j++){
				if(vet[j] < vet[i]){
					aux = vet[j];
					vet[j] = vet[i];
					vet[i] = aux;
				}
			}
		}
	}
	for(int i = 0; i<5; i++){
		printf("Elemento da posição %d: %d\n", i+1, vet[i]);
	}
	return 0;
}
