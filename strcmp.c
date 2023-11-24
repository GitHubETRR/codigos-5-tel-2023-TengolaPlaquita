#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define QCHAR 1024

void read(bool,char []);
bool compare(char[], char[]);
void write(bool);

int main (void){
  char txt1[QCHAR] = "0";
  char txt2[QCHAR] = "0";
  bool e = 0;
  read(0,txt1);
  read(1,txt2);
  e = compare(txt1, txt2);
  printf("has escrito %s y %s \n", txt1, txt2, e);
  if(e == 0)
    printf("piola, escribiste lo mismo dos veces");
  else
    printf("piola, escribiste dos cosas distintas");
  return 0;
}
void read (bool sel,char txt[]){
  if(sel)
    printf("Escribí tu segundo texto\n");
  else
    printf("Escribí tu primer texto\n");
  gets(txt);
}
bool compare(char txt1[QCHAR], char txt2[QCHAR]){
  bool var = 0;
  for(int i = 0; i < QCHAR; i++){
    if(txt1[i] != txt2[i]){
      var = 1;
    }
  }
  return (var);
}
