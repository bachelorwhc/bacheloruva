#include <algorithm>
#include <cstdio>
#include <cmath>
#define D_HOUR 30.0f
#define D_MIN 6.0f
#define HOUR_TO_MIN 60.0f

inline double HourDegreeTransform(unsigned short hour, unsigned short min)
{
	return D_HOUR * (hour % 12) + (min / HOUR_TO_MIN) * D_HOUR;
}

int main()
{
	unsigned short hour;
	unsigned short min;
	while (scanf("%u:%u", &hour, &min))
	{
		if(hour == 0 && min == 0)
			break;
		double d_h(HourDegreeTransform(hour, min));
		double d_m(D_MIN * min);
		double dd(std::abs(d_h - d_m));
		if(dd > 180.0f)
			dd = 360.0f - dd;
		printf("%.3f\n", dd);
	}
	return 0;
}