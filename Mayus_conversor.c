#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define QCHAR 1024

void read(char []);
void process(char[]);
void write(char[]);

int main (void){
  char txtin[QCHAR] = "0";
  read(txtin);
  process(txtin);
  write(txtin);
  return 0;
}
void read (char txtin[]){
    printf("Enter your text\n");
    fgets(txtin, QCHAR, stdin);
}
void process(char txtin[]){
  int i = 0;
  while (txtin[i] != '\0') {
    if(txtin[i] >= 'a' && txtin[i] <= 'z'){
      txtin[i] = txtin[i] - ('a' - 'A');
    }
    i++;
  }
}
void write(char txtin[]){
  printf("%s\n", txtin);
}
