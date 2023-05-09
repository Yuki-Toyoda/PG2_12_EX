#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy() {

}

// ����������
void Enemy::Initialize() {
	// ���W������
	translate = { 110000, 110000 };
	// �T�C�Y
	size = { 64.0f, 64.0f };

	// ��]���S
	point = {
		-size.x / 2, -size.y / 2,
		size.x / 2, -size.y / 2,
		-size.x / 2, size.y / 2,
		size.x / 2, size.y / 2
	};

	// ��]����W
	rotate = {
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 0.0f
	};

	// �v���C���[�p�x
	theta = 0.0f;

	// �X�s�[�h
	speed = { 1.0f, 1.0f };

	// ����
	isAlive = false;

	// �m�b�N�o�b�N
	isNockBacking = false;

	// �m�b�N�o�b�N���̃X�s�[�h
	nockBackSpeed = 0.0f;

	// �e�N�X�`��
	texture = Novice::LoadTexture("./Resources/Graph/Enemy.png");
	// �e�N�X�`���T�C�Y
	textureSize = { 256.0f, 256.0f };

	// �F
	color = 0xFFFFFFFF;

}

// �X�V����
void Enemy::Update(Player* player) {

	Vector2 PlayerTranslate = player->GetPlayerPos();

	// �}�E�X���W�ƃv���C���[�̊p�x�����߂�
	theta = atan2(PlayerTranslate.y - translate.y, PlayerTranslate.x - translate.x);

	// �v���C���[��]����
	rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
	rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

	rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
	rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

	rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
	rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

	rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
	rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

	// �������̏���
	if (isAlive == true) {
		if (isNockBacking == true) {
			// �m�b�N�o�b�N����
			translate.x += -(cosf(theta) * nockBackSpeed);
			translate.y += -(sinf(theta) * nockBackSpeed);

			// �m�b�N�o�b�N�X�s�[�h�������Â�����
			nockBackSpeed--;

		}
		else {
			// �ړ�����
			translate.x += (cosf(theta) * speed.x);
			translate.y += (sinf(theta) * speed.y);
		}
		
	}

	if (nockBackSpeed < 0) {
		isNockBacking = false;
		nockBackSpeed = 0.0f;
	}

}

// �`�揈��
void Enemy::Draw() {
	// �v���C���[�̕`��
	Novice::DrawQuad(
		rotate.q1.x, rotate.q1.y,
		rotate.q2.x, rotate.q2.y,
		rotate.q3.x, rotate.q3.y,
		rotate.q4.x, rotate.q4.y,
		0.0f, 0.0f,
		textureSize.x, textureSize.y,
		texture,
		color
	);

}
