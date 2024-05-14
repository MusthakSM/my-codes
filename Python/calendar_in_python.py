import calendar

# weekheader prints the days of a week.. In python a week starts with Monday...
# Number in the parenthesis indicates the length of the day name... (m/mo/mon/mon )
print(calendar.weekheader(3))
print()

# in default monday has the index of 0 since it's the first week day according to python. 
# mon 0 tue 1 wed 2 thu 3 fri 4 sat 5 sun 6
print(calendar.firstweekday())
print()

# calendar.month() function is used to get a particular month in a particular year...
# First parameter is the year and the second parameter is the month(no position of the month in the year.)
print(calendar.month(2022, 6, m=3))