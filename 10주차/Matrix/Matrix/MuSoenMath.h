#pragma once
#define PI 3.141592						//�������� �Ҽ��� 6�ڸ����� �ٻ簪���� ����

typedef struct mat3 {					//float �ڷ����� ������ 2���� ��� ����ü ����
	float mat[3][3];

	mat3(float a[3][3]) {		//�����ڿ��� ����� value �ʱ�ȭ
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) this->mat[i][j] = a[i][j];
		}
	}


	mat3 operator*(mat3& ref) {			//������ �����ε����� 3x3 ��ĳ����� �� ����
		mat3 resultMat(new float[3][3]{ {1, 0, 0}, {0,1,0}, {0,0,1} });		//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultMat.mat[i][j] = 0;
				for (int k = 0; k < 3; k++)
					resultMat.mat[i][j] += this->mat[i][k] * ref.mat[k][j];
			}
		}

		return resultMat;					//��� ���� ��� �� ��ȯ
	}

};

typedef struct vec3 {					//float �ڷ����� ������ 2������ǥ + ������ǥ ����ü ����
	float vec[3];

	vec3(float a[3]) {					//�����ڿ��� Vector�� value �ʱ�ȭ
		for (int i = 0; i < 3; i++) this->vec[i] = a[i];
	}

	vec3 operator*(mat3& ref) {			//������ �����ε����� 3x1 Vector�� 3x3 ��İ� ����
		vec3 resultVec(new float[3] { 0, 0, 0 });	//��� ���� ������� �����ϴ� ���� ����
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				resultVec.vec[i] += this->vec[j] * ref.mat[j][i];
			}
		}

		return resultVec;		//��� ���� ��� �� ��ȯ
	}

};