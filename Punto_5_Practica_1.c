#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define REAL 0
#define IMG 1
#define FREQ 5
#define VMOD 0
#define VANG 1
#define IMOD 2
#define IANG 3
#define RMOD 0
#define RANG 1
#define RES 0
#define IND 1
#define CAP 2


#define PI 3.141592653589793238462643383279502884197169

void presentacion();
float read(uint8_t);
float think(bool, float, float);
float think2(bool, float, float);
float think3(float, float);
void write(float, float);
void write2(float, float, float);

int main(void) {
  float vmod;
  float vang;
  float imod;
  float iang;
  float freq;
  float rmod;
  float rang;
  float real;
  float img;
  float tipo;
  float valor;
  (void)presentacion();
  vmod=read(VMOD);
  vang=read(VANG);
  imod=read(IMOD);
  iang=read(IANG);
  freq=read(FREQ);
  rmod=think(RMOD, vmod, imod);
  rang=think(RANG, vang, iang);
  real=think2(REAL, rmod, rang);
  img=think2(IMG, rmod, rang);
  valor=think3(img, freq);
  (void)write(real, img);
  (void)write2(img, valor, real);
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
         "\nBienvenido a la única e insuperable calculadora\n");
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
  if (sel == VMOD) {
    printf("¿podría usted decir el modulo del voltaje a calcular?\n");
  } else if (sel == VANG) {
    printf("¿podría usted decir el ángulo del voltaje a calcular?\n");
  } else if (sel == IMOD){
    printf("¿podría usted decir el modulo de la corriente a calcular?\n");
  } else if (sel == IANG) {
    printf("¿podría usted decir el ángulo de la corriente a calcular?\n");
  } else if (sel == FREQ) {
    printf("¿podría usted decir la frecuencia de trabajo?\n");
  }
  scanf("%f", &num);
  return (num);
}
float think(bool sel, float num1, float num2){
  float num;
  if (sel == RMOD){
    num = num1/num2;
  }else if (sel == RANG){
    num = num1-num2;
  }
  return(num);
}
float think2(bool sel, float mod, float ang) {
  float num;
  if (sel == IMG){
    num=(sin(ang*PI/180)*mod);
  }else{
    num=(cos(ang*PI/180)*mod);
  }
return(num);
}
float think3(float img, float freq) {
  float num;
  if (img == 0){
    num = RES;
  }else if (img > 0){
    num = 2*PI*freq*img;
  }else if (img < 0){
    num = -1/(2*PI*freq*img);
  }
return(num);
}void write(float real, float img){
  printf("⠀⠀⠀⡀⠄⢔⠠⢂⠔⠠⡂⠔⡠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⢄⠢⢐⠄⠢⡐⡠⠠⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⡢⠐⢄⠢⢐⠠⠀⠀⠀⠀⢀⠢⠀⠀⠀⠀⠀⠄⢄⠀⠀⠀⠀⢄⠢⢐⠠⢂⠔⠠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡐⠄⠢⡐⠄⡂⢄⠀⠀⠀⠀ \n⠀⠀⠀⠀⠁⠡⠊⢔⠨⢊⠄⢕⢐⢑⢐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠪⡐⢌⠊⢔⠨⠨⡐⡀⠀⠀⠀⠨⠨⡨⠨⡂⡂⡪⠠⢃⠅⡊⠔⡡⠂⠀⠀⠀⠀⠌⠄⠀⠀⠀⠀⡑⠅⡊⢔⠠⡈⡢⠡⡑⠌⡂⡪⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡑⡐⠅⢕⠐⢅⠪⢐⠅⡂⠀⠀ \n⠀⠀⠀⠀⠀⠀⠀⠀⠈⠂⡑⢔⠐⢅⠢⡑⠡⡀⠀⠀⠀⠀⠀⠀⠀⠀⠁⢂⠅⡪⢐⠡⡑⠌⠔⡀⠀⠀⠀⠈⠔⡡⢂⢊⠄⡅⠕⠨⠐⢅⠢⠁⠀⠀⠀⠀⠈⠄⠀⠀⠀⠀⠌⢌⠢⠡⡂⠪⠠⡑⡐⢅⢊⠔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⢑⠔⡨⠨⡂⢅⠕⠨⡂⡊⠄⠁⠀ \n ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠡⢊⢐⠅⡢⠡⡀⠀⠀⠀⠀⠀⠀⠀⠀⡈⠢⡁⡪⢐⠡⡑⢄⠀⠀⠀⠀⠀⢊⠔⡐⡡⢂⠕⠀⠀⢀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⡂⠅⢕⠨⡘⠨⢂⢊⠔⡐⠀⠀⠀⠀⠀⢀⠢⡀⠀⠀⠀⠀⡐⠌⢔⠨⡐⢅⢊⠔⡨⢊⠐⠀⠀⠀⠀ \n ⠀⠀⠀⠠⠠⡀⠀⠀⠀⠀⠀⠀⠀⡀⢄⠢⢑⠨⠂⠊⠀⠀⠀⠠⠠⡐⡐⢔⠨⢊⠔⡐⡡⠊⡐⠅⠂⠀⠀⠀⠀⠀⠌⡂⡢⠡⢊⠂⠀⠠⠡⡑⡨⢐⠔⡐⠄⠄⠀⠀⠀⠀⠨⡐⢅⢑⠌⠔⠀⠀⠂⠑⡀⠀⠀⠀⠀⠀⠄⢕⠐⠄⠀⠀⡐⠌⢌⠢⠡⢊⢐⠔⡨⠐⠀⠀⠀⠀⠀⠀ \n ⠀⡠⢊⠜⠨⡐⡐⡀⠀⠀⠀⠐⠨⢐⠡⢊⠔⢄⠀⠀⠀⠀⠀⠈⠈⠔⡨⢂⠪⡐⠌⢔⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡊⢌⠢⢑⠀⠀⠡⢂⢊⠔⠨⡐⡑⠀⠀⠀⠀⠀⠐⡐⡡⢂⢅⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡅⠕⠨⢊⠢⢐⠨⡨⢂⠅⠕⡡⢂⠅⠂⠀⢀⠆⠄⠀⠀⡐ \n ⠐⠌⢔⠨⢊⠔⡨⢂⠅⢄⠀⠀⠀⠀⠈⠐⢈⠢⡑⢄⠀⠀⠀⠀⠀⠀⠀⢑⢐⠌⢌⠢⠡⡡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢔⠨⢂⠂⠀⠈⠔⡐⠌⠌⠔⠨⠀⠈⠔⠠⢀⠀⡢⠂⢅⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⡀⠅⠅⡂⡁⠅⠨⠐⠠⠁⠅⡂⠅⠀⠀⢀⠢⢊⠔⡀⢔⠐ \n ⡈⡪⢐⠡⡂⢅⠢⠡⢊⠔⡁⡂⡀⠀⠀⠀⠀⠀⠀⠡⠑⢄⠀⠀⠀⠀⠀⠀⠀⠅⠕⡨⠨⢂⠅⠄⠀⠀⠀⠀⠀⠑⠅⠅⠕⡐⠌⡂⢅⠀⠀⠨⠠⠡⠡⠡⠑⡀⠀⠡⢑⠐⡐⠄⠅⠅⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠅⢂⠨⠐⡀⠂⠌⠨⠈⡂⠁⠅⠀⠀⠀⢀⠢⠡⡑⡐⠌⢔⠁ \n ⢐⢐⠡⢊⠄⠕⡨⠨⡂⡊⢔⠨⡐⠄⠄⠀⠀⠀⠀⠀⠀⠀⠁⠂⠀⠀⠀⠀⠀⠀⠈⠐⠡⡑⡨⠨⡀⠀⠀⠀⠀⠀⠡⢑⠡⢂⠁⠂⢂⢂⡠⡬⡬⡴⣕⢮⢦⣢⢤⣬⣀⡂⠂⠁⠅⠡⠀⠀⠀⠀⠀⠀⢂⠄⠀⠀⡐⢌⢐⠄⠕⠀⠀⠀⠡⡑⠄⠁⠀⠀⠀⢀⠢⡑⠅⠂⠈⡪⢐⠁ \n ⠀⠀⠡⠡⠊⢌⠢⢑⢐⠌⡂⢅⢊⠌⡪⢐⢀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⢀⢀⠠⢐⢐⠌⢌⠂⠅⠀⠀⠀⠀⢀⢂⡕⣔⢖⣝⢕⡗⣝⢮⡺⣕⣗⢯⡳⡯⣻⢮⢷⢿⣻⣾⣤⣡⠀⠀⠀⠀⠀⠀⢅⠌⢄⢀⠪⢐⢐⠡⠁⠀⠌⢄⠀⠀⠀⠀⠀⠀⢀⠢⠑⠀⠀⠀⠀⠐⠁⠀ \n ⠀⠀⠀⠀⠈⠀⠡⠑⠄⢕⢈⢂⠢⡑⠄⢕⠠⡡⠂⠀⠀⠀⢄⠪⢐⠡⢂⢀⠀⠐⠐⡡⢑⢐⠌⠂⠁⠁⠁⡠⡰⡸⡜⣕⢝⢼⡱⣕⢗⡝⡮⣳⡹⣪⢮⡳⡽⡽⡽⣝⣯⢿⡽⡾⣯⣟⡷⣆⠄⠀⠀⠌⡂⢌⠂⢅⠪⢐⠡⠀⠀⢌⢊⠢⠡⡀⠀⠀⠀⠠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠐⠈⠢⡑⡐⢅⢑⠈⠀⢀⢀⠢⡡⢑⠌⠢⠡⡑⡐⡐⡀⠀⠀⠂⡂⡊⠄⢄⢰⢱⢕⡝⣎⢗⣕⢯⢳⡹⡜⡵⡹⣪⢺⢜⢵⡫⣞⢽⢝⣞⣗⡯⣯⢯⣟⣗⣯⣟⣿⣻⣄⢀⠂⡂⠂⠁⠅⡊⠔⠀⠀⢌⠢⡂⢅⠕⡐⢄⠀⠀⠁⠀⠀⠀⠀⠀⢀⢐⠄⠀⠀ \n ⢀⠀⠀⠀⠀⠀⠀⠀⢀⠠⡨⠨⡂⢌⢂⠢⠠⢀⠀⠀⠑⡐⡡⠨⡊⢌⠢⠨⢂⢊⠔⡠⠀⠀⠠⡱⡱⡕⣇⠧⡳⡱⡳⡵⡹⡕⡧⡫⡎⣗⢵⢹⢕⢗⢽⢜⡵⣻⡺⡮⡯⣗⣟⡮⣗⡷⣳⣻⣞⡿⣆⠂⠀⠀⠀⠀⠂⠀⢀⢊⠢⠡⢊⢐⠌⡂⠅⠂⠀⠀⠀⠀⠀⠀⡠⢂⠆⡑⠀⠀ \n ⠀⠀⠀⠀⠀⠀⢀⢐⢐⠅⡢⠑⢌⢂⠢⡑⠅⢅⢂⠢⢀⠀⠀⠑⠨⡐⠌⡊⢔⢐⠡⠂⢅⢢⡣⡫⣪⢺⢸⢸⢪⢳⡹⣜⢝⡎⡧⡫⡪⡎⡮⣺⢸⢕⢗⣝⢮⣗⡽⡽⣝⣞⡮⣯⢷⣻⢽⣞⣾⣻⣻⣆⠀⠠⠐⡁⡀⠠⡡⢂⠅⢅⠕⡠⡑⠈⠀⠀⠀⠀⠀⠀⡀⡢⠊⢔⠨⠨⠂⠀ \n ⠀⠀⠀⠀⠀⠀⠀⠀⠁⠐⠈⠌⢂⠢⢑⠨⡨⢂⠅⡪⢐⠔⠄⠄⠀⠀⠑⠨⢐⠄⠅⢕⠰⢱⢱⢹⢸⢸⢪⢣⡫⢮⡺⣜⢵⢹⢜⢎⢇⢏⢮⡪⡳⡝⡮⣺⢵⡳⣯⣻⣺⡵⡯⣷⣻⣺⢕⢕⡷⣯⢷⣷⡂⠄⠅⢂⠌⠌⠔⡐⡡⠡⡂⠂⠀⠀⠔⠀⠀⠀⠀⢔⢐⠔⡡⢑⠌⠪⢨⢈ \n ⠠⠠⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠁⠌⠂⢅⢊⠌⡊⠐⠀⠀⠀⡀⢌⠌⡲⣩⢪⢪⢪⡪⢎⢎⢇⢏⢇⢗⢵⡱⣝⢜⢎⢇⢯⡪⡞⣝⢮⢯⣺⡳⣯⣳⣳⢗⡿⣽⣳⣳⣻⢮⢮⢿⢽⣻⣞⣧⠂⠨⠠⠨⠨⠨⡐⡐⠁⠀⠀⠄⢕⠡⡁⠀⡠⢡⠡⡂⡊⢄⠅⠪⠨⡂⡂ \n ⢈⠪⢐⠡⠡⡂⢄⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢄⢊⠔⡐⡡⠀⠀⠀⠄⠕⡨⠐⢌⢧⢣⢣⡣⡳⡸⡱⡱⡹⡸⡱⡝⣜⢼⢸⢕⡝⣕⢧⢳⢝⢮⡳⡳⣕⡯⣞⣞⣞⡯⣯⣗⣷⣻⣺⢽⢯⢿⢽⣳⡯⣿⡌⠀⠁⠈⠌⠌⠀⠀⠀⡠⠡⢃⠅⡊⠔⡨⢐⠡⡂⡢⠊⠀⠁⠈⢌⠔⡐ \n ⠐⢌⠢⢑⠡⢊⠔⡐⠅⠅⠂⠀⠀⠀⠀⠀⠀⠁⠅⠂⠪⡐⡐⢅⠢⠠⠀⠁⠂⠅⡏⡮⡪⡣⡣⡣⡣⢣⢣⢣⢫⢪⢪⡪⡪⣣⢳⡹⡜⣎⢗⢽⢵⢝⡽⣺⡺⣵⣳⣳⣻⣳⣗⡷⣳⢯⢿⢽⣻⣽⣳⣟⡷⣇⠀⠀⠀⠈⠀⠀⠠⡊⡐⠅⠁⠈⠔⡡⠊⠔⡁⠂⠀⠀⠀⠀⠀⠢⢑⠐ \n ⠨⢐⠌⡢⠡⠡⡊⡐⠅⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠁⠑⠡⠠⢐⢝⢜⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢎⢮⢺⢪⡫⡮⡳⣝⢾⣕⣟⣞⣞⣞⣷⣻⣺⡽⣯⣻⡽⣯⢿⣺⣗⣯⢿⣻⠀⠀⠀⠀⢀⠌⠌⠀⠀⠀⠀⠀⠡⠂⠁⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀ \n ⠈⠐⠈⢐⠡⡑⠔⡨⠠⡠⢀⠄⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⢄⠀⢐⢕⢵⢱⢱⢱⢱⢱⢱⢱⢱⢱⢱⢱⠱⡱⡱⡱⡳⡹⡱⡝⣎⢯⡺⣵⣳⣳⣳⣳⣗⣷⢯⣷⣻⣳⣻⣞⣯⣿⣽⣾⣻⣯⢿⠀⠀⠀⠐⠀⠀⠀⡀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n ⠀⠀⢀⠢⢑⠨⡨⢐⠅⡊⢔⠨⡂⠅⢕⢐⠔⡠⠠⠀⠀⠀⠀⠀⢀⠢⠡⡑⠨⠂⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⡇⣇⢏⢧⢫⢎⢧⡫⣞⣞⣞⣾⣺⢾⢽⣻⣞⣷⣻⣞⣾⣳⡷⣟⣾⣿⣾⡿⠀⠀⠀⠀⢀⠠⢂⠢⠂⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⠀⠀⠀⠀⠀⠀⠀ \n ⠀⡀⡢⠡⡑⢌⢐⠅⢌⢂⠅⡢⢊⠌⡂⢂⠅⡢⠁⠀⠀⠀⠀⠠⠡⢊⠌⠢⡑⠡⢱⢝⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⢜⡜⢎⢣⢣⢣⢳⣳⣳⣟⡾⣞⡿⣽⣗⣟⣾⣳⣟⣾⣳⣿⣻⣽⣾⣿⡇⠀⠀⠠⠐⢄⢑⢐⠅⢅⠀⠀⠀⠀⢀⠠⢐⠨⡐⠔⠀⠀⠀⠠⡐⠌⠌ \n ⠀⠂⠊⠈⠀⠂⠁⠈⠀⠀⠀⠀⠀⢀⢐⠡⢐⢐⠄⠄⢄⢀⠀⠀⠀⠀⠀⠁⠈⠈⠂⢇⢇⢇⢇⢇⢇⢇⢇⢇⢇⢧⢣⡣⡣⡣⡳⡱⡹⠐⠨⡊⣎⢮⡺⣞⡾⣯⢿⡽⣷⣻⣞⣷⣻⣞⣷⣟⣾⣯⣿⣽⣿⠃⢈⠠⢁⠑⠄⢅⢂⠪⠐⠀⠀⢄⢂⠢⢊⠔⡡⠊⢌⢀⠢⠡⡑⡐⢅⠑ \n ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠄⢂⠢⢑⢐⠡⠊⠌⠂⠢⠡⠑⠐⠄⠄⠀⠀⠀⠀⢨⢪⢣⢣⢣⢣⢣⢣⡣⣣⢣⡣⡣⡫⡪⡪⠪⠠⡱⡱⣱⣱⢳⣝⡯⡿⣝⣯⢿⡽⣷⣻⢷⣻⡾⣷⣟⣷⣿⣾⡿⣏⠠⠀⡐⠠⠁⠁⠁⠀⡀⠄⠊⠌⠂⠂⠁⠁⠀⠢⡑⡡⢂⠅⡣⠨⡂⠅⠅ \n ⠠⡠⠠⠠⡐⡠⠀⠂⠀⢈⠀⠀⡀⢀⠀⡀⢀⠀⡀⡀⡀⡀⡀⠀⠀⠀⠀⠀⠀⠀⠈⠀⢘⢼⢸⢸⡸⡸⡪⡪⡪⡪⣪⢪⢪⠪⡨⠨⡸⣼⣿⣿⣿⣿⣾⣽⣻⡽⣞⡯⣿⢽⣯⡿⣯⣿⣯⣿⣿⣿⣿⣿⠅⠀⠀⠀⠀⢀⢀⠀⠀⠀⠀⢀⠠⡐⠌⠌⠀⠀⠕⡐⠐⠁⠌⠀⠁⢀⠠⠀ \n ⠨⠂⠁⡁⠀⢀⠀⠂⢀⢑⠌⡪⢐⠅⠪⡐⡡⢊⠰⡐⢔⠨⢂⠁⠀⢀⠠⠀⠂⠁⠀⠀⠀⠸⡸⡱⡱⡱⡹⡸⡸⡪⡪⡊⡎⢌⠢⡑⣽⣿⢿⣽⣾⣳⣽⡺⣯⣟⣷⣻⣽⡻⣷⡿⣟⣷⣿⣷⣿⣿⣿⣿⡧⠀⠀⡀⠂⠅⠂⠀⡀⡂⡪⢐⠡⡂⠕⡀⠀⢀⢀⠠⡠⡐⡐⢌⢌⠢⡑⠀ \n ⠀⡀⠂⠀⠠⠀⠀⠄⠠⡑⢌⠢⡡⢊⢌⠢⢊⠔⡡⢊⠔⢌⢂⠢⡠⠠⡂⠔⡠⠡⠡⠁⠀⠀⠱⡱⡱⡑⢕⢑⢕⠸⡰⡑⡌⢆⢕⢼⣿⣯⣿⣿⢾⡻⡮⡯⣗⣿⢾⣳⣷⢿⣯⢿⣯⣿⣷⣿⣿⣿⣿⣿⡗⠀⠐⠀⠡⢑⢈⠢⠡⡂⠪⡐⡡⢊⢂⠢⡑⢅⠪⢨⢐⠌⡌⡢⠢⡑⠌⠀ \n ⠀⡀⡐⢈⢀⢀⢁⠀⢌⢌⠢⡑⢌⠢⠢⡑⠅⠪⠐⠁⢌⠢⡊⠔⢌⠢⢊⠔⠨⠨⡈⡂⡂⡂⠂⠑⡌⡎⡌⡆⡅⢇⢪⢪⢸⢰⣵⣿⣿⣿⢿⢽⣽⣽⣽⣽⣳⢯⢯⢯⣿⣿⣽⣿⣷⣟⣿⢿⣿⣿⣿⡿⠁⠀⠀⠀⠌⠐⠐⠈⠈⠈⠈⠀⢔⠡⡊⢌⠢⡑⢌⠢⡢⠱⡐⡌⡪⠨⠊⠀ \n ⠌⠢⡊⡢⠱⠨⠂⢀⠢⠡⠑⠘⢀⠁⢁⠀⢐⠀⡀⠄⠅⢕⠨⡘⠀⡁⠀⠀⠠⢑⠐⠐⣠⣦⡀⠀⠱⣵⣮⣦⣧⣧⣷⣷⡷⣕⢵⣿⣿⢯⠿⢻⢻⣿⣟⣿⣏⢧⢫⢯⣿⣾⣿⣾⣿⣿⡿⣿⣽⣿⣿⣥⡀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠂⠢⠑⠌⠢⠑⠌⠢⠃⠪⠨⠢⠊⠌⠊⠐⠀ \n ⠨⢂⢂⠂⡅⡑⡁⠄⡐⡀⢅⠌⡄⠆⢆⠣⡑⠄⠀⠐⠅⠁⠄⠀⡀⢀⠀⡀⠀⠀⡀⣼⣵⠿⠀⠀⠈⠙⢿⣿⣿⣿⢿⡿⣿⣷⡕⣗⡿⣻⠀⠄⡓⢵⣻⡳⡕⢕⣕⣯⣿⣯⣿⣿⣾⣷⢯⡹⣿⣿⣿⣿⣷⣆⡀⠀⠄⠀⠀⠐⠀⠐⠈⠀⠄⠂⠀⠐⠀⠐⢀⠐⠀⠄⡠⠀⠠⠈⠀⠄ \n ⠨⡐⢔⢁⠢⠨⡢⢱⠨⡊⡢⡑⢜⢘⢌⠬⡨⢂⠨⡐⠄⢕⢐⠡⠈⠀⡀⠠⠠⣡⣾⣿⠇⠅⠄⡂⠌⠨⠀⢈⢱⡷⡟⣟⢿⣿⡷⡘⡮⣪⢫⡣⣗⢽⠪⢪⢸⡸⣮⣿⣽⣿⣟⣿⣗⡯⡧⣟⣿⣿⣿⣿⣿⣿⣷⣅⠀⠀⠀⠀⠀⡁⠊⠔⢌⠢⡑⢅⠣⡑⢅⠪⡊⡪⠀⠠⠐⠀⠂⡀ \n ⠨⠊⠢⡱⢨⠪⡨⢢⠣⡱⢨⢊⠂⠅⠢⡑⢌⠢⡑⠌⠊⠀⠀⠀⡐⠡⢠⣱⣿⣿⠟⠁⠂⡡⢁⠂⠅⠀⠀⠀⠰⡹⣦⢶⡽⡾⡇⡣⡯⡪⡒⢌⠢⡑⣜⢼⡸⡮⣷⣿⢿⡾⣟⣿⣽⣿⣽⣹⢵⣻⣻⢿⣿⣿⣿⣿⣧⡀⠐⠠⠠⢀⢀⠄⠀⠂⢁⠁⠃⠕⢅⢣⢑⠠⢈⢐⢈⢄⠡⡀ \n ⠀⠅⢕⠜⢔⢱⠡⡣⠑⠌⠂⠄⢂⠨⢘⠌⠢⠁⠂⠐⠀⠐⠀⡀⣴⣵⣿⡿⠏⠁⠀⠁⠀⢐⠁⠈⠀⠀⠀⠀⠈⢎⡎⡇⡏⡎⡪⡘⡮⡫⡪⣪⣾⣾⢾⣷⢏⢞⣽⡾⣟⡿⣯⢿⣾⣿⣿⣷⣷⣷⣕⣯⣫⢿⣿⣿⣿⣔⣌⡠⠁⡂⡂⢁⠈⡀⠂⠠⡁⢇⢕⢑⢔⠱⡑⡌⡆⢕⢅⠕ \n ⠠⢑⢰⠩⡊⠆⡑⠄⠅⠡⠡⠈⠄⠄⠡⠈⡀⠂⠀⠂⠀⢠⣶⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⡀⠠⠐⠀⠐⠀⠠⠠⠘⢪⢗⣗⣵⢑⢌⢮⣳⢽⣽⡿⡳⣹⠪⡂⣳⢽⡽⡯⣯⢯⢿⣿⣿⣿⣿⠟⠛⠻⠿⠿⣗⡿⣽⣻⣿⣽⣿⣦⠂⠀⠀⠄⠠⠈⡐⢈⠢⠑⢜⠰⡑⢕⢌⠪⡢⡑⡅ \n ⠈⢔⠘⢌⢐⢁⠂⠅⡊⠨⠠⠁⠅⠨⢀⠁⠠⠀⠂⠠⣴⣿⣿⣿⣿⣿⣷⣆⡀⠀⠄⠂⠁⠀⠀⠠⡨⡀⢐⠠⡡⠁⠀⠙⣞⢧⡣⣳⢿⣿⣿⢿⣹⡺⡡⢣⢱⢕⣯⢯⡯⣷⣻⣿⣿⣿⣿⠣⠀⠀⠀⠀⠀⠈⢿⣿⣟⣿⣿⣿⡟⠆⠀⠐⠀⠂⠁⠄⠂⠌⠨⢀⠂⢌⢐⠡⢑⢑⠸⡐ \n ⡈⡂⡑⡐⠔⡐⡡⡱⡨⡊⠨⠈⠌⢐⠀⡐⠠⢂⣥⣿⣿⢿⣫⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠠⠨⡨⠢⡨⢂⠕⠄⢀⠠⠀⠀⠳⡸⢸⢪⢷⢻⡫⡳⡸⡘⡜⣜⢽⣺⢽⢽⣿⣿⣿⣿⣿⡏⠀⠀⠠⠐⠀⠄⢀⠈⢿⣿⣝⣿⣿⣿⣄⠐⠠⡈⢄⠡⢈⠄⠅⠡⠂⠅⡂⠢⠨⡐⢄⢕⠅ \n ⠐⡌⡢⡪⡪⢪⢊⢆⢕⢜⠨⠈⠌⢄⢂⠊⣰⣷⣿⢯⢯⣟⣾⣿⣿⣿⣿⣾⣿⣿⠃⠀⠠⠨⡨⢂⠕⠈⡢⡑⠀⠄⠢⡡⢁⠌⢐⢑⡐⣹⢵⡃⢅⠪⠨⡊⡼⣽⣺⣽⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠡⠈⠄⡐⠈⢺⣷⣳⢿⣿⣿⣬⠐⠐⠄⢅⠕⡨⠪⠨⡈⡂⡊⠌⡢⠨⡢⡣⠣ \n ⡊⡎⢎⢪⢊⢎⢪⠢⡣⢢⢑⠅⡍⡂⣢⢾⢽⡻⣕⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⡊⢌⠢⡑⡀⢂⠐⡀⠡⠨⡊⠔⡁⠐⠠⢈⠢⢊⢗⡅⢕⢘⠌⡆⣻⣺⡾⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠠⠐⠈⠐⠠⡁⠂⣿⣯⢯⢿⣿⣿⡦⡀⡑⠄⠕⠈⠌⡐⡐⡐⠌⡂⠪⡐⠔⠌⠅ \n ⢌⢎⢕⢕⢕⠕⡅⢇⢎⠢⢅⠕⡐⣼⣿⣻⣷⣿⣿⣿⣿⣿⠟⠙⠉⠋⢋⠻⠻⡿⠟⢅⠢⡑⢌⢂⠐⡀⠢⠀⢅⠣⡊⡪⡐⢁⠀⠂⠘⢔⢽⣧⢣⢪⣊⣪⣺⣷⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠂⡀⢐⢈⠄⡂⠅⠰⣿⢯⢯⣻⣿⣿⣷⣆⠡⠡⢡⢑⠰⡐⢌⢂⠪⡨⢂⠕⡡⠃ \n ⠸⡸⡸⡸⡰⡱⡑⡑⢌⠪⡂⠕⢸⡿⣵⣿⣿⠋⠉⠉⠉⠀⠀⠄⠅⡡⠂⠌⡂⠢⠑⠐⢅⢊⠆⢂⠐⢌⢊⠨⡪⡘⢌⠢⡊⠠⠐⠈⠀⠑⣽⣿⣮⣺⢺⣺⣿⣿⢿⣿⣿⣿⣿⣿⣷⡇⠀⠀⠈⢐⠀⠄⠂⠂⢅⠂⢅⢁⢻⣯⣟⢾⢿⣿⣿⣿⣮⠨⢐⢐⢑⠜⢌⢎⢪⢪⢢⢣⢢⠣ \n ⢸⢸⢸⠸⠨⡂⠆⡊⢌⠪⡨⢨⣺⣯⣿⣿⡗⠀⠐⠈⠠⠨⡨⢊⠔⡐⡅⢕⠌⡊⠨⢈⠔⡡⠡⢂⢕⢑⠄⡣⢪⢘⢌⠪⢐⠀⢂⠐⠀⠀⠁⠩⣿⢎⢆⢳⢻⢺⣿⣿⣿⣿⣿⣿⣿⢷⠀⠀⠀⠀⢊⢐⢀⠁⠄⠑⡐⠠⠈⣿⡾⣽⣻⣿⣿⣿⣿⣯⡂⠂⢕⠨⡊⡢⢣⢱⢸⢸⠸⡨ \n ⢘⠜⡌⡪⢊⠔⡑⠌⡂⢕⠌⣰⣟⣾⣿⣿⠂⠄⠡⢈⠪⡨⢢⢡⢑⠕⡌⢆⠕⠠⡑⡅⠢⠨⡨⢢⠱⡁⡂⡂⠅⢊⠢⡑⢁⠐⢐⠀⠂⠀⠀⣼⣿⠕⡌⢆⣳⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⠀⠀⠀⠐⢐⠐⠠⠀⠀⠡⠈⣸⣿⡵⣳⡻⣿⣿⣿⣿⣿⢔⠀⡑⢌⠪⡊⡎⡪⠢⡱⢐ \n ⢐⠕⡌⡊⢆⠕⢌⠌⠔⡁⡐⣼⣳⣿⣿⣿⠈⠄⡁⡂⠌⢌⢆⢣⢱⢱⠸⢐⠌⡪⡊⡎⡕⡱⡘⡜⠌⠔⡀⡂⠌⠄⠂⠐⠀⠐⡐⠀⢀⣠⣾⣿⡷⡱⣨⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣶⣤⣤⣀⣐⠈⠠⠁⠠⠀⠀⠀⣿⣽⡪⣞⣯⣿⣿⣿⣿⣯⣆⢊⢂⢣⠱⡸⡸⡨⡢⡡ \n ⢐⠕⡅⡣⡑⢅⠕⡈⢆⠂⢼⣳⣿⣿⣿⣿⠀⠡⢐⠠⠡⡑⠌⡎⡪⡢⡑⢅⢎⢎⢎⢪⠸⡰⡑⢜⢈⠂⡂⢐⠈⠠⠈⢀⢨⣰⣴⣷⣿⣿⣿⣿⣵⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣷⣦⣦⣤⣸⣷⣻⢜⢮⢿⣻⣿⣿⣿⣾⡢⡑⡰⢑⠕⡜⡜⡜⡬ \n ⢂⢇⠕⡌⡪⢂⢕⢜⠰⣡⡿⣽⣿⣿⣿⣿⠀⠅⡂⠅⢕⢨⢌⠜⢌⠢⡊⡆⡇⡕⡜⢔⠁⢌⠪⡂⠂⠂⠄⢠⣠⣶⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣇⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡮⡫⣫⣿⣿⣿⣿⣿⣯⡂⡊⡢⢣⠣⡪⡪⡢ \n ⢢⠱⡡⡃⡎⡎⡆⢕⢑⣾⢝⣷⣿⣿⣿⣷⠠⢁⠂⢕⢸⢰⢱⢡⠅⡕⡕⢕⠕⡕⡱⢁⠂⢄⠑⡀⣁⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⠻⡫⣿⣿⣿⣿⣯⣿⣟⣿⣿⣿⣿⢿⣟⣿⣽⣷⣿⣷⡷⣿⣟⣿⣽⣟⣿⣻⡿⣿⣿⣿⣿⣿⣿⣿⣽⡪⡪⢾⣽⣿⣿⣿⣽⠆⠌⡊⡆⡇⡇⡇⡇ \n ⠨⡪⡢⡣⡣⡣⡪⡊⣼⡏⣗⣽⣿⣿⣿⣯⠐⠠⡑⡅⢇⢎⢪⢢⢣⠣⡣⡃⡇⢕⠌⡂⡁⠂⡐⢘⢿⣿⣿⣿⣿⣿⣿⣿⣏⣵⣤⡖⡷⣆⣮⣿⣷⡿⣟⣿⣻⣽⣾⣿⣿⣿⣿⢿⣿⣻⣽⣻⡽⣞⡷⣯⢿⣽⡯⣿⣻⡾⣿⣽⣯⣿⣿⣾⣯⣏⢧⡳⣿⣿⣿⣯⣇⢂⢂⠪⢸⢸⢸⡘ \n ⢱⢱⡱⡱⡱⡑⡆⣪⣷⡫⡮⣿⣿⣿⣿⡿⠠⡑⡌⡪⡂⢇⢕⠕⡅⢇⠕⢜⠨⠢⠁⠄⢐⣠⣦⣿⣿⣿⣿⣿⣿⣿⣿⣯⣷⣿⣿⣽⣿⣿⣿⣿⣾⣿⢿⡿⣿⣻⢿⣽⢾⣳⣟⣯⡷⣟⣞⣗⣯⢿⡽⣯⢿⣺⡽⡯⣷⣻⣗⣿⣺⣯⣿⣿⣾⣳⢧⡳⡽⣿⣿⣷⣷⡂⡢⠡⡑⡌⡲⡱ \n ⢸⢸⢸⢸⢸⢘⢄⣷⣗⢵⢽⣿⣿⣿⣿⡟⢌⠢⡊⡢⡊⢎⠢⡃⠪⡂⡣⠡⡑⡁⣅⣼⣾⣿⣿⣿⣿⣿⣿⡿⣽⡽⣯⢿⣻⣟⢽⣻⣯⢿⣺⢷⢷⣻⣯⢿⡽⣯⢿⣞⣯⣷⣻⢾⣽⢽⣞⡷⣯⢿⢽⡽⣯⣻⡿⣽⣻⣞⢾⣺⣗⣿⣺⣯⣿⣻⣽⣞⢮⣳⣿⣿⣾⡗⢜⢘⠔⡑⡌⢎ \n ⢪⢪⢣⢣⢣⢑⢴⣿⡺⣸⣽⣿⣿⣿⣿⡏⡐⢅⠪⡐⢌⠢⡑⠌⣐⣐⢌⣌⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⡽⣯⢿⣽⡻⣼⣫⡷⡿⣽⣫⣟⡿⣽⣞⣯⢿⣽⣻⣾⣳⣟⣾⣟⣾⣻⣽⣻⣽⢿⣽⢯⣷⣻⡿⣽⡷⣿⣽⡷⣿⡾⣷⢿⣽⣿⡿⣾⣗⣯⣿⣿⣿⡯⡂⢕⠨⡪⢸⢐ \n ⡪⣪⢣⢣⢃⠢⣿⣳⢹⢜⣾⣿⣿⣿⣿⡇⡊⠔⡁⡪⢐⢅⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣯⢿⣽⢾⢝⡷⣽⢽⡯⣗⣗⡯⣾⣳⢯⣾⣻⢷⣻⣾⣯⡿⣷⢿⣽⣿⣽⢿⡾⣟⣿⣻⣽⣷⣿⣿⡿⣿⣷⣿⢟⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⡯⢢⢣⢱⢘⢌⠆ \n ⢸⢸⢜⢢⢑⣑⣿⢧⠳⡽⣿⣿⣿⣿⣿⡃⢊⢌⢢⣮⣶⣿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡾⣯⣯⢗⡯⣟⣞⣯⣻⢚⢪⡯⣗⣯⢿⣞⣿⣻⣿⣽⣾⣿⢿⣿⢿⣾⢿⣻⣿⣿⣿⣿⣿⣷⣿⣿⣿⣟⣜⢽⡪⣯⡪⣯⢪⣫⡭⡫⣯⣫⣿⣿⡟⡜⡜⡜⣜⢜⢎⢮ \n ⠰⡱⡑⡕⢔⢸⣯⡳⡹⣾⣿⣿⣿⣿⣿⢁⣦⣷⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣾⣻⢯⡷⣻⣝⣷⡳⣗⣯⡱⣱⢿⣽⡽⣿⡽⣯⣿⡾⣿⣽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢞⢼⡪⣗⢧⢟⢺⠪⠓⠍⠃⢋⠫⡑⢜⢜⢜⢼⢸⢪⢳⡱ \n ⡑⡕⡕⢜⢌⢪⣷⡳⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⡯⡯⡯⣟⡮⡾⣝⣿⣺⣽⢽⡽⣞⣯⣷⣿⣟⣷⣿⣿⣻⣯⣿⣷⣿⣿⣻⣿⣿⣿⣿⣿⣿⡿⣿⣿⡿⡷⣿⣿⣿⢧⡑⡢⡒⡌⡪⢨⢈⡐⡕⢜⢔⢅⢇⡗⣝⢎⢧⡓ \n ⢸⢘⢌⢆⢣⢹⣷⣫⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣯⢯⡿⣝⡷⣝⢾⣳⢯⡷⣯⣟⣟⣯⣿⣳⣿⣽⣟⣷⣿⣟⣿⣿⢿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⣿⢯⢿⣿⣟⣯⢪⢸⢸⢨⡊⡆⡣⡪⡪⡪⣎⢮⡣⣏⢮⢳⢕⡭ \n ⡸⡸⡸⡨⡢⢻⣗⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⡿⡟⣝⣿⣿⣿⣿⣿⣿⣽⢽⡽⣽⢽⡺⣝⣾⢝⣯⡷⣯⢿⣽⣯⣿⢾⣯⣿⣻⣾⡿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⢿⣯⡳⣿⣿⣿⣽⡆⡇⡇⡇⡧⣣⢣⢣⢣⢣⢳⠵⣝⣜⢮⢳⡣⡏ \n ⢜⢜⢜⢌⢪⢺⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⠽⡟⡕⢕⠜⣼⡿⣯⣿⣿⣿⣷⡯⣯⣻⣺⡳⡽⣺⣺⣏⢷⢿⡽⣯⡷⣿⢾⣿⣻⣾⢿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣻⣗⣝⣿⣿⣷⣻⡎⡎⡎⡞⣜⢮⢺⢜⢜⢎⢮⢹⡪⣺⡪⡳⣝⢎ \n ⢎⢎⢎⢎⢪⠺⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣯⣿⡿⡟⢿⢛⢻⢩⠕⢄⠢⡱⡑⡕⡅⡳⣟⣿⣻⣟⣿⣿⣿⣝⣗⣗⢵⣫⢯⢞⣞⣮⢫⡿⡽⡷⣿⣻⣿⣽⣿⣽⣿⣟⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣟⣷⣳⢵⣿⣿⣷⣻⡇⡇⡝⢜⢜⢜⢜⢜⢎⢇⢧⢣⡫⡺⣪⠯⡮⣣ \n ⢸⢸⢜⢜⢜⢜⢝⠿⡿⡿⡷⡿⡽⢟⢟⢝⢕⢕⢕⢭⢪⡪⣪⢪⢪⢪⠸⡐⡅⡣⢣⣻⣟⡮⡷⣟⣿⢿⣿⣳⡳⣳⢝⡮⡯⣳⡳⣯⡳⣻⣽⣟⣯⣿⢾⣷⢿⡷⣿⣟⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣻⣯⣿⠮⣞⢵⣿⣿⣷⣻⡿⡰⢱⢱⢱⢱⢹⡸⡱⡝⣜⢕⢵⡹⡜⣝⢮⡳ \n ⢣⢳⢱⢕⢇⢇⢇⢇⢇⢕⢕⢜⢜⢜⡎⡧⣫⢪⣣⡳⡕⡧⣳⡹⡸⡸⡸⡸⡨⡪⣪⡿⡐⢭⣻⣽⢿⣿⣿⣳⡫⣞⢽⡪⣟⢞⢮⢷⣯⣻⢾⣽⣻⣾⢿⣻⡿⣿⢿⣻⣿⣯⣿⣿⣿⣿⣞⡾⣿⣿⣿⣿⣿⣿⡿⣝⢵⣫⣾⣿⣿⣺⡿⡘⡜⢜⣜⢜⢕⢕⡝⣜⢎⢗⢵⡱⡝⣜⢵⡳ \n ⢸⢪⡣⣣⢳⢱⢕⢕⢕⢕⢕⢕⢎⣗⣝⢞⢮⡳⡱⣕⢯⡺⣪⡺⡜⡵⡱⡣⡣⡣⣾⢯⢴⢔⡿⣾⢿⣿⣿⣟⡮⣳⡫⡾⣕⢯⡫⣗⣷⣫⡿⣽⣻⣾⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣾⣿⣿⣿⣿⣿⣿⢿⣝⡺⣜⣿⣿⣿⣺⣿⡸⡘⡬⡪⡳⣕⢇⢏⢮⢪⢳⡱⣕⢽⢸⡪⡺ \n ⡱⣕⢕⡇⣯⣺⣪⢪⢎⢎⢮⡺⣝⢮⢮⣫⡳⣝⢵⢕⢧⢻⣪⢺⡪⣣⡫⡎⣇⣻⡿⡽⣝⡽⡽⣯⣿⣿⣿⣷⣝⢮⡫⡯⣺⢵⡻⣪⢷⣗⣟⣿⡽⣷⡿⣿⢿⣾⡿⣯⣿⣾⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣟⡧⢽⡸⣿⣿⣿⣳⣿⡪⡸⡰⡱⡹⣪⢗⡽⣸⢪⡣⣣⢳⢕⢗⡝⣜ \n ⡜⡜⡮⣺⢕⡧⣗⢧⡣⡳⣳⢝⣮⣳⡳⡳⣝⢮⡺⣪⢳⢕⢧⢳⡹⡢⡳⡱⣕⣿⡯⡯⣺⣪⣯⢷⣿⣾⣿⣿⡮⡳⣝⢽⡪⣗⢽⣪⣳⣻⣞⣞⣿⣽⢿⡿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⢯⢪⢮⢿⣿⣿⣺⣿⡕⢕⠜⡜⡜⠼⣝⣞⢵⣣⡫⣎⢧⡫⡺⡜⡎ \n ⢕⢽⡺⣕⡯⣞⢵⣫⢞⡽⣪⢯⡺⣜⣞⢽⣪⡳⡕⡧⡫⡮⡳⡕⣇⢯⢪⡣⣽⡯⡯⡯⣗⣟⣾⡿⣿⣿⣿⣿⡯⣫⢞⡵⣫⢞⡵⣣⢗⣽⢾⣺⣻⡾⣿⢿⣻⣿⣻⣾⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣗⣟⠜⣜⣿⣿⣿⣺⣿⣞⢌⢎⠎⡎⡇⡗⣵⢻⣪⢾⢜⢎⢮⢳⡹⡪ \n ⡽⣕⢯⢞⡮⣳⡫⣞⣝⣞⢵⣫⢾⢕⣗⡽⣪⡺⣪⢳⡹⣪⢺⡪⣎⢎⢇⢗⣿⢯⣫⢯⣗⣯⣷⣿⣿⣿⣿⣿⣿⡳⣝⢮⡳⣻⢮⡳⣝⢮⢿⣳⢯⣿⣻⣿⣻⣯⣿⣿⣿⣽⣿⣾⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣗⣗⢕⢸⣾⣿⣿⣽⣿⣗⠜⡔⢕⢕⢕⢕⢕⢯⢞⡵⡯⡯⡳⣕⢝⡎ \n ⢯⡺⡽⣕⣟⢮⡫⣞⢮⢮⣳⢳⢽⢕⣗⢽⢕⣕⢗⢵⡹⣜⢵⢱⢕⢝⢜⣽⡿⡽⡮⣳⣗⡿⣞⣯⣿⣿⣿⣿⣿⢽⣪⡳⣝⣽⣟⣞⡮⡳⣻⣻⡽⣾⣿⣽⡿⣯⣿⣿⣻⣿⣿⣿⣿⣿⣯⣿⣿⣿⣿⣽⣾⣿⣿⣺⢝⢮⣿⣿⣿⢾⣿⣗⢕⢱⠱⡱⡱⡱⡱⡹⡽⣝⣞⢽⣝⢮⢧⡣ \n ⣝⣞⢽⣺⡪⣗⡽⣪⢗⡳⡵⣫⢗⢯⣺⢹⢸⡪⡮⣣⡳⡱⡕⡧⡳⡹⣸⣿⡫⡯⣞⢷⡷⣿⣿⣿⣿⣿⣿⣿⣿⢕⣗⢽⡪⣞⣷⡫⣿⢹⢪⡿⣯⣷⣻⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣯⣿⣟⣿⣗⡯⡳⣽⣿⣿⣿⢯⣿⣟⠌⡆⣇⢧⣳⣹⡪⣗⡽⣺⢮⣳⢽⢝⣵⡫ \n ⢧⡳⣯⣺⡺⣵⡫⣗⡳⣹⡪⡳⡯⣳⡳⣑⢜⣜⢮⡺⡼⣝⣞⡜⡮⡪⣿⣻⡺⡮⡺⡽⣯⣿⣷⣿⣿⣿⣿⣿⣿⣕⣯⡳⣝⣞⢾⣽⣪⣱⢹⣻⢿⣞⡷⣿⣯⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣾⡿⣷⢿⡷⣯⢯⢏⢾⢿⣿⣿⢽⣿⣽⢀⢇⢗⣝⢮⡺⡮⣳⣝⣗⡽⡮⡯⣫⣞⢮ \n ⡵⣻⣪⣞⢾⣕⢯⡺⣜⢮⡺⣹⡪⣗⣟⢮⢳⢕⢧⣳⣫⣞⢞⡮⣳⢽⣿⢽⡺⣝⣯⢯⣟⣾⣿⣿⡿⣿⣿⣷⣿⢺⡺⣝⢮⢮⣳⣻⣮⢿⣿⣾⣽⣝⣟⡮⣿⣽⣿⣿⣿⣿⣿⣿⣿⣯⣷⣿⣿⣿⢿⣻⡿⣽⢯⢯⢇⡯⣿⣿⣿⡽⣿⣿⣎⢎⢮⢪⣳⡫⣯⣳⡳⣵⣫⢞⣝⢼⢜⡎ \n ⡽⡵⣳⣳⣫⢞⡵⣝⢮⢳⢝⢮⡺⣪⢞⢮⡳⣝⢵⢕⡷⡵⣻⡪⣗⣿⡯⣗⢯⣗⣯⡿⣽⡾⣷⣿⣿⣿⣿⣿⡿⡵⣝⢮⡳⡳⣕⢗⣟⡷⡽⣾⢿⣽⣷⡿⣷⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣻⣯⢿⡽⡽⣕⢿⣿⣿⣿⢽⣿⣿⣗⢝⡜⡵⡱⣝⣞⢮⢾⢵⡳⡯⣞⢮⡣⡏ \n⣹⣝⣗⣗⡽⣕⢗⡵⣝⢵⣫⡳⣝⢮⡳⡳⣕⢧⡫⡯⣞⡽⣺⡪⣿⡿⣝⡮⣗⡷⡷⣟⣿⣻⣿⣿⣿⣿⣿⣿⣻⡵⡳⡳⡽⣝⢮⡳⣳⣻⣯⣞⢿⣯⣷⣿⡿⣿⡿⣿⣽⣿⣿⣿⣿⣾⣿⣿⣿⣻⣿⢿⣾⣻⡽⣝⢮⣻⣿⣿⣿⢽⣿⣿⡧⣣⢳⡹⣪⡺⣪⢯⢯⣳⣫⢟⣞⡽⣺⢝ \n ⣳⡳⡵⣝⢎⣗⣝⢮⡳⣕⣝⢮⢳⡹⡺⡪⡧⡯⣻⣪⢯⡺⣝⣿⣻⡪⡾⣵⣻⣻⡿⣽⡿⣿⣿⣿⣟⣷⣿⣟⡮⣫⢯⣺⡪⣗⢽⡪⣞⢾⣾⢽⢯⣿⣾⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣻⡿⣾⣽⢽⢮⡳⣻⣿⣿⣿⢽⣿⣿⣿⡸⣪⢺⢜⢮⡪⡯⣳⣳⢝⣗⢷⢽⣝⣗ \n ⡮⡯⣫⢮⡳⣕⢮⡳⣹⢜⢮⡺⡵⣝⢭⡳⣝⣞⢗⣗⢽⡺⣽⣟⣞⢮⣻⣺⣗⡿⣽⡿⣿⣿⣿⣟⣯⣿⣿⡽⣏⢞⢮⡺⣪⢗⣟⣾⢵⣻⣞⣿⣻⣞⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣟⣿⢷⣻⣽⡣⡯⣿⣿⣿⣿⢽⣿⣿⣿⡪⣎⢧⡫⡺⣜⢮⡳⡽⣝⣞⡽⣵⡳⣳ \n");
  printf("El número binómico resultante es:\n  %f+j%f\n", real, img);
}
void write2(float img, float valor, float real){
  printf("El valor resistivo resultante es: %f ohmios\n", real);
  if (img == 0){
    printf("Es neutro en reactancia o no hay ningun inductor/capacitor\n");
  }else if (img >= 0){
    printf("El circuito inductivo tiene un inductor de %f Henrios\n", valor);
  }else if (img <= 0){
    printf("El circuito capacitivo tiene un capacitivo de %f Faradios\n", -valor);
  }
}
