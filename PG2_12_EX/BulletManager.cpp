#include "BulletManager.h"

// �R���X�g���N�^
BulletManager::BulletManager() {

}

// ����������
void BulletManager::Initialize() {
	// �e��������
	for (int i = 0; i < kMaxShotBullet; i++) {
		bullet[i] = new Bullet;
		bullet[i]->Initialize();
	}
}

// �X�V����
void BulletManager::Update(){
	// �e�̍X�V����
	for (int i = 0; i < kMaxShotBullet; i++) {
		bullet[i]->Update();
	}
}

// �`�揈��
void BulletManager::Draw() {
	// �e�̕`�揈��
	for (int i = 0; i < kMaxShotBullet; i++) {
		if(bullet[i]->GetIsShot() == true)
		bullet[i]->Draw();
	}
}

/// <summary>
/// �w�肳�ꂽ�e���ˌ������ǂ������擾����Q�b�^�[
/// </summary>
/// <param name="bulletNum">�����擾����e</param>
/// <returns></returns>
bool BulletManager::GetBulletIsShot(int shotNum) {
	return bullet[shotNum]->GetIsShot();
}

/// <summary>
/// �w�肳�ꂽ�e�̍��W���擾����֐�
/// </summary>
/// <param name="bulletNum">�����擾����e</param>
/// <returns></returns>
Vector2 BulletManager::GetBulletPosition(int bulletNum) {
	return bullet[bulletNum]->GetPosition();
}

/// <summary>
/// �w�肳�ꂽ�e�̑傫�����擾����֐�
/// </summary>
/// <param name="bulletNum">�����擾����e</param>
/// <returns></returns>
Vector2 BulletManager::GetBulletSize(int bulletNum) {
	return bullet[bulletNum]->GetSize();
}

/// <summary>
/// �w�肳�ꂽ�e���ˌ����̏�Ԃɂ���Z�b�^�[
/// </summary>
/// <param name="bulletNum">�ˌ����ɂ���e</param>
/// <returns></returns>
void BulletManager::SetBulletIsShot(int bulletNum, bool isShot) {
	bullet[bulletNum]->SetIsShot(isShot);
}

/// <summary>
/// �w�肳�ꂽ�e�̍��W���Z�b�g����Z�b�^�[
/// </summary>
/// <param name="bulletNum">�Z�b�g����e</param>
/// <param name="position">�Z�b�g������W</param>
void BulletManager::SetBulletPosition(int bulletNum, Vector2 position) {
	bullet[bulletNum]->SetPosition(position);
}

/// <summary>
/// �ˌ����ɌĂяo���A�e�̍��W��������������֐�
/// </summary>
/// <param name="bulletNum">���������s���e</param>
/// <param name="Position">������������W</param>
/// <param name="theta">���˕������w��</param>
void BulletManager::SetShotInitialize(int bulletNum, Vector2 Position, float theta) {
	bullet[bulletNum]->SetPosition(Position);
	bullet[bulletNum]->SetTheta(theta);
	SetBulletIsShot(bulletNum, true);
}

// �����o�ϐ��̎��̂�錾
Bullet* BulletManager::bullet[kMaxShotBullet];