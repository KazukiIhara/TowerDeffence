#pragma once
#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

/*-----定数-----*/
//世界
const int kScreenWidth = 1920;//スクリーンの横幅
const int kScreenHeight = 1080;//スクリーンの縦幅

//プレイヤー
const int kInvicibleTime = 70;//プレイヤーの無敵時間の長さ
const int kBulletNum = 30;//弾の最大数

//エネミー
const int kEnemySpwanTime = 240;//通常敵のリポップタイム

//パーティクル
const int kParticleNum = 30;//パーティクルの数

/*-----列挙型-----*/
enum eLevel
{
	EASY,
	NOMAL,
	HARD
};
enum eTitleMenu
{
	GAMESTART,
	EXIT
};

enum eDirection//方向列挙型
{
	UP,
	DOWN,
	LEFT,
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
struct MenuTab
{
	Vector2 size;
	Vector2 position;
	int texture;
};

struct Particle//パーティクル構造体
{
	Vector2 size;
	Vector2 position;
	Vector2 velosity;
	float theta;
	bool isActive;
};

struct Bullet//弾構造体
{
	Vector2 position;
	Vector2 velosity;
	bool isActive;
};

struct Transform//int型のx,y構造体
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