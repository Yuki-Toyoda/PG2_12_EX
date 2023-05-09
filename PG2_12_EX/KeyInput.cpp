#include "KeyInput.h"

/******** 初期化 **********/
void KeyInput::Initialize() {

	//マウス位置初期化
	mousePosition = { 0.0f, 0.0f };

	//キー状態の初期化
	for (int i = 0; i < 256; i++) {

		keys[i] = { 0 };
		preKeys[i] = { 0 };

	}

}

/******** 更新 **********/
void KeyInput::Update() {

	/******** マウス位置取得 **********/
	//取得したマウス位置を2次元座標(x, y)で受け取る
	int x = 0, y = 0;
	Novice::GetMousePosition(&x, &y);
	mousePosition = { (float)x, (float)y };

	/******** キー情報取得 **********/
	//どのキーがどのような状態で入力されているかを受け取る
	//key ... 確認するキー
	//state ... 確認したいキーの状態
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

/******** マウス位置取得関数 **********/
Vector2 KeyInput::GetMousePosition() {

	return mousePosition;

}

/******** マウス入力の状態検知 **********/
//key ... 確認するマウス入力
//state ... 確認したいマウス入力の状態
bool KeyInput::GetMouseState(MouseButton key, InputState state) {

	switch (state)
	{
		//押されていない場合
	case Null:

		if (!Novice::IsTriggerMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//押された瞬間
	case Trigger:

		if (Novice::IsTriggerMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//押している間
	case Press:

		if (Novice::IsPressMouse(key)) {

			return true;

		}
		else {

			return false;

		}

		//離した瞬間
	case Release:

		//現在使用予定がないため後に実装

	//上記以外だった場合エラー
	default:

		return false;

	}

}

/******** キーボード入力の状態検知 **********/
//key ... 確認するマウス入力
//state ... 確認したいマウス入力の状態
bool KeyInput::GetKeyboardState(int key, InputState state) {

	switch (state)
	{

		//押されていない場合
	case Null:

		if (!keys[key] && !preKeys[key]) {

			return true;

		}
		else {

			return false;

		}

		//押した瞬間
	case Trigger:

		if (keys[key] && !preKeys[key]) {

			return true;

		}
		else {

			return false;

		}

		//押している間
	case Press:

		if (keys[key]) {

			return true;

		}
		else {

			return false;

		}

		//離した瞬間
	case Release:

		if (keys[key]) {

			return true;

		}
		else {

			return false;

		}

		//上記以外だった場合はエラー
	default:

		return false;

	}

}

/******** ヘッダファイルで宣言した変数の実態宣言 **********/

//マウス座標
Vector2 KeyInput::mousePosition;

//キー入力状況
char KeyInput::keys[256];

//前フレームでの入力状況
char KeyInput::preKeys[256];

#pragma region コメントアウト用

/*********************************
	大見出しコピペ
*********************************/

/******** 小見出しコピペ用 **********/

#pragma endregion