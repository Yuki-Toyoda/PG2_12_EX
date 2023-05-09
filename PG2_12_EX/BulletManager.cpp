#include "BulletManager.h"

// コンストラクタ
BulletManager::BulletManager() {

}

// 初期化処理
void BulletManager::Initialize() {
	// 弾を初期化
	for (int i = 0; i < kMaxShotBullet; i++) {
		bullet[i] = new Bullet;
		bullet[i]->Initialize();
	}
}

// 更新処理
void BulletManager::Update(){
	// 弾の更新処理
	for (int i = 0; i < kMaxShotBullet; i++) {
		bullet[i]->Update();
	}
}

// 描画処理
void BulletManager::Draw() {
	// 弾の描画処理
	for (int i = 0; i < kMaxShotBullet; i++) {
		if(bullet[i]->GetIsShot() == true)
		bullet[i]->Draw();
	}
}

/// <summary>
/// 指定された弾が射撃中かどうかを取得するゲッター
/// </summary>
/// <param name="bulletNum">情報を取得する弾</param>
/// <returns></returns>
bool BulletManager::GetBulletIsShot(int shotNum) {
	return bullet[shotNum]->GetIsShot();
}

/// <summary>
/// 指定された弾の座標を取得する関数
/// </summary>
/// <param name="bulletNum">情報を取得する弾</param>
/// <returns></returns>
Vector2 BulletManager::GetBulletPosition(int bulletNum) {
	return bullet[bulletNum]->GetPosition();
}

/// <summary>
/// 指定された弾の大きさを取得する関数
/// </summary>
/// <param name="bulletNum">情報を取得する弾</param>
/// <returns></returns>
Vector2 BulletManager::GetBulletSize(int bulletNum) {
	return bullet[bulletNum]->GetSize();
}

/// <summary>
/// 指定された弾を射撃中の状態にするセッター
/// </summary>
/// <param name="bulletNum">射撃中にする弾</param>
/// <returns></returns>
void BulletManager::SetBulletIsShot(int bulletNum, bool isShot) {
	bullet[bulletNum]->SetIsShot(isShot);
}

/// <summary>
/// 指定された弾の座標をセットするセッター
/// </summary>
/// <param name="bulletNum">セットする弾</param>
/// <param name="position">セットする座標</param>
void BulletManager::SetBulletPosition(int bulletNum, Vector2 position) {
	bullet[bulletNum]->SetPosition(position);
}

/// <summary>
/// 射撃時に呼び出す、弾の座標等を初期化する関数
/// </summary>
/// <param name="bulletNum">初期化を行う弾</param>
/// <param name="Position">初期化する座標</param>
/// <param name="theta">発射方向を指定</param>
void BulletManager::SetShotInitialize(int bulletNum, Vector2 Position, float theta) {
	bullet[bulletNum]->SetPosition(Position);
	bullet[bulletNum]->SetTheta(theta);
	SetBulletIsShot(bulletNum, true);
}

// メンバ変数の実体を宣言
Bullet* BulletManager::bullet[kMaxShotBullet];