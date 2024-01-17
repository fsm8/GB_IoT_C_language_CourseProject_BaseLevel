/*
�������� ������ �� �������� "���������������� �� ��. ������� �������".
��������: ������� ������ ����������.
������: GU_IoT_2309 (23.03.22).
29.06.2022.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "functions.h"

struct temperature month[13] = { 0 };

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	int user_month = 0;
	char user_filename[1000] = { 0 };
	
	for (int i = 0; i < argc; i++)
	{
		//printf("argc = %d , argv = %s\n", i, argv[i]);
		if (strcmp(argv[i], "-h") == 0)
		{
			printf("���������� ���������� ��� ������ ����������, ��������� �������� ����������� �� 1 ����������� ���.\n");
			printf("��������� ����������� �� ��� ��� ��������� ������������� �����:\n");
			printf("- �������������� �����������,\n");
			printf("- ����������� ����������� � ������� ������,\n");
			printf("- ������������ ����������� � ������� ������.\n");
			printf("��������� ���������� ����������� �� ���:\n");
			printf("- ������������� �����������,\n");
			printf("- ����������� �����������,\n");
			printf("- ������������ �����������.\n");
			printf("������ �������������� ���������� ������:\n");
			printf("1. -h - ������ ������, ������� ������������ ������ ���������� � �� ����������.\n");
			printf("2. -f filename.csv - ������� ���� csv ��� ���������.\n");
			printf("3. -m ����� ������ - ���� ����� ������ ����, �� ��������� ������ ���������� �� ��������� �����.\n");
		}
		if (strcmp(argv[i], "-m") == 0) // compare
		{
			if(i != argc-1)
				user_month = atoi(argv[i + 1]); // ascii to integer

			if (user_month < 1 || user_month > 12)
			{
				printf("����� ������ �������\n");
				printf("��� ������ �� ��������� ������� Enter\n");
				while (getchar() != '\n');
				return 1;
			}
		}
		if (strcmp(argv[i], "-f") == 0)
		{
			if (i != argc - 1)
			{
				if (strlen(argv[i + 1]) < 1000) // length
				{
					strcpy(user_filename, argv[i + 1]); // copy
				}
				else
				{
					printf("����� ���� � �������� ����� .csv ��������� �������� ������\n");
					printf("��� ������ �� ��������� ������� Enter\n");
					while (getchar() != '\n');
					return 1;
				}
			}
		}
	}
	
	if (user_filename[0] == '\0')
	{
		printf("�� �� ������� ������� ���� .csv ��� ���������\n");
		printf("��� ������ �� ��������� ������� Enter\n");
		while (getchar() != '\n');
		return 1;
	}
	
	printf("\n");

	//FILE* f = fopen("C:\\Users\\Sergey\\source\\repos\\Course_project_C_base\\temperature_small.csv", "r");

	FILE* f = fopen(user_filename, "r");
	
	if (f == NULL)
	{
		printf("������� ���� .csv �� ����� ���� ������ ��� �� ����������.\n");
		printf("��� ������ �� ��������� ������� Enter\n");
		while (getchar() != '\n');
		return 1;
	}

	int a;
	int y, m, d, h, mi, t;
	char* name[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", NULL };

	for (int i = 1; i < 13; i++)
	{
		month[i].max.t = INT_MIN;
		month[i].min.t = INT_MAX;
	}

	while ((a = (fscanf(f, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &mi, &t))) != EOF)
	{
		if (a != 6)
		{
			char error[100] = { 0 };
			fscanf(f, "%[^\n]", error);
			printf("Error string: %s\n", error);
		}
		else
		{
			month[m].sum += t; // ����� ���������� �� �����
			month[m].count++; // ����� ��������� �� �����
						
			if (t > month[m].max.t)
			{
				month[m].max.t = t;
				month[m].max.day = d;
				month[m].max.month = m;
				month[m].max.hour = h;
				month[m].max.min = mi;
			}
			if (t < month[m].min.t)
			{
				month[m].min.t = t;
				month[m].min.day = d;
				month[m].min.month = m;
				month[m].min.hour = h;
				month[m].min.min = mi;
			}
		}
	}
	fclose(f);

	printf("\n");

	if (user_month) // ������� ���������� �� ��������� ������������� �����
	{
		if (month[user_month].count) // ���� �� ������ ����� ���������� ����
		{
			printf("%-10s: Average t = %5.1f, ", name[user_month - 1], (float)month[user_month].sum / month[user_month].count);
			printf("Max t = %3d, ", month[user_month].max.t);
			printf("Min t = %3d\n", month[user_month].min.t);
		}
		else
		{
			printf("�� ��������� ����� ���������� �� ����������\n");
		}
	}
	
	else // ������� ���������� �� ���� �������
	{
		for (int manth = 1, nnm = 0; manth < 13; manth++, nnm++)
		{
			if (month[manth].count)
			{
				printf("%-10s: Average t = %5.1f, ", name[nnm], (float)month[manth].sum / month[manth].count);
				printf("Max t = %3d, ", month[manth].max.t);
				printf("Min t = %3d\n", month[manth].min.t);
			}
		}
	}

	printf("\n");

	// ������� ���������� �� ���� ���
	printf("Year, %4d: Average t = %5.1f, ", y, average_t_year(month));
	printf("Max t = %3d, ", max_t_year(month));
	printf("Min t = %3d\n", min_t_year(month));

	printf("��� �������� ��������� ������� Enter\n");
	while (getchar() != '\n');

	return 0;
}
