#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
#include "Player.h"
#include "Bullet.h"
class Enemy
{
public:
	// コンストラクタ
	Enemy();

	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(Player* player);

	// 描画処理
	void Draw();

	// 座標のゲッター
	Vector2 GetEnemyTranslate() { return translate; }

	// 大きさのゲッター
	Vector2 GetEnemySize() { return size; }

	// 生存状態のゲッター
	bool GetEnemyIsAlive() { return isAlive; }

	// 座標のセッター
	void SetEnemyTranslate(Vector2 translate) { this->translate = translate; }

	// 生存トリガーのセッター
	void SetEnemyIsAlive(bool isAlive) { this->isAlive = isAlive; }

	// スピードのセッター
	void SetEnemySpeed(Vector2 speed) { this->speed = speed; }

	// ノックバック状態のセッター
	void SetEnemyNockBack(float nockBackSpeed, bool isNockBacking) { this->nockBackSpeed = nockBackSpeed, this->isNockBacking = isNockBacking; }

private:
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

	// スピード
	Vector2 speed;

	// 生存しているかどうか
	bool isAlive;

	// ノックバックしているか
	bool isNockBacking;

	// ノックバック時のスピード
	float nockBackSpeed;

	// テクスチャ
	int texture;
	// テクスチャサイズ
	Vector2 textureSize;
	// 色
	unsigned int color;

};

