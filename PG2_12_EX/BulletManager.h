#pragma once
#include "Bullet.h"
#include "Player.h"
class BulletManager
{
public:

	// �R���X�g���N�^
	BulletManager();

	// ����������
	static void Initialize();

	// �X�V����
	static void Update();

	// �`�揈��
	static void Draw();

	/// <summary>
	/// �w�肳�ꂽ�e���ˌ������ǂ������擾����Q�b�^�[
	/// </summary>
	/// <param name="bulletNum">�����擾����e</param>
	/// <returns></returns>
	static bool GetBulletIsShot(int bulletNum);

	/// <summary>
	/// �w�肳�ꂽ�e�̍��W���擾����Q�b�^�[
	/// </summary>
	/// <param name="bulletNum">�����擾����e</param>
	/// <returns></returns>
	static Vector2 GetBulletPosition(int bulletNum);

	/// <summary>
	/// �w�肳�ꂽ�e�̑傫�����擾����Q�b�^�[
	/// </summary>
	/// <param name="bulletNum">�����擾����e</param>
	/// <returns></returns>
	static Vector2 GetBulletSize(int bulletNum);

	/// <summary>
	/// �w�肳�ꂽ�e���ˌ����̏�Ԃɂ���Z�b�^�[
	/// </summary>
	/// <param name="bulletNum">�ˌ����ɂ���e</param>
	/// <param name="isShot">�ˌ����ɂ��邩</param>
	/// <returns></returns>
	static void SetBulletIsShot(int bulletNum, bool isShot);

	/// <summary>
	/// �w�肳�ꂽ�e�̍��W���Z�b�g����Z�b�^�[
	/// </summary>
	/// <param name="bulletNum">�Z�b�g����e</param>
	/// <param name="position">�Z�b�g������W</param>
	static void SetBulletPosition(int bulletNum, Vector2 position);

	/// <summary>
	/// �ˌ����ɌĂяo���A�e�̍��W��������������֐�
	/// </summary>
	/// <param name="bulletNum">���������s���e</param>
	/// <param name="Position">������������W</param>
	/// <param name="theta">���˕������w��</param>
	static void SetShotInitialize(int bulletNum, Vector2 Position, float theta);

private:

	// �ÓI�ȃ����o�ϐ���錾
	static Bullet* bullet[kMaxShotBullet];

};

