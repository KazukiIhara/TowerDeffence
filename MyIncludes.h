#pragma once
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

/*-----�萔-----*/
const int kScreenWidth = 1920;//�X�N���[���̉���
const int kScreenHeight = 1080;//�X�N���[���̏c��

/*-----�񋓌^-----*/

enum eDirection//�����񋓌^
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum eScene//�V�[���񋓌^
{
	TITLE,
	GAME,
	RESULT,

};

enum eMapNum//�}�b�v�`�b�v�񋓌^
{
	NONE,
	BLOCK,
	START,
	GOAL
};

/*-----�\����-----*/

struct eTransform//int�^��x,y�\����
{
	int x;
	int y;
};

struct Matrix2x2//2x2�s��
{
	float m[2][2];
};

struct Matrix3x3//3x3�s��
{
	float m[3][3];
};

struct ObjQuad//�I�u�W�F�N�g�̎l�p�\����
{
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};

/*-----�֐�-----*/

void Add(Vector2& v1, Vector2 v2);