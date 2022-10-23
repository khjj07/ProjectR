#include "gamePad.h"

void GamePad::GetState()
{
	Sleep(30);	// CPU ������ 100%�� �����ϱ� ����
	result = XInputGetState(id, &state);
}

void GamePad::Update()
{
	result = XInputGetState(id, &state);
}

GamePad::GamePad(int x)
{
	id = x;
	ZeroMemory(&state, sizeof(XINPUT_STATE));
}





// /// �е� ��ƽ Ű
//x = state.Gamepad.sThumbLX;	// ���� ��ƽ X��
//y = state.Gamepad.sThumbLY;	// ���� ��ƽ Y��
//state.Gamepad.sThumbRX;	// ������ ��ƽ X��
//state.Gamepad.sThumbRY;	// ������ ��ƽ Y��

/// Ű�ڵ� Ȯ�ο�
// �е� ����Ű
//#define XINPUT_GAMEPAD_DPAD_UP          0x00000001
//#define XINPUT_GAMEPAD_DPAD_DOWN        0x00000002
//#define XINPUT_GAMEPAD_DPAD_LEFT        0x00000004
//#define XINPUT_GAMEPAD_DPAD_RIGHT       0x00000008
//#define XINPUT_GAMEPAD_START            0x00000010
//#define XINPUT_GAMEPAD_BACK             0x0020
//#define XINPUT_GAMEPAD_LEFT_THUMB       0x0040
//#define XINPUT_GAMEPAD_RIGHT_THUMB      0x0080
//#define XINPUT_GAMEPAD_LEFT_SHOULDER    0x0100
//#define XINPUT_GAMEPAD_RIGHT_SHOULDER   0x0200
//#define XINPUT_GAMEPAD_A                0x1000
//#define XINPUT_GAMEPAD_B                0x2000
//#define XINPUT_GAMEPAD_X                0x4000
//#define XINPUT_GAMEPAD_Y                0x8000