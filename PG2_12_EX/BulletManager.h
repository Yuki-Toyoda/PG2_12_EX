#pragma once
#include "Bullet.h"
#include "Player.h"
class BulletManager
{
public:

	// コンストラクタ
	BulletManager();

	// 初期化処理
	static void Initialize();

	// 更新処理
	static void Update();

	// 描画処理
	static void Draw();

	/// <summary>
	/// 指定された弾が射撃中かどうかを取得するゲッター
	/// </summary>
	/// <param name="bulletNum">情報を取得する弾</param>
	/// <returns></returns>
	static bool GetBulletIsShot(int bulletNum);

	/// <summary>
	/// 指定された弾の座標を取得するゲッター
	/// </summary>
	/// <param name="bulletNum">情報を取得する弾</param>
	/// <returns></returns>
	static Vector2 GetBulletPosition(int bulletNum);

	/// <summary>
	/// 指定された弾の大きさを取得するゲッター
	/// </summary>
	/// <param name="bulletNum">情報を取得する弾</param>
	/// <returns></returns>
	static Vector2 GetBulletSize(int bulletNum);

	/// <summary>
	/// 指定された弾を射撃中の状態にするセッター
	/// </summary>
	/// <param name="bulletNum">射撃中にする弾</param>
	/// <param name="isShot">射撃中にするか</param>
	/// <returns></returns>
	static void SetBulletIsShot(int bulletNum, bool isShot);

	/// <summary>
	/// 指定された弾の座標をセットするセッター
	/// </summary>
	/// <param name="bulletNum">セットする弾</param>
	/// <param name="position">セットする座標</param>
	static void SetBulletPosition(int bulletNum, Vector2 position);

	/// <summary>
	/// 射撃時に呼び出す、弾の座標等を初期化する関数
	/// </summary>
	/// <param name="bulletNum">初期化を行う弾</param>
	/// <param name="Position">初期化する座標</param>
	/// <param name="theta">発射方向を指定</param>
	static void SetShotInitialize(int bulletNum, Vector2 Position, float theta);

private:

	// 静的なメンバ変数を宣言
	static Bullet* bullet[kMaxShotBullet];

};

