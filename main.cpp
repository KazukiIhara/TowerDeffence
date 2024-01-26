#include <Novice.h>
#include "SceneManager.h"

const char kWindowTitle[] = "PG2_STG";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWidth, kScreenHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// パッドのスティック入力を受け取る箱
	int padLeftX = 0;
	int padLeftY = 0;

	// デッドゾーンの設定
	Novice::SetJoystickDeadZone(0, 7000, 7000);

	// new
	cSceneManager* sceneManagaer = new cSceneManager;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetAnalogInputLeft(0, &padLeftX, &padLeftY);

		///
		/// ↓更新処理ここから
		///
		sceneManagaer->Update(keys, preKeys);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneManagaer->Draw();
		///
		/// ↑描画処理ここまで
		///

		// シーンの変更処理
		sceneManagaer->SceneChange();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// delete
	delete sceneManagaer;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}