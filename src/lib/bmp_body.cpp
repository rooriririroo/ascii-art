/*
-----------------------
파일명 : bmp_body.cpp
라이선스 : MIT
작성 : jgcmarins
수정 : rooriririroo
수정일 : 2018.04.29
-----------------------
bmp파일을 불러와 가로값과 세로값 저장
*/


#include "../headers/bmp_body.h"

bmp_body *new_bmp_body(int width, int height, int m, int n) { // 구조체 bmp_body로 부터 함수 *new_bmp_body 정의
  bmp_body *bb = (bmp_body *) malloc(sizeof(bmp_body)); // *bb에 구조체 bmp_body의 크기만큼 동적할당받아 저장
  bb->body = new int * [height]; // bb->body에 세로값을 동적할당하여 저장
  for(int i = 0 ; i < height ; i++) bb->body[i] = new int[width]; // 각 세로값마다 가로값을 동적할당하여 저장
  bb->width = width; 
  bb->height = height; 
  bb->m = m;
  bb->n = n;
  return bb;
}

void delete_bmp_body(bmp_body *bb) {
  if(bb->body != NULL) {
    for(int i = 0 ; i < bb->height ; i++) 
      if(bb->body[i] != NULL) delete [] bb->body[i]; // new로 동적할당 받은 bb->body[i]의 메모리 해제
    delete [] bb->body; // new로 동적할당 받은 bb->body의 메모리 해제
  }
  if(bb != NULL) free(bb); // malloc으로 동적할당 받은 bb의 메모리 해제
}
