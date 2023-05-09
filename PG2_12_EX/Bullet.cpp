#include "Bullet.h"

// コンストラクタ
Bullet::Bullet() {
	
}

// デストラクタ
Bullet::~Bullet() {

}

// 初期化処理
void Bullet::Initialize() {
	// 中心座標
	translate = { 10000, 10000 };
	// サイズ
	size = { 32.0f, 32.0f };

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

	// 角度
	theta = 0.0f;

	// 発射スピード
	speed = { 15.0f, 15.0f };

	// 発射されているかのトリガー
	isShot = false;

	// テクスチャ
	texture = Novice::LoadTexture("./Resources/Graph/Bullet.png");
	// テクスチャサイズ
	textureSize = { 64.0f, 64.0f };
}

// 更新処理
void Bullet::Update() {
	if (isShot == true) {
		// 弾回転処理
		rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
		rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

		rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
		rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

		rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
		rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

		rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
		rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

		translate.x += (cosf(theta) * speed.x);
		translate.y += (sinf(theta) * speed.y);

		if (translate.x > kWindowWidth + size.x || translate.x < 0 - size.x || 
			translate.y > kWindowHeight + size.y || translate.y < 0 - size.x) {
			isShot = false;
		}
		
	}
}

// 描画処理
void Bullet::Draw() {
	// 弾の描画
	if (isShot == true) {
		Novice::DrawQuad(
			rotate.q1.x, rotate.q1.y,
			rotate.q2.x, rotate.q2.y,
			rotate.q3.x, rotate.q3.y,
			rotate.q4.x, rotate.q4.y,
			0.0f, 0.0f,
			textureSize.x, textureSize.y,
			texture,
			0xFFFFFFFF
		);
	}
}

