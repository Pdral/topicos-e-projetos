#include <stdio.h>
#include <time.h>

#define Estadovermelho 0
#define EstadoAmarelo 1
#define Estadoverde 2

typedef int TipoFuncao();

TipoFuncao *semaforo[3];

int Ledverde = 0, LedAmarelo = 0, LedVermelho = 0;

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int verificapedestre(){
    int pedestre = 0;
    printf("Pedestre apertou o botão?\n");
    scanf("%d", &pedestre);
    return pedestre;
}

void printSemaforo(){
    printf("Semaforo: \n");
    printf("Vermelho: %d\n", LedVermelho);
    printf("Amarelo: %d\n", LedAmarelo);
    printf("Verde: %d\n\n", Ledverde);

}

int sinalVermelho(){
    Ledverde = 0, LedAmarelo = 0, LedVermelho = 1;
    printSemaforo();
    waitFor(7); //delay de 3 segundos
    return Estadoverde;
}

int sinalAmarelo(){
    Ledverde = 0, LedAmarelo = 1, LedVermelho = 0;
    printSemaforo();
    waitFor(2); //delay de 1 segundo
    return Estadovermelho;
}

int sinalVerde(){
    Ledverde = 1, LedAmarelo = 0, LedVermelho = 0;
    printSemaforo();
    for(int i=0; i<5; i++){
        waitFor(1); //delay de 1 segundo
        if(verificapedestre()) return EstadoAmarelo;
    }
    return EstadoAmarelo;
}

void SetCallbackFunc(int indice, TipoFuncao *PonteiroParaUmaFuncao)
{
    semaforo[indice] = PonteiroParaUmaFuncao;
}

int main(){

    SetCallbackFunc(Estadovermelho, sinalVermelho);
    SetCallbackFunc(EstadoAmarelo, sinalAmarelo);
    SetCallbackFunc(Estadoverde, sinalVerde);

    int EstadoAtual = Estadovermelho; // estado inicial
    int ProximoEstado = Estadovermelho;

    while (1)
    {
        EstadoAtual = (*semaforo[EstadoAtual])(); 
    }
    
    return 0;
}