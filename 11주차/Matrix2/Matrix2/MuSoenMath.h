#pragma once
#define PI 3.141592						//�������� �Ҽ��� 6�ڸ����� �ٻ簪���� ����

typedef struct mat3 {					//float �ڷ����� ������ 2���� ��� ����ü ����
	float mat[3][3];

	mat3(float a[3][3]) {		//�����ڿ� ���ڰ��� ������ �Է¹��� ������ ��� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) this->mat[i][j] = a[i][j];
		}
	}

	mat3() {		//�����ڿ� ���ڰ��� ������ ������ķ� ��� ����
		this->identity();
	}


	mat3 operator*(mat3& ref) {			//������ �����ε����� 3x3 ��ĳ����� �� ����
		mat3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 3; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat3 operator*(float ref) {			//������ �����ε����� 3x3 ��İ� ����� �� ����
		mat3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] * ref;
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat3 operator/(float ref) {			//������ �����ε����� 3x3 ��İ� ����� ������ ����
		mat3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] / ref;
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat3 operator+(mat3& ref) {			//������ �����ε����� 3x3 ��İ� ���� ����
		mat3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] + ref.mat[i][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat3 operator-(mat3& ref) {			//������ �����ε����� 3x3 ��İ� ����  ����
		mat3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = this->mat[i][j] - ref.mat[i][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}



	mat3 identity() {						//���� ��ķ� �ʱ�ȭ�ϴ� �Լ�
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)	this->mat[i][j] = (i == j) ? 1 : 0;
		}
		return *this;
	}


	mat3 transpose() {					//����� ��ġ��Ű�� �Լ�
		float tmp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0+i; j < 3; j++) {
				tmp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];		//2���� �迭�� �ε��� �� i,j ���� ���� �ٲ����� ����� ��ġ��Ŵ
				this->mat[j][i] = tmp;
			}
		}
		return *this;
	}

};

typedef struct mat4 {									//float �ڷ����� ������ 3���� ��� ����ü ����
	float mat[4][4];
	mat4(float a[4][4]) {								//�����ڿ� ���ڰ��� ������ �Է¹��� ������ ��� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) this->mat[i][j] = a[i][j];
		}
	}

	mat4() {											//�����ڿ� ���ڰ��� ������ ������ķ� ��� ����
		this->identity();
	}

	mat4 operator*(mat4& ref) {			//������ �����ε����� 4x4 ��ĳ����� �� ����
		mat4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 4; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat4 operator*(float ref) {			//������ �����ε����� 4x4 ��İ� ����� �� ����
		mat4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] * ref;
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat4 operator/(float ref) {			//������ �����ε����� 4x4 ��İ� ����� ������ ����
		mat4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] / ref;
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat4 operator+(mat4& ref) {			//������ �����ε����� 3x3 ��İ� ���� ����
		mat4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] + ref.mat[i][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat4 operator-(mat4& ref) {			//������ �����ε����� 4x4 ��İ� ����  ����
		mat4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultMat.mat[i][j] = this->mat[i][j] - ref.mat[i][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

	mat4 identity() {						//���� ��ķ� �ʱ�ȭ�ϴ� �Լ�
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)	this->mat[i][j] = (i == j) ? 1 : 0;
		}
		return *this;
	}

	mat4 transpose() {					//����� ��ġ��Ű�� �Լ�
		float tmp;
		for (int i = 0; i < 4; i++) {
			for (int j = i; j < 4; j++) {
				tmp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];		//2���� �迭�� �ε��� �� i,j ���� ���� �ٲ����� ����� ��ġ��Ŵ
				this->mat[j][i] = tmp;
			}
		}
		return *this;
	}

};

