struct data
{
	int year, month, day, hour, min, t;
};

struct temperature
{
	int sum;  // ����� ���������� �� �����
	int count; // ����� ��������� ���������� �� �����
	struct data max, min; // ���� t � ��� t
};

float average_t_year(struct temperature*);
int max_t_year(struct temperature*);
int min_t_year(struct temperature*);
