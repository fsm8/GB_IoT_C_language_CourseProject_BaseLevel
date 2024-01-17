#include "functions.h"

float average_t_year(struct temperature month[])
{
	float sum = 0, cnt = 0;
	for (int i = 1; i < 13; i++)
	{
		sum += month[i].sum;
		cnt += month[i].count;
	}
	//sum = month->sum;
	//cnt = month->count;
	return (sum / cnt);
}

int max_t_year(struct temperature month[])
{
	int max = month[1].max.t;
	for (int i = 1; i < 13; i++)
	{
		if (month[i].max.t > max)
		{
			max = month[i].max.t;
		}
	}
	return max;
}

int min_t_year(struct temperature month[])
{
	int min = month[1].min.t;
	for (int i = 1; i < 13; i++)
	{
		if (month[i].min.t < min)
		{
			min = month[i].min.t;
		}
	}
	return min;
}