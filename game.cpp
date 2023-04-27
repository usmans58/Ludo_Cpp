//============================================================================
// Name        : LUDO.cpp
// Author      : Usman Siddiqui
// Version     : 1.0
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

 int x_y1=270,x_y3=270, y_y1=200,y_y2=200,x_y2=400,x_y4=400,y_y3=100,y_y4=100; // corinates when Yellow tokens are in gome
 int x_g1=270,x_g3=270, x_g2=400,x_g4=400,y_g1=650,y_g2=650,y_g3=550,y_g4=550; // corinates when Green tokens are in gome
 int x_r1=720,x_r3=720, x_r2=850,x_r4=850,y_r1=650,y_r2=650,y_r3=550,y_r4=550; // corinates when Red tokens are in gome
 int x_b1=720,x_b3=720, x_b2=850,x_b4=850,y_b1=200,y_b2=200,y_b3=100,y_b4=100; // corinates when Blue tokens are in gome
 int count_y=0,count_g=0,count_r=0,count_b=0;
 int player_Turn=0;   // counter for player turn
 int yellow_Kill=0, green_Kill=0, red_Kill=0, blue_Kill=0; //  counter for tokens getting killed
 int menu=0; // variable for storing input in menu
 int players=0; // varaible for storing the  number of players
 bool option=true;
 int score_Yellow=0, score_Green=0, score_Red=0, score_Blue=0; // variable for storing the score of the players
 int Yellow=0,Green=0,Red=0,Blue=0;
 string yellow,green,blue,red; // string varaibles fro displaying the score 
 int dice=0; // variable for storing the dice valule
 int mouse_x=0,mouse_y=0; // for storing the cordinates of mouse click.
 int index1=0, index2=0,index3=0,index4=0,index5=0, index6=0,index7=0,index8=0; // for moving the token in the array 
 int g_index1=0, g_index2=0,g_index3=0,g_index4=0,g_index5=0, g_index6=0,g_index7=0,g_index8=0; // for moving the token in the array 
 int r_index1=0, r_index2=0,r_index3=0,r_index4=0,r_index5=0, r_index6=0,r_index7=0,r_index8=0; // for moving the token in the array 
 int b_index1=0, b_index2=0,b_index3=0,b_index4=0,b_index5=0, b_index6=0,b_index7=0,b_index8=0; // for moving the token in the array 
  
 int Array_Xy[58]={515,515,515,515,515,465,415,365,315,265,215,215,215,265,315,365,415,465,515,515,515,515,515,515,565,615,615,615,615,615,615,665,715,765,815,865,915,915,
 915,865,815,765,715,665,615,615,615,615,615,615,565,565,565,565,565,565,565};
 int Array_Yy[58]={75,125,175,225,275,325,325,325,325,325,325,375,425,425,425,425,425,425,475,525,575,625,675,725,725,725,675,625,575,525,475,425,425,425,425,425,425,
 375,325,325,325,325,325,325,275,225,175,125,75,25,25,75,125,175,225,275,325};
 
 
 int Array_Xg[58]={265,315,365,415,465,515,515,515,515,515,515,565,615,615,615,615,615,615,665,715,765,815,865,915,915,915,865,815,765,715,665,615,615,615,615,615,615,565,515,515,
  515,515,515,515,465,415,365,315,265,215,215,265,315,365,415,465,515};
 int Array_Yg[58]={425,425,425,425,425,475,525,575,625,675,725,725,725,675,625,575,525,475,425,425,425,425,425,425,375,325,325,325,325,325,325,275,225,175,125,75,25,25,25,75,125,
 175,225,275,325,325,325,325,325,325,375,375,375,375,375,375,375};
 
 int Array_Xr[58]={615,615,615,615,615,665,715,765,815,865,915,915,915,865,815,765,715,665,615,615,615,615,615,615,565,515,515,515,515,515,515,465,415,365,315,265,215,215,215,265,315,
 365,415,465,515,515,515,515,515,515,565,565,565,565,565,565,565};
 int Array_Yr[58]={675,625,575,525,475,425,425,425,425,425,425,375,325,325,325,325,325,325,275,225,175,125,75,25,25,25,75,125,175,225,275,325,325,325,325,325,325,375,425,425,425,425,
 425,425,475,525,575,625,675,725,725,675,625,575,525,475,425};
 
 int Array_Xb[58]={865,815,765,715,665,615,615,615,615,615,615,565,515,515,515,515,515,515,465,415,365,315,265,215,215,215,265,315,365,415,465,515,515,515,515,515,515,565,615,615,615,
 615,615,665,715,765,815,865,915,915,865,815,765,715,665,615};
 int Array_Yb[58]={325,325,325,325,325,275,225,175,125,75,25,25,25,75,125,175,225,275,325,325,325,325,325,325,375,425,425,425,425,425,425,475,525,575,625,675,725,725,725,675,625,575,
 525,475,425,425,425,425,425,425,375,375,375,375,375,375,375};
 
 


// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
//Board *b;

 string Num2Str(int t); // converting number to string 



