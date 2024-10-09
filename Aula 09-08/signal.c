#include <unistd.h>
#include <signal.h>

int meuLen(char *str){
    int i = 0;
    while(str[i]!= '\0')
    i++;
    return i;
}

void exemploINT(int signal){
    write(1, "Olha só, quer me encerrar seu safado!!!\n\n", meuLen("Olha só, quer me encerrar seu safado!!!\n\n"));
    exit(0);

}

void exemploTSTP(int sinal){
    write(1, "Calma lá amigo, ta podendo colocar em background não\n\n", meuLen("Calma lá amigo, ta podendo colocar em background não\n\n"));

}

void exemploLRM(int sinal){
    write(1, "Ocorrêndia de alarme\n\n", 24);
}

int main(){

    signal(SIGINT, exemploINT);     //Quando o sinal tocar, nao deixar o programa encerrar com ctrl C
    signal(SIGTSTP, exemploTSTP);   //Quando o sinal tocar, nao deixar o programa usar o ctrl Z
    signal(SIGALRM, exemploLRM);    //Quando o sinal de alarme tocar, vai disparar para todo mundo fazer algo, neste caso, vai chamar o exemploLRM

    while(1){
        alarm(5);
        pause(); //Serve para garantir que vai entregar o alarme para todo mundo
    }
}
