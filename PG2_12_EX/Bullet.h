#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
class Bullet
{
public:

	// コンストラクタ
	Bullet();
	
	// デストラクタ
	~Bullet();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 発射中かを取得するゲッター
	bool GetIsShot() { return isShot; }

	// 中心座標を取得するゲッター
	Vector2 GetPosition() { return translate; }

	// 大きさを取得するゲッター
	Vector2 GetSize() { return size; }

	// 位置を決定するセッター
	void SetPosition(Vector2 position) { this->translate = position; }

	// 角度のセッター
	void SetTheta(float theta) { this->theta = theta; }

	// 発射状態のセッター
	void SetIsShot(bool isShot) { this->isShot = isShot; }

private:

	// 中心座標
	Vector2 translate;
	// サイズ
	Vector2 size;

	// 回転中心
	Quad point;
	// 回転後座標
	Quad rotate;
	// 角度
	float theta;

	// 発射スピード
	Vector2 speed;

	// 発射されているかのトリガー
	bool isShot;

	// テクスチャ
	int texture;
	// テクスチャサイズ
	Vector2 textureSize;
	
};

