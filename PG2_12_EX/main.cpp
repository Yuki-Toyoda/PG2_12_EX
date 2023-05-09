#include <Novice.h>
#include "Const.h"
#include "KeyInput.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "Random.h"
#include "Easing.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	/*********************************
		変数宣言ここから
	*********************************/

	// シーン管理用
	int scene = TITLE;

	Player* player = new Player;
	player->Initialize();

	BulletManager* bulletManager = new BulletManager;

	bulletManager->Initialize();
	
	EnemyManager::Initialize();

	SetSrand();

	// シーンチェンジ開始
	bool sceneChangeTitle = false;
	// シーンチェンジ終了
	bool sceneChangeGame = false;

	// スペースキー用T
	float buttonT = 0.0f;

	// シーンチェンジ用T
	float sceneChangeT = 1.0f;

	int titleTex = Novice::LoadTexture("./Resources/Graph/Title.png");
	int UITex = Novice::LoadTexture("./Resources/Graph/UI.png");
	int buttonTex = Novice::LoadTexture("./Resources/Graph/SPACE.png");
	int whiteTex = Novice::LoadTexture("white1x1.png");

	int buttonSound = Novice::LoadAudio("./Resources/SE/Button.wav");

	Vector2 buttonUI = { kWindowWidth / 2, kWindowHeight + 200 };
	Vector2 sceneTranslate = { kWindowWidth / 2, kWindowHeight / 2 };

	unsigned int Color = 0x00000000;

	/*********************************
		変数宣言ここまで
	*********************************/

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// フルスクリーンに設定
		Novice::SetWindowMode(kFullscreen);

		// カーソル消去
		Novice::SetMouseCursorVisibility(0);

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*********************************
			更新処理ここから
		*********************************/
		// キー入力検知更新
		KeyInput::Update();

		if (sceneChangeTitle == true || sceneChangeGame == true) {
			if (sceneChangeT <= 1.0f) {
				Color = ColorEasing(sceneChangeT, 0x00000000, 0xFFFFFFFF);
				sceneChangeT += 1.0f / 60.0f;
			}
		}
		if (sceneChangeTitle == false && sceneChangeGame == false) {
			if (sceneChangeT <= 1.0f) {
				Color = ColorEasing(sceneChangeT, 0xFFFFFFFF, 0x00000000);
				sceneChangeT += 1.0f / 60.0f;
			}
		}

		switch (scene)
		{
		case TITLE:

			if (sceneChangeGame == true) {
				sceneChangeT = 0.0f;
				sceneChangeGame = false;
			}

			if (buttonT < 1.0f) {
				buttonUI.y = EaseOut(buttonT, kWindowHeight + 200, kWindowHeight - 300);
				buttonT += 1.0f / 60.0f;
			}

			// スペースキーを押したらシーン切り替え
			if (KeyInput::GetKeyboardState(DIK_SPACE, Trigger)) {
				if (sceneChangeTitle == false) {
					Novice::PlayAudio(buttonSound, 0, 0.25f);
					buttonT = 1.0f;
					sceneChangeT = 0.0f;
					sceneChangeTitle = true;
				}
			}

			if (sceneChangeTitle == true && Color == 0xFFFFFFFF) {
				buttonT = 0.0f;
				scene = GAME;

			}

			break;
		case GAME:

			if (sceneChangeTitle == true) {

				// プレイヤーの更新処理
				player->Update();

				// 弾の更新処理
				bulletManager->Update();

				// 敵の更新処理
				EnemyManager::Update(player, bulletManager);

				sceneChangeT = 0.0f;
				sceneChangeTitle = false;
			}

			if (Color == 0x00000000) {
				// プレイヤーの更新処理
				player->Update();

				// 弾の更新処理
				bulletManager->Update();

				// 敵の更新処理
				EnemyManager::Update(player, bulletManager);

				if (KeyInput::GetKeyboardState(DIK_R, Trigger)) {
					Novice::PlayAudio(buttonSound, 0, 0.25f);
					sceneChangeT = 0.0f;
					sceneChangeGame = true;
				}
			}

			if (sceneChangeGame == true && Color == 0xFFFFFFFF) {
				player->Initialize();
				bulletManager->Initialize();
				EnemyManager::Initialize();
				scene = TITLE;
			}

			break;
		case RESULT:


			break;
		}

		/*********************************
			更新処理ここまで
		*********************************/

		/*********************************
			描画処理ここから
		*********************************/

		switch (scene)
		{
		case TITLE:
			Novice::DrawSprite(
				0, 0,
				titleTex,
				1.0f, 1.0f,
				0.0f, WHITE
			);

			Novice::DrawQuad(
				buttonUI.x - 500, buttonUI.y - 96,
				buttonUI.x + 500, buttonUI.y - 96,
				buttonUI.x - 500, buttonUI.y + 96,
				buttonUI.x + 500, buttonUI.y + 96,
				0, 0, 1280, 256,
				buttonTex, WHITE
			);

			break;
		case GAME:

			// 背景描画
			Novice::DrawBox(
				0, 0, kWindowWidth, kWindowHeight, 0.0f,
				BLACK, kFillModeSolid
			);

			// 弾の描画
			bulletManager->Draw();

			// 敵の描画
			EnemyManager::Draw();

			// プレイヤーの描画
			player->Draw();

			Novice::DrawSprite(
				0, 0,
				UITex,
				1.0f, 1.0f,
				0.0f, WHITE
			);

			break;
		case RESULT:


			break;
		}

		Novice::DrawQuad(
			sceneTranslate.x - kWindowWidth / 2, sceneTranslate.y - kWindowHeight / 2,
			sceneTranslate.x + kWindowWidth / 2, sceneTranslate.y - kWindowHeight / 2,
			sceneTranslate.x - kWindowWidth / 2, sceneTranslate.y + kWindowHeight / 2,
			sceneTranslate.x + kWindowWidth / 2, sceneTranslate.y + kWindowHeight / 2,
			0, 0, 1, 1,
			whiteTex, Color
		);

		/*********************************
			描画処理ここまで
		*********************************/

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (KeyInput::GetKeyboardState(DIK_ESCAPE, Trigger)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
