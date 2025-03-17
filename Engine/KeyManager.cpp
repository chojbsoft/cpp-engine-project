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
		_keys.push_back({ KEY_STATE::NONE, false });
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
				if (_keys[i]._isPrev)
				{
					_keys[i]._state = KEY_STATE::HOLD;
				}
				else
				{
					_keys[i]._state = KEY_STATE::TAP;
				}

				_keys[i]._isPrev = true;
			}

			// ���� ������ �ȴ���
			else
			{
				if (_keys[i]._isPrev)
				{
					_keys[i]._state = KEY_STATE::AWAY;
				}
				else
				{
					_keys[i]._state = KEY_STATE::NONE;
				}

				_keys[i]._isPrev = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			_keys[i]._isPrev = false;

			if (_keys[i]._state == KEY_STATE::TAP
				|| _keys[i]._state == KEY_STATE::HOLD)
			{

				_keys[i]._state = KEY_STATE::AWAY;
			}
			else if (_keys[i]._state == KEY_STATE::AWAY)
			{
				_keys[i]._state == KEY_STATE::NONE;
			}
		}
	}
}
