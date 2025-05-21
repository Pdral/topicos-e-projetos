#include <stdio.h>

#define MAX2(a, b) (a>b ? a:b)
#define MAX3(a, b, c) MAX2(MAX2(a, b), MAX2(b, c))

int main(void){
	int a, b, c;
	printf("Insira o primeiro valor: ");
	scanf("%d", &a);
	printf("Insira o segundo valor: ");
	scanf("%d", &b);
	printf("Insira o terceiro valor: ");
	scanf("%d", &c);
	printf("O maior valor digitado foi: %d\n", MAX3(a, b, c));

	return 0;
}
