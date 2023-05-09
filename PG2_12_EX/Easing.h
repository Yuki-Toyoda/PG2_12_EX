#pragma once
#include <math.h>

//�ʏ�
static float ConstantLinear(float t, float start, float end) {
	return (1.0 - t) * start + t * end;
}

//�C�[�Y�C��
static float EaseIn(float t, float start, float end) {
	float easeT = t * t;
	return (1.0 - easeT) * start + easeT * end;
}

//�C�[�Y�A�E�g
static float EaseOut(float t, float start, float end) {
	float easeT = 1.0f - powf(1.0f - t, 3.0f);
	return (1.0 - easeT) * start + easeT * end;
}

//�C�[�Y�A�E�g�iInt�^�j
static int IntEaseOut(float t, long int b, long int c) {
	float easeT = 1.0f - powf(1.0f - t, 3.0f);
	return (1.0f - easeT) * b + easeT * c;
}

//�J���[�C�[�W���O
static unsigned int ColorEasing(float t, unsigned int startColor, unsigned int endColor) {
	unsigned int red = IntEaseOut(t, (((startColor & 0xFF000000) >> 24) & 0xFF), (((endColor & 0xFF000000) >> 24) & 0xFF));
	unsigned int green = IntEaseOut(t, (((startColor & 0x00FF0000) >> 16) & 0xFF), (((endColor & 0x00FF0000) >> 16) & 0xFF));
	unsigned int blue = IntEaseOut(t, (((startColor & 0x0000FF00) >> 8) & 0xFF), (((endColor & 0x0000FF00) >> 8) & 0xFF));
	unsigned int alpha = IntEaseOut(t, (((startColor & 0x000000FF)) & 0xFF), (((endColor & 0x000000FF)) & 0xFF));

	unsigned int color = IntEaseOut(t, (startColor & 0xFF), (endColor & 0xFF));
	return (red << 24) + (green << 16) + (blue << 8) + alpha;
}
