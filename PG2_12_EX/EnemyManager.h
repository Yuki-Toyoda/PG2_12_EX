#pragma once
#include "Random.h"
#include "Enemy.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>

class EnemyManager
{
public:

	// コンストラクタ
	EnemyManager();

	// 初期化処理
	static void Initialize();

	// 更新処理
	static void Update(Player* player, BulletManager* bulletManager);

	// 描画処理
	static void Draw();

	/// <summary>
	/// 引数の敵の生存状態を取得するゲッター
	/// </summary>
	/// <param name="enemyNum">取得する敵</param>
	/// <returns></returns>
	static bool GetEnemyIsAlive(int enemyNum);

	/// <summary>
	/// 引数の敵の座標を取得するゲッター
	/// </summary>
	/// <param name="enemyNum">取得する敵</param>
	/// <returns></returns>
	static Vector2 GetEnemyTranslate(int enemyNum);

	/// <summary>
	/// 引数の敵の大きさを取得するゲッター
	/// </summary>
	/// <param name="enemyNum">取得する敵</param>
	/// <returns></returns>
	static Vector2 GetEnemySize(int enemyNum);

	static int GetKillCount();

	/// <summary>
	/// 引数の敵の生存状態を変更するセッター
	/// </summary>
	/// <param name="enemyNum">セットする敵</param>
	/// <param name="isAlive">トリガー設定</param>
	static void setEnemyIsAlive(int enemyNum, bool isAlive);

	/// <summary>
	/// 引数の敵の座標をセットするセッター
	/// </summary>
	/// <param name="enemyNum">設定する敵</param>
	/// <param name="translate">設定する座標</param>
	static void SetEnemyTranslate(int enemyNum, Vector2 translate);

private:

	/// <summary>
	/// 敵のスポーン時に呼び出される関数
	/// </summary>
	/// <param name="enemyNum">スポーンさせる敵</param>
	static void SpawnEnemy(int enemyNum);

	/// <summary>
	/// 敵の死亡時に呼び出される処理
	/// </summary>
	/// <param name="enemyNum">死亡させる敵</param>
	static void DeadEnemy(int enemyNum);

	/// <summary>
	/// 敵がプレイヤーと衝突しているかどうかを検知する関数
	/// </summary>
	/// <param name="enemyNum">検知する敵</param>
	/// <param name="player">プレイヤーのポインタ</param>
	static void HitPlayer(int enemyNum, Player* player);

	/// <summary>
	/// 敵が弾と衝突しているかどうかを検知する関数
	/// </summary>
	/// <param name="enemyNum">検知する敵</param>
	/// <param name="bulletNum">検知する弾</param>
	/// <param name="bullet">弾のポインタ</param>
	static void HitEnemy(int enemyNum, int bulletNum, BulletManager* bulletManager);

	// 静的なメンバ変数を宣言
	static int enemyKillCount;
	static int downSE;
	static int hitSE;
	static Enemy* enemy[kMaxSpawnEnemy];
};

