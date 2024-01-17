struct data
{
	int year, month, day, hour, min, t;
};

struct temperature
{
	int sum;  // сумма температур за месяц
	int count; // число измерений температур за месяц
	struct data max, min; // макс t и мин t
};

float average_t_year(struct temperature*);
int max_t_year(struct temperature*);
int min_t_year(struct temperature*);
