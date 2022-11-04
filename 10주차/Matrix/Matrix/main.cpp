#include <iostream>				//기본 입출력 라이브러리
#include <math.h>				//회전 행렬에서 사용할 삼각함수를 위한 라이브러리
#include "MuSoenMath.h"			//자료구조를 구현한 헤더파일


int main() {
	//3,5 만큼 이동하는 이동행렬, 행렬곱의 형식이 Vector가 가장 왼쪽 항에 있기에 기존 이동행렬을 전치하여 선언함
	mat3 Translate(new float[3][3]{
		{1, 0, 0},
		{0 ,1 ,0},
		{3 ,5 ,1} });
	//30도 만큼 회전하는 회전행렬, 30도는 Radian 값으로 원주율/6이기에 회전행렬에 해당하는 값을 넣음
	mat3 Rotate(new float[3][3]
		{ {(float)cos(PI/6), -(float)sin(PI / 6), 0},
		{(float)sin(PI / 6), (float)cos(PI / 6), 0},
		{0, 0, 1}});
	//2배 확대하는 스케일행렬
	mat3 Scale(new float[3][3]{
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 1} });

	vec3 v(new float[3] {4, 2, 1});		//시작 좌표를 4,2로 선언
	vec3 p(new float[3] {0, 0, 0});		//결과 좌표값 선언 및 초기화

	p = v * Translate * Rotate * Scale;	//3,5 이동 | 30도 회전 | 2배 확대


	for (int i = 0; i < 3; i++) {		//결과 좌표값 출력
		std::cout << p.vec[i];
		if (i < 2) std::cout << " ";
	}

	return 0;
}