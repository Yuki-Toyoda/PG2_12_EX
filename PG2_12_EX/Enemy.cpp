#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {

}

// 初期化処理
void Enemy::Initialize() {
	// 座標初期化
	translate = { 110000, 110000 };
	// サイズ
	size = { 64.0f, 64.0f };

	// 回転中心
	point = {
		-size.x / 2, -size.y / 2,
		size.x / 2, -size.y / 2,
		-size.x / 2, size.y / 2,
		size.x / 2, size.y / 2
	};

	// 回転後座標
	rotate = {
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f
	};

	// プレイヤー角度
	theta = 0.0f;

	// スピード
	speed = { 1.0f, 1.0f };

	// 生存
	isAlive = false;

	// ノックバック
	isNockBacking = false;

	// ノックバック時のスピード
	nockBackSpeed = 0.0f;

	// テクスチャ
	texture = Novice::LoadTexture("./Resources/Graph/Enemy.png");
	// テクスチャサイズ
	textureSize = { 256.0f, 256.0f };

	// 色
	color = 0xFFFFFFFF;

}

// 更新処理
void Enemy::Update(Player* player) {

	Vector2 PlayerTranslate = player->GetPlayerPos();

	// マウス座標とプレイヤーの角度を求める
	theta = atan2(PlayerTranslate.y - translate.y, PlayerTranslate.x - translate.x);

	// プレイヤー回転処理
	rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
	rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

	rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
	rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

	rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
	rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

	rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
	rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

	// 生存時の処理
	if (isAlive == true) {
		if (isNockBacking == true) {
			// ノックバック処理
			translate.x += -(cosf(theta) * nockBackSpeed);
			translate.y += -(sinf(theta) * nockBackSpeed);

			// ノックバックスピードを少しづつ下げる
			nockBackSpeed--;

		}
		else {
			// 移動処理
			translate.x += (cosf(theta) * speed.x);
			translate.y += (sinf(theta) * speed.y);
		}
		
	}

	if (nockBackSpeed < 0) {
		isNockBacking = false;
		nockBackSpeed = 0.0f;
	}

}

// 描画処理
void Enemy::Draw() {
	// プレイヤーの描画
	Novice::DrawQuad(
		rotate.q1.x, rotate.q1.y,
		rotate.q2.x, rotate.q2.y,
		rotate.q3.x, rotate.q3.y,
		rotate.q4.x, rotate.q4.y,
		0.0f, 0.0f,
		textureSize.x, textureSize.y,
		texture,
		color
	);

}
