
// gcc -c cg2d.c
// gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11 

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  hobject * poligono1, * poligono2;
  viewport * vp;
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo

  vp = (viewport *) malloc(sizeof(viewport));
  vp -> xmin = 50;
  vp -> ymin = 50;
  vp -> xmax = 350;
  vp -> ymax = 350;
  
  palheta = CreatePalette(6);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  //Objetos homogeneos
  poligono1 = CreateHObject(5);
  poligono2 = CreateHObject(4);
  
  //Setando pontos com h

  SetHObject(SetHPoint(-9.0,-8.0,1,1), poligono1);
  SetHObject(SetHPoint(-7.0,-3.0,1,1), poligono1);
  SetHObject(SetHPoint(-4.0,-4.0,1,1), poligono1);
  SetHObject(SetHPoint(-3.0,-6.0,1,1), poligono1);
  SetHObject(SetHPoint(-6.0,-9.0,1,1), poligono1);
  
  SetHObject(SetHPoint(-6.0,-2.0,1,3), poligono2);
  SetHObject(SetHPoint(-1.0,-2.0,1,3), poligono2);
  SetHObject(SetHPoint(-1.0,-6.0,1,3), poligono2);
  SetHObject(SetHPoint(-6.0,-6.0,1,3), poligono2);

  //janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  janela = CreateWindow(-10.0,0.0,-10.0,0.0);  
  
  //Desenhando poligonos homogeneos
  DrawObjectH(poligono1, janela, dispositivo, vp);
  DrawObjectH(poligono2, janela, dispositivo, vp);
  /* 
   * Dispositivo gráfico matricial.
   * A janela de visualização considerada não está adequada para visualizar completamente os dois objetos.
   * Poderiamos considerar a janela definida pelos pontos (-10,-10) e (0,0)
   */
  
  Dump2X(dispositivo,palheta);
 
  return 0;
  }

