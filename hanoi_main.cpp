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
	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
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
