#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    char c;
    //int status;
    printf("Bem vindo ao mini Shelldon. Selecione uma opcao para comecar: \n");
    printf("1- ls: Lista todos os arquivos do diretório, \n2- ps: mostra uma série de informações sobre os processos, \n3- ifconfig: mostra informações do dispositivo de redes e ip \n");
    read(0, &c, sizeof(char)); //0, aonde ta salvando, sizeof(tipo da variavel que ta salvando)
    
    int pid = fork();

    if (c == '1')
    {
        if (pid == 0)
        {
            execl("/bin/ls", "ls", NULL, NULL); //"caminho", "processo", *argumento da funcao (se nao tiver argumento, é NULL), NULL
        }else if (pid < 0){
            printf("Erro ao criar o processo \n");
        }
    }

    else if(c == '2'){
        execl("/bin/ps", "ps", NULL, NULL);
    }else if(c == '3'){
        execl("/bin/ifconfig", "ifconfig", NULL, NULL);
    }
    return 0;
}
