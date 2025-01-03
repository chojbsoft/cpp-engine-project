#include "pch.h"
#include "KeyManager.h"

int arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'Z',
	'X',
	'C',
	'V',
	'B',
	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
};

KeyManager::KeyManager()
{

}

KeyManager::~KeyManager()
{

}

void KeyManager::Init()
{
	// 초기화
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		vecKey.push_back({ KEY_STATE::NONE, false });
	}
}

void KeyManager::Update()
{
	// 현재 포커싱되어 있는 윈도우 핸들값 알려줌
	// 프로세스 상에서 보유하고 있는 윈도우가 없다면 nullptr나옴
	HWND hWnd = GetFocus();

	if (hWnd)
	{
		// 키입력 받기
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// 현재 프레임 눌림
			if (GetAsyncKeyState(arrVK[i]) & 0x8000)
			{
				if (vecKey[i].bPrev)
				{
					vecKey[i].eState = KEY_STATE::HOLD;
				}
				else
				{
					vecKey[i].eState = KEY_STATE::TAP;
				}

				vecKey[i].bPrev = true;
			}

			// 현재 프레임 안눌림
			else
			{
				if (vecKey[i].bPrev)
				{
					vecKey[i].eState = KEY_STATE::AWAY;
				}
				else
				{
					vecKey[i].eState = KEY_STATE::NONE;
				}

				vecKey[i].bPrev = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			vecKey[i].bPrev = false;

			if (vecKey[i].eState == KEY_STATE::TAP
				|| vecKey[i].eState == KEY_STATE::HOLD)
			{

				vecKey[i].eState = KEY_STATE::AWAY;
			}
			else if (vecKey[i].eState == KEY_STATE::AWAY)
			{
				vecKey[i].eState == KEY_STATE::NONE;
			}
		}
	}
}
