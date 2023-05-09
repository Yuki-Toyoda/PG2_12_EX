#include "EnemyManager.h"

// �R���X�g���N�^
EnemyManager::EnemyManager() {

}

// ����������
void EnemyManager::Initialize() {

	downSE = Novice::LoadAudio("./Resources/SE/Down.wav");
	hitSE = Novice::LoadAudio("./Resources/SE/Hit.mp3");

	enemyKillCount = 0;

	// �G��������
	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		enemy[i] = new Enemy;
		enemy[i]->Initialize();
	}
}

// �X�V����
void EnemyManager::Update(Player* player, BulletManager* bulletManager) {
	// �G�̍X�V����
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

// �`�揈��
void EnemyManager::Draw() {
	// �G�̕`�揈��
	for (int i = 0; i < kMaxSpawnEnemy; i++) {
		if (enemy[i]->GetEnemyIsAlive() == true)
			enemy[i]->Draw();
	}
}

/// <summary>
/// �����̓G�̐�����Ԃ��擾����Q�b�^�[
/// </summary>
/// <param name="enemyNum">�擾����G</param>
/// <returns></returns>
bool EnemyManager::GetEnemyIsAlive(int enemyNum) {
	return enemy[enemyNum]->GetEnemyIsAlive();
}

/// <summary>
/// �����̓G�̍��W���擾����Q�b�^�[
/// </summary>
/// <param name="enemyNum">�擾����G</param>
/// <returns></returns>
Vector2 EnemyManager::GetEnemyTranslate(int enemyNum) {
	return enemy[enemyNum]->GetEnemyTranslate();
}

/// <summary>
/// �����̓G�̑傫�����擾����Q�b�^�[
/// </summary>
/// <param name="enemyNum">�擾����G</param>
/// <returns></returns>
Vector2 EnemyManager::GetEnemySize(int enemyNum) {
	return enemy[enemyNum]->GetEnemySize();
}

int EnemyManager::GetKillCount() {
	return EnemyManager::enemyKillCount;
}

/// <summary>
/// �����̓G�̐�����Ԃ�ύX����Z�b�^�[
/// </summary>
/// <param name="enemyNum">�Z�b�g����G</param>
/// <param name="isAlive">�g���K�[�ݒ�</param>
void EnemyManager::setEnemyIsAlive(int enemyNum, bool isAlive) {
	enemy[enemyNum]->SetEnemyIsAlive(isAlive);
}

/// <summary>
/// �����̓G�̍��W���Z�b�g����Z�b�^�[
/// </summary>
/// <param name="enemyNum">�ݒ肷��G</param>
/// <param name="translate">�ݒ肷����W</param>
void EnemyManager::SetEnemyTranslate(int enemyNum, Vector2 translate) {
	enemy[enemyNum]->SetEnemyTranslate(translate);
}

/// <summary>
/// �G�̃X�|�[�����ɌĂяo�����֐�
/// </summary>
/// <param name="enemyNum">�X�|�[��������G</param>
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
/// �G�̎��S���ɌĂяo����鏈��
/// </summary>
/// <param name="enemyNum">���S������G</param>
void EnemyManager::DeadEnemy(int enemyNum) {

	// �G��|�����ۂɃv���X����
	enemyKillCount++;

	Novice::PlayAudio(downSE, 0, 0.35f);

	// �G����ʂ������
	enemy[enemyNum]->SetEnemyTranslate({ 110000,110000 });
	enemy[enemyNum]->SetEnemyIsAlive(false);
}

/// <summary>
/// �G���v���C���[�ƏՓ˂��Ă��邩�ǂ��������m����
/// </summary>
/// <param name="enemyNum">���m����G</param>
void EnemyManager::HitPlayer(int enemyNum, Player* player) {

	// ���W�擾
	Vector2 enemyPosition = enemy[enemyNum]->GetEnemyTranslate();
	Vector2 playerPosition = player->GetPlayerPos();

	// �T�C�Y�擾
	Vector2 enemySize = enemy[enemyNum]->GetEnemySize();
	Vector2 playerSize = player->GetPlayerSize();

	// �v���C���[�Ƃ̋��������߂�
	Vector2 e2p = {
		enemyPosition.x - playerPosition.x,
		enemyPosition.y - playerPosition.y
	};

	float distance = sqrt(pow(e2p.x, 2) + pow(e2p.y, 2));

	// �Փ˔���
	if (distance < enemySize.x / 2 + playerSize.x / 2) {
		enemy[enemyNum]->SetEnemyNockBack(20.0f, true);
		Novice::PlayAudio(hitSE, 0, 0.25f);
	}

}

/// <summary>
/// �G���e�ƏՓ˂��Ă��邩�ǂ��������m����֐�
/// </summary>
/// <param name="enemyNum">���m����G</param>
/// <param name="bulletNum">���m����e</param>
/// <param name="bullet">�e�̃|�C���^</param>
void EnemyManager::HitEnemy(int enemyNum, int bulletNum, BulletManager* bullet) {
	// ���W�擾
	Vector2 enemyPosition = enemy[enemyNum]->GetEnemyTranslate();
	Vector2 bulletPosition[kMaxShotBullet];

	// �T�C�Y�擾
	Vector2 enemySize = enemy[enemyNum]->GetEnemySize();
	Vector2 bulletSize[kMaxShotBullet];

	for (int i = 0; i < kMaxShotBullet; i++) {
		// �e�̍��W���擾
		bulletPosition[i] = bullet->GetBulletPosition(i);
		// �e�̃T�C�Y���擾
		bulletSize[i] = bullet->GetBulletSize(i);
	}

	// �e�Ƃ̋��������߂�
	Vector2 e2b[kMaxShotBullet];
	
	float distance[kMaxShotBullet];

	for (int i = 0; i < kMaxShotBullet; i++) {
		e2b[i] = {
			enemyPosition.x - bulletPosition[i].x,
			enemyPosition.y - bulletPosition[i].y
		};
		distance[i] = sqrt(pow(e2b[i].x, 2) + pow(e2b[i].y, 2));

		if (distance[i] < enemySize.x / 2 + bulletSize[i].x / 2) {
			// �e������
			bullet[i].SetBulletIsShot(i, false);
			bullet[i].SetBulletPosition(i, { 10000, 10000 });

			DeadEnemy(enemyNum);
		}

	}

}

// �����o�ϐ��̎��̂�錾
int EnemyManager::enemyKillCount;
int EnemyManager::downSE;
int EnemyManager::hitSE;
Enemy* EnemyManager::enemy[kMaxSpawnEnemy];
