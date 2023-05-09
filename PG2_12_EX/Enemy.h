#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
#include "Player.h"
#include "Bullet.h"
class Enemy
{
public:
	// �R���X�g���N�^
	Enemy();

	// ����������
	void Initialize();

	// �X�V����
	void Update(Player* player);

	// �`�揈��
	void Draw();

	// ���W�̃Q�b�^�[
	Vector2 GetEnemyTranslate() { return translate; }

	// �傫���̃Q�b�^�[
	Vector2 GetEnemySize() { return size; }

	// ������Ԃ̃Q�b�^�[
	bool GetEnemyIsAlive() { return isAlive; }

	// ���W�̃Z�b�^�[
	void SetEnemyTranslate(Vector2 translate) { this->translate = translate; }

	// �����g���K�[�̃Z�b�^�[
	void SetEnemyIsAlive(bool isAlive) { this->isAlive = isAlive; }

	// �X�s�[�h�̃Z�b�^�[
	void SetEnemySpeed(Vector2 speed) { this->speed = speed; }

	// �m�b�N�o�b�N��Ԃ̃Z�b�^�[
	void SetEnemyNockBack(float nockBackSpeed, bool isNockBacking) { this->nockBackSpeed = nockBackSpeed, this->isNockBacking = isNockBacking; }

private:
	// ���S���W
	Vector2 translate;
	// �T�C�Y
	Vector2 size;

	// ��]���S
	Quad point;
	// ��]����W
	Quad rotate;
	// �v���C���[�p�x
	float theta;

	// �X�s�[�h
	Vector2 speed;

	// �������Ă��邩�ǂ���
	bool isAlive;

	// �m�b�N�o�b�N���Ă��邩
	bool isNockBacking;

	// �m�b�N�o�b�N���̃X�s�[�h
	float nockBackSpeed;

	// �e�N�X�`��
	int texture;
	// �e�N�X�`���T�C�Y
	Vector2 textureSize;
	// �F
	unsigned int color;

};

