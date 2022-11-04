#include <iostream>				//�⺻ ����� ���̺귯��
#include <math.h>				//ȸ�� ��Ŀ��� ����� �ﰢ�Լ��� ���� ���̺귯��
#include "MuSoenMath.h"			//�ڷᱸ���� ������ �������


int main() {
	//3,5 ��ŭ �̵��ϴ� �̵����, ��İ��� ������ Vector�� ���� ���� �׿� �ֱ⿡ ���� �̵������ ��ġ�Ͽ� ������
	mat3 Translate(new float[3][3]{
		{1, 0, 0},
		{0 ,1 ,0},
		{3 ,5 ,1} });
	//30�� ��ŭ ȸ���ϴ� ȸ�����, 30���� Radian ������ ������/6�̱⿡ ȸ����Ŀ� �ش��ϴ� ���� ����
	mat3 Rotate(new float[3][3]
		{ {(float)cos(PI/6), -(float)sin(PI / 6), 0},
		{(float)sin(PI / 6), (float)cos(PI / 6), 0},
		{0, 0, 1}});
	//2�� Ȯ���ϴ� ���������
	mat3 Scale(new float[3][3]{
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 1} });

	vec3 v(new float[3] {4, 2, 1});		//���� ��ǥ�� 4,2�� ����
	vec3 p(new float[3] {0, 0, 0});		//��� ��ǥ�� ���� �� �ʱ�ȭ

	p = v * Translate * Rotate * Scale;	//3,5 �̵� | 30�� ȸ�� | 2�� Ȯ��


	for (int i = 0; i < 3; i++) {		//��� ��ǥ�� ���
		std::cout << p.vec[i];
		if (i < 2) std::cout << " ";
	}

	return 0;
}