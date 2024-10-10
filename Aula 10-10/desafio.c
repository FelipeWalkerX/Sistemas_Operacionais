#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int contador = 0; //contador

int meuLen(char *str){  //Funcao para contar as letras de cada frase
    int i = 0;
    while(str[i]!= '\0')    //conta ate chegar no \0 e armazena em i
    i++;
    return i;
}

void saiPrograma (int signal){  //funcao para sair do programa
    int sair;
    contador++; //Apenas conta quantas vezes o usuario apertou o ctrl C

    if (contador == 3)    { //Se o usuario apertar ctrl C 3 vezes, ele entra no if
        write(1, "Deseja realmente sair? [Y/n]: \n\n", meuLen("Deseja realmente sair? [Y/n]: \n\n"));
        alarm(20);  //cooldown de 20 segundos para o usuario escolher continuar ou nao com o programa
        read(0, &sair, sizeof(int));    //le a resposta do usuario
        if (sair = 'y')
        {
            write(1, "Saindo......", meuLen("Saindo......"));   //Usuario digitou y, entao ele sai do programa
            exit(0);    //forcar encerramento do programa
        } else if (sair = 'n')
        {
            write(1, "Continuando...", meuLen("Continuando..."));   //Usuario digitou n, entao ele continua o programa
            contador = 0;
        } else{
            write(1, "Demorou muito para responder. Saindo......", meuLen("Demorou muito para responder. Saindo......"));       // Se deu os 20 segundos e o usuario nao digitar nada, ele encerra o programa
            exit(0);
        }
        
        
    }


}

void mostraC(int signal){   //Funcao para contar quantas vezes foi apertada o ctrl C

    int cont = contador + '0';  // Passando o contador de inteiro para ASCII
    write(1, "Voce apertou Ctrl-C ", meuLen("Voce apertou Ctrl-C"));
    write(1, &cont, 1); 
    write(1, "vezes \n\n", meuLen("vezes \n\n"));   //Tem que ter essa quebra de linha, pois em baixo nivel, o sistema nao entende tudo de uma vez
}

void pulsoLRM(int signal){
    write(1, "Ta funcionando ai?\n\n", meuLen("Ta funcionando ai?\n\n"));       //Apenas para testar se o alarme ta funcionando
}
int main(int argc, char* argv[])
{

    signal(SIGINT, saiPrograma);        //Sigint = Usado para interferir no funcionamento do CTRL C
    signal(SIGTSTP, mostraC);           //Sigtstp = Usado para interferir no funcionamento do CTRL Z
    signal(SIGALRM, pulsoLRM);          //SIGALRM = Usado para mostrar algo ao usuario a cada pulso do alarme

  while(1){
    alarm(5);   //Pulso do alarme para cada 5 segundos
    pause();    //Reiniciar a contagem
  }

  return 0;


}
