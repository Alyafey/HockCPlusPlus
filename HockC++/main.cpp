#include<Windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

HHOOK Hock = NULL;
string GetKey(int key);

LRESULT CALLBACK KeyHock ( int nCode , WPARAM wParam , LPARAM lParam)
{
	KBDLLHOOKSTRUCT *kbdStruct = (KBDLLHOOKSTRUCT*)lParam;

	if(wParam == 257) //check key up
	{
		//char key = (char)kbdStruct->vkCode;
		//int keyk = kbdStruct->vkCode;
		//system("CLS") ;
		//printf("%d\n",kbdStruct->vkCode);
		printf("The Pressed key is: %s\n",GetKey(kbdStruct->vkCode).c_str());
	}
		return CallNextHookEx(Hock , nCode ,wParam , lParam);
}



int main()
{
    MSG msg;
	Hock = SetWindowsHookEx(WH_KEYBOARD_LL, KeyHock , NULL,NULL);

    while(!GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
	
    UnhookWindowsHookEx(Hock);
} 

string GetKey(int key)
{

	char result[20]="";

	switch (key)
	{
	case 0:
		strcpy(result,"Null");
		break;
	case 8:
		strcpy(result,"Back Space");
		break;
	case 9:
		strcpy(result,"Tap");
		break;
	case 13:
		strcpy(result,"Enter");
		break;
	case 19:
		strcpy(result,"Pause Break");
		break;
	case 20:
		strcpy(result,"CAPSE LOCK");
		break;
	case 27:
		strcpy(result,"Escape");
		break;
	case 32:
		strcpy(result,"Space");
		break;
	case 33:
		strcpy(result,"Page UP");
		break;
	case 34:
		strcpy(result,"Page Down");
		break;
	case 35:
		strcpy(result,"End");
		break;
	case 36:
		strcpy(result,"Home");
		break;
	case 37:
		strcpy(result,"Left");
		break;
	case 38:
		strcpy(result,"Up");
		break;
	case 39:
		strcpy(result,"Right");
		break;
	case 40:
		strcpy(result,"Down");
		break;
	case 44:
		strcpy(result,"PRSTSC SYSRQ");
		break;
	case 45:
		strcpy(result,"INS");
		break;
	case 46:
		strcpy(result,"DEL");
		break;
	case 91:
		strcpy(result,"Windows Key");
		break;
	case 93:
		strcpy(result,"Menu");
		break;
	case 160:
		strcpy(result,"Left Shift");
		break;
	case 161:
		strcpy(result,"Right Shift");
		break;
	case 162:
		strcpy(result,"Left Control");
		break;
	case 163:
		strcpy(result,"Right Control");
		break;
	case 164:
		strcpy(result,"Left Alt");
		break;
	case 165:
		strcpy(result,"Righ Alt");
		break;
	case 186:
		strcpy(result,"Semicolon");
		break;
	case 187:
		strcpy(result,"Plus");
		break;
	case 188:
		strcpy(result,"Comma");
		break;
	case 189:
		strcpy(result,"Minus");
		break;
	case 190:
		strcpy(result,"Period");
		break;
	case 191:
		strcpy(result,"Question");
		break;
	case 192:
		strcpy(result,"Tilde");
		break;
	case 219:
		strcpy(result,"Open Brackets");
		break;
	case 220:
		strcpy(result,"BAck Slash");
		break;
	case 221:
		strcpy(result,"Close Brackets");
		break;
	case 222:
		strcpy(result,"Quotation");
		break;
	default:
		if(key >=48 && key <=90)
		{
			result[0]= (char)key;
		}else if(key >=112 && key <=123)
		{
			int temp =key-63;
			if(temp >=49 && temp <=57){
				result[0] = 'F';
				result[1] = temp;
			}
			else if( temp >=58 && temp <=71)
			{
				result[0] = 'F';
				result[1] = 49;
				result[2] = (temp-10);
			}
		}
		else
		{
			strcpy(result,"Undefined");
		}
		break;
	}	

	return result;
}