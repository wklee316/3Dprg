#pragma once
#define PI 3.141592						//원주율을 소수점 6자리까지 근사값으로 정의

typedef struct mat3 {					//float 자료형을 가지는 2차원 행렬 구조체 선언
	float mat[3][3];

	mat3(float a[3][3]) {		//생성자에 인자값이 있을시 입력받은 값으로 행렬 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) this->mat[i][j] = a[i][j];
		}
	}

	mat3() {		//생성자에 인자값이 없을시 단위행렬로 행렬 선언
		this->identity();
	}


	mat3 operator*(mat3& ref) {			//연산자 오버로딩으로 3x3 행렬끼리의 곱 구현
		mat3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 3; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat3 operator*(float ref) {			//연산자 오버로딩으로 3x3 행렬과 상수의 곱 구현
		mat3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] * ref;
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat3 operator/(float ref) {			//연산자 오버로딩으로 3x3 행렬과 상수의 나눗셈 구현
		mat3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] / ref;
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat3 operator+(mat3& ref) {			//연산자 오버로딩으로 3x3 행렬간 덧셈 구현
		mat3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] + ref.mat[i][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat3 operator-(mat3& ref) {			//연산자 오버로딩으로 3x3 행렬간 뺄셈  구현
		mat3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] - ref.mat[i][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}



	mat3 identity() {						//단위 행렬로 초기화하는 함수
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)	this->mat[i][j] = (i == j) ? 1 : 0;
		}
		return *this;
	}


	mat3 transpose() {					//행렬을 전치시키는 함수
		float tmp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0+i; j < 3; j++) {
				tmp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];		//2차원 배열의 인덱스 값 i,j 값을 서로 바꿈으로 행렬을 전치시킴
				this->mat[j][i] = tmp;
			}
		}
		return *this;
	}

};

typedef struct mat4 {									//float 자료형을 가지는 3차원 행렬 구조체 선언
	float mat[4][4];
	mat4(float a[4][4]) {								//생성자에 인자값이 있을시 입력받은 값으로 행렬 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) this->mat[i][j] = a[i][j];
		}
	}

	mat4() {											//생성자에 인자값이 없을시 단위행렬로 행렬 선언
		this->identity();
	}

	mat4 operator*(mat4& ref) {			//연산자 오버로딩으로 4x4 행렬끼리의 곱 구현
		mat4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 4; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat4 operator*(float ref) {			//연산자 오버로딩으로 4x4 행렬과 상수의 곱 구현
		mat4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] * ref;
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat4 operator/(float ref) {			//연산자 오버로딩으로 4x4 행렬과 상수의 나눗셈 구현
		mat4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] / ref;
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat4 operator+(mat4& ref) {			//연산자 오버로딩으로 3x3 행렬간 덧셈 구현
		mat4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] + ref.mat[i][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat4 operator-(mat4& ref) {			//연산자 오버로딩으로 4x4 행렬간 뺄셈  구현
		mat4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] - ref.mat[i][j];
			}
		}

		return resultMat;					//행렬 곱의 결과 값 반환
	}

	mat4 identity() {						//단위 행렬로 초기화하는 함수
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)	this->mat[i][j] = (i == j) ? 1 : 0;
		}
		return *this;
	}

	mat4 transpose() {					//행렬을 전치시키는 함수
		float tmp;
		for (int i = 0; i < 4; i++) {
			for (int j = i; j < 4; j++) {
				tmp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];		//2차원 배열의 인덱스 값 i,j 값을 서로 바꿈으로 행렬을 전치시킴
				this->mat[j][i] = tmp;
			}
		}
		return *this;
	}

};

