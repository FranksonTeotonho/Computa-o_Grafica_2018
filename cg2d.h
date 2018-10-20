
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>

#define EventMask (KeyPressMask | ExposureMask)

#define PI 3.1415926535

/* Exemplo de estruturas de dados para a 
   biblioteca de funções gráficas em C, considerando 
   o plano como referência para o mundo */

float XWMax, XWMin, YWMax, YWMin;

struct Window {
  float xmin,
        xmax,
        ymin,
        ymax;
        };
      
typedef struct Window window;

struct ViewPort {
  int xmin,
      xmax,
      ymin,
      ymax;
      };
      
typedef struct ViewPort viewport;

struct Point2D {
  float x,
        y;
  int   color;
  };
      
typedef struct Point2D point;

struct HPoint2D {
  float x,
        y,
        w;
  int   color;
        };

typedef struct HPoint2D hpoint;

struct Object2D {
  int numbers_of_points;
  point * points; 
  };
  
typedef struct Object2D object; 

// a) Criar uma estrutura "hobject" para trabalhar com pontos homogêneos;
struct Object2Dh {
  int numbers_of_points;
  hpoint * hpoints;
};

typedef struct Object2Dh hobject;

struct Color {
  float red,
        green,
        blue;
        };
      
typedef struct Color ColorValues;    
  
struct Palette {
  int numbers_of_colors;
  ColorValues * colors;
  };

typedef struct Palette palette;

struct Buffer {
  int MaxX,
      MaxY;
  int * buffer;
  };

typedef struct Buffer bufferdevice;

struct HMatrix2D {
  float a11, a12, a13,
        a21, a22, a23,
        a31, a32, a33;
        };

typedef struct HMatrix2D hmatrix;

/* estabelece os limites do mundo */
void SetWorld(float, float, float, float);

/* cria pontos e objetos no mundo */
point * SetPoint(float, float, int);
object * CreateObject(int);
int SetObject(point *, object *);

//b) Modificar as funções SetPoint(), CreateObject() e SetObject() para incorporar o conceito de coordenadas homogêneas;
/* cria pontos e objetos no mundo */
hpoint * SetHPoint(float, float, float, int);
hobject * CreateHObject(int);
int SetHObject(hpoint *, hobject *);
//Fim b)

/* sistemas de referências */
window * CreateWindow(float, float, float, float);
viewport* CreateViewport(float, float, float, float);
void CreateViewportBorder(viewport *,bufferdevice *);
point * Sru2Srn(point *, window *);
bufferdevice * CreateBuffer(int, int);
point * Srn2Srd(point *, bufferdevice *);

/*
c) Modificar as funções sru2srn() e srn2srd() para trabalhar com pontos homogêneos;
d) Modificar a função srn2srd() para trabalhar com a "estrutura viewport";
*/ 
hpoint * Sru2SrnH(hpoint *, window *);
hpoint * Srn2SrdH(hpoint *, bufferdevice *, viewport *); 
//Fim c) e d)

/* funções para criar e gerenciar uma 
   paleta e cores */
palette * CreatePalette(int);
int SetColor(float, float, float, palette *);
ColorValues * GetColor(int, palette *);
object * ChangeColor(object *, int);

/* funções para conversão matricial 
   e preenchimento de objetos */
int DrawLine(point *, point *, window *, bufferdevice *, int);
int DrawObject(object *, window *, bufferdevice *);
//
int DrawLineH(hpoint *, hpoint *, window *, bufferdevice *,viewport *, int);
int DrawObjectH(hobject *, window *, bufferdevice *, viewport *);
//
int Fill(object *, window *, bufferdevice *, int);

/* operações com objetos no mundo */
object * Rotate(object *, float);
object * Translate(object *, float, float);
object * Scale(object *, float, float);
hobject * Cisalhamento (hobject * ,hmatrix * );
hpoint * LinearTransf(hmatrix *, hpoint *);
hmatrix * ComposeMatrix(hmatrix *, hmatrix *);
hmatrix * SetRotMatrix(float);
hmatrix * SetSclMatrix(float, float);
hmatrix * SetSftMatrix(float, float);
/* visualiza o buffer (SRD) no monitor virtual */
int Dump2X(bufferdevice *, palette *);


