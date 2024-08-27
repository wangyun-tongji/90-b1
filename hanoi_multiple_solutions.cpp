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
int stack[3][10]={0};
int number[3] = {0};
void initlize(int& layer, char& src, char& tmp, char& dst)
{
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> layer;
		if (layer > 10 || layer < 1)
		{
			cin.clear();
			cin.ignore(65536, '\n');
			;
		}
		else
			break;
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)：" << endl;
		cin.ignore(65536, '\n');
		cin >> src;
		if (src == 'A' || src == 'a')
		{
			src = 'A';
			break;
		}
		if (src == 'B' || src == 'b')
		{
			src = 'B';
			break;
		}
		if (src == 'C' || src == 'c')
		{
			src = 'C';
			break;
		}
		if (src != 'A' && src != 'a' &&
			src != 'B' && src != 'b' &&
			src != 'C' && src != 'c')
		{
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)：" << endl;
		cin.ignore(65536, '\n');
		cin >> dst;
		if ((dst == 'A' || dst == 'a') && src != 'A')
		{
			dst = 'A';
			break;
		}
		if ((dst == 'B' || dst == 'b') && src != 'B')
		{
			dst = 'B';
			break;
		}
		if ((dst == 'C' || dst == 'c') && src != 'C')
		{
			dst = 'C';
			break;
		}
		if (dst != 'A' && dst != 'a' &&
			dst != 'B' && dst != 'b' &&
			dst != 'C' && dst != 'c')
		{
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (1)
	{
		if (src != 'C' && dst != 'C')
			tmp = 'C';
		if (src != 'B' && dst != 'B')
			tmp = 'B';
		if (src != 'A' && dst != 'A')
			tmp = 'A';
		break;
	}

}
void one_move(int layer, char src, char tmp, char dst)
{
	if (layer == 1)
	{
		cout << setw(2) << layer << "#" << src << "-->" << dst << endl;
	}
	else
	{
		one_move(layer - 1, src, dst, tmp);
		cout << setw(2) << layer << "#" << src << "-->" << dst << endl;
		one_move(layer - 1, tmp, src, dst);
	}
}
void solution_one()
{
	int layer;
	char src, dst, tmp;
	initlize(layer, src, tmp, dst);
	one_move(layer - 1, src, tmp, dst);
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void solution_two()
{
	int layer = 0;
	char src = '0';
	char tmp = '0';
	char dst = '0';
	initlize(layer, src, tmp, dst);
	two_move(layer, src, tmp, dst);
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void two_move(int layer, char src, char tmp, char dst)
{
	static int i = 0;
	if (layer == 1)
	{
		cout << "第" << setiosflags(ios::right) << setw(4) << ++i << "步（";
		cout << layer << "#" << src << "--->" << dst<< ")" << endl;
	}
	else
	{
		two_move(layer - 1, src, dst, tmp);
		cout << "第" << setiosflags(ios::right) << setw(4) << ++i << "步（";
		cout << layer << "#" << src << "--->" << dst << ")" << endl;
		two_move(layer - 1, tmp, src, dst);
	}
}
void three_move(int layer, char src, char tmp, char dst)
{
	static int a = 0;
	static int i = 1;
	if (layer == 1)
	{
		cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
		a = stack[src - 'A'][--number[src - 'A']];
		stack[dst - 'A'][number[dst - 'A']++] = a;
		stack[src - 'A'][number[src - 'A']] = 0;
		for (int i = 0; i < 3; i++)
		{
			cout << char(65 + i) << ":";
			for (int j = 0; j < 10; j++)
			{
				if (stack[i][j] == 0)
					cout << "  ";
				else
					cout << stack[i][j] << " ";
			}
			if (i == 2)
				cout << endl;
			else
				;
		}
	}
	else
	{
		three_move(layer-1, src, dst, tmp);
		cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
		a = stack[src - 'A'][--number[src - 'A']];
		stack[dst - 'A'][number[dst - 'A']++] = a;
		stack[src - 'A'][number[src - 'A']] = 0;
		for (int i = 0; i < 3; i++)
		{
			cout << char(65 + i) << ":";
			for (int j = 0; j < 10; j++)
			{
				if (stack[i][j] == 0)
					cout << "  ";
				else
					cout << stack[i][j] << " ";
			}
			if (i == 2)
				cout << endl;
			else
				;
		}
		three_move(layer-1, tmp, src, dst);
	}
}
void solution_three()
{
	int layer;
	char src, tmp, dst;
	initlize(layer, src, tmp, dst);
	number[src - 'A'] = layer;
	number[tmp - 'A'] = 0;
	number[dst - 'A'] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i])
			{
				if (j <= layer)
					stack[i][j] = layer - j;
				else
					stack[i][j] = 0;
			}
			else
				stack[i][j] = 0;
		}
	}
	three_move(layer, src, tmp, dst);
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void four_move(int layer,int is_delay, char src, char tmp, char dst)
{
	static int t = 0;
	static int i = 1;
	if (is_delay == 0)
	{
		if (layer == 1)
		{
			while (getchar() != '\n')
				;
			cct_gotoxy(0, Z);
			cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
			t = stack[src - 'A'][--number[src - 'A']];
			stack[dst - 'A'][number[dst - 'A']++] = t;
			stack[src - 'A'][number[src - 'A']] = 0;
			cct_gotoxy(A+(src-'A')*10, X - number[src - 'A']);
			cout << " ";
			cct_gotoxy(A + (dst - 'A') * 10, Y - number[dst - 'A']);
			cout << t;
			cct_gotoxy(X, Z);
			for (int i = 0; i < 3; i++)
			{
				cout << char(65 + i) << ":";
				for (int j = 0; j < 10; j++)
				{
					if (stack[i][j] == 0)
						cout << "  ";
					else
						cout << stack[i][j] << " ";
				}
				if (i == 2)
					cout << endl;
				else
					;
			}
		}
		else
		{
			four_move(layer - 1, is_delay, src, dst,tmp);
			while (getchar() != '\n')
				;
			cct_gotoxy(0, Z);
			cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
			t = stack[src - 'A'][--number[src - 'A']];
			stack[dst - 'A'][number[dst - 'A']++] = t;
			stack[src - 'A'][number[src - 'A']] = 0;
			cct_gotoxy(A + (src - 'A') * 10, X - number[src - 'A']);
			cout << " ";
			cct_gotoxy(A + (dst - 'A') * 10, Y - number[dst - 'A']);
			cout << t;
			cct_gotoxy(X, Z);
			for (int i = 0; i < 3; i++)
			{
				cout << char(65 + i) << ":";
				for (int j = 0; j < 10; j++)
				{
					if (stack[i][j] == 0)
						cout << "  ";
					else
						cout << stack[i][j] << " ";
				}
				if (i == 2)
					cout << endl;
				else
					;
			}
			four_move(layer - 1, is_delay, tmp, src, dst);
		}
	}
	else
	{
		if (layer == 1)
		{
			Sleep(600 - 100 * is_delay);
			cct_gotoxy(0, Z);
			cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
			t = stack[src - 'A'][--number[src - 'A']];
			stack[dst - 'A'][number[dst - 'A']++] = t;
			stack[src - 'A'][number[src - 'A']] = 0;
			cct_gotoxy(A + (src - 'A') * 10, X - number[src - 'A']);
			cout << " ";
			cct_gotoxy(A + (dst - 'A') * 10, Y - number[dst - 'A']);
			cout << t;
			cct_gotoxy(X, Z);
			for (int i = 0; i < 3; i++)
			{
				cout << char(65 + i) << ":";
				for (int j = 0; j < 10; j++)
				{
					if (stack[i][j] == 0)
						cout << "  ";
					else
						cout << stack[i][j] << " ";
				}
				if (i == 2)
					cout << endl;
				else
					;
			}
		}
		else
		{
			four_move(layer - 1, is_delay, src, dst, tmp);
			Sleep(600 - 100 * is_delay);
			cct_gotoxy(0, Z);
			cout << "第" << setw(4) << i++ << "步(" << layer << "):" << src << "-->" << dst << " ";
			t = stack[src - 'A'][--number[src - 'A']];
			stack[dst - 'A'][number[dst - 'A']++] = t;
			stack[src - 'A'][number[src - 'A']] = 0;
			cct_gotoxy(A + (src - 'A') * 10, X - number[src - 'A']);
			cout << " ";
			cct_gotoxy(A + (dst - 'A') * 10, Y - number[dst - 'A']);
			cout << t;
			cct_gotoxy(X, Z);
			for (int i = 0; i < 3; i++)
			{
				cout << char(65 + i) << ":";
				for (int j = 0; j < 10; j++)
				{
					if (stack[i][j] == 0)
						cout << "  ";
					else
						cout << stack[i][j] << " ";
				}
				if (i == 2)
					cout << endl;
				else
					;
			}
			four_move(layer - 1, is_delay, tmp, src, dst);
		}
	}
}
void solution_four()
{
	int layer;
	char src, dst, tmp;
	int is_delay = 0;
	char huiche = '\n';
	initlize(layer, src, tmp, dst);
	number[src - 'A'] = layer;
	number[tmp - 'A'] = 0;
	number[dst - 'A'] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i])
			{
				if (j <= layer)
					stack[i][j] = layer - j;
				else
					stack[i][j] = 0;
			}
			else
				stack[i][j] = 0;
		}
	}
	cout << "请输入移动速度（0-5：0-按回车键单步演示 1-延时最长 5-延时最短）" << endl;
	cin >> is_delay;
	cct_cls();
	cout << "从" << src << "移动到" << dst << "共" << layer << "层,延时设置为" << is_delay;
	cct_gotoxy(12, Y);
	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
	cout << endl;
	cct_gotoxy(12, 26);
	for (int i = 0; i < 3; i++)
	{
		cout << "  " << char(65 + i) << "       ";
	}
	for (int i = 0; i < 3; i++)
	{
		if (number[i])
		{
			for (int j = 0; j < layer; j++)
			{
				cct_gotoxy(A + 10 * i, X - j);
				cout << stack[i][j];
			}
		}
		else
			;
	}
	four_move(layer,is_delay,src,tmp,dst);
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void solution_five()
{
	cct_cls();
	int Q = 12;
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(34, 15, ' ', 14, 0, 23);
	cct_showch(67, 15, ' ', 14, 0, 23);
	for (int y = 14; y > 3; y--)
	{
		cct_showch(Q, y, ' ', 14, 0, 1);
		cct_showch(Q + 33, y, ' ', 14, 0, 1);
		cct_showch(Q + 66, y, ' ', 14, 0, 1);
		Sleep(100);
	}
	Sleep(100);
	cct_gotoxy(0, 27);
	cct_setcolor();
	cout << "按回车键继续";
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void solution_six()
{
	int layer = 0;
	char src = '0';
	char tmp = '0';
	char dst = '0';
	int delay = 0;
	char huiche = '\0';
	initlize(layer, src, tmp, dst);
	cct_cls();
	int Q = 12;
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(34, 15, ' ', 14, 0, 23);
	cct_showch(67, 15, ' ', 14, 0, 23);
	for (int y = 14; y > 3; y--)
	{
		cct_showch(Q, y, ' ', 14, 0, 1);
		cct_showch(Q + 33, y, ' ', 14, 0, 1);
		cct_showch(Q + 66, y, ' ', 14, 0, 1);
		Sleep(100);
	}
	Sleep(100);
	cct_setcursor(CURSOR_INVISIBLE);
	for (int i = layer; i > 0; i--)
	{
		cct_showch((int(src) - 'A') * 33 + 11 - i, 14 + i - layer, ' ', i, 0, 2 * i + 3);
	}
	cct_gotoxy(0, 27);
	cct_setcolor();
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void seven_graph_move(char src,char dst)
{
	int src_x = (src - 'A') * 33 + 11 - stack[src - 'A'][number[src - 'A']];
	int src_y = 14 - (number[src - 'A']);
	int dst_x=(dst - 'A') * 33 + 11 - stack[src - 'A'][number[src - 'A']];
	int dst_y = 14 - (number[dst - 'A'])+1;
	/*上移*/
	for (int y = src_y; y > 2; y--)
	{
		cct_showch(src_x, y, ' ', stack[src - 'A'][number[src - 'A']], 0, 2*stack[src - 'A'][number[src - 'A']]+3);
		Sleep(300);
		if (y>3) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(src_x, y, ' ', COLOR_BLACK, COLOR_WHITE,stack[src - 'A'][number[src - 'A']]+1);
			cct_showch(src_x + stack[src - 'A'][number[src - 'A']]+1, y, ' ', 14, 0, 1);
			cct_showch(src_x + stack[src - 'A'][number[src - 'A']]+2, y, ' ', COLOR_BLACK, COLOR_WHITE, stack[src - 'A'][number[src - 'A']]+1);
		}
	}
	/*左右移动*/
	if (dst_x > src_x)
	{
		for (int x = src_x; x <dst_x+1; x++)
		{
			cct_showch(x, 3, ' ', stack[src - 'A'][number[src - 'A']], 0, 2 * stack[src - 'A'][number[src - 'A']] + 3);
			Sleep(300);
			if(x<dst_x)
				cct_showch(x, 3, ' ', COLOR_BLACK, COLOR_WHITE, 2 * stack[src - 'A'][number[src - 'A']] + 3);
		}
	}
	else
	{
		for (int x = src_x; x>dst_x-1; x--)
		{
			cct_showch(x, 3, ' ', stack[src - 'A'][number[src - 'A']], 0, 2 * stack[src - 'A'][number[src - 'A']] + 3);
			Sleep(300);
			if (x>dst_x)
				cct_showch(x, 3, ' ', COLOR_BLACK, COLOR_WHITE, 2 * stack[src - 'A'][number[src - 'A']] + 3);
		}
	}
	/*下移*/
	for(int y=3; y<dst_y+1; y++)
	{
		cct_showch(dst_x, y, ' ', stack[src - 'A'][number[src - 'A']], 0, 2*stack[src - 'A'][number[src - 'A']]+3);
		Sleep(300);
		if (y <dst_y) {
			/* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
			cct_showch(dst_x, y, ' ', COLOR_BLACK, COLOR_WHITE, stack[src - 'A'][number[src - 'A']] + 1);
			cct_showch(dst_x + stack[src - 'A'][number[src - 'A']] + 1, y, ' ', 14, 0, 1);
			cct_showch(dst_x + stack[src - 'A'][number[src - 'A']] + 2, y, ' ', COLOR_BLACK, COLOR_WHITE, stack[src - 'A'][number[src - 'A']] + 1);
		}
	}
}
void solution_seven()
{
	int layer = 0;
	char src = '0';
	char tmp = '0';
	char dst = '0';
	int delay = 0;
	char huiche = '\0';
	initlize(layer, src, tmp, dst);
	number[src - 'A'] = layer;
	number[tmp - 'A'] = 0;
	number[dst - 'A'] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i])
			{
				if (j <= layer)
					stack[i][j] = layer - j;
				else
					stack[i][j] = 0;
			}
			else
				stack[i][j] = 0;
		}
	}
	cct_cls();
	int Q = 12;
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(34, 15, ' ', 14, 0, 23);
	cct_showch(67, 15, ' ', 14, 0, 23);
	for (int y = 14; y > 3; y--)
	{
		cct_showch(Q, y, ' ', 14, 0, 1);
		cct_showch(Q + 33, y, ' ', 14, 0, 1);
		cct_showch(Q + 66, y, ' ', 14, 0, 1);
		Sleep(100);
	}
	Sleep(100);
	cct_setcursor(CURSOR_INVISIBLE);
	for (int i = layer; i > 0; i--)
	{
		cct_showch((int(src) - 'A') * 33 + 11 - i, 14 + i - layer, ' ', i, 0, 2 * i + 3);
	}
	
	if (layer % 2 == 0)
	{
		--number[src - 'A'];
		number[tmp - 'A']++;
		seven_graph_move(src, tmp);
	}
	else
	{
		--number[src - 'A'];
		number[dst - 'A']++;
		seven_graph_move(src, dst);
	}
	cct_gotoxy(0, 27);
	cct_setcolor();
	cout << "按回车键继续";
	getchar();
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void eight_move(int layer,char src,char tmp,char dst)
{
	static int t = 0;
	if (layer == 1)
	{
		t = stack[src - 'A'][--number[src - 'A']];
		stack[dst - 'A'][number[dst - 'A']++] = t;
		
		seven_graph_move(src, dst);
		stack[src - 'A'][number[src - 'A']] = 0;
	}
	else
	{
		eight_move(layer - 1, src, dst, tmp);
		t = stack[src - 'A'][--number[src - 'A']];
		stack[dst - 'A'][number[dst - 'A']++] = t;
		seven_graph_move(src, dst);
		stack[src - 'A'][number[src - 'A']] = 0;
		eight_move(layer - 1, tmp, src, dst);
	}
}
void solution_eight()
{
	int layer = 0;
	char src = '0';
	char tmp = '0';
	char dst = '0';
	int delay = 0;
	char huiche = '\0';
	initlize(layer, src, tmp, dst);
	number[src - 'A'] = layer;
	number[tmp - 'A'] = 0;
	number[dst - 'A'] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i])
			{
				if (j <= layer)
					stack[i][j] = layer - j;
				else
					stack[i][j] = 0;
			}
			else
				stack[i][j] = 0;
		}
	}
	cct_cls();
	int Q = 12;
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(34, 15, ' ', 14, 0, 23);
	cct_showch(67, 15, ' ', 14, 0, 23);
	for (int y = 14; y > 3; y--)
	{
		cct_showch(Q, y, ' ', 14, 0, 1);
		cct_showch(Q + 33, y, ' ', 14, 0, 1);
		cct_showch(Q + 66, y, ' ', 14, 0, 1);
		Sleep(100);
	}
	Sleep(100);
	cct_setcursor(CURSOR_INVISIBLE);
	for (int i = layer; i > 0; i--)
	{
		cct_showch((int(src) - 'A') * 33 + 11 - i, 14 + i - layer, ' ', i, 0, 2 * i + 3);
	}
	eight_move(layer,src,tmp,dst);
	getchar();
	cct_gotoxy(0, 20);
	cct_setcolor(0,7);
	cout << "按回车键结束" << endl;
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
void solution_night()
{
	int is_jinxing = 1;
	int check = 0;
	char src, tmp, dst;
	int layer;
	char str[3] = { '0','0','0' };
	initlize(layer, src, tmp, dst);
	number[src - 'A'] = layer;
	number[tmp - 'A'] = 0;
	number[dst - 'A'] = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (number[i])
			{
				if (j <= layer)
					stack[i][j] = layer - j;
				else
					stack[i][j] = 0;
			}
			else
				stack[i][j] = 0;
		}
	}
	cct_cls();
	cout << "从" << src << "移动到" << dst << ",共" << layer << "层" << endl;
	int Q = 12;
	cct_showch(1, 15, ' ', 14, 0, 23);
	cct_showch(34, 15, ' ', 14, 0, 23);
	cct_showch(67, 15, ' ', 14, 0, 23);
	for (int y = 14; y > 3; y--)
	{
		cct_showch(Q, y, ' ', 14, 0, 1);
		cct_showch(Q + 33, y, ' ', 14, 0, 1);
		cct_showch(Q + 66, y, ' ', 14, 0, 1);
		Sleep(100);
	}
	Sleep(100);
	cct_setcursor(CURSOR_INVISIBLE);
	for (int i = layer; i > 0; i--)
	{
		cct_showch((int(src) - 'A') * 33 + 11 - i, 14 + i - layer, ' ', i, 0, 2 * i + 3);
	}
	cct_setcolor(0, 7);
	cct_gotoxy(12, Y+1);
	for (int i = 0; i < 30; i++)
	{
		cout << "=";
	}
	cout << endl;
	cct_gotoxy(12, 26+1);
	for (int i = 0; i < 3; i++)
	{
		cout << "  " << char(65 + i) << "       ";
	}
	for (int i = 0; i < 3; i++)
	{
		if (number[i])
		{
			for (int j = 0; j < layer; j++)
			{
				cct_gotoxy(A + 10 * i, X - j+1);
				cout << stack[i][j];
			}
		}
		else
			;
	}
	cct_gotoxy(0, 32+1);

	cout << "初始:";
	for (int i = 0; i < 3; i++)
	{
		cout << char(65 + i) << ":";
		for (int j = 0; j < 10; j++)
		{
			if (stack[i][j] == 0)
				cout << "  ";
			else
				cout << stack[i][j] << " ";
		}
		if (i == 2)
			cout << endl;
		else
			;
	}
	cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)";
	for (;;)
	{
		while (1)
		{
			int w = 0;
			night_scanf(str);
			while (1)
			{
				if (str[0] == 'q' || str[0] == 'Q')
				{
					check = 0;
					break;
				}
				else
				{
					check = 1;
					break;
				}
			}
			if (check == 0)
			{
				cct_gotoxy(0,35+1);
				cout << "游戏终止"<<endl;
				is_jinxing = 0;
				break;
			}
			else
			{
				cct_gotoxy(0, 35);
				w = check_is_true(str[0], str[1]);
			}
			if (w == 0)
				;
			else
				break;
		}
		if (is_jinxing == 0)
			break;
		else
			;
		night_move(str[0], str[1]);
		if (number[dst - 'A'] == layer)
		{
			cout << endl;
			cout << "游戏结束";
			break;
		}
		else
			;
	}
	cout << "按回车键结束";
	while (1)
	{
		if (getchar() != '\n')
			;
		else
			break;
	}
	cct_cls();
}
int check_is_true(char src, char dst)
{
	if (src == 'A' || src == 'a')
		src = 'A';
	if (src == 'B' || src == 'b')
		src = 'B';
	if (src == 'C' || src == 'c')
		src = 'C';
	if (dst == 'A' || dst == 'a')
		dst = 'A';
	if (dst == 'B' || dst == 'b')
		dst = 'B';
	if (dst == 'C' || dst == 'c')
		dst = 'C';
	if (number[src - 'A'] == 0)
	{
		cout << "移动非法，柱源为空";
		return 0;
	}
	else
	{
		if (number[dst - 'A'] > 0)
		{
			if (stack[src - 'A'][number[src - 'A'] - 1] > stack[dst - 'A'][number[dst - 'A'] - 1] && stack[dst - 'A'][number[dst - 'A'] - 1] > 0)
			{
				cout << "移动非法，大盘压小盘";
				return 0;
			}
			else
				return 1;
		}
		else
			;
	}
}
void night_scanf(char str[3])
{
	while (1)
	{
		int number = 0;
		cct_gotoxy(56, 33+1);
		cout << "                       ";
		cct_gotoxy(56, 33+1);
		for (int i = 0;; i++, number++)
		{
			str[i] = getchar();
			if (str[i] == '\n')
				break;
			else
				;
		}
		cct_gotoxy(0, 35);
		cout << "                                            ";
		if (str[0] == 'q' || str[0] == 'a' || str[0] == 'b' || str[0] == 'c' || str[0] == 'Q' || str[0] == 'A' || str[0] == 'B' || str[0] == 'C')
		{
			if (str[1] == 'a' || str[1] == 'b' || str[1] == 'c' || str[1] == 'A' || str[1] == 'B' || str[1] == 'C' || str[1] == '\n')
				break;
			else
				;
		}
		else
			;
	}
}
void night_move(char src, char dst)
{
	static int t = 0;
	static int i = 1;
	t = stack[src - 'A'][--number[src - 'A']];
	stack[dst - 'A'][number[dst - 'A']++] = t;
	seven_graph_move(src, dst);
	cct_setcolor(0, 7);
	stack[src - 'A'][number[src - 'A']] = 0;
	cct_gotoxy(0, Z+5+1);
	cout << "第" << setw(4) << i++ << "步(" <<t<< "):" << src << "-->" << dst << " ";
	cct_gotoxy(A + (src - 'A') * 10, X - number[src - 'A']+1);
	cout << " ";
	cct_gotoxy(A + (dst - 'A') * 10, Y - number[dst - 'A']+1);
	cout << t;
	cct_gotoxy(X, Z+5+1);
	for (int i = 0; i < 3; i++)
	{
		cout << char(65 + i) << ":";
		for (int j = 0; j < 10; j++)
		{
			if (stack[i][j] == 0)
				cout << "  ";
			else
				cout << stack[i][j] << " ";
		}
		if (i == 2)
			cout << endl;
		else
			;
	}
}