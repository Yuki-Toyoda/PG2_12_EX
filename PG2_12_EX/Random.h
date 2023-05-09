#pragma once
#include <stdlib.h>
#include <math.h>
#include <time.h>

// srand�Z�b�g�֐�
// �Ԃ�l�F�Ȃ�
// �����Ȃ�
// �w�肳�ꂽ�͈͓��̃����_���Ȓl��Ԃ��֐�(int�^)
static void SetSrand() {
    srand(static_cast<unsigned int>(time(NULL)));
}

// �����_���֐��iint�^�j
// �Ԃ�l�F�����_���̒l�iint�^�j
// �����F
// min ... �ŏ��l
// max ... �ő�l
// �w�肳�ꂽ�͈͓��̃����_���Ȓl��Ԃ��֐�(int�^)
static int Random(int min, int max) {
    return min + static_cast<int>(rand() * static_cast<float>(max - min + 1.0f) / static_cast<float>(1.0f + RAND_MAX));
}

// �����_���֐��ifloat�^�j
// �Ԃ�l�F�����_���̒l�ifloat�^�j
// �����F
// min ... �ŏ��l
// max ... �ő�l
// num ... �����_�����܂ŕ\�����邩
// �w�肳�ꂽ�����ŁA�͈͓��̃����_���Ȓl��Ԃ��֐�(float�^)
static float RandomF(float min, float max, int num) {
    int Num = pow(10, num);
    return static_cast<float>(Random(static_cast<int>(max * Num), static_cast<int>(min * Num)) * (1.0f / static_cast<float>(Num)));
}
