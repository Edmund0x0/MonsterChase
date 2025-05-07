#include "Input.h"
#include "winuser.h"

Input::Input()
{

}

unsigned int PLAYERONEKEYPRESS;
unsigned int PLAYERTWOKEYPRESS;

unsigned int KEYUP = 0x57;
unsigned int KEYDOWN = 0x53;
unsigned int KEYLEFT = 0x41;
unsigned int KEYRIGHT = 0x44;

unsigned int KEYNONE = 0xFF;

unsigned int LEFTARROW = 0x4A;
unsigned int UPARROW = 0x49;
unsigned int RIGHTARROW = 0x4C;
unsigned int DOWNARROW = 0x4B;



void KeyPress(unsigned int i_VKeyID, bool bWentDown)
{
#ifdef _DEBUG
	const size_t	lenBuffer = 65;
	char			Buffer[lenBuffer];

	sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
	OutputDebugStringA(Buffer);

	// Player One
	if (i_VKeyID == KEYUP)
	{
		if (bWentDown)
		{
			PLAYERONEKEYPRESS = KEYUP;
		}
		else
		{
			PLAYERONEKEYPRESS = KEYNONE;
		}
	}
	if (i_VKeyID == KEYDOWN)
	{
		if (bWentDown)
		{
			PLAYERONEKEYPRESS = KEYDOWN;
		}
		else
		{
			PLAYERONEKEYPRESS = KEYNONE;
		}
	}
	/*if (i_VKeyID == KEYLEFT)
	{
		if (bWentDown)
		{
			PLAYERONEKEYPRESS = KEYLEFT;
		}
		else
		{
			PLAYERONEKEYPRESS = KEYNONE;
		}
	}
	if (i_VKeyID == KEYRIGHT)
	{
		if (bWentDown)
		{
			PLAYERONEKEYPRESS = KEYRIGHT;
		}
		else
		{
			PLAYERONEKEYPRESS = KEYNONE;
		}
	}*/

	// Player TWO
	if (i_VKeyID == UPARROW)
	{
		if (bWentDown)
		{
			PLAYERTWOKEYPRESS = UPARROW;
		}
		else
		{
			PLAYERTWOKEYPRESS = KEYNONE;
		}
	}
	if (i_VKeyID == DOWNARROW)
	{
		if (bWentDown)
		{
			PLAYERTWOKEYPRESS = DOWNARROW;
		}
		else
		{
			PLAYERTWOKEYPRESS = KEYNONE;
		}
	}
	/*if (i_VKeyID == LEFTARROW)
	{
		if (bWentDown)
		{
			PLAYERTWOKEYPRESS = LEFTARROW;
		}
		else
		{
			PLAYERTWOKEYPRESS = KEYNONE;
		}
	}
	if (i_VKeyID == RIGHTARROW)
	{
		if (bWentDown)
		{
			PLAYERTWOKEYPRESS = RIGHTARROW;
		}
		else
		{
			PLAYERTWOKEYPRESS = KEYNONE;
		}
	}*/
#endif // __DEBUG
}


void Movement(GameObject& io_Object)
{
	if (io_Object.playerOne)
	{
		if ((PLAYERONEKEYPRESS == KEYUP))
		{
			io_Object.moveVer = true;
			if (io_Object.force > 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}

		if ((PLAYERONEKEYPRESS == KEYDOWN))
		{
			io_Object.moveVer = true;
			if (io_Object.force < 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}
	

		/*if ((PLAYERONEKEYPRESS == KEYRIGHT))
		{
			io_Object.moveHor = true;
			if (io_Object.force > 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}

		if ((PLAYERONEKEYPRESS == KEYLEFT))
		{
			io_Object.moveHor = true;
			if (io_Object.force < 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}*/
	}

	if (io_Object.playerTwo)
	{
		if ((PLAYERTWOKEYPRESS == UPARROW))
		{
			io_Object.moveVer = true;
			if (io_Object.force > 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}

		if ((PLAYERTWOKEYPRESS == DOWNARROW))
		{
			io_Object.moveVer = true;
			if (io_Object.force < 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}

	/*	if ((PLAYERTWOKEYPRESS == RIGHTARROW))
		{
			io_Object.moveHor = true;
			if (io_Object.force > 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}

		if ((PLAYERTWOKEYPRESS == LEFTARROW))
		{
			io_Object.moveHor = true;
			if (io_Object.force < 0)
			{
				io_Object.force *= 1;
			}
			else
			{
				io_Object.force *= -1;
			}
		}*/
	}
}


void Input::CheckForInput(std::shared_ptr<GameObject> io_Object)
{
	GLib::SetKeyStateChangeCallback(KeyPress);
	Movement(*io_Object);
}

