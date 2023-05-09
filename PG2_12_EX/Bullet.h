#pragma once
#include <Novice.h>
#include "Const.h"
#include "Struct.h"
#include "KeyInput.h"
class Bullet
{
public:

	// �R���X�g���N�^
	Bullet();
	
	// �f�X�g���N�^
	~Bullet();

	// ����������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	// ���˒������擾����Q�b�^�[
	bool GetIsShot() { return isShot; }

	// ���S���W���擾����Q�b�^�[
	Vector2 GetPosition() { return translate; }

	// �傫�����擾����Q�b�^�[
	Vector2 GetSize() { return size; }

	// �ʒu�����肷��Z�b�^�[
	void SetPosition(Vector2 position) { this->translate = position; }

	// �p�x�̃Z�b�^�[
	void SetTheta(float theta) { this->theta = theta; }

	// ���ˏ�Ԃ̃Z�b�^�[
	void SetIsShot(bool isShot) { this->isShot = isShot; }

private:

	// ���S���W
	Vector2 translate;
	// �T�C�Y
	Vector2 size;

	// ��]���S
	Quad point;
	// ��]����W
	Quad rotate;
	// �p�x
	float theta;

	// ���˃X�s�[�h
	Vector2 speed;

	// ���˂���Ă��邩�̃g���K�[
	bool isShot;

	// �e�N�X�`��
	int texture;
	// �e�N�X�`���T�C�Y
	Vector2 textureSize;
	
};