typedef struct vec1x3 {				//float 자료형을 가지는 2차원좌표 + 동차좌표 1x3 형태의 벡터 구조체 선언
	float vec[3];

	vec1x3(float a[3]) {
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec1x3() {
		for (int i = 0; i < 3; i++) this->vec[i] = 0;
	}

	friend vec1x3 operator*(mat3& ref, const vec1x3& ref2);			//반환형 문제 때문에 1x3 벡터가 좌항에 있는 3x3 행렬과의 곱은 friend를 사용하여 일반함수로 선언한다.

	vec1x3 operator*(float ref) {			//1x3 벡터의 상수 곱셈 연산자 오버로딩으로 구현
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}


	vec1x3 operator/(float ref) {			//1x3 벡터의 상수 나눗셈 연산자 오버로딩으로 구현
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec1x3 operator+(vec1x3& ref) {			//연산자 오버로딩으로 3x1 벡터간 덧셈 구현
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec1x3 operator-(vec1x3& ref) {			//연산자 오버로딩으로 3x1 벡터간 뺄셈 구현
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}

};

vec1x3 operator*(mat3& ref, const vec1x3& ref2) {			//일반함수 연산자로 선언한 함수를 재정의 하여 return 형이 vec1x3이고 vec1x3이 우항에 있도록 연산자 오버로딩
	vec1x3 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
	for (int i = 0; i < 3; i++) {
		resultMat.vec[i] = 0;
		for (int j = 0; j < 3; j++) {
			resultMat.vec[i] += ref.mat[i][j] * ref2.vec[j];
		}
	}

	return resultMat;					//행렬 곱의 결과 값 반환
}

typedef struct vec3 {					//float 자료형을 가지는 2차원좌표 + 동차좌표 3x1 형태의 벡터 구조체 선언
	float vec[3];

	vec3(float a[3]) {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec3() {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 3; i++) this->vec[i] = 0;
	}

	vec3 operator*(mat3& ref) {			//연산자 오버로딩으로 3x1 벡터와 3x3 행렬곱 구현
		vec3 resultVec(new float[3] { 0, 0, 0 });	//행렬 곱의 결과값을 저장하는 변수 선언
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//행렬 곱의 결과 값 반환
	}
	

	vec3 operator*(float ref) {			//3x1 벡터의 상수 곱셈 연산자 오버로딩으로 구현
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec3 operator/(float ref) {			//3x1 벡터의 상수 나눗셈 연산자 오버로딩으로 구현
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec3 operator+(vec3& ref) {			//연산자 오버로딩으로 3x1 벡터간 덧셈 구현
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec3 operator-(vec3& ref) {			//연산자 오버로딩으로 3x1 벡터간 뺄셈 구현
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

typedef struct vec1x4 {					//float 자료형을 가지는 2차원좌표 + 동차좌표 1x4 형태의 벡터 구조체 선언
	float vec[4];

	vec1x4(float a[4]) {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 4; i++) this->vec[i] = a[i];
	}

	vec1x4() {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 4; i++) this->vec[i] = 0;
	}

	friend vec1x4 operator*(mat4& ref, const vec1x4& ref2);					//3x3행렬과 1x3벡터의 곱 연산과 같은 이유로 일반함수 선언


	vec1x4 operator*(float ref) {			//4x1 벡터의 상수 곱셈 연산자 오버로딩으로 구현
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec1x4 operator/(float ref) {			//4x1 벡터의 상수 나눗셈 연산자 오버로딩으로 구현
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec1x4 operator+(vec1x4& ref) {			//연산자 오버로딩으로 4x1 벡터간 덧셈 구현
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec1x4 operator-(vec1x4& ref) {			//연산자 오버로딩으로 4x1 벡터간 뺄셈 구현
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

vec1x4 operator*(mat4& ref, const vec1x4& ref2) {			//일반함수 연산자로 선언한 함수를 재정의 하여 return 형이 vec1x4이고 vec1x4이 우항에 있도록 연산자 오버로딩
	vec1x4 resultMat;		//행렬 곱의 결과값을 저장하는 변수 선언
	for (int i = 0; i < 4; i++) {
		resultMat.vec[i] = 0;
		for (int j = 0; j < 4; j++) {
			resultMat.vec[i] += ref.mat[i][j] * ref2.vec[j];
		}
	}

	return resultMat;					//행렬 곱의 결과 값 반환
}

typedef struct vec4 {					//float 자료형을 가지는 2차원좌표 + 동차좌표 4x1 형태의 벡터 구조체 선언
	float vec[4];

	vec4(float a[4]) {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 4; i++) this->vec[i] = a[i];
	}

	vec4() {					//생성자에서 벡터의 value 초기화
		for (int i = 0; i < 4; i++) this->vec[i] = 0;
	}

	vec4 operator*(mat4& ref) {			//연산자 오버로딩으로 4x1 벡터와 4x4 행렬곱 구현
		vec4 resultVec(new float[4] { 0, 0, 0, 0});	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//행렬 곱의 결과 값 반환
	}

	vec4 operator*(float ref) {			//4x1 벡터의 상수 곱셈 연산자 오버로딩으로 구현
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec4 operator/(float ref) {			//4x1 벡터의 상수 나눗셈 연산자 오버로딩으로 구현
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec4 operator+(vec4& ref) {			//연산자 오버로딩으로 4x1 벡터간 덧셈 구현
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec4 operator-(vec4& ref) {			//연산자 오버로딩으로 4x1 벡터간 뺄셈 구현
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

vec1x3 transposeVec(vec3 v) {						//3x1벡터에서 1x3벡터로 전치하는 함수
	vec1x3 result;
	for (int i = 0; i < 3; i++) result.vec[i] = v.vec[i];
	return result;
}

vec3 transposeVec(vec1x3 v) {							//1x3벡터에서 3x1벡터로 전치하는 함수
	vec3 result;
	for (int i = 0; i < 3; i++) result.vec[i] = v.vec[i];
	return result;
}

vec1x4 transposeVec(vec4 v) {							//4x1벡터에서 1x4벡터로 전치하는 함수
	vec1x4 result;
	for (int i = 0; i < 4; i++) result.vec[i] = v.vec[i];
	return result;
}

vec4 transposeVec(vec1x4 v) {							//1x4벡터에서 4x1벡터로 전치하는 함수
	vec4 result;
	for (int i = 0; i < 4; i++) result.vec[i] = v.vec[i];
	return result;
}