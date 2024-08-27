/* 班级 学号 姓名 */
#pragma once
#define X 24
#define Y 25
#define Z 27
#define A 14
extern void solution_one();
extern void solution_two();
extern void solution_three();
extern void solution_four();
extern void solution_five();
extern void solution_six();
extern void solution_seven();
extern void seven_graph_move(char src,char dst);
extern void eight_move(int layer, char src, char tmp, char dst);
extern void solution_eight();
extern int check_is_true(char src, char dst);
extern int menu();
extern void one_move(int layer, char src, char tmp, char dst);
extern void initlize(int &layer, char &src, char &tmp, char &dst);
extern void two_move(int layer, char src, char tmp, char dst);
extern void three_move(int layer, char src, char tmp, char dst);
extern void four_move(int layer, int is_delay,char src, char tmp, char dst);
extern void solution_night();
extern int  check_is_true(char src, char dst);
extern void night_scanf(char str[3]);
extern void night_move(char src, char dst);
/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

