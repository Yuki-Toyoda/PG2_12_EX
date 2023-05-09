#include "Player.h"

// �R���X�g���N�^
Player::Player() {
	

}

// �f�X�g���N�^
Player::~Player() {

}

// ����������
void Player::Initialize() {
	// ���W������
	translate = { (float)kWindowWidth / 2, (float)kWindowHeight / 2 };
	// �T�C�Y
	size = { 96.0f, 96.0f };

	// ���e�B�N�����W
	reticlePos = { 0.0f, 0.0f };
	// ���e�B�N���T�C�Y
	reticleSize = { 16.0f, 16.0f };

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

	// �p�x��ύX���邽�߂̃}�E�X���W
	mousePosition = { 0.0f, 0.0f };

	// �X�s�[�h
	speed = { 5.0f, 5.0f };
	// ����x�N�g��
	moveVector = { 0.0f, 0.0f };
	// �x�N�g���̒���
	vectorLength = 0.0f;

	// �e�����ˉ\�ȏ�Ԃ�
	canShot = true;

	// �e�N�X�`��
	texture = Novice::LoadTexture("./Resources/Graph/Player.png");
	// �e�N�X�`���T�C�Y
	textureSize = { 256.0f, 256.0f };

	// �F
	color = 0xFFFFFFFF;

	// ���e�B�N���e�N�X�`��
	reticleTex = Novice::LoadTexture("./Resources/Graph/Reticle.png");
	// ���e�B�N���摜�T�C�Y
	reticleTexSize = { 128.0f, 128.0f };

	shotSE = Novice::LoadAudio("./Resources/SE/Shot.wav");

}

// �X�V����
void Player::Update() {

	// �}�E�X���W�擾
	mousePosition = KeyInput::GetMousePosition();
	
	// ���e�B�N�����}�E�X���W��
	reticlePos = mousePosition;

	// �}�E�X���W�ƃv���C���[�̊p�x�����߂�
	theta = atan2(mousePosition.y - translate.y, mousePosition.x - translate.x);

	// �v���C���[��]����
	rotate.q1.x = point.q1.x * cosf(theta) - point.q1.y * sinf(theta) + translate.x;
	rotate.q1.y = point.q1.y * cosf(theta) + point.q1.x * sinf(theta) + translate.y;

	rotate.q2.x = point.q2.x * cosf(theta) - point.q2.y * sinf(theta) + translate.x;
	rotate.q2.y = point.q2.y * cosf(theta) + point.q2.x * sinf(theta) + translate.y;

	rotate.q3.x = point.q3.x * cosf(theta) - point.q3.y * sinf(theta) + translate.x;
	rotate.q3.y = point.q3.y * cosf(theta) + point.q3.x * sinf(theta) + translate.y;

	rotate.q4.x = point.q4.x * cosf(theta) - point.q4.y * sinf(theta) + translate.x;
	rotate.q4.y = point.q4.y * cosf(theta) + point.q4.x * sinf(theta) + translate.y;

	// ��ʊO�ɍs���Ȃ��悤��
	// x
	if (translate.x > kWindowWidth - size.x / 2) {
		translate.x = kWindowWidth - size.x / 2;
	}
	else if (translate.x < 0 + size.x / 2) {
		translate.x = size.x / 2;
	}

	// y
	if (translate.y > kWindowHeight - size.y / 2) {
		translate.y = kWindowHeight - size.y / 2;
	}
	else if (translate.y < 0 + size.y / 2) {
		translate.y = size.y / 2;
	}

	// �v���C���[�̓��쏈��
	Player::Move();

	// �ˌ�����
	if (this->shotRate > 0.0f) {
		shotRate -= 1.0 / 60.0f;
	}
	else {
		canShot = true;
	}

	if (canShot == true) {
		if (KeyInput::GetKeyboardState(DIK_SPACE, Press) || Novice::IsPressMouse(0) == true) {
			Shot();
			canShot = false;
			shotRate = kShotRate;
		}
	}
}

// �`�揈��
void Player::Draw() {
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

	// ���e�B�N���`��
	Novice::DrawQuad(
		reticlePos.x - reticleSize.x, reticlePos.y - reticleSize.y,
		reticlePos.x + reticleSize.x, reticlePos.y - reticleSize.y,
		reticlePos.x - reticleSize.x, reticlePos.y + reticleSize.y,
		reticlePos.x + reticleSize.x, reticlePos.y + reticleSize.y,
		0, 0,
		reticleTexSize.x, reticleTexSize.y,
		reticleTex,
		0xFFFFFFFF
	);
}

/// <summary>
/// �ˌ�����
/// </summary>
void Player::Shot() {
	for (int i = 0; i < kMaxShotBullet; i++) {
		if (BulletManager::GetBulletIsShot(i) == false) {
			Novice::PlayAudio(shotSE, 0, 0.25f);
			BulletManager::SetShotInitialize(i, translate, theta);
			break;
		}
	}
}

/// <summary>
///	�v���C���[�̓�����s���ϐ�
/// </summary>
void Player::Move() {

	// �x�N�g��������
	moveVector.x = 0.0f;
	moveVector.y = 0.0f;

	// �ړ�
	// ��
	if (KeyInput::GetKeyboardState(DIK_W, Press)) {
		moveVector.y--;
	}
	// ��
	if (KeyInput::GetKeyboardState(DIK_A, Press)) {
		moveVector.x--;
	}
	// ��
	if (KeyInput::GetKeyboardState(DIK_S, Press)) {
		moveVector.y++;
	}
	// �E
	if (KeyInput::GetKeyboardState(DIK_D, Press)) {
		moveVector.x++;
	}

	// �x�N�g���̒��������߂�
	vectorLength = sqrt((moveVector.x * moveVector.x)
		+ (moveVector.y * moveVector.y));

	//�x�N�g���̒�����0�ȊO�̎�
	if (vectorLength != 0.0f) {

		//�v���C���[��x���W��x�����̃x�N�g���ƃx�N�g���̒���������A�X�s�[�h�������đ���
		translate.x += moveVector.x / vectorLength * speed.x;
		//�v���C���[��y���W��y�����̃x�N�g���ƃx�N�g���̒���������A�X�s�[�h�������đ���
		translate.y += moveVector.y / vectorLength * speed.y;

	}
	else {

		translate.x += moveVector.x * speed.x;
		translate.y += moveVector.y * speed.y;

	}

}
