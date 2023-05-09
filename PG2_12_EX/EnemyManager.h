#pragma once
#include "Random.h"
#include "Enemy.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>

class EnemyManager
{
public:

	// �R���X�g���N�^
	EnemyManager();

	// ����������
	static void Initialize();

	// �X�V����
	static void Update(Player* player, BulletManager* bulletManager);

	// �`�揈��
	static void Draw();

	/// <summary>
	/// �����̓G�̐�����Ԃ��擾����Q�b�^�[
	/// </summary>
	/// <param name="enemyNum">�擾����G</param>
	/// <returns></returns>
	static bool GetEnemyIsAlive(int enemyNum);

	/// <summary>
	/// �����̓G�̍��W���擾����Q�b�^�[
	/// </summary>
	/// <param name="enemyNum">�擾����G</param>
	/// <returns></returns>
	static Vector2 GetEnemyTranslate(int enemyNum);

	/// <summary>
	/// �����̓G�̑傫�����擾����Q�b�^�[
	/// </summary>
	/// <param name="enemyNum">�擾����G</param>
	/// <returns></returns>
	static Vector2 GetEnemySize(int enemyNum);

	static int GetKillCount();

	/// <summary>
	/// �����̓G�̐�����Ԃ�ύX����Z�b�^�[
	/// </summary>
	/// <param name="enemyNum">�Z�b�g����G</param>
	/// <param name="isAlive">�g���K�[�ݒ�</param>
	static void setEnemyIsAlive(int enemyNum, bool isAlive);

	/// <summary>
	/// �����̓G�̍��W���Z�b�g����Z�b�^�[
	/// </summary>
	/// <param name="enemyNum">�ݒ肷��G</param>
	/// <param name="translate">�ݒ肷����W</param>
	static void SetEnemyTranslate(int enemyNum, Vector2 translate);

private:

	/// <summary>
	/// �G�̃X�|�[�����ɌĂяo�����֐�
	/// </summary>
	/// <param name="enemyNum">�X�|�[��������G</param>
	static void SpawnEnemy(int enemyNum);

	/// <summary>
	/// �G�̎��S���ɌĂяo����鏈��
	/// </summary>
	/// <param name="enemyNum">���S������G</param>
	static void DeadEnemy(int enemyNum);

	/// <summary>
	/// �G���v���C���[�ƏՓ˂��Ă��邩�ǂ��������m����֐�
	/// </summary>
	/// <param name="enemyNum">���m����G</param>
	/// <param name="player">�v���C���[�̃|�C���^</param>
	static void HitPlayer(int enemyNum, Player* player);

	/// <summary>
	/// �G���e�ƏՓ˂��Ă��邩�ǂ��������m����֐�
	/// </summary>
	/// <param name="enemyNum">���m����G</param>
	/// <param name="bulletNum">���m����e</param>
	/// <param name="bullet">�e�̃|�C���^</param>
	static void HitEnemy(int enemyNum, int bulletNum, BulletManager* bulletManager);

	// �ÓI�ȃ����o�ϐ���錾
	static int enemyKillCount;
	static int downSE;
	static int hitSE;
	static Enemy* enemy[kMaxSpawnEnemy];
};