void Kill_Yellow() // for checking if Yellow Token kills anyother token 
 {
   if(((x_y1==x_g1 and y_y1==y_g1) || (x_y2==x_g1 and y_y2==y_g1) || (x_y3==x_g1 and y_y3==y_g1) || (x_y4==x_g1 and y_y4==y_g1))        and                ((x_g1!=Array_Xg[0] and y_g1!=Array_Yg[0]) || (x_g1!=Array_Xg[8] and y_g1!=Array_Yg[8]) || (x_g1!=Array_Xg[13] and y_g1!=Array_Yg[13]) ||  (x_g1!=Array_Xg[21] and y_g1!=Array_Yg[21])  || (x_g1!=Array_Xg[26] and y_g1!=Array_Yg[26])  || (x_g1!=Array_Xg[34] and y_g1!=Array_Yg[34]) || (x_g1!=Array_Xg[39] and y_g1!=Array_Yg[39]) ||(x_g1!=Array_Xg[47] and y_g1!=Array_Yg[47])))
    {
      x_g1=270;
      y_g1=650;
      yellow_Kill++;
      score_Yellow+=10;
      Yellow=score_Yellow;
     }
     
    if(((x_y1==x_g2 and y_y1==y_g2) || (x_y2==x_g2 and y_y2==y_g2) || (x_y3==x_g2 and y_y3==y_g2) || (x_y4==x_g2 and y_y4==y_g2))        and                ((x_g2!=Array_Xg[0] and y_g2!=Array_Yg[0]) || (x_g2!=Array_Xg[8] and y_g2!=Array_Yg[8]) || (x_g2!=Array_Xg[13] and y_g2!=Array_Yg[13]) ||  (x_g2!=Array_Xg[21] and y_g2!=Array_Yg[21])  || (x_g2!=Array_Xg[26] and y_g2!=Array_Yg[26])  || (x_g2!=Array_Xg[34] and y_g2!=Array_Yg[34]) || (x_g2!=Array_Xg[39] and y_g2!=Array_Yg[39]) ||(x_g2!=Array_Xg[47] and y_g2!=Array_Yg[47])))
    {
      x_g2=400;
      y_g2=650;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_g3 and y_y1==y_g3) || (x_y2==x_g3 and y_y2==y_g3) || (x_y3==x_g3 and y_y3==y_g3) || (x_y4==x_g3 and y_y4==y_g3))       and                ((x_g3!=Array_Xg[0] and y_g3!=Array_Yg[0]) || (x_g3!=Array_Xg[8] and y_g3!=Array_Yg[8]) || (x_g3!=Array_Xg[13] and y_g3!=Array_Yg[13]) ||  (x_g3!=Array_Xg[21] and y_g3!=Array_Yg[21])  || (x_g3!=Array_Xg[26] and y_g3!=Array_Yg[26])  || (x_g3!=Array_Xg[34] and y_g3!=Array_Yg[34]) || (x_g3!=Array_Xg[39] and y_g3!=Array_Yg[39]) ||(x_g3!=Array_Xg[47] and y_g3!=Array_Yg[47])))
    {
      x_g3=270;
      y_g3=550;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_g4 and y_y1==y_g4) || (x_y2==x_g4 and y_y2==y_g4) || (x_y3==x_g4 and y_y3==y_g4)  || (x_y4==x_g4 and y_y4==y_g4))      and                ((x_g4!=Array_Xg[0] and y_g4!=Array_Yg[0]) || (x_g4!=Array_Xg[8] and y_g4!=Array_Yg[8]) || (x_g4!=Array_Xg[13] and y_g4!=Array_Yg[13]) ||  (x_g4!=Array_Xg[21] and y_g4!=Array_Yg[21])  || (x_g4!=Array_Xg[26] and y_g4!=Array_Yg[26])  || (x_g4!=Array_Xg[34] and y_g4!=Array_Yg[34]) || (x_g4!=Array_Xg[39] and y_g4!=Array_Yg[39]) ||(x_g4!=Array_Xg[47] and y_g4!=Array_Yg[47])))
    {
      x_g4=400;
      y_g4=550;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_r1 and y_y1==y_r1) || (x_y2==x_r1 and y_y2==y_r1) || (x_y3==x_r1 and y_y3==y_r1)  || (x_y4==x_r1 and y_y4==y_r1))       and                ((x_r1!=Array_Xr[0] and y_r1!=Array_Yr[0]) || (x_r1!=Array_Xr[8] and y_r1!=Array_Yr[8]) || (x_r1!=Array_Xr[13] and y_r1!=Array_Yr[13]) ||  (x_r1!=Array_Xr[21] and y_r1!=Array_Yr[21])  || (x_r1!=Array_Xr[26] and y_r1!=Array_Yr[26])  || (x_r1!=Array_Xr[34] and y_r1!=Array_Yr[34]) || (x_r1!=Array_Xr[39] and y_r1!=Array_Yr[39]) ||(x_r1!=Array_Xr[47] and y_r1!=Array_Yr[47])))
    {
      x_r1=720;
      y_r1=650;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_r2 and y_y1==y_r2) || (x_y2==x_r2 and y_y2==y_r2) || (x_y3==x_r2 and y_y3==y_r2)  || (x_y4==x_r2 and y_y4==y_r2))       and                ((x_r2!=Array_Xr[0] and y_r2!=Array_Yr[0]) || (x_r2!=Array_Xr[8] and y_r2!=Array_Yr[8]) || (x_r2!=Array_Xr[13] and y_r2!=Array_Yr[13]) ||  (x_r2!=Array_Xr[21] and y_r2!=Array_Yr[21])  || (x_r2!=Array_Xr[26] and y_r2!=Array_Yr[26])  || (x_r2!=Array_Xr[34] and y_r2!=Array_Yr[34]) || (x_r2!=Array_Xr[39] and y_r2!=Array_Yr[39]) ||(x_r2!=Array_Xr[47] and y_r2!=Array_Yr[47])))
    {
      x_r2=850;
      y_r2=650;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_r3 and y_y1==y_r3) || (x_y2==x_r3 and y_y2==y_r3) || (x_y3==x_r3 and y_y3==y_r3)  || (x_y4==x_r3 and y_y4==y_r3))       and                ((x_r3!=Array_Xr[0] and y_r3!=Array_Yr[0]) || (x_r3!=Array_Xr[8] and y_r3!=Array_Yr[8]) || (x_r3!=Array_Xr[13] and y_r3!=Array_Yr[13]) ||  (x_r3!=Array_Xr[21] and y_r3!=Array_Yr[21])  || (x_r3!=Array_Xr[26] and y_r3!=Array_Yr[26])  || (x_r3!=Array_Xr[34] and y_r3!=Array_Yr[34]) || (x_r3!=Array_Xr[39] and y_r3!=Array_Yr[39]) ||(x_r3!=Array_Xr[47] and y_r3!=Array_Yr[47])))
    {
      x_r3=720;
      y_r3=550;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_r4 and y_y1==y_r4) || (x_y2==x_r4 and y_y2==y_r4) || (x_y3==x_r4 and y_y3==y_r4)  || (x_y4==x_r4 and y_y4==y_r4))       and                ((x_r4!=Array_Xr[0] and y_r4!=Array_Yr[0]) || (x_r4!=Array_Xr[8] and y_r4!=Array_Yr[8]) || (x_r4!=Array_Xr[13] and y_r4!=Array_Yr[13]) ||  (x_r4!=Array_Xr[21] and y_r4!=Array_Yr[21])  || (x_r4!=Array_Xr[26] and y_r4!=Array_Yr[26])  || (x_r4!=Array_Xr[34] and y_r4!=Array_Yr[34]) || (x_r4!=Array_Xr[39] and y_r4!=Array_Yr[39]) ||(x_r4!=Array_Xr[47] and y_r4!=Array_Yr[47])))
    {
      x_r4=850;
      y_r4=550;
      yellow_Kill++; 
      score_Yellow+=10;
      Yellow=score_Yellow;
      
     }
     
     if(((x_y1==x_b1 and y_y1==y_b1) || (x_y2==x_b1 and y_y2==y_b1) || (x_y3==x_b1 and y_y3==y_b1)  || (x_y4==x_b1 and y_y4==y_b1))       and                ((x_b1!=Array_Xb[0] and y_b1!=Array_Yb[0]) || (x_b1!=Array_Xb[8] and y_b1!=Array_Yb[8]) || (x_b1!=Array_Xb[13] and y_b1!=Array_Yb[13]) ||  (x_b1!=Array_Xb[21] and y_b1!=Array_Yb[21])  || (x_b1!=Array_Xb[26] and y_b1!=Array_Yb[26])  || (x_b1!=Array_Xb[34] and y_b1!=Array_Yb[34]) || (x_b1!=Array_Xb[39] and y_b1!=Array_Yb[39]) ||(x_b1!=Array_Xb[47] and y_b1!=Array_Yb[47])))
    {
      x_b1=720;
      y_b1=200;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_b2 and y_y1==y_b2) || (x_y2==x_b2 and y_y2==y_b2) || (x_y3==x_b2 and y_y3==y_b2)  || (x_y4==x_b2 and y_y4==y_b2))       and                ((x_b2!=Array_Xb[0] and y_b2!=Array_Yb[0]) || (x_b2!=Array_Xb[8] and y_b2!=Array_Yb[8]) || (x_b2!=Array_Xb[13] and y_b2!=Array_Yb[13]) ||  (x_b2!=Array_Xb[21] and y_b2!=Array_Yb[21])  || (x_b2!=Array_Xb[26] and y_b2!=Array_Yb[26])  || (x_b2!=Array_Xb[34] and y_b2!=Array_Yb[34]) || (x_b2!=Array_Xb[39] and y_b2!=Array_Yb[39]) ||(x_b2!=Array_Xb[47] and y_b2!=Array_Yb[47])))
    {
      x_b2=850;
      y_b2=200;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_b3 and y_y1==y_b3) || (x_y2==x_b3 and y_y2==y_b3) || (x_y3==x_b3 and y_y3==y_b3) || (x_y4==x_b3 and y_y4==y_b3))       and                ((x_b3!=Array_Xb[0] and y_b3!=Array_Yb[0]) || (x_b3!=Array_Xb[8] and y_b3!=Array_Yb[8]) || (x_b3!=Array_Xb[13] and y_b3!=Array_Yb[13]) ||  (x_b3!=Array_Xb[21] and y_b3!=Array_Yb[21])  || (x_b3!=Array_Xb[26] and y_b3!=Array_Yb[26])  || (x_b3!=Array_Xb[34] and y_b3!=Array_Yb[34]) || (x_b3!=Array_Xb[39] and y_b3!=Array_Yb[39]) ||(x_b3!=Array_Xb[47] and y_b3!=Array_Yb[47])))
    {
      x_b3=720;
      y_b3=100;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
     
     if(((x_y1==x_b4 and y_y1==y_b4) || (x_y2==x_b4 and y_y2==y_b4) || (x_y3==x_b4 and y_y3==y_b4) || (x_y4==x_b4 and y_y4==y_b4))       and                ((x_b4!=Array_Xb[0] and y_b4!=Array_Yb[0]) || (x_b4!=Array_Xb[8] and y_b4!=Array_Yb[8]) || (x_b4!=Array_Xb[13] and y_b4!=Array_Yb[13]) ||  (x_b4!=Array_Xb[21] and y_b4!=Array_Yb[21])  || (x_b4!=Array_Xb[26] and y_b4!=Array_Yb[26])  || (x_b4!=Array_Xb[34] and y_b4!=Array_Yb[34]) || (x_b4!=Array_Xb[39] and y_b4!=Array_Yb[39]) ||(x_b4!=Array_Xb[47] and y_b4!=Array_Yb[47])))
    {
      x_b4=850;
      y_b4=100;
      yellow_Kill++;
       score_Yellow+=10;
       Yellow=score_Yellow;
     }
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
 void Kill_Green() // for checking if Green Token kills anyother token 
 {
   if(((x_g1==x_y1 and y_g1==y_y1) || (x_g2==x_y1 and y_g2==y_y1) || (x_g3==x_y1 and y_g3==y_y1)  || (x_g4==x_y1 and y_g4==y_y1))       and                ((x_y1!=Array_Xy[0] and y_y1!=Array_Yy[0]) || (x_y1!=Array_Xy[8] and y_y1!=Array_Yy[8]) || (x_y1!=Array_Xy[13] and y_y1!=Array_Yy[13]) ||  (x_y1!=Array_Xy[21] and y_y1!=Array_Yy[21])  || (x_y1!=Array_Xy[26] and y_y1!=Array_Yy[26])  || (x_y1!=Array_Xb[34] and y_y1!=Array_Yy[34]) || (x_y1!=Array_Xy[39] and y_y1!=Array_Yy[39]) ||(x_y1!=Array_Xy[47] and y_y1!=Array_Yy[47])))
    {
      x_y1=270;
      y_y1=200;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
    if(((x_g1==x_y2 and y_g1==y_y2) || (x_g2==x_y2 and y_g2==y_y2) || (x_g3==x_y2 and y_g3==y_y2)  || (x_g4==x_y2 and y_g4==y_y2))       and                ((x_y2!=Array_Xy[0] and y_y2!=Array_Yy[0]) || (x_y2!=Array_Xy[8] and y_y2!=Array_Yy[8]) || (x_y2!=Array_Xy[13] and y_y2!=Array_Yy[13]) ||  (x_y2!=Array_Xy[21] and y_y2!=Array_Yy[21])  || (x_y2!=Array_Xy[26] and y_y2!=Array_Yy[26])  || (x_y2!=Array_Xb[34] and y_y2!=Array_Yy[34]) || (x_y2!=Array_Xy[39] and y_y2!=Array_Yy[39]) ||(x_y2!=Array_Xy[47] and y_y2!=Array_Yy[47])))
    {
      x_y2=400;
      y_y2=200;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_y3 and y_g1==y_y3) || (x_g2==x_y3 and y_g2==y_y3) || (x_g3==x_y3 and y_g3==y_y3)  || (x_g4==x_y3 and y_g4==y_y3))       and                ((x_y3!=Array_Xy[0] and y_y3!=Array_Yy[0]) || (x_y3!=Array_Xy[8] and y_y3!=Array_Yy[8]) || (x_y3!=Array_Xy[13] and y_y3!=Array_Yy[13]) ||  (x_y3!=Array_Xy[21] and y_y3!=Array_Yy[21])  || (x_y3!=Array_Xy[26] and y_y3!=Array_Yy[26])  || (x_y3!=Array_Xb[34] and y_y3!=Array_Yy[34]) || (x_y3!=Array_Xy[39] and y_y3!=Array_Yy[39]) ||(x_y3!=Array_Xy[47] and y_y3!=Array_Yy[47])))
    {
      x_y3=270;
      y_y3=100;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_y4 and y_g1==y_y4) || (x_g2==x_y4 and y_g2==y_y4) || (x_g3==x_y4 and y_g3==y_y4)  || (x_g4==x_y4 and y_g4==y_y4))       and                ((x_y4!=Array_Xy[0] and y_y4!=Array_Yy[0]) || (x_y4!=Array_Xy[8] and y_y4!=Array_Yy[8]) || (x_y4!=Array_Xy[13] and y_y4!=Array_Yy[13]) ||  (x_y4!=Array_Xy[21] and y_y4!=Array_Yy[21])  || (x_y4!=Array_Xy[26] and y_y4!=Array_Yy[26])  || (x_y4!=Array_Xb[34] and y_y4!=Array_Yy[34]) || (x_y4!=Array_Xy[39] and y_y4!=Array_Yy[39]) ||(x_y4!=Array_Xy[47] and y_y4!=Array_Yy[47])))
    {
      x_y4=400;
      y_y4=100;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_r1 and y_g1==y_r1) || (x_g2==x_r1 and y_g2==y_r1) || (x_g3==x_r1 and y_g3==y_r1)  || (x_g4==x_r1 and y_g4==y_r1))       and                ((x_r1!=Array_Xr[0] and y_r1!=Array_Yr[0]) || (x_r1!=Array_Xr[8] and y_r1!=Array_Yr[8]) || (x_r1!=Array_Xr[13] and y_r1!=Array_Yr[13]) ||  (x_r1!=Array_Xr[21] and y_r1!=Array_Yr[21])  || (x_r1!=Array_Xr[26] and y_r1!=Array_Yr[26])  || (x_r1!=Array_Xr[34] and y_r1!=Array_Yr[34]) || (x_r1!=Array_Xr[39] and y_r1!=Array_Yr[39]) ||(x_r1!=Array_Xr[47] and y_r1!=Array_Yr[47])))
    {
      x_r1=720;
      y_r1=650;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_r2 and y_g1==y_r2) || (x_g2==x_r2 and y_g2==y_r2) || (x_g3==x_r2 and y_g3==y_r2)  || (x_g4==x_r2 and y_g4==y_r2))       and                ((x_r2!=Array_Xr[0] and y_r2!=Array_Yr[0]) || (x_r2!=Array_Xr[8] and y_r2!=Array_Yr[8]) || (x_r2!=Array_Xr[13] and y_r2!=Array_Yr[13]) ||  (x_r2!=Array_Xr[21] and y_r2!=Array_Yr[21])  || (x_r2!=Array_Xr[26] and y_r2!=Array_Yr[26])  || (x_r2!=Array_Xr[34] and y_r2!=Array_Yr[34]) || (x_r2!=Array_Xr[39] and y_r2!=Array_Yr[39]) ||(x_r2!=Array_Xr[47] and y_r2!=Array_Yr[47])))
    {
      x_r2=850;
      y_r2=650;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_r3 and y_g1==y_r3) || (x_g2==x_r3 and y_g2==y_r3) || (x_g3==x_r3 and y_g3==y_r3)  || (x_g4==x_r3 and y_g4==y_r3))       and                ((x_r3!=Array_Xr[0] and y_r3!=Array_Yr[0]) || (x_r3!=Array_Xr[8] and y_r3!=Array_Yr[8]) || (x_r3!=Array_Xr[13] and y_r3!=Array_Yr[13]) ||  (x_r3!=Array_Xr[21] and y_r3!=Array_Yr[21])  || (x_r3!=Array_Xr[26] and y_r3!=Array_Yr[26])  || (x_r3!=Array_Xr[34] and y_r3!=Array_Yr[34]) || (x_r3!=Array_Xr[39] and y_r3!=Array_Yr[39]) ||(x_r3!=Array_Xr[47] and y_r3!=Array_Yr[47])))
    {
      x_r3=720;
      y_r3=550;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_r4 and y_g1==y_r4) || (x_g2==x_r4 and y_g2==y_r4) || (x_g3==x_r4 and y_g3==y_r4)  || (x_g4==x_r4 and y_g4==y_r4))       and                ((x_r4!=Array_Xr[0] and y_r4!=Array_Yr[0]) || (x_r4!=Array_Xr[8] and y_r4!=Array_Yr[8]) || (x_r4!=Array_Xr[13] and y_r4!=Array_Yr[13]) ||  (x_r4!=Array_Xr[21] and y_r4!=Array_Yr[21])  || (x_r4!=Array_Xr[26] and y_r4!=Array_Yr[26])  || (x_r4!=Array_Xr[34] and y_r4!=Array_Yr[34]) || (x_r4!=Array_Xr[39] and y_r4!=Array_Yr[39]) ||(x_r4!=Array_Xr[47] and y_r4!=Array_Yr[47])))
    {
      x_r4=850;
      y_r4=550;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_b1 and y_g1==y_b1) || (x_g2==x_b1 and y_g2==y_b1) || (x_g3==x_b1 and y_g3==y_b1)  || (x_g4==x_b1 and y_g4==y_b1))       and                ((x_b1!=Array_Xb[0] and y_b1!=Array_Yb[0]) || (x_b1!=Array_Xb[8] and y_b1!=Array_Yb[8]) || (x_b1!=Array_Xb[13] and y_b1!=Array_Yb[13]) ||  (x_b1!=Array_Xb[21] and y_b1!=Array_Yb[21])  || (x_b1!=Array_Xb[26] and y_b1!=Array_Yb[26])  || (x_b1!=Array_Xb[34] and y_b1!=Array_Yb[34]) || (x_b1!=Array_Xb[39] and y_b1!=Array_Yb[39]) ||(x_b1!=Array_Xb[47] and y_b1!=Array_Yb[47])))
    {
      x_b1=720;
      y_b1=200;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_b2 and y_g1==y_b2) || (x_g2==x_b2 and y_g2==y_b2) || (x_g3==x_b2 and y_g3==y_b2)  || (x_g4==x_b2 and y_g4==y_b2))       and                ((x_b2!=Array_Xb[0] and y_b2!=Array_Yb[0]) || (x_b2!=Array_Xb[8] and y_b2!=Array_Yb[8]) || (x_b2!=Array_Xb[13] and y_b2!=Array_Yb[13]) ||  (x_b2!=Array_Xb[21] and y_b2!=Array_Yb[21])  || (x_b2!=Array_Xb[26] and y_b2!=Array_Yb[26])  || (x_b2!=Array_Xb[34] and y_b2!=Array_Yb[34]) || (x_b2!=Array_Xb[39] and y_b2!=Array_Yb[39]) ||(x_b2!=Array_Xb[47] and y_b2!=Array_Yb[47])))
    {
      x_b2=850;
      y_b2=200;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_b3 and y_g1==y_b3) || (x_g2==x_b3 and y_g2==y_b3) || (x_g3==x_b3 and y_g3==y_b3) || (x_g4==x_b3 and y_g4==y_b3))      and                ((x_b3!=Array_Xb[0] and y_b3!=Array_Yb[0]) || (x_b3!=Array_Xb[8] and y_b3!=Array_Yb[8]) || (x_b3!=Array_Xb[13] and y_b3!=Array_Yb[13]) ||  (x_b3!=Array_Xb[21] and y_b3!=Array_Yb[21])  || (x_b3!=Array_Xb[26] and y_b3!=Array_Yb[26])  || (x_b3!=Array_Xb[34] and y_b3!=Array_Yb[34]) || (x_b3!=Array_Xb[39] and y_b3!=Array_Yb[39]) ||(x_b3!=Array_Xb[47] and y_b3!=Array_Yb[47])))
    {
      x_b3=720;
      y_b3=100;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
     
     if(((x_g1==x_b4 and y_g1==y_b4) || (x_g2==x_b4 and y_g2==y_b4) || (x_g3==x_b4 and y_g3==y_b4)  || (x_g4==x_b4 and y_g4==y_b4))       and                ((x_b4!=Array_Xb[0] and y_b4!=Array_Yb[0]) || (x_b4!=Array_Xb[8] and y_b4!=Array_Yb[8]) || (x_b4!=Array_Xb[13] and y_b4!=Array_Yb[13]) ||  (x_b4!=Array_Xb[21] and y_b4!=Array_Yb[21])  || (x_b4!=Array_Xb[26] and y_b4!=Array_Yb[26])  || (x_b4!=Array_Xb[34] and y_b4!=Array_Yb[34]) || (x_b4!=Array_Xb[39] and y_b4!=Array_Yb[39]) ||(x_b4!=Array_Xb[47] and y_b4!=Array_Yb[47])))
    {
      x_b4=850;
      y_b4=100;
      green_Kill++;
       score_Green+=10;
       Green=score_Green;
     }
    } 
    
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     
   void Kill_Red() // for checking if Red Token kills anyother token 
 {
   if(((x_r1==x_y1 and y_r1==y_y1) || (x_r2==x_y1 and y_r2==y_y1) || (x_r3==x_y1 and y_r3==y_y1)  || (x_r4==x_y1 and y_r4==y_y1))       and                ((x_y1!=Array_Xy[0] and y_y1!=Array_Yy[0]) || (x_y1!=Array_Xy[8] and y_y1!=Array_Yy[8]) || (x_y1!=Array_Xy[13] and y_y1!=Array_Yy[13]) ||  (x_y1!=Array_Xy[21] and y_y1!=Array_Yy[21])  || (x_y1!=Array_Xy[26] and y_y1!=Array_Yy[26])  || (x_y1!=Array_Xb[34] and y_y1!=Array_Yy[34]) || (x_y1!=Array_Xy[39] and y_y1!=Array_Yy[39]) ||(x_y1!=Array_Xy[47] and y_y1!=Array_Yy[47])))
    {
      x_y1=270;
      y_y1=200;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
    if(((x_r1==x_y2 and y_r1==y_y2) || (x_r2==x_y2 and y_r2==y_y2) || (x_r3==x_y2 and y_r3==y_y2)  || (x_r4==x_y2 and y_r4==y_y2))       and                ((x_y2!=Array_Xy[0] and y_y2!=Array_Yy[0]) || (x_y2!=Array_Xy[8] and y_y2!=Array_Yy[8]) || (x_y2!=Array_Xy[13] and y_y2!=Array_Yy[13]) ||  (x_y2!=Array_Xy[21] and y_y2!=Array_Yy[21])  || (x_y2!=Array_Xy[26] and y_y2!=Array_Yy[26])  || (x_y2!=Array_Xb[34] and y_y2!=Array_Yy[34]) || (x_y2!=Array_Xy[39] and y_y2!=Array_Yy[39]) ||(x_y2!=Array_Xy[47] and y_y2!=Array_Yy[47])))
    {
      x_y2=400;
      y_y2=200;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_y3 and y_r1==y_y3) || (x_r2==x_y3 and y_r2==y_y3) || (x_r3==x_y3 and y_r3==y_y3)  || (x_r4==x_y3 and y_r4==y_y3))      and                ((x_y3!=Array_Xy[0] and y_y3!=Array_Yy[0]) || (x_y3!=Array_Xy[8] and y_y3!=Array_Yy[8]) || (x_y3!=Array_Xy[13] and y_y3!=Array_Yy[13]) ||  (x_y3!=Array_Xy[21] and y_y3!=Array_Yy[21])  || (x_y3!=Array_Xy[26] and y_y3!=Array_Yy[26])  || (x_y3!=Array_Xb[34] and y_y3!=Array_Yy[34]) || (x_y3!=Array_Xy[39] and y_y3!=Array_Yy[39]) ||(x_y3!=Array_Xy[47] and y_y3!=Array_Yy[47])))
    {
      x_y3=270;
      y_y3=100;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_y4 and y_r1==y_y4) || (x_r2==x_y4 and y_r2==y_y4) || (x_r3==x_y4 and y_r3==y_y4)  || (x_r4==x_y4 and y_r4==y_y4))       and                ((x_y4!=Array_Xy[0] and y_y4!=Array_Yy[0]) || (x_y4!=Array_Xy[8] and y_y4!=Array_Yy[8]) || (x_y4!=Array_Xy[13] and y_y4!=Array_Yy[13]) ||  (x_y4!=Array_Xy[21] and y_y4!=Array_Yy[21])  || (x_y4!=Array_Xy[26] and y_y4!=Array_Yy[26])  || (x_y4!=Array_Xb[34] and y_y4!=Array_Yy[34]) || (x_y4!=Array_Xy[39] and y_y4!=Array_Yy[39]) ||(x_y4!=Array_Xy[47] and y_y4!=Array_Yy[47])))
    {
      x_y4=400;
      y_y4=100;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_g1 and y_r1==y_g1) || (x_r2==x_g1 and y_r2==y_g1) || (x_r3==x_g1 and y_r3==y_g1)  || (x_r4==x_g1 and y_r4==y_g1))        and                ((x_g1!=Array_Xg[0] and y_g1!=Array_Yg[0]) || (x_g1!=Array_Xg[8] and y_g1!=Array_Yg[8]) || (x_g1!=Array_Xg[13] and y_g1!=Array_Yg[13]) ||  (x_g1!=Array_Xg[21] and y_g1!=Array_Yg[21])  || (x_g1!=Array_Xg[26] and y_g1!=Array_Yg[26])  || (x_g1!=Array_Xg[34] and y_g1!=Array_Yg[34]) || (x_g1!=Array_Xg[39] and y_g1!=Array_Yg[39]) ||(x_g1!=Array_Xg[47] and y_g1!=Array_Yg[47])))
    {
      x_g1=270;
      y_g1=650;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_g2 and y_r1==y_g2) || (x_r2==x_g2 and y_r2==y_g2) || (x_r3==x_g2 and y_r3==y_g2)  || (x_r4==x_g2 and y_r4==y_g2))        and                ((x_g2!=Array_Xg[0] and y_g2!=Array_Yg[0]) || (x_g2!=Array_Xg[8] and y_g2!=Array_Yg[8]) || (x_g2!=Array_Xg[13] and y_g2!=Array_Yg[13]) ||  (x_g2!=Array_Xg[21] and y_g2!=Array_Yg[21])  || (x_g2!=Array_Xg[26] and y_g2!=Array_Yg[26])  || (x_g2!=Array_Xg[34] and y_g2!=Array_Yg[34]) || (x_g2!=Array_Xg[39] and y_g2!=Array_Yg[39]) ||(x_g2!=Array_Xg[47] and y_g2!=Array_Yg[47])))
    {
      x_g2=400;
      y_g2=650;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_g3 and y_r1==y_g3) || (x_r2==x_g3 and y_r2==y_g3) || (x_r3==x_g3 and y_r3==y_g3)  || (x_r4==x_g3 and y_r4==y_g3))       and                ((x_g3!=Array_Xg[0] and y_g3!=Array_Yg[0]) || (x_g3!=Array_Xg[8] and y_g3!=Array_Yg[8]) || (x_g3!=Array_Xg[13] and y_g3!=Array_Yg[13]) ||  (x_g3!=Array_Xg[21] and y_g3!=Array_Yg[21])  || (x_g3!=Array_Xg[26] and y_g3!=Array_Yg[26])  || (x_g3!=Array_Xg[34] and y_g3!=Array_Yg[34]) || (x_g3!=Array_Xg[39] and y_g3!=Array_Yg[39]) ||(x_g3!=Array_Xg[47] and y_g3!=Array_Yg[47])))
    {
      x_g3=270;
      y_g3=550;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_g4 and y_r1==y_g4) || (x_r2==x_g4 and y_r2==y_g4) || (x_r3==x_g4 and y_r3==y_g4)  || (x_r4==x_g4 and y_r4==y_g4))      and                ((x_g4!=Array_Xg[0] and y_g4!=Array_Yg[0]) || (x_g4!=Array_Xg[8] and y_g4!=Array_Yg[8]) || (x_g4!=Array_Xg[13] and y_g4!=Array_Yg[13]) ||  (x_g4!=Array_Xg[21] and y_g4!=Array_Yg[21])  || (x_g4!=Array_Xg[26] and y_g4!=Array_Yg[26])  || (x_g4!=Array_Xg[34] and y_g4!=Array_Yg[34]) || (x_g4!=Array_Xg[39] and y_g4!=Array_Yg[39]) ||(x_g4!=Array_Xg[47] and y_g4!=Array_Yg[47])))
    {
      x_g4=400;
      y_g4=550;
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_b1 and y_r1==y_b1) || (x_r2==x_b1 and y_r2==y_b1) || (x_r3==x_b1 and y_r3==y_b1)  || (x_r4==x_b1 and y_r4==y_b1))       and                ((x_b1!=Array_Xb[0] and y_b1!=Array_Yb[0]) || (x_b1!=Array_Xb[8] and y_b1!=Array_Yb[8]) || (x_b1!=Array_Xb[13] and y_b1!=Array_Yb[13]) ||  (x_b1!=Array_Xb[21] and y_b1!=Array_Yb[21])  || (x_b1!=Array_Xb[26] and y_b1!=Array_Yb[26])  || (x_b1!=Array_Xb[34] and y_b1!=Array_Yb[34]) || (x_b1!=Array_Xb[39] and y_b1!=Array_Yb[39]) ||(x_b1!=Array_Xb[47] and y_b1!=Array_Yb[47])))
    {
      x_b1=Array_Xb[0];
      y_b1=Array_Yb[0];
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_b2 and y_r1==y_b2) || (x_r2==x_b2 and y_r2==y_b2) || (x_r3==x_b2 and y_r3==y_b2)  || (x_r4==x_b2 and y_r4==y_b2))       and                ((x_b2!=Array_Xb[0] and y_b2!=Array_Yb[0]) || (x_b2!=Array_Xb[8] and y_b2!=Array_Yb[8]) || (x_b2!=Array_Xb[13] and y_b2!=Array_Yb[13]) ||  (x_b2!=Array_Xb[21] and y_b2!=Array_Yb[21])  || (x_b2!=Array_Xb[26] and y_b2!=Array_Yb[26])  || (x_b2!=Array_Xb[34] and y_b2!=Array_Yb[34]) || (x_b2!=Array_Xb[39] and y_b2!=Array_Yb[39]) ||(x_b2!=Array_Xb[47] and y_b2!=Array_Yb[47])))
    {
      x_b2=Array_Xb[0];
      y_b2=Array_Yb[0];
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_b3 and y_r1==y_b3) || (x_r2==x_b3 and y_r2==y_b3) || (x_r3==x_b3 and y_r3==y_b3) || (x_r4==x_b3 and y_r4==y_b3))      and                ((x_b3!=Array_Xb[0] and y_b3!=Array_Yb[0]) || (x_b3!=Array_Xb[8] and y_b3!=Array_Yb[8]) || (x_b3!=Array_Xb[13] and y_b3!=Array_Yb[13]) ||  (x_b3!=Array_Xb[21] and y_b3!=Array_Yb[21])  || (x_b3!=Array_Xb[26] and y_b3!=Array_Yb[26])  || (x_b3!=Array_Xb[34] and y_b3!=Array_Yb[34]) || (x_b3!=Array_Xb[39] and y_b3!=Array_Yb[39]) ||(x_b3!=Array_Xb[47] and y_b3!=Array_Yb[47])))
    {
      x_b3=Array_Xb[0];
      y_b3=Array_Yb[0];
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }
     
     if(((x_r1==x_b4 and y_r1==y_b4) || (x_r2==x_b4 and y_r2==y_b4) || (x_r3==x_b4 and y_r3==y_b4)  || (x_r4==x_b4 and y_r4==y_b4))       and                ((x_b4!=Array_Xb[0] and y_b4!=Array_Yb[0]) || (x_b4!=Array_Xb[8] and y_b4!=Array_Yb[8]) || (x_b4!=Array_Xb[13] and y_b4!=Array_Yb[13]) ||  (x_b4!=Array_Xb[21] and y_b4!=Array_Yb[21])  || (x_b4!=Array_Xb[26] and y_b4!=Array_Yb[26])  || (x_b4!=Array_Xb[34] and y_b4!=Array_Yb[34]) || (x_b4!=Array_Xb[39] and y_b4!=Array_Yb[39]) ||(x_b4!=Array_Xb[47] and y_b4!=Array_Yb[47])))
    {
      x_b4=Array_Xb[0];
      y_b4=Array_Yb[0];
      red_Kill++;
      score_Red+=10;
      Red=score_Red;
     }

 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////  
 
   void Kill_Blue() // for checking if Blue Token kills anyother token 
 {
   if(((x_b1==x_y1 and y_b1==y_y1) || (x_b2==x_y1 and y_b2==y_y1) || (x_b3==x_y1 and y_b3==y_y1)  || (x_b4==x_y1 and y_b4==y_y1))       and                ((x_y1!=Array_Xy[0] and y_y1!=Array_Yy[0]) || (x_y1!=Array_Xy[8] and y_y1!=Array_Yy[8]) || (x_y1!=Array_Xy[13] and y_y1!=Array_Yy[13]) ||  (x_y1!=Array_Xy[21] and y_y1!=Array_Yy[21])  || (x_y1!=Array_Xy[26] and y_y1!=Array_Yy[26])  || (x_y1!=Array_Xb[34] and y_y1!=Array_Yy[34]) || (x_y1!=Array_Xy[39] and y_y1!=Array_Yy[39]) ||(x_y1!=Array_Xy[47] and y_y1!=Array_Yy[47])))
    {
      x_y1=270;
      y_y1=200;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
    if(((x_b1==x_y2 and y_b1==y_y2) || (x_b2==x_y2 and y_b2==y_y2) || (x_b3==x_y2 and y_b3==y_y2)  || (x_b4==x_y2 and y_b4==y_y2))       and                ((x_y2!=Array_Xy[0] and y_y2!=Array_Yy[0]) || (x_y2!=Array_Xy[8] and y_y2!=Array_Yy[8]) || (x_y2!=Array_Xy[13] and y_y2!=Array_Yy[13]) ||  (x_y2!=Array_Xy[21] and y_y2!=Array_Yy[21])  || (x_y2!=Array_Xy[26] and y_y2!=Array_Yy[26])  || (x_y2!=Array_Xb[34] and y_y2!=Array_Yy[34]) || (x_y2!=Array_Xy[39] and y_y2!=Array_Yy[39]) ||(x_y2!=Array_Xy[47] and y_y2!=Array_Yy[47])))
    {
      x_y2=400;
      y_y2=200;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_y3 and y_b1==y_y3) || (x_b2==x_y3 and y_b2==y_y3) || (x_b3==x_y3 and y_b3==y_y3)  || (x_b4==x_y3 and y_b4==y_y3))      and                ((x_y3!=Array_Xy[0] and y_y3!=Array_Yy[0]) || (x_y3!=Array_Xy[8] and y_y3!=Array_Yy[8]) || (x_y3!=Array_Xy[13] and y_y3!=Array_Yy[13]) ||  (x_y3!=Array_Xy[21] and y_y3!=Array_Yy[21])  || (x_y3!=Array_Xy[26] and y_y3!=Array_Yy[26])  || (x_y3!=Array_Xb[34] and y_y3!=Array_Yy[34]) || (x_y3!=Array_Xy[39] and y_y3!=Array_Yy[39]) ||(x_y3!=Array_Xy[47] and y_y3!=Array_Yy[47])))
    {
      x_y3=270;
      y_y3=100;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_y4 and y_b1==y_y4) || (x_b2==x_y4 and y_b2==y_y4) || (x_b3==x_y4 and y_b3==y_y4)  || (x_b4==x_y4 and y_b4==y_y4))       and                ((x_y4!=Array_Xy[0] and y_y4!=Array_Yy[0]) || (x_y4!=Array_Xy[8] and y_y4!=Array_Yy[8]) || (x_y4!=Array_Xy[13] and y_y4!=Array_Yy[13]) ||  (x_y4!=Array_Xy[21] and y_y4!=Array_Yy[21])  || (x_y4!=Array_Xy[26] and y_y4!=Array_Yy[26])  || (x_y4!=Array_Xb[34] and y_y4!=Array_Yy[34]) || (x_y4!=Array_Xy[39] and y_y4!=Array_Yy[39]) ||(x_y4!=Array_Xy[47] and y_y4!=Array_Yy[47])))
    {
      x_y4=400;
      y_y4=100;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_g1 and y_b1==y_g1) || (x_b2==x_g1 and y_b2==y_g1) || (x_b3==x_g1 and y_b3==y_g1)  || (x_b4==x_g1 and y_b4==y_g1))        and                ((x_g1!=Array_Xg[0] and y_g1!=Array_Yg[0]) || (x_g1!=Array_Xg[8] and y_g1!=Array_Yg[8]) || (x_g1!=Array_Xg[13] and y_g1!=Array_Yg[13]) ||  (x_g1!=Array_Xg[21] and y_g1!=Array_Yg[21])  || (x_g1!=Array_Xg[26] and y_g1!=Array_Yg[26])  || (x_g1!=Array_Xg[34] and y_g1!=Array_Yg[34]) || (x_g1!=Array_Xg[39] and y_g1!=Array_Yg[39]) ||(x_g1!=Array_Xg[47] and y_g1!=Array_Yg[47])))
    {
      x_g1=270;
      y_g1=650;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_g2 and y_b1==y_g2) || (x_b2==x_g2 and y_b2==y_g2) || (x_b3==x_g2 and y_b3==y_g2)  || (x_b4==x_g2 and y_b4==y_g2))        and                ((x_g2!=Array_Xg[0] and y_g2!=Array_Yg[0]) || (x_g2!=Array_Xg[8] and y_g2!=Array_Yg[8]) || (x_g2!=Array_Xg[13] and y_g2!=Array_Yg[13]) ||  (x_g2!=Array_Xg[21] and y_g2!=Array_Yg[21])  || (x_g2!=Array_Xg[26] and y_g2!=Array_Yg[26])  || (x_g2!=Array_Xg[34] and y_g2!=Array_Yg[34]) || (x_g2!=Array_Xg[39] and y_g2!=Array_Yg[39]) ||(x_g2!=Array_Xg[47] and y_g2!=Array_Yg[47])))
    {
      x_g2=400;
      y_g2=650;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_g3 and y_b1==y_g3) || (x_b2==x_g3 and y_b2==y_g3) || (x_b3==x_g3 and y_b3==y_g3)  || (x_b4==x_g3 and y_b4==y_g3))       and                ((x_g3!=Array_Xg[0] and y_g3!=Array_Yg[0]) || (x_g3!=Array_Xg[8] and y_g3!=Array_Yg[8]) || (x_g3!=Array_Xg[13] and y_g3!=Array_Yg[13]) ||  (x_g3!=Array_Xg[21] and y_g3!=Array_Yg[21])  || (x_g3!=Array_Xg[26] and y_g3!=Array_Yg[26])  || (x_g3!=Array_Xg[34] and y_g3!=Array_Yg[34]) || (x_g3!=Array_Xg[39] and y_g3!=Array_Yg[39]) ||(x_g3!=Array_Xg[47] and y_g3!=Array_Yg[47])))
    {
      x_g3=270;
      y_g3=550;
     blue_Kill++;
     score_Blue+=10;
     Blue=score_Blue;
     }
     
     if(((x_b1==x_g4 and y_b1==y_g4) || (x_b2==x_g4 and y_b2==y_g4) || (x_b3==x_g4 and y_b3==y_g4)  || (x_b4==x_g4 and y_b4==y_g4))      and                ((x_g4!=Array_Xg[0] and y_g4!=Array_Yg[0]) || (x_g4!=Array_Xg[8] and y_g4!=Array_Yg[8]) || (x_g4!=Array_Xg[13] and y_g4!=Array_Yg[13]) ||  (x_g4!=Array_Xg[21] and y_g4!=Array_Yg[21])  || (x_g4!=Array_Xg[26] and y_g4!=Array_Yg[26])  || (x_g4!=Array_Xg[34] and y_g4!=Array_Yg[34]) || (x_g4!=Array_Xg[39] and y_g4!=Array_Yg[39]) ||(x_g4!=Array_Xg[47] and y_g4!=Array_Yg[47])))
    {
      x_g4=400;
      y_g4=550;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_r1 and y_b1==y_r1) || (x_b2==x_r1 and y_b2==y_r1) || (x_b3==x_r1 and y_b3==y_r1)  || (x_b4==x_r1 and y_b4==y_r1))       and                ((x_r1!=Array_Xr[0] and y_r1!=Array_Yr[0]) || (x_r1!=Array_Xr[8] and y_r1!=Array_Yr[8]) || (x_r1!=Array_Xr[13] and y_r1!=Array_Yr[13]) ||  (x_r1!=Array_Xr[21] and y_r1!=Array_Yr[21])  || (x_r1!=Array_Xr[26] and y_r1!=Array_Yr[26])  || (x_r1!=Array_Xr[34] and y_r1!=Array_Yr[34]) || (x_r1!=Array_Xr[39] and y_r1!=Array_Yr[39]) ||(x_r1!=Array_Xr[47] and y_r1!=Array_Yr[47])))
    {
      x_r1=720;
      y_r1=650;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_r2 and y_b1==y_r2) || (x_b2==x_r2 and y_b2==y_r2) || (x_b3==x_r2 and y_b3==y_r2)  || (x_b4==x_r2 and y_b4==y_r2))       and                ((x_r2!=Array_Xr[0] and y_r2!=Array_Yr[0]) || (x_r2!=Array_Xr[8] and y_r2!=Array_Yr[8]) || (x_r2!=Array_Xr[13] and y_r2!=Array_Yr[13]) ||  (x_r2!=Array_Xr[21] and y_r2!=Array_Yr[21])  || (x_r2!=Array_Xr[26] and y_r2!=Array_Yr[26])  || (x_r2!=Array_Xr[34] and y_r2!=Array_Yr[34]) || (x_r2!=Array_Xr[39] and y_r2!=Array_Yr[39]) ||(x_r2!=Array_Xr[47] and y_r2!=Array_Yr[47])))
    {
    {
      x_r2=850;
      y_r2=650;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_r3 and y_b1==y_r3) || (x_b2==x_r3 and y_b2==y_r3) || (x_b3==x_r3 and y_b3==y_r3) || (x_b4==x_r3 and y_b4==y_r3))       and                ((x_r3!=Array_Xr[0] and y_r3!=Array_Yr[0]) || (x_r3!=Array_Xr[8] and y_r3!=Array_Yr[8]) || (x_r3!=Array_Xr[13] and y_r3!=Array_Yr[13]) ||  (x_r3!=Array_Xr[21] and y_r3!=Array_Yr[21])  || (x_r3!=Array_Xr[26] and y_r3!=Array_Yr[26])  || (x_r3!=Array_Xr[34] and y_r3!=Array_Yr[34]) || (x_r3!=Array_Xr[39] and y_r3!=Array_Yr[39]) ||(x_r3!=Array_Xr[47] and y_r3!=Array_Yr[47])))
    {
      x_r3=720;
      y_r3=550;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }
     
     if(((x_b1==x_r4 and y_b1==y_r4) || (x_b2==x_r4 and y_b2==y_r4) || (x_b3==x_r4 and y_b3==y_r4)  || (x_b4==x_r4 and y_b4==y_r4))       and                ((x_r4!=Array_Xr[0] and y_r4!=Array_Yr[0]) || (x_r4!=Array_Xr[8] and y_r4!=Array_Yr[8]) || (x_r4!=Array_Xr[13] and y_r4!=Array_Yr[13]) ||  (x_r4!=Array_Xr[21] and y_r4!=Array_Yr[21])  || (x_r4!=Array_Xr[26] and y_r4!=Array_Yr[26])  || (x_r4!=Array_Xr[34] and y_r4!=Array_Yr[34]) || (x_r4!=Array_Xr[39] and y_r4!=Array_Yr[39]) ||(x_r4!=Array_Xr[47] and y_r4!=Array_Yr[47])))
    {
      x_r4=850;
      y_r4=550;
      blue_Kill++;
      score_Blue+=10;
      Blue=score_Blue;
     }

 }
} 
 
 //////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////////////////////////////////////////////////////////////
 void start()
 {
 
     DrawCircle(x_y1,y_y1,20,colors[GOLD]); // For Displaying Yellow Tokens
	DrawCircle(x_y2,y_y2,20,colors[GOLD]);
	DrawCircle(x_y3,y_y3,20,colors[GOLD]);
	DrawCircle(x_y4,y_y4,20,colors[GOLD]);
	
	DrawCircle(x_g1,y_g1,20,colors[FOREST_GREEN]); // For Displaying Green Tokens
	DrawCircle(x_g2,y_g2,20,colors[FOREST_GREEN]);
	DrawCircle(x_g3,y_g3,20,colors[FOREST_GREEN]);
	DrawCircle(x_g4,y_g4,20,colors[FOREST_GREEN]);
	
	DrawCircle(x_r1,y_r1,20,colors[FIREBRICK]); // For Displaying Red Tokens
	DrawCircle(x_r2,y_r2,20,colors[FIREBRICK]);
	DrawCircle(x_r3,y_r3,20,colors[FIREBRICK]);
	DrawCircle(x_r4,y_r4,20,colors[FIREBRICK]);
	
	DrawCircle(x_b1,y_b1,20,colors[DEEP_SKY_BLUE]); // For Displaying Blue Tokens
	DrawCircle(x_b2,y_b2,20,colors[DEEP_SKY_BLUE]);
	DrawCircle(x_b3,y_b3,20,colors[DEEP_SKY_BLUE]);
	DrawCircle(x_b4,y_b4,20,colors[DEEP_SKY_BLUE]);
 }
 
 void Dice_Num() // Generate random numbers for dice
  {
   srand(time(0));
   dice=(rand()%6)+1;
   //cout<<dice<<endl;
  }
 
  void Display_Dice() // Display the dots on dice 
    {
      if (dice==1)
       DrawCircle(87,87,15,colors[RED]); //  for one
     
     
     if(dice==2)
     {
      DrawCircle(87,70,10,colors[RED]); // For two
      DrawCircle(87,105,10,colors[RED]);
     }
    
     if(dice==3)
     {
      DrawCircle(87,60,10,colors[RED]);  // For three
      DrawCircle(87,85,10,colors[RED]);
      DrawCircle(87,110,10,colors[RED]);
     }
     
     if(dice==4)
     {
      DrawCircle(75,100,10,colors[RED]);  // For four
      DrawCircle(105,100,10,colors[RED]);
      DrawCircle(75,75,10,colors[RED]);
      DrawCircle(105,75,10,colors[RED]);
     }
     
     if(dice==5)
     {
      DrawCircle(75,100,7,colors[RED]);   // For FIVE
      DrawCircle(105,100,7,colors[RED]);
      DrawCircle(75,75,7,colors[RED]);
      DrawCircle(105,75,7,colors[RED]);
      DrawCircle(90,87,7,colors[RED]);
     }
     
    if(dice==6)
    { 
      DrawCircle(75,60,7,colors[RED]);  // For six
      DrawCircle(75,85,7,colors[RED]);
      DrawCircle(75,110,7,colors[RED]);
      DrawCircle(105,60,7,colors[RED]);  
      DrawCircle(105,85,7,colors[RED]);
      DrawCircle(105,110,7,colors[RED]);
    }  
  }
  
   
  
  
 void Player1() // MOVEMNET OF YELLOW COLOUR
  
  {
    DrawString( 400, 800, "Yellow Turn", colors[MISTY_ROSE]);
    yellow=Num2Str(Yellow);
     DrawString( 50, 800, "Score= " ,colors[MISTY_ROSE]);
    DrawString( 130, 800, yellow ,colors[MISTY_ROSE]);
    int count=0;
   if(dice==6)

   {
    if((mouse_x>=380 && mouse_x<=420) && (mouse_y>=80 && mouse_y<=120))
     {
      
       x_y4=Array_Xy[0];
       y_y4=Array_Yy[0];
       Dice_Num();
       Display_Dice();     
      }
     }
    if(dice==6)
   {    
     if((mouse_x>=380 && mouse_x<=420) && (mouse_y>=180 && mouse_y<=220)) 
     {
      x_y2=Array_Xy[0];
      y_y2=Array_Yy[0];
      Dice_Num();
       Display_Dice();
      }
     }
      if(dice==6)
      {
       if((mouse_x>=250 && mouse_x<=290) && (mouse_y>=80 && mouse_y<=120)) 
     {
      x_y3=Array_Xy[0];
      y_y3=Array_Yy[0];
      Dice_Num();
       Display_Dice();
      } 
     }
     if(dice==6)
     {
      if((mouse_x>=250 && mouse_x<=290) && (mouse_y>=180 && mouse_y<=220)) 
     {
      x_y1=Array_Xy[0];
      y_y1=Array_Yy[0];
       Dice_Num();
       Display_Dice();
     }   
   } 
   
    // Movement for Token 4.
     if(dice>=1 && dice<=6)
     {
      if(x_y4!=400 && y_y4!=100)
      {
       if(count==0)
       {
      if((mouse_x>=x_y4-15 && mouse_x<=x_y4+15) && (mouse_y>=y_y4-15 && mouse_y<=y_y4+15))
        {
          if( yellow_Kill==0 )
         { 
          if(index1+dice<52)
         { 
         x_y4=Array_Xy[index1+dice];
         index1=index1+dice;
      
        y_y4=Array_Yy[index2+dice]; 
        index2=index2+dice;
       }
      } 
        if( yellow_Kill!=0)
        {
          x_y4=Array_Xy[index1+dice];
         index1=index1+dice;
      
        y_y4=Array_Yy[index2+dice]; 
        index2=index2+dice;
        } 
        score_Yellow=score_Yellow+dice;
        Yellow=score_Yellow;
       if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { 
        count++;
        }
       }
      }
     }
    }
         // Movemnet for Token 2
       if(x_y2!=400 && y_y2!=200)
       {   
      if((mouse_x>=x_y2-15 && mouse_x<=x_y2+15) && (mouse_y>=y_y2-15 && mouse_y<=y_y2+15))
        {
         if(count==0)
         {
          if(yellow_Kill==0)
           {
            if(index3+dice<52 )
          {
         x_y2=Array_Xy[index3+dice];
         index3=index3+dice;
      
        y_y2=Array_Yy[index4+dice]; 
        index4=index4+dice;
        }
       }
         if( yellow_Kill!=0)
        {
          x_y2=Array_Xy[index3+dice];
         index3=index3+dice;
      
        y_y2=Array_Yy[index4+dice]; 
        index4=index4+dice;
        } 
        score_Yellow=score_Yellow+dice;
        Yellow=score_Yellow;
          if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
      }
     } 
    }
        // Movemnet for Token 1
       
        if(x_y1!=270 && y_y1!=200)
       { 
       if((mouse_x>=x_y1-10 && mouse_x<=x_y1+10) && (mouse_y>=y_y1-10 && mouse_y<=y_y1+10))
        {
         if(count==0)
         {
            if( yellow_Kill==0 )
         { 
          if(index5+dice<52)
         { 
         x_y1=Array_Xy[index5+dice];
         index5=index5+dice;
      
        y_y1=Array_Yy[index6+dice]; 
        index6=index6+dice;
       }
      } 
      if(yellow_Kill!=0)
      {
         x_y1=Array_Xy[index5+dice];
         index5=index5+dice;
      
        y_y1=Array_Yy[index6+dice]; 
        index6=index6+dice;
       }
        score_Yellow=score_Yellow+dice;
        Yellow=score_Yellow;
          if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
        }
       }
       }
       
        // Movemnet for Token 3
        
       if(x_y3!=270 && y_y3!=100)
      {   
      if((mouse_x>=x_y3-10 && mouse_x<=x_y3+10) && (mouse_y>=y_y3-10 && mouse_y<=y_y3+10))
        {
         if(count==0)
          {
            if( yellow_Kill==0 )
         { 
          if(index7+dice<52)
         { 
         x_y3=Array_Xy[index7+dice];
         index7=index7+dice;
      
        y_y3=Array_Yy[index8+dice]; 
        index8=index8+dice;
       }
      } 
      if(yellow_Kill!=0)
       {
         x_y3=Array_Xy[index7+dice];
         index7=index7+dice;
      
        y_y3=Array_Yy[index8+dice]; 
        index8=index8+dice;
       }
       
        score_Yellow=score_Yellow+dice;
        Yellow=score_Yellow;
         if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
        }
     }
     }
 }
  Kill_Yellow();
  if(count_y==0)
  {
   if(index1>=52)
    {
     score_Yellow=score_Yellow+15;
     count_y++;
    } 
   }
  if(count_y==1)
   {
    if(index3>=52)
    {
       score_Yellow=score_Yellow+15;
     count_y++;
    }
   }
   
   
    if(count_y==2)
  {
   if(index5>=52)
    {
     score_Yellow=score_Yellow+15;
     count_y++;
    } 
   }
  if(count_y==3)
   {
    if(index7>=52)
    {
       score_Yellow=score_Yellow+15;
     count_y++;
    }
   } 

     
}
//                                     ------------------------------------------------------------------------------------------------
//                                     ------------------------------------------------------------------------------------------------

 void Player2()
 {
    DrawString (400, 800, "Green Turn", colors[MISTY_ROSE]);
     green=Num2Str(Green);
     DrawString( 50, 800, "Score= " ,colors[MISTY_ROSE]);
    DrawString( 130, 800, green ,colors[MISTY_ROSE]);
    int count=0;
    
   if(dice==6)
   {
    if((mouse_x>=380 && mouse_x<=420) && (mouse_y>=540 && mouse_y<=560))
     {
      
       x_g4=Array_Xg[0];
       y_g4=Array_Yg[0];
       Dice_Num();
       Display_Dice();     
      }
     }
    if(dice==6)
   {    
     if((mouse_x>=385 && mouse_x<=415) && (mouse_y>=635 && mouse_y<=665)) 
     {
      x_g2=Array_Xg[0];
      y_g2=Array_Yg[0];
      Dice_Num();
       Display_Dice();
      }
     }
      if(dice==6)
      {
       if((mouse_x>=255 && mouse_x<=285) && (mouse_y>=535 && mouse_y<=565)) 
     {
      x_g3=Array_Xg[0];
      y_g3=Array_Yg[0];
      Dice_Num();
      Display_Dice();
      } 
     }
     if(dice==6)
     {
      if((mouse_x>=255 && mouse_x<=275) && (mouse_y>=635 && mouse_y<=665)) 
     {
      x_g1=Array_Xg[0];
      y_g1=Array_Yg[0];
       Dice_Num();
       Display_Dice();
     }   
   } 
   
   
    // Movement for Token 4.
    
     if(dice>=1 && dice<=6)
     {
      if(x_g4!=400 && y_g4!=550)
      {
      if((mouse_x>=x_g4-15 && mouse_x<=x_g4+15) && (mouse_y>=y_g4-15 && mouse_y<=y_g4+15))
        {
         if(count==0)
         {
          if( green_Kill==0 )
         { 
          if(g_index1+dice<52)
         { 
         x_g4=Array_Xg[g_index1+dice];
         g_index1=g_index1+dice;
      
        y_g4=Array_Yg[g_index2+dice]; 
        g_index2=g_index2+dice;
       }
      } 
          if(green_Kill!=0)
          {
         x_g4=Array_Xg[g_index1+dice];
         g_index1=g_index1+dice;
      
        y_g4=Array_Yg[g_index2+dice]; 
        g_index2=g_index2+dice;
       }
        score_Green=score_Green+dice;
         Green=score_Green;
        if(dice<=6)
       {
        dice=0;
        if(dice<6)
        { count++;}
       }
        }
       }
      } 
         // Movemnet for Token 2
       if(x_g2!=400 && y_g2!=650)
       {   
      if((mouse_x>=x_g2-15 && mouse_x<=x_g2+15) && (mouse_y>=y_g2-15 && mouse_y<=y_g2+15))
        {
         if(count=0)
         {
           if( green_Kill==0 )
         { 
          if(g_index3+dice<52)
         { 
         x_g2=Array_Xg[g_index3+dice];
         g_index3=g_index3+dice;
      
        y_g2=Array_Yg[g_index4+dice]; 
        g_index4=g_index4+dice;
       }
      } 
          if(green_Kill!=0)
         {
         x_g2=Array_Xg[g_index3+dice];
         g_index3=g_index3+dice;
      
        y_g2=Array_Yg[g_index4+dice]; 
        g_index4=g_index4+dice;
       }
         score_Green=score_Green+dice;
          Green=score_Green;
       if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
       }
        }
       }
        // Movemnet for Token 1
       
        if(x_g1!=270 && y_g1!=650)
       { 
       if((mouse_x>=x_g1-15 && mouse_x<=x_g1+15) && (mouse_y>=y_g1-15 && mouse_y<=y_g1+15))
        {
         if(count==0)
         {
           if( green_Kill==0 )
         { 
          if(g_index5+dice<52)
         { 
         x_g1=Array_Xg[g_index5+dice];
         g_index5=g_index5+dice;
      
        y_g1=Array_Yg[g_index6+dice]; 
        g_index6=g_index6+dice;
       }
      } 
       if(green_Kill!=0)
       {
         x_g1=Array_Xg[g_index5+dice];
         g_index5=g_index5+dice;
      
        y_g1=Array_Yg[g_index6+dice]; 
        g_index6=g_index6+dice;
       }
         score_Green=score_Green+dice;
          Green=score_Green;
         if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
        }
       } 
      }
       
        // Movemnet for Token 3
        
       if(x_g3!=270 && y_g3!=550)
      {   
      if((mouse_x>=x_g3-15 && mouse_x<=x_g3+15) && (mouse_y>=y_g3-15 && mouse_y<=y_g3+15))
        {
         if(count==0)
         {
           if( green_Kill==0 )
         { 
          if(g_index7+dice<52)
         { 
         x_g3=Array_Xg[g_index7+dice];
         g_index7=g_index7+dice;
      
        y_g3=Array_Yg[g_index8+dice]; 
        g_index8=g_index8+dice;
       }
      } 
         if(green_Kill!=0)
         { 
         x_g3=Array_Xg[g_index7+dice];
         g_index7=g_index7+dice;
 
        y_g3=Array_Yg[g_index8+dice]; 
        g_index8=g_index8+dice;
       }
         score_Green=score_Green+dice;
          Green=score_Green;
         if(dice<=6)
       {
        dice=0;
         if(dice<6)
        { count++;}
       }
       }
        }
       }
 } 
  Kill_Green();
  
  if(count_g==0)
  {
   if(g_index1>=53)
    {
     score_Green=score_Green+15;
     count_g++;
    } 
   }
  if(count_g==1)
   {
    if(g_index3>=53)
    {
       score_Green=score_Green+15;
     count_g++;
    }
   }
   
   
    if(count_y==2)
  {
   if(g_index5>=53)
    {
     score_Green=score_Green+15;
     count_g++;
    } 
   }
  if(count_y==3)
   {
    if(g_index7>=53)
    {
       score_Green=score_Green+15;
     count_g++;
    }
   } 
}

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------


  void Player3()
 {
    DrawString (400, 800, "Red Turn", colors[MISTY_ROSE]);
    red=Num2Str(Red);
     DrawString( 50, 800, "Score= " ,colors[MISTY_ROSE]);
    DrawString( 130, 800, red ,colors[MISTY_ROSE]);
    int count=0;
   if(dice==6)
   {
    if((mouse_x>=835 && mouse_x<=860) && (mouse_y>=540 && mouse_y<=560))
     {
      
       x_r4=Array_Xr[0];
       y_r4=Array_Yr[0];
       Dice_Num();
       Display_Dice();     
      }
     }
    if(dice==6)
   {    
     if((mouse_x>=835 && mouse_x<=860) && (mouse_y>=635 && mouse_y<=665)) 
     {
      x_r2=Array_Xr[0];
      y_r2=Array_Yr[0];
      Dice_Num();
       Display_Dice();
      }
     }
      if(dice==6)
      {
       if((mouse_x>=705 && mouse_x<=735) && (mouse_y>=535 && mouse_y<=565)) 
     {
      x_r3=Array_Xr[0];
      y_r3=Array_Yr[0];
      Dice_Num();
      Display_Dice();
      } 
     }
     if(dice==6)
     {
      if((mouse_x>=705 && mouse_x<=735) && (mouse_y>=635 && mouse_y<=665)) 
     {
      x_r1=Array_Xr[0];
      y_r1=Array_Yr[0];
       Dice_Num();
       Display_Dice();
     }   
   } 
   
   
    // Movement for Token 4.
     if(dice>=1 && dice<=6)
     {
      if(x_r4!=850 && y_r4!=550)
      {
      if((mouse_x>=x_r4-15 && mouse_x<=x_r4+15) && (mouse_y>=y_r4-15 && mouse_y<=y_r4+15))
        {
         if(count==0)
         {
         if(red_Kill==0)
         {
          if(r_index1+dice<52)
         {
          
         x_r4=Array_Xr[r_index1+dice];
         r_index1=r_index1+dice;
      
        y_r4=Array_Yr[r_index2+dice]; 
        r_index2=r_index2+dice;
       }
      } 
       if(red_Kill!=0)
       {
       x_r4=Array_Xr[r_index1+dice];
         r_index1=r_index1+dice;
      
        y_r4=Array_Yr[r_index2+dice]; 
        r_index2=r_index2+dice;
       }
         score_Red=score_Red+dice;
         Red=score_Red;
        if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
       } 
      }
         // Movemnet for Token 2
       if(x_r2!=850 && y_r2!=650)
       {   
      if((mouse_x>=x_r2-15 && mouse_x<=x_r2+15) && (mouse_y>=y_r2-15 && mouse_y<=y_r2+15))
        {
         if(count==0)
         {
           if(red_Kill==0)
         {
          if(r_index3+dice<52)
         {
          
         x_r2=Array_Xr[r_index3+dice];
         r_index3=r_index3+dice;
      
        y_r2=Array_Yr[r_index4+dice]; 
        r_index4=r_index4+dice;
       }
      } 
         if(red_Kill!=0)
         { 
         x_r2=Array_Xr[r_index3+dice];
         r_index3=r_index3+dice;
      
        y_r2=Array_Yr[r_index4+dice]; 
        r_index4=r_index4+dice;
       } 
         score_Red=score_Red+dice;
         Red=score_Red;
       if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
       } 
       }
        // Movemnet for Token 1
       
        if(x_r1!=720 && y_r1!=650)
       { 
       if((mouse_x>=x_r1-15 && mouse_x<=x_r1+15) && (mouse_y>=y_r1-15 && mouse_y<=y_r1+15))
        {
        if(count==0)
        {
          if(red_Kill==0)
         {
          if(r_index5+dice<52)
         {
          
         x_r1=Array_Xr[r_index5+dice];
         r_index5=r_index5+dice;
      
        y_r1=Array_Yr[r_index6+dice]; 
        r_index6=r_index6+dice;
       }
      } 
       if(red_Kill!=0)
       {
         x_r1=Array_Xr[r_index5+dice];
         r_index5=r_index5+dice;
      
        y_r1=Array_Yr[r_index6+dice]; 
        r_index6=r_index6+dice;
       } 
         score_Red=score_Red+dice;
         Red=score_Red;
         if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
       } 
      }
       
        // Movemnet for Token 3
        
       if(x_r3!=720 && y_r3!=550)
      {   
      if((mouse_x>=x_r3-15 && mouse_x<=x_r3+15) && (mouse_y>=y_r3-15 && mouse_y<=y_r3+15))
        {
        if(count==0)
        {
         
        if(red_Kill==0)
         {
          if(r_index7+dice<52)
         {
          
         x_r3=Array_Xr[r_index7+dice];
         r_index7=r_index7+dice;
      
        y_r3=Array_Yr[r_index8+dice]; 
        r_index8=r_index8+dice;
       }
      } 
        if(red_Kill!=0)
        {  
         x_r3=Array_Xr[r_index7+dice];
         r_index7=r_index7+dice;
      
        y_r3=Array_Yr[r_index8+dice]; 
        r_index8=r_index8+dice;
       }
         score_Red=score_Red+dice;
         Red=score_Red;
         if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
       } 
       }
 } 
 Kill_Red();
 
 if(count_r==0)
  {
   if(r_index1>=53)
    {
     score_Red=score_Red+15;
     count_r++;
    } 
   }
  if(count_r==1)
   {
    if(r_index3>=53)
    {
       score_Red=score_Red+15;
     count_r++;
    }
   }
   
   
    if(count_r==2)
  {
   if(r_index5>=53)
    {
     score_Red=score_Red+15;
     count_r++;
    } 
   }
  if(count_r==3)
   {
    if(r_index7>=53)
    {
       score_Red=score_Red+15;
     count_r++;
    }
   } 
   
}

 //------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
  void Player4() // MOVEMNET OF Blue COLOUR
  
  {
    DrawString( 400, 800, "Blue  Turn", colors[MISTY_ROSE]);
    blue=Num2Str(Blue);
     DrawString( 50, 800, "Score= " ,colors[MISTY_ROSE]);
    DrawString( 130, 800, blue ,colors[MISTY_ROSE]);
     int count=0;
   if(dice==6)

   {
    if((mouse_x>=835 && mouse_x<=865) && (mouse_y>=80 && mouse_y<=120))
     {
      
       x_b4=Array_Xb[0];
       y_b4=Array_Yb[0];
       Dice_Num();
       Display_Dice();     
      }
     }
    if(dice==6)
   {    
     if((mouse_x>=835 && mouse_x<=865) && (mouse_y>=180 && mouse_y<=220)) 
     {
      x_b2=Array_Xb[0];
      y_b2=Array_Yb[0];
      Dice_Num();
       Display_Dice();
      }
     }
      if(dice==6)
      {
       if((mouse_x>=705 && mouse_x<=735) && (mouse_y>=80 && mouse_y<=120)) 
     {
      x_b3=Array_Xb[0];
      y_b3=Array_Yb[0];
      Dice_Num();
       Display_Dice();
      } 
     }
     if(dice==6)
     {
      if((mouse_x>=705 && mouse_x<=735) && (mouse_y>=180 && mouse_y<=220)) 
     {
      x_b1=Array_Xb[0];
      y_b1=Array_Yb[0];
       Dice_Num();
       Display_Dice();
     }   
   } 
   
    // Movement for Token 4.
     if(dice>=1 && dice<=6)
     {
      if(x_b4!=850 && y_b4!=100)
      {
      if((mouse_x>=x_b4-15 && mouse_x<=x_b4+15) && (mouse_y>=y_b4-15 && mouse_y<=y_b4+15))
        {
         if(count==0)
         {
          if(blue_Kill==0)
          {
            if(b_index1+dice<52)
           { 
         	x_b4=Array_Xb[b_index1+dice];
         	b_index1=b_index1+dice;
      
        y_b4=Array_Yb[b_index2+dice]; 
        b_index2=b_index2+dice;
       }
      } 
       if(blue_Kill!=0)
       {
        	x_b4=Array_Xb[b_index1+dice];
         	b_index1=b_index1+dice;
      
        y_b4=Array_Yb[b_index2+dice]; 
        b_index2=b_index2+dice;
      }
       
         score_Blue=score_Blue+dice;
         Blue=score_Blue;
        if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
       }
        }
       }
         // Movemnet for Token 2
       if(x_b2!=850 && y_b2!=200)
       {   
      if((mouse_x>=x_b2-15 && mouse_x<=x_b2+15) && (mouse_y>=y_b2-15 && mouse_y<=y_b2+15))
        {
         if(count==0)
         {
          if(blue_Kill==0)
          {
            if(b_index3+dice<52)
           { 
         	x_b2=Array_Xb[b_index3+dice];
         	b_index3=b_index3+dice;
      
        y_b2=Array_Yb[b_index4+dice]; 
        b_index4=b_index4+dice;
       }
      } 
       if(blue_Kill!=0)
       {
         x_b2=Array_Xb[b_index3+dice];
         b_index3=b_index3+dice;
      
        y_b2=Array_Yb[b_index4+dice]; 
        b_index4=b_index4+dice;
       }
         score_Blue=score_Blue+dice;
         Blue=score_Blue;
    		 if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
        }
       }
        // Movemnet for Token 1
       
        if(x_b1!=720 && y_b1!=200)
       { 
       if((mouse_x>=x_b1-10 && mouse_x<=x_b1+10) && (mouse_y>=y_b1-10 && mouse_y<=y_b1+10))
        {
         if(count==0)
         {
          if(blue_Kill==0)
          {
            if(b_index5+dice<52)
           { 
         	x_b1=Array_Xb[b_index5+dice];
         	b_index5=b_index5+dice;
      
        y_b1=Array_Yb[b_index6+dice]; 
        b_index6=b_index6+dice;
       }
      } 
       if(blue_Kill!=0)
        {
         x_b1=Array_Xb[b_index5+dice];
         b_index5=b_index5+dice;
      
        y_b1=Array_Yb[b_index6+dice]; 
        b_index6=b_index6+dice;
       }
         score_Blue=score_Blue+dice;
         Blue=score_Blue;
         if(dice<=6)
       {
        dice=0;
          if(dice<6)
        { count++;}
       }
        }
        }
       }
       
        // Movemnet for Token 3
        
       if(x_b3!=720 && y_b3!=100)
      {   
      if((mouse_x>=x_b3-10 && mouse_x<=x_b3+10) && (mouse_y>=y_b3-10 && mouse_y<=y_b3+10))
        {
         if(count==0)
         {
          if(blue_Kill==0)
          {
            if(b_index7+dice<52)
           { 
         	x_b3=Array_Xb[b_index7+dice];
         	b_index7=b_index7+dice;
      
        y_b3=Array_Yb[b_index8+dice]; 
        b_index8=b_index8+dice;
       }
      } 
       if(blue_Kill!=0)
       {
         x_b3=Array_Xb[b_index7+dice];
         b_index7=b_index7+dice;
      
        y_b3=Array_Yb[b_index8+dice]; 
        b_index8=b_index8+dice;
      }  
         score_Blue=score_Blue+dice;
         Blue=score_Blue;
        if(dice<=6)
        {
         dice=0;
           if(dice<6)
        { count++;}
         }
        }
  }
  }
 }
 Kill_Blue();
 
   if(count_b==0)
  {
   if(b_index1>=53)
    {
     score_Blue=score_Blue+15;
     count_b++;
    } 
   }
  if(count_b==1)
   {
    if(b_index3>=53)
    {
       score_Blue=score_Blue+15;
     count_b++;
    }
   }
   
   
    if(count_b==2)
  {
   if(b_index5>=53)
    {
     score_Blue=score_Blue+15;
     count_b++;
    } 
   }
  if(count_b==3)
   {
    if(b_index7>=53)
    {
       score_Blue=score_Blue+15;
     count_b++;
    }
   } 
}


 

 
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	
	Blue=score_Blue;
	Yellow=score_Yellow;
	Green=score_Green;
	Red=score_Red;
	
	if(menu==0)
	{
	  DrawString( 50, 600, "Press 1 for 2 players. Colours (Red & Yellow)", colors[MISTY_ROSE]);
	  DrawString( 50, 550, "Press 2 for 2 players. Colours(Green & Yellow)", colors[MISTY_ROSE]);
	  DrawString( 50, 500, "Press 3 for 3 players.", colors[MISTY_ROSE]);
	  DrawString( 50, 450, "Press 4 for 4 players.", colors[MISTY_ROSE]);
	
	 }
	 
 if(menu>0)
  {
	//Fire Gun
	DrawSquare( 190 , 00 ,300,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 230 , 40 ,225,colors[MISTY_ROSE]);
	
	
	DrawSquare( 190 , 450 ,300,colors[GREEN]);
	DrawSquare( 230 , 490 ,225,colors[MISTY_ROSE]);
	
	
	DrawSquare( 640 , 00 ,300,colors[MIDNIGHT_BLUE]);
	DrawSquare( 680 , 40 ,225,colors[MISTY_ROSE]);
	
	
	DrawSquare( 640 , 450 ,300,colors[RED]);
	DrawSquare( 680 , 490 ,225,colors[MISTY_ROSE]);
	
	
	//Mushroom
	DrawSquare( 490 , 50 ,50,colors[DARK_GOLDEN_ROD]);      // Boxes around Yellow side.
	DrawSquare( 490 , 100 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 150 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 200 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 250 ,50,colors[DIM_GRAY]);
	DrawSquare( 440 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 390 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 340 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 290 , 300 ,50,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 240 , 300 ,50,colors[DIM_GRAY]);
	
	
	DrawSquare( 190 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 190 , 350 ,50,colors[DIM_GRAY]);
	DrawSquare( 190 , 400 ,50,colors[DIM_GRAY]);
	
	
	DrawSquare( 240 , 400 ,50,colors[GREEN]);   // Boxes around Green Side
	DrawSquare( 290 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 340 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 390 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 440 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 450 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 500 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 550 ,50,colors[DIM_GRAY]);
	DrawSquare( 490 , 600 ,50,colors[GREEN]);
	DrawSquare( 490 , 650 ,50,colors[DIM_GRAY]);
	
	DrawSquare( 490 , 700 ,50,colors[DIM_GRAY]);
	DrawSquare( 540 , 700 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 700 ,50,colors[DIM_GRAY]);
	
	
	
	DrawSquare( 640 , 300 ,50,colors[DIM_GRAY]); // Boxes around Blue side
	DrawSquare( 690 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 740 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 790 , 300 ,50,colors[DIM_GRAY]);
	DrawSquare( 840 , 300 ,50,colors[MIDNIGHT_BLUE]);
	DrawSquare( 590 , 50 ,50,colors[DIM_GRAY]); 
	DrawSquare( 590 , 100 ,50,colors[MIDNIGHT_BLUE]);
	DrawSquare( 590 , 150 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 200 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 250 ,50,colors[DIM_GRAY]);
	
	DrawSquare( 890 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 890 , 350 ,50,colors[DIM_GRAY]);
	DrawSquare( 890 , 300 ,50,colors[DIM_GRAY]);
	
	
	DrawSquare( 590 , 450 ,50,colors[DIM_GRAY]); // Boxes around the Red side
	DrawSquare( 590 , 500 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 550 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 600 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 650 ,50,colors[RED]);
     DrawSquare( 640 , 400 ,50,colors[DIM_GRAY]);
     DrawSquare( 690 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 740 , 400 ,50,colors[DIM_GRAY]);
	DrawSquare( 790 , 400 ,50,colors[RED]);
	DrawSquare( 840 , 400 ,50,colors[DIM_GRAY]);
	
	DrawSquare( 490 , 0 ,50,colors[DIM_GRAY]);
	DrawSquare( 540 , 0 ,50,colors[DIM_GRAY]);
	DrawSquare( 590 , 0 ,50,colors[DIM_GRAY]);
	
	
	
	DrawSquare( 540 , 50 ,50,colors[DARK_GOLDEN_ROD]); // Home for Yellow
	DrawSquare( 540 , 100 ,50,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 540 , 150 ,50,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 540 , 200 ,50,colors[DARK_GOLDEN_ROD]);
	DrawSquare( 540 , 250 ,50,colors[DARK_GOLDEN_ROD]);
	
	
	DrawSquare( 540 , 650 ,50,colors[RED]); // Home for Red
	DrawSquare( 540 , 600 ,50,colors[RED]);
	DrawSquare( 540 , 550 ,50,colors[RED]);
	DrawSquare( 540 , 500 ,50,colors[RED]);
	DrawSquare( 540 , 450 ,50,colors[RED]);
	
	DrawSquare( 240 , 350 ,50,colors[GREEN]); // Home for Green	
	DrawSquare( 290 , 350 ,50,colors[GREEN]);
	DrawSquare( 340 , 350 ,50,colors[GREEN]);
	DrawSquare( 390 , 350 ,50,colors[GREEN]);
	DrawSquare( 440 , 350 ,50,colors[GREEN]);
	
	DrawSquare( 840 , 350 ,50,colors[MIDNIGHT_BLUE]); // Home for BLUE
	DrawSquare( 790 , 350 ,50,colors[MIDNIGHT_BLUE]);
	DrawSquare( 740 , 350 ,50,colors[MIDNIGHT_BLUE]);
	DrawSquare( 690 , 350 ,50,colors[MIDNIGHT_BLUE]);
	DrawSquare( 640 , 350 ,50,colors[MIDNIGHT_BLUE]);
	
	
	//Display Score
	
	//Spider
	DrawTriangle( 565, 375, 490, 300 , 640 , 300, colors[DARK_GOLDEN_ROD] ); 
	DrawTriangle( 565, 375, 490, 450 , 490 , 300, colors[GREEN] );
	DrawTriangle( 565, 375, 490, 450 , 640 , 450, colors[RED] );
	DrawTriangle( 565, 375, 640, 450 , 640 , 300, colors[MIDNIGHT_BLUE] );
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)

	DrawRoundRect( 50.0, 50.0, 75.0, 75.0,colors[DIM_GRAY], 25.0);
	
	
	start();
 Display_Dice();
 
 }
        if(players==4) // Turn for 4 players
        {
          if(player_Turn==0)
			  { 
			    Player1();
			  }
			 
			 if(player_Turn==1)
			  {
			    Player2();
			  }
			 if(player_Turn==2)
			  { 
			    Player3();
			  }
			 
			 if(player_Turn==3)
			  {
			    Player4();
			  }
               }
               
            if(players==3) // Turn for 3 players
             {
             
             if(player_Turn==0)
			  { 
			    Player1();
			  }
			 
			 if(player_Turn==1)
			  {
			    Player2();
			  }
			 if(player_Turn==2)
			  { 
			    Player3();
			  }
             }   
               
               
                  
            if(players==2) // Turn for 2 players (Yellow & RED)
             {
             
             if(player_Turn==0)
			  { 
			    Player1(); 
			  }
			 
			 if(player_Turn==1)
			  {
			    Player3();
			  }
             }   
             
                
            if(players==22) // Turn for 2 players (Green & Blue)
             {
             
             if(player_Turn==0)
			  { 
			    Player2();
			  }
			 
			 if(player_Turn==1)
			  {
			    Player4();
			  }
			}

	glutSwapBuffers(); // do not modify this line..

}

 
  

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32) //Space key for changing the turn between players
			{
			 
			while(true && players==4)
		 {	
			if(player_Turn==0)
			  { 
			    player_Turn=1;
			    dice=0;
			    break;
			  }
			 
			 if(player_Turn==1)
			  {
			    player_Turn=2;
			    dice=0;
			    break;
			  }
			 if(player_Turn==2)
			  { 
			    player_Turn=3;
			    dice=0;
			    break;
			  }
			 
			 if(player_Turn==3)
			  {
			    player_Turn=0;
			    dice=0;
			    break;
			  }
			} 
             
             
       ////////////////////////////////////////////////////////////////////////////////////
       ///////////////////////////////////////////////////////////////////////////////   
       
       // 2 PLAYERS (Yellow & RED)   
             while(true && players==2)
		 {	
			if(player_Turn==0)
			  { 
			    player_Turn=1;
			    dice=0;
			    break;
			  }
			 
			 if(player_Turn==1)
			  {
			    player_Turn=0;
			    dice=0;
			    break;
			  }
			}
			
			
	/////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////
	 
	 // 2 Players (Green & Blue)	
			
			
			while(true && players==22)
		 {	
			if(player_Turn==0)
			  { 
			    player_Turn=1;
			    dice=0;
			    break;
			  }
			 
			 if(player_Turn==1)
			  {
			    player_Turn=0;
			    dice=0;
			    break;
			  }
			
			}
			
			
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	
	// 3 Players 		
			
			while(true && players==3)
		 {	
			if(player_Turn==0)
			  { 
			    player_Turn=1;
			    dice=0;
			    break;
			  }
			 
			 if(player_Turn==1)
			  {
			    player_Turn=2;
			    dice=0;
			    break;
			  }
			 if(player_Turn==2)
			  { 
			    player_Turn=0;
			    dice=0;
			    break;
			  }
			} 
			
		}	 
       ///////////////////////////////////////////////////////////////////////////////////
       ///////////////////////////////////////////////////////////////////////////////////
                                 //INPUT FOR MENU
        if(key== '1')
        { 
         while(option==true)
        {
         cout<<"One pressed"<<endl;
         players=2;
         menu++;
         option=false;
         }
        } 
         
       if(key == '2')
       {
       while(option==true)
        {
        cout<<"Two pressed"<<endl;
        players=22;
        menu++;
        option=false;
        }
       } 
       
       
       if(key=='3')
       {
       while(option==true)
        {
        players=3;
        menu++;
        option=false;
       }
      } 
       if(key=='4')
       {
        while(option==true)
        {
        players=4;
       menu++; 
       option=false;
      }
     } 
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	//glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y)
 {

	 y=840-y; 
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		/*cout << GLUT_DOWN << " " << GLUT_UP << endl;*/
		if(state==0)
		{
		     mouse_x=x;
		     mouse_y=y;	
		     if((x>=45 && x<=130) && (y>=45 && y<=130))
		    { 
		     Dice_Num();
		    }
		}
	} 
	//else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
