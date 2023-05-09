#include "EnemyManager.h"

// コンストラクタ
EnemyManager::EnemyManager() {

}

// 初期化処理
void EnemyManager::Initialize() {

	downSE = Novice::LoadAudio("./Resources/SE/Down.wav");
	hitSE = Novice::LoadAudio("./Resources/SE/Hit.mp3");

	enemyKillCount = 0;

	// 敵を初期化
	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		enemy[i] = new Enemy;
		enemy[i]->Initialize();
	}
}

// 更新処理
void EnemyManager::Update(Player* player, BulletManager* bulletManager) {
	// 敵の更新処理
	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		enemy[i]->Update(player);

	}

	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		if (enemy[i]->GetEnemyIsAlive() == false) {
			SpawnEnemy(i);
		}

		if (enemy[i]->GetEnemyIsAlive() == true) {
			HitPlayer(i, player);
			for (int j = 0; j < kMaxShotBullet; j++) {
				if(bulletManager->GetBulletIsShot(j) == true)
				HitEnemy(i, j, bulletManager);
			}
		}
	}

}

// 描画処理
void EnemyManager::Draw() {
	// 敵の描画処理
	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		if (enemy[i]->GetEnemyIsAlive() == true)
			enemy[i]->Draw();
	}
}

/// <summary>
/// 引数の敵の生存状態を取得するゲッター
/// </summary>
/// <param name="enemyNum">取得する敵</param>
/// <returns></returns>
bool EnemyManager::GetEnemyIsAlive(int enemyNum) {
	return enemy[enemyNum]->GetEnemyIsAlive();
}

/// <summary>
/// 引数の敵の座標を取得するゲッター
/// </summary>
/// <param name="enemyNum">取得する敵</param>
/// <returns></returns>
Vector2 EnemyManager::GetEnemyTranslate(int enemyNum) {
	return enemy[enemyNum]->GetEnemyTranslate();
}

/// <summary>
/// 引数の敵の大きさを取得するゲッター
/// </summary>
/// <param name="enemyNum">取得する敵</param>
/// <returns></returns>
Vector2 EnemyManager::GetEnemySize(int enemyNum) {
	return enemy[enemyNum]->GetEnemySize();
}

int EnemyManager::GetKillCount() {
	return EnemyManager::enemyKillCount;
}

/// <summary>
/// 引数の敵の生存状態を変更するセッター
/// </summary>
/// <param name="enemyNum">セットする敵</param>
/// <param name="isAlive">トリガー設定</param>
void EnemyManager::setEnemyIsAlive(int enemyNum, bool isAlive) {
	enemy[enemyNum]->SetEnemyIsAlive(isAlive);
}

/// <summary>
/// 引数の敵の座標をセットするセッター
/// </summary>
/// <param name="enemyNum">設定する敵</param>
/// <param name="translate">設定する座標</param>
void EnemyManager::SetEnemyTranslate(int enemyNum, Vector2 translate) {
	enemy[enemyNum]->SetEnemyTranslate(translate);
}

/// <summary>
/// 敵のスポーン時に呼び出される関数
/// </summary>
/// <param name="enemyNum">スポーンさせる敵</param>
void EnemyManager::SpawnEnemy(int enemyNum) {

	float spawnTheta = Random(0, 360);
	spawnTheta = spawnTheta * (M_PI / 180.0f);

	Vector2 enemySpawnPosition = { kWindowWidth / 3.5f, kWindowHeight / 3.5f };
	enemySpawnPosition.x += (cosf(spawnTheta) * kWindowWidth);
	enemySpawnPosition.y += -(sinf(spawnTheta) * kWindowHeight);

	Vector2 enemySpeed = {
		RandomF(1, 3, 1),
		RandomF(1, 3, 1)
	};

	enemy[enemyNum]->SetEnemySpeed(enemySpeed);

	enemy[enemyNum]->SetEnemyTranslate(enemySpawnPosition);
	enemy[enemyNum]->SetEnemyIsAlive(true);

}

/// <summary>
/// 敵の死亡時に呼び出される処理
/// </summary>
/// <param name="enemyNum">死亡させる敵</param>
void EnemyManager::DeadEnemy(int enemyNum) {

	// 敵を倒した際にプラスする
	enemyKillCount++;

	Novice::PlayAudio(downSE, 0, 0.35f);

	// 敵を画面から消す
	enemy[enemyNum]->SetEnemyTranslate({ 110000,110000 });
	enemy[enemyNum]->SetEnemyIsAlive(false);
}

/// <summary>
/// 敵がプレイヤーと衝突しているかどうかを検知する
/// </summary>
/// <param name="enemyNum">検知する敵</param>
void EnemyManager::HitPlayer(int enemyNum, Player* player) {

	// 座標取得
	Vector2 enemyPosition = enemy[enemyNum]->GetEnemyTranslate();
	Vector2 playerPosition = player->GetPlayerPos();

	// サイズ取得
	Vector2 enemySize = enemy[enemyNum]->GetEnemySize();
	Vector2 playerSize = player->GetPlayerSize();

	// プレイヤーとの距離を求める
	Vector2 e2p = {
		enemyPosition.x - playerPosition.x,
		enemyPosition.y - playerPosition.y
	};

	float distance = sqrt(pow(e2p.x, 2) + pow(e2p.y, 2));

	// 衝突判定
	if (distance < enemySize.x / 2 + playerSize.x / 2) {
		enemy[enemyNum]->SetEnemyNockBack(20.0f, true);
		Novice::PlayAudio(hitSE, 0, 0.25f);
	}

}

/// <summary>
/// 敵が弾と衝突しているかどうかを検知する関数
/// </summary>
/// <param name="enemyNum">検知する敵</param>
/// <param name="bulletNum">検知する弾</param>
/// <param name="bullet">弾のポインタ</param>
void EnemyManager::HitEnemy(int enemyNum, int bulletNum, BulletManager* bullet) {
	// 座標取得
	Vector2 enemyPosition = enemy[enemyNum]->GetEnemyTranslate();
	Vector2 bulletPosition[kMaxShotBullet];

	// サイズ取得
	Vector2 enemySize = enemy[enemyNum]->GetEnemySize();
	Vector2 bulletSize[kMaxShotBullet];

	for (int i = 0; i < kMaxShotBullet; i++) {
		// 弾の座標を取得
		bulletPosition[i] = bullet->GetBulletPosition(i);
		// 弾のサイズを取得
		bulletSize[i] = bullet->GetBulletSize(i);
	}

	// 弾との距離を求める
	Vector2 e2b[kMaxShotBullet];
	
	float distance[kMaxShotBullet];

	for (int i = 0; i < kMaxShotBullet; i++) {
		e2b[i] = {
			enemyPosition.x - bulletPosition[i].x,
			enemyPosition.y - bulletPosition[i].y
		};
		distance[i] = sqrt(pow(e2b[i].x, 2) + pow(e2b[i].y, 2));

		if (distance[i] < enemySize.x / 2 + bulletSize[i].x / 2) {
			// 弾を消去
			bullet[i].SetBulletIsShot(i, false);
			bullet[i].SetBulletPosition(i, { 10000, 10000 });

			DeadEnemy(enemyNum);
		}

	}

}

// メンバ変数の実体を宣言
int EnemyManager::enemyKillCount;
int EnemyManager::downSE;
int EnemyManager::hitSE;
Enemy* EnemyManager::enemy[kMaxSpawnEnemy];
