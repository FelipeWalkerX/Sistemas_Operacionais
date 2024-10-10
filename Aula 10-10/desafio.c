#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int contador = 0;

int meuLen(char *str){
    int i = 0;
    while(str[i]!= '\0')
    i++;
    return i;
}

void saiPrograma (int signal){
    int sair;
    contador++;

    if (contador == 3)    {
        write(1, "Deseja realmente sair? [Y/n]: \n\n", meuLen("Deseja realmente sair? [Y/n]: \n\n"));
        alarm(20);
        read(0, &sair, sizeof(int));
        if (sair = 'y')
        {
            write(1, "Saindo......", meuLen("Saindo......"));
            exit(0);
        } else if (sair = 'n')
        {
            write(1, "Continuando...", meuLen("Continuando..."));
        } else{
            write(1, "Demorou muito para responder. Saindo......", meuLen("Demorou muito para responder. Saindo......"));
        }
        
        
    }


}

void mostraC(int signal){

    int cont = contador + '0';
    write(1, "Voce apertou Ctrl-C ", meuLen("Voce apertou Ctrl-C"));
    write(1, &cont, 1);
    write(1, "vezes", meuLen("vezes"));
}

void pulsoLRM(int signal){
    write(1, "Ta funcionando ai?\n\n", meuLen("Ta funcionando ai?\n\n"));
}
int main(int argc, char* argv[])
{

    signal(SIGINT, saiPrograma);
    signal(SIGTSTP, mostraC);
    signal(SIGALRM, pulsoLRM);

  while(1){
    alarm(5);
    pause();
  }

  return 0;


}
