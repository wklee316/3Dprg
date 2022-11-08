#include <iostream>				//기본 입출력 라이브러리
#include <math.h>				//회전 행렬에서 사용할 삼각함수를 위한 라이브러리
#include "MuSoenMath.h"			//자료구조를 구현한 헤더파일


int main() {


	mat3 mt1(new float[3][3]{
		{1,0,0},
		{0,1,0},
		{2,3,1}
		});

	mat3 mt2(new float[3][3]{
		{3,0,0},
		{0,3,0},
		{2,0,1}
		});

	mat3 result;
	result = mt1 * mt2;
	/*
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << result.mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	mat4 mt4_1(new float[4][4]{
		{4,0,0,0},
		{0,5,0,0},
		{0,0,6,0},
		{0,0,0,1}
		});

	mat4 mt4_2(new float[4][4]{
		{1,0,0,7},
		{0,1,0,8},
		{0,0,1,12},
		{0,0,0,1}
		});

	mat4 result2;
	mt4_2.transpose();
	result2 = mt4_1 * mt4_2;
	/*
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << result2.mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	mat3 translate(new float[3][3]{
		{1,0,0},
		{0,1,0},
		{5,6,1}
		});

	vec3 p(new float[3] {1, 5, 1});

	vec3 re;
	re = p * translate;
	/*
	for (int i = 0; i < 3; i++) {
		std::cout << re.vec[i] << " ";
	}
	*/

	vec4 v(new float[4] {1, 3, 5, 1});
	mat4 translate4(new float[4][4]{
		{1,0,0,5},
		{0,1,0,2},
		{0,0,1,3},
		{0,0,0,1}
		});


	vec1x4 resul;
	resul = translate4 * transposeVec(v);
	/*
	for (int i = 0; i < 4; i++) {
		std::cout << resul.vec[i] << std::endl;
	}
	*/

	vec4 v4(new float[4] {1, 2, 3, 4});
	vec4 v5(new float[4] {3, 3, 3, 3});

	mat3 matirx1(new float[3][3]{
		{1,2,3},
		{2,2,2},
		{0,1,0}
		});

	mat3 matirx2(new float[3][3]{
	{1,2,3},
	{1,2,3},
	{1,2,3}
		});

	/*
	for (int i = 0; i < 4; i++) {
		std::cout << (v4 + v5).vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << (matirx1 + matirx2).mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	mat4 matrix(new float[4][4]{
		{4,0,0,0},
		{0,4,0,0},
		{0,0,4,0},
		{0,0,0,1}
		});

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << (matrix *3).mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl; std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << (matrix / 4).mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}