# epoch-to-time_and_date
This repository includes C code to get time and date info from epoch seconds.
You  can use this code on the microporecessors.
No additional library is required.

I will explain tricky part here.

if ( leap(D_T.year)){
	if ( (day_of_year+leap_years) >365 ) {
		day_of_year++;
	}
}

this code snippet is where leap years  play its  role.
I will give example.

For example, 2024 is leap year and there is a 13 leap years before 2024 since 1970.

I tested and saw tht 31-13= 18 and at the date 18/12/2024, it repeated 18/12/2024 and
ignored 31/12/2024. jumped 01/01/2025 from 30/12/2024
tihs code solves this problem.
