// gcc -c cg2d.c
// gcc exemplo_1.c -o exemplo_1 cg2d.o -lm -lX11 

#include "cg2d.h"

int main(int argc, char ** argv) {
  
  palette * palheta;
  bufferdevice * dispositivo;
  window * janela;
  hobject * poligono1, * poligono2, * poligono1C, * poligono2C;
  viewport * vp, * vp2, *vp3, *vp4;
  hmatrix * MatrizC;
  
  SetWorld(-20, 10, -20, 15); // Define o tamanho do mundo  
  dispositivo = CreateBuffer(640,530); // cria um dispositivo
  //CreateViewport(float xmin, float xmax, float ymin, float ymax)
  vp = CreateViewport(10,260,10,260);
  vp2 = CreateViewport(270,520,10,260);
  vp3 = CreateViewport(10,260,270,520);
  vp4 = CreateViewport(270,520,270,520);

  CreateViewportBorder(vp, dispositivo);
  CreateViewportBorder(vp2, dispositivo);
  CreateViewportBorder(vp3, dispositivo);
  CreateViewportBorder(vp4, dispositivo);

  palheta = CreatePalette(6);  
  SetColor(0,0,0,palheta);
  SetColor(1,0,0,palheta);
  SetColor(0,1,0,palheta);
  SetColor(0,0,1,palheta);
  SetColor(1,1,1,palheta);
  
  poligono1 = CreateHObject(7);
  poligono2 = CreateHObject(3);
  //Parte externa do A
  SetHObject(SetHPoint(-6.0,-1.0,1,2), poligono1);
  SetHObject(SetHPoint(-11.0,-11.0,1,2), poligono1);
  SetHObject(SetHPoint(-9.0,-11.0,1,2), poligono1);
  SetHObject(SetHPoint(-8.0,-9.0,1,2), poligono1);
  SetHObject(SetHPoint(-4.0,-9.0,1,2), poligono1);
  SetHObject(SetHPoint(-3.0,-11.0,1,2), poligono1);
  SetHObject(SetHPoint(-1.0,-11.0,1,2), poligono1);
  //Parte Interna do A
  SetHObject(SetHPoint(-6.0,-5.0,1,3), poligono2);
  SetHObject(SetHPoint(-7.2,-8.0,1,3), poligono2);
  SetHObject(SetHPoint(-4.8,-8.0,1,3), poligono2);
  

  //janela = CreateWindow(-8.0,5.0,-7.0,5.0); // define uma janela de visualização
  janela = CreateWindow(-20.0,10.0,-20.0,15.0);  
  //DrawObject(poligono1,janela,dispositivo); // desenha o poligono 1 dentro da janela no buffer do dispositivo 
  //DrawObject(poligono2,janela,dispositivo); // desenha o poligono 2 dentro da janela no buffer do dispositivo

  MatrizC = SetSclMatrix(0.3,0.0);

  DrawObjectH(poligono1, janela, dispositivo, vp);
  DrawObjectH(poligono2, janela, dispositivo, vp);

  Cisalhamento (poligono1,MatrizC);
  Cisalhamento (poligono2,MatrizC);
  

  DrawObjectH(poligono1, janela, dispositivo, vp2);
  DrawObjectH(poligono2, janela, dispositivo, vp2);

  MatrizC = SetSclMatrix(-0.6,0.2);

  Cisalhamento (poligono1,MatrizC);
  Cisalhamento (poligono2,MatrizC);
  
  DrawObjectH(poligono1, janela, dispositivo, vp3);
  DrawObjectH(poligono2, janela, dispositivo, vp3);

  MatrizC = SetSclMatrix(0.2,0.4);

  Cisalhamento (poligono1,MatrizC);
  Cisalhamento (poligono2,MatrizC); 

  DrawObjectH(poligono1, janela, dispositivo, vp4);
  DrawObjectH(poligono2, janela, dispositivo, vp4);

  /* 
   * Dispositivo gráfico matricial.
   * A janela de visualização considerada não está adequada para visualizar completamente os dois objetos.
   * Poderiamos considerar a janela definida pelos pontos (-10,-10) e (0,0)
   */
  
  Dump2X(dispositivo,palheta);
 
  return 0;
  }


