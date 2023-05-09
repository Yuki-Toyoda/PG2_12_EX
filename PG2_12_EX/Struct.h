#pragma once
/*********************************
	構造体管理
*********************************/

/******** 二次元座標 **********/
struct Vector2 {
	float x;
	float y;
};

struct IntVector2 {
	int x;
	int y;
};

/******** 矩形 **********/
struct Quad {
	Vector2 q1;
	Vector2 q2;
	Vector2 q3;
	Vector2 q4;
};

/******** エフェクト **********/
struct Effect {
	Vector2 translate;
	Vector2 startPos;
	Vector2 endPos;

	Vector2 size;
	Vector2 startSize;
	Vector2 endSize;

	unsigned int color;

	bool isAlive;

	float t;

};

/*================================
	構造体管理
=================================*/