typedef struct vec1x3 {				//float �ڷ����� ������ 2������ǥ + ������ǥ 1x3 ������ ���� ����ü ����
	float vec[3];

	vec1x3(float a[3]) {
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec1x3() {
		for (int i = 0; i < 3; i++) this->vec[i] = 0;
	}

	friend vec1x3 operator*(mat3& ref, const vec1x3& ref2);			//��ȯ�� ���� ������ 1x3 ���Ͱ� ���׿� �ִ� 3x3 ��İ��� ���� friend�� ����Ͽ� �Ϲ��Լ��� �����Ѵ�.

	vec1x3 operator*(float ref) {			//1x3 ������ ��� ���� ������ �����ε����� ����
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}


	vec1x3 operator/(float ref) {			//1x3 ������ ��� ������ ������ �����ε����� ����
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec1x3 operator+(vec1x3& ref) {			//������ �����ε����� 3x1 ���Ͱ� ���� ����
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec1x3 operator-(vec1x3& ref) {			//������ �����ε����� 3x1 ���Ͱ� ���� ����
		vec1x3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}

};

vec1x3 operator*(mat3& ref, const vec1x3& ref2) {			//�Ϲ��Լ� �����ڷ� ������ �Լ��� ������ �Ͽ� return ���� vec1x3�̰� vec1x3�� ���׿� �ֵ��� ������ �����ε�
	vec1x3 resultMat;		//��� ���� ������� �����ϴ� ���� ����
	for (int i = 0; i < 3; i++) {
		resultMat.vec[i] = 0;
		for (int j = 0; j < 3; j++) {
			resultMat.vec[i] += ref.mat[i][j] * ref2.vec[j];
		}
	}

	return resultMat;					//��� ���� ��� �� ��ȯ
}

typedef struct vec3 {					//float �ڷ����� ������ 2������ǥ + ������ǥ 3x1 ������ ���� ����ü ����
	float vec[3];

	vec3(float a[3]) {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec3() {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 3; i++) this->vec[i] = 0;
	}

	vec3 operator*(mat3& ref) {			//������ �����ε����� 3x1 ���Ϳ� 3x3 ��İ� ����
		vec3 resultVec(new float[3] { 0, 0, 0 });	//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//��� ���� ��� �� ��ȯ
	}
	

	vec3 operator*(float ref) {			//3x1 ������ ��� ���� ������ �����ε����� ����
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec3 operator/(float ref) {			//3x1 ������ ��� ������ ������ �����ε����� ����
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec3 operator+(vec3& ref) {			//������ �����ε����� 3x1 ���Ͱ� ���� ����
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec3 operator-(vec3& ref) {			//������ �����ε����� 3x1 ���Ͱ� ���� ����
		vec3 resultVec;
		for (int i = 0; i < 3; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

typedef struct vec1x4 {					//float �ڷ����� ������ 2������ǥ + ������ǥ 1x4 ������ ���� ����ü ����
	float vec[4];

	vec1x4(float a[4]) {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 4; i++) this->vec[i] = a[i];
	}

	vec1x4() {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 4; i++) this->vec[i] = 0;
	}

	friend vec1x4 operator*(mat4& ref, const vec1x4& ref2);					//3x3��İ� 1x3������ �� ����� ���� ������ �Ϲ��Լ� ����


	vec1x4 operator*(float ref) {			//4x1 ������ ��� ���� ������ �����ε����� ����
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec1x4 operator/(float ref) {			//4x1 ������ ��� ������ ������ �����ε����� ����
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec1x4 operator+(vec1x4& ref) {			//������ �����ε����� 4x1 ���Ͱ� ���� ����
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec1x4 operator-(vec1x4& ref) {			//������ �����ε����� 4x1 ���Ͱ� ���� ����
		vec1x4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

vec1x4 operator*(mat4& ref, const vec1x4& ref2) {			//�Ϲ��Լ� �����ڷ� ������ �Լ��� ������ �Ͽ� return ���� vec1x4�̰� vec1x4�� ���׿� �ֵ��� ������ �����ε�
	vec1x4 resultMat;		//��� ���� ������� �����ϴ� ���� ����
	for (int i = 0; i < 4; i++) {
		resultMat.vec[i] = 0;
		for (int j = 0; j < 4; j++) {
			resultMat.vec[i] += ref.mat[i][j] * ref2.vec[j];
		}
	}

	return resultMat;					//��� ���� ��� �� ��ȯ
}

typedef struct vec4 {					//float �ڷ����� ������ 2������ǥ + ������ǥ 4x1 ������ ���� ����ü ����
	float vec[4];

	vec4(float a[4]) {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 4; i++) this->vec[i] = a[i];
	}

	vec4() {					//�����ڿ��� ������ value �ʱ�ȭ
		for (int i = 0; i < 4; i++) this->vec[i] = 0;
	}

	vec4 operator*(mat4& ref) {			//������ �����ε����� 4x1 ���Ϳ� 4x4 ��İ� ����
		vec4 resultVec(new float[4] { 0, 0, 0, 0});	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//��� ���� ��� �� ��ȯ
	}

	vec4 operator*(float ref) {			//4x1 ������ ��� ���� ������ �����ε����� ����
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] * ref;

		return resultVec;
	}

	vec4 operator/(float ref) {			//4x1 ������ ��� ������ ������ �����ε����� ����
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] / ref;

		return resultVec;
	}

	vec4 operator+(vec4& ref) {			//������ �����ε����� 4x1 ���Ͱ� ���� ����
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] + ref.vec[i];
		return resultVec;
	}

	vec4 operator-(vec4& ref) {			//������ �����ε����� 4x1 ���Ͱ� ���� ����
		vec4 resultVec;
		for (int i = 0; i < 4; i++) resultVec.vec[i] = this->vec[i] - ref.vec[i];
		return resultVec;
	}
};

vec1x3 transposeVec(vec3 v) {						//3x1���Ϳ��� 1x3���ͷ� ��ġ�ϴ� �Լ�
	vec1x3 result;
	for (int i = 0; i < 3; i++) result.vec[i] = v.vec[i];
	return result;
}

vec3 transposeVec(vec1x3 v) {							//1x3���Ϳ��� 3x1���ͷ� ��ġ�ϴ� �Լ�
	vec3 result;
	for (int i = 0; i < 3; i++) result.vec[i] = v.vec[i];
	return result;
}

vec1x4 transposeVec(vec4 v) {							//4x1���Ϳ��� 1x4���ͷ� ��ġ�ϴ� �Լ�
	vec1x4 result;
	for (int i = 0; i < 4; i++) result.vec[i] = v.vec[i];
	return result;
}

vec4 transposeVec(vec1x4 v) {							//1x4���Ϳ��� 4x1���ͷ� ��ġ�ϴ� �Լ�
	vec4 result;
	for (int i = 0; i < 4; i++) result.vec[i] = v.vec[i];
	return result;
}