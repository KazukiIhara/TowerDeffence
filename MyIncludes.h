#pragma once
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

/*-----定数-----*/
const int kScreenWidth = 1920;//スクリーンの横幅
const int kScreenHeight = 1080;//スクリーンの縦幅

/*-----列挙型-----*/

enum eDirection//方向列挙型
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

enum eScene//シーン列挙型
{
	TITLE,
	GAME,
	RESULT,

};

enum eMapNum//マップチップ列挙型
{
	NONE,
	BLOCK,
	START,
	GOAL
};

/*-----構造体-----*/

struct eTransform//int型のx,y構造体
{
	int x;
	int y;
};

struct Matrix2x2//2x2行列
{
	float m[2][2];
};

struct Matrix3x3//3x3行列
{
	float m[3][3];
};

struct ObjQuad//オブジェクトの四つ角構造体
{
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};

/*-----関数-----*/

void Add(Vector2& v1, Vector2 v2);