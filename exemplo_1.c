
// gcc -c cg2d.c
// gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11 

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  object * poligono1, * poligono2, * poligono3;
  hobject * poligono4, * poligono5;
  viewport * vp;
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,480); // cria um dispositivo

  
  palheta = CreatePalette(6);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  poligono1 = CreateObject(5);
  poligono2 = CreateObject(4);

  
  SetObject(SetPoint(-9.0,-8.0,1), poligono1);
  SetObject(SetPoint(-7.0,-3.0,1), poligono1);
  SetObject(SetPoint(-4.0,-4.0,1), poligono1);
  SetObject(SetPoint(-3.0,-6.0,1), poligono1);
  SetObject(SetPoint(-6.0,-9.0,1), poligono1);
  
  SetObject(SetPoint(-6.0,-2.0,3), poligono2);
  SetObject(SetPoint(-1.0,-2.0,3), poligono2);
  SetObject(SetPoint(-1.0,-6.0,3), poligono2);
  SetObject(SetPoint(-6.0,-6.0,3), poligono2);


  //janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  janela = CreateWindow(-10.0,0.0,-10.0,0.0);  
  printf("Janela criada com sucesso\n");
  DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo

  /* 
   * Dispositivo gráfico matricial.
   * A janela de visualização considerada não está adequada para visualizar completamente os dois objetos.
   * Poderiamos considerar a janela definida pelos pontos (-10,-10) e (0,0)
   */
  
  Dump2X(dispositivo,palheta);
 
  return 0;
  }

