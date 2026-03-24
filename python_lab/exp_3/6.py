# 1
# 121
# 12321
# 1234321

rows = 4

for i in range(1, rows + 1):
	left = ""
	for j in range(1, i + 1):
		left += str(j)

	right = ""
	for j in range(i - 1, 0, -1):
		right += str(j)

	print(left + right)
