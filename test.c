#include <stdio.h>
# include <signal.h>

void chamou_sinal(int signal)
{
    printf("voce mandou sinal para mim!\n");

    if(signal == SIGUSR1)
        printf("voce mando sinal SIGUSR1\n");

    if(signal == 15)
        printf("voce mando sinal Padrao\n");

    if(signal == SIGUSR2)
        printf("voce mando sinal SIGUSR2\n");

}

int main (void)
{
    int i;
    i = 0;

    // signal: é uma função, que a recener um sinal,os parametro da função são:
    // 1º parametro é o tipo de sinal, so vai chamar a função "chamou_sinal", se o sinal for o mesmo tipo
    // 2º é função do tipo "void função (int numero)", esse "numero" eh o valor do sinal
    signal( SIGUSR1, chamou_sinal); // so vai chamar a função chamou sinal se o sinal for SIGUSR1
    signal( 15, chamou_sinal); // so vai chamar a função chamou sinal se o sinal for padrão
    signal( SIGUSR2, chamou_sinal); // so vai chamar a função chamou sinal se o sinal for SIGUSR2


    while( i< 1000)
    {
        printf("%d\n", i);
        sleep(1);
        i++;
    }
    return (0);
}
 