#pragma once
#define PI 3.141592						//원주율을 소수점 6자리까지 근사값으로 정의

typedef struct mat3 {					//float 자료형을 가지는 2차원 행렬 구조체 선언
	float mat[3][3];

	mat3(float a[3][3]) {		//생성자에서 행렬의 value 초기화
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) this->mat[i][j] = a[i][j];
		}
	}


	mat3 operator*(mat3& ref) {			//연산자 오버로딩으로 3x3 행렬끼리의 곱 구현
		mat3 resultMat(new float[3][3]{ {1, 0, 0}, {0,1,0}, {0,0,1} });		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 3; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

};

typedef struct vec3 {					//float 자료형을 가지는 2차원좌표 + 동차좌표 구조체 선언
	float vec[3];

	vec3(float a[3]) {					//생성자에서 Vector의 value 초기화
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec3 operator*(mat3& ref) {			//연산자 오버로딩으로 3x1 Vector와 3x3 행렬곱 구현
		vec3 resultVec(new float[3] { 0, 0, 0 });	//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//행렬 곱의 결과 값 반환
	}

};