#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include"hanoi.h"
#include<conio.h>
#include<limits>
using namespace std;
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1)
	{
		int fanhui = menu();
		if (fanhui == 1)
			solution_one();
		if (fanhui == 2)
			solution_two();
		if (fanhui == 3)
			solution_three();
		if (fanhui == 4)
			solution_four();
		if (fanhui == 5)
			solution_five();
		if (fanhui == 6)
			solution_six();
		if (fanhui == 7)
			solution_seven();
		if (fanhui == 8)
			solution_eight();
		if (fanhui == 9)
			solution_night();
		if (fanhui == 0)
			break;
	}
	return 0;
}
