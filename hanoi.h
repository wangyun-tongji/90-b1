/* �༶ ѧ�� ���� */
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

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

