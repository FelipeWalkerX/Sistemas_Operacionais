#include <unistd.h>

int main(){

int i=9;
//int j = i + '0';
read(0, &i, sizeof(int));
//write(1, &j, sizeof(int));
write(1, "\n\n", 2 );

}
