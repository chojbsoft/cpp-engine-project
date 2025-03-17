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
	// �ʱ�ȭ
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		vecKey.push_back({ KEY_STATE::NONE, false });
	}
}

void KeyManager::Update()
{
	// ���� ��Ŀ�̵Ǿ� �ִ� ������ �ڵ鰪 �˷���
	// ���μ��� �󿡼� �����ϰ� �ִ� �����찡 ���ٸ� nullptr����
	HWND hWnd = GetFocus();

	if (hWnd)
	{
		// Ű�Է� �ޱ�
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			// ���� ������ ����
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

			// ���� ������ �ȴ���
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
