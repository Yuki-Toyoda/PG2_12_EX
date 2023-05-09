#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
#include "BulletManager.h"
class Player
{
public:
	// コンストラクタ
	Player();

	// デストラクタ
	~Player();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// 発射処理
	void Shot();

	// 座標のゲッター
	Vector2 GetPlayerPos() { return translate; }

	// 大きさのゲッター
	Vector2 GetPlayerSize() { return size; }

	// 角度のゲッター
	float GetPlayerTheta() { return theta; }

private:

	/// メンバ関数

	/// <summary>
	///	プレイヤーの動作を行う変数
	/// </summary>
	void Move();

	// 中心座標
	Vector2 translate;
	// サイズ
	Vector2 size;

	// 回転中心
	Quad point;
	// 回転後座標
	Quad rotate;
	// プレイヤー角度
	float theta;

	// レティクル座標
	Vector2 reticlePos;

	// レティクルサイズ
	Vector2 reticleSize;

	// 角度を変更するためのマウス座標
	Vector2 mousePosition;

	// スピード
	Vector2 speed;
	// 動作ベクトル
	Vector2 moveVector;
	// ベクトルの長さ
	float vectorLength;

	// 弾が発射可能な状態か
	bool canShot;

	// 射撃フレーム
	float shotRate;

	// テクスチャ
	int texture;
	// テクスチャサイズ
	Vector2 textureSize;
	// 色
	unsigned int color;

	// レティクルテクスチャ
	int reticleTex;
	// レティクル画像サイズ
	Vector2 reticleTexSize;

	// 射撃音
	int shotSE;

};

