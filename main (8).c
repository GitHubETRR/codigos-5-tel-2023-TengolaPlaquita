#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define REAL 0
#define IMG 1
#define REAL1 0
#define IMG1 1
#define REAL2 2
#define IMG2 3
#define MOD 0
#define ANG 1

#define PI 3.141592653589793238462643383279502884197169

void presentacion();
float read(uint8_t);
float sum(float, float);
void write(float, float);
float think(bool, float, float);

int main(void) {
  float real;
  float img;
  float real1;
  float img1;
  float real2;
  float img2;
  (void)presentacion();
  real1=read(REAL1);
  img1=read(IMG1);
  real2=read(REAL2);
  img2=read(IMG2);
  real=sum(real1, real2);
  img=sum(img1, img2);
  (void)write(real, img);
   return 0;
}
void presentacion() {
  printf("\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡿⣿⡽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⢫⣟⣭⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⢙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢟⡡⣏⣷⢾⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⡷⣎⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣄⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠤⢳⣏⣾⡿⣿⣿⢿⣯⣿⣷⡿⣿⣾⢿⡿⣿⣾⣿⢿⣯⣿⣿⣽⣿⣻⣿⣿⡷⣠⢹⣿⣿⣿⣿⣧⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⢻⣷⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⡰⢈⡳⢾⣽⣿⣟⣿⣿⣻⡷⣟⣿⣻⣽⡿⣟⣿⣳⡿⣿⢯⣷⢿⣯⣷⣿⢯⣷⣿⠰⢤⢻⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⡟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠰⢡⢆⡽⣻⡾⣷⣻⡷⣯⡷⣟⡿⣽⢯⡷⣟⣿⣳⢯⡿⣽⣻⣞⡿⣞⡷⣯⢿⣯⢿⡧⣜⢺⠍⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠈⡕⣮⣼⣿⣽⣯⣷⢻⢳⣽⣯⣽⢫⣯⣽⣽⣮⡝⣧⢻⣵⢳⣭⢳⣯⡟⣽⢻⡞⣯⣷⡏⡞⣧⣿⣿⣿⢹⣿⣿⣿⣿⣿⣿⣿⡍⢰ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠰⡑⢧⣻⣞⢷⡻⣞⢯⣏⠷⣍⢯⡞⣭⣓⢷⡪⣝⢭⡳⣹⠮⣝⡳⢮⡝⣯⢻⣝⣯⢷⣛⡜⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣷⣾⣿ "
         "\n⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠠⡙⢮⣳⢟⡞⣽⣊⠷⣘⠯⢎⡳⢜⡲⢍⡲⠵⣩⠒⣍⢣⠝⣢⡝⣣⠞⡱⢏⡾⣹⣟⢮⡜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⡹⢎⡵⣏⠾⣅⢯⡹⢬⡙⢎⡱⢩⡜⡡⢃⠏⡴⠩⣌⠣⢎⡱⢜⡰⢫⡝⣹⡜⣧⡟⣾⢸⣿⣿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢳⢩⣞⡽⣚⡜⢢⢓⡌⣣⢃⠞⣡⠊⡕⢪⠜⡰⠣⣌⢓⠢⡱⢊⢔⡣⡜⢦⢛⡶⣻⢵⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢣⢏⡼⣣⠗⡬⢃⠧⣘⠤⢍⡚⢤⡙⠤⢃⠞⡰⠱⠄⣎⠱⡌⠥⢊⠴⡉⢎⢷⣹⢭⡟⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢎⡷⣍⢯⡱⣉⠖⣠⠓⠢⢜⠰⡨⣑⢊⠜⡰⣉⡒⣌⠒⣄⢋⡜⢢⣙⡚⣶⡹⣞⣳⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣩⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⠳⣎⢧⣓⠲⡜⢠⢋⡅⢎⠴⡑⠆⡎⡝⣠⠇⡥⠬⡕⠦⠪⠜⡥⢲⠹⡶⣝⣳⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣚⡞⣼⡑⢎⡕⢦⡘⣌⢢⠱⢋⡜⡰⡡⢚⡠⢅⠦⣋⠳⣍⠖⣫⢳⡝⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⠸⣱⢪⡕⢲⠆⠶⣐⠦⢍⠲⠢⡕⢡⠣⡜⡌⠲⢉⠱⣈⣍⢲⢏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡠⡗⡜⢃⠋⡓⢌⡚⡌⢅⢣⡘⠡⢑⣨⣤⣷⣟⡛⠛⡿⣷⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣷⡼⠾⢿⣿⣷⣦⣤⣴⣬⠴⠖⠙⣽⣽⢿⣿⡿⣿⣭⡱⣨⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣳⣎⣽⡟⠹⣾⣿⡿⣻⣟⡆⢼⣿⠛⢿⣿⡿⠋⣿⣵⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣾⣷⣶⣿⣯⣧⣟⣿⣷⣦⣤⢶⣾⣿⣟⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣯⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡻⡞⣽⢫⡟⢿⣻⢿⣿⣿⣿⢿⡿⣿⢿⣻⢯⢷⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣷⣻⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡛⣌⣣⣝⣣⣾⣿⣿⡳⣿⣯⣝⡳⢎⠧⢫⡜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡾⣽⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡄⢿⣿⣻⣿⣿⣿⣿⣧⣿⣿⣧⣜⡼⢃⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⣻⣟⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡎⣽⣳⣟⣿⣜⣎⣷⡾⣽⢶⢯⡝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣾⣳⢯⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡖⣽⢾⡻⣟⣿⣿⣛⣯⡟⣾⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣯⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡜⣯⣟⣿⣿⣿⣽⢾⣹⣿⣿⣿⣮⡛⠿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⣿⣞⣿⣞⣿⣷⣻⣯⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣷⡿⣿⣿⣼⣿⣿⣯⣿⣟⣿⣻⣿⣿⣿⣿ "
         "\n⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢓⣾⣿⣿⣿⣯⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣷⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢋⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⢟⣿⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿ "
         "\nBienvenido a la única e insuperable calculadora sumadora de cartesiano y conversor a polar\n");
  sleep(6);
}
float read(uint8_t sel) {
  float num;
    printf("⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝ \n⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇ "
           "\n⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀ \n⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀ "
           "\n⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀ \n⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀ "
           "\n⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀ "
           "\n⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
           "\n⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ "
           "\n⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n");
  if (sel == REAL1) {
    printf("¿podría usted decir la parte real del primer número a sumar?\n→");
  } else if (sel == IMG1){
    printf("¿podría usted decir la parte imaginaria del primer número a sumar?\n→");
  } else if (sel == REAL2){
    printf("¿podría usted decir la parte real del segundo número a sumar?\n→");
  } else if (sel == IMG2){
    printf("¿podría usted decir la parte imaginaria del segundo número a sumar?\n→");
  }
  scanf("%f", &num);
  return (num);
}

float sum(float num1, float num2){
  float num=(num1+num2);
  return(num);
}

void write(float real, float img){
  char sel;
  printf("¿Como desea ver el resultado? Si lo desea en binomica ingrese B, mientras que si lo quiere ver en polar marque P\n→");
  scanf(" %c", &sel);
  while((sel != 'B')&&(sel != 'P')){
  printf("Si desea su resultado en binomica ingrese B, mientras que si lo quiere ver en polar marque P\n→");
  scanf(" %c", &sel);
  }
  if (sel == 'B'){
    printf("El número binómico resultante es:\n  %f+j%f", real, img);
  }else if (sel == 'P'){
    float mod;
    float ang;
    mod=think(MOD, real, img);
    ang=think(ANG, real, img);
    printf("El número polar resultante es:\n  %fe^j%f°", mod, ang);
  }
}

float think(bool sel, float real, float img) {
  float num;
  if (sel == ANG){
    num=(atan2(img, real)*180/PI);
  }else{
    num=sqrt(((real*real)+(img*img)));
  }
return(num);
}