#include <unistd.h>

int main(){

int i=9;
int j = i + '0';
write(1, &j, sizeof(int));
write(1, "\n\n", 2 );

}

//gcc -0 ex exemplo.c -w
//./ex
