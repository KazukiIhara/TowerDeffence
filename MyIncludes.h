#pragma once
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

/*-----θ-----*/
const int kScreenWidth = 1920;//XN[Μ‘
const int kScreenHeight = 1080;//XN[Μc

/*-----ρ^-----*/

enum eDirection//ϋόρ^
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum eScene//V[ρ^
{
	TITLE,
	GAME,
	RESULT,

};

enum eMapNum//}bv`bvρ^
{
	NONE,
	BLOCK,
	START,
	GOAL
};

/*-----\’Μ-----*/

struct eTransform//int^Μx,y\’Μ
{
	int x;
	int y;
};

struct Matrix2x2//2x2sρ
{
	float m[2][2];
};

struct Matrix3x3//3x3sρ
{
	float m[3][3];
};

struct ObjQuad//IuWFNgΜlΒp\’Μ
{
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};

/*-----Φ-----*/

void Add(Vector2& v1, Vector2 v2);