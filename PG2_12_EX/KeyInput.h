#pragma once
#include "Struct.h"
#include "Enum.h"
#include <Novice.h>

/*********************************
	入力状態検知用クラス
*********************************/

class KeyInput {

public:

	//初期化
	static void Initialize();

	//更新
	static void Update();

	//マウス座標取得
	static Vector2 GetMousePosition();

	//マウス入力状態取得
	static bool GetMouseState(MouseButton key, InputState state);

	//キー入力状態取得
	static bool GetKeyboardState(int key, InputState state);

private:

	//マウス座標
	static Vector2 mousePosition;

	//キー入力状態
	static char keys[];

	//前フレームのキー入力状態
	static char preKeys[];

};

#pragma region コメントアウト用

/*********************************
	大見出しコピペ
*********************************/

/******** 小見出しコピペ用 **********/

#pragma endregion
