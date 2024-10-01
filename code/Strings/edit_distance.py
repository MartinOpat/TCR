def editDistance(str1, str2):
	m = len(str1)
	n = len(str2)
	curr = [0] * (n + 1)
	for j in range(n + 1):
		curr[j] = j
	previous = 0
	# dp rows
	for i in range(1, m + 1):
		previous = curr[0]
		curr[0] = i
		
		# dp cols
		for j in range(1, n + 1):
			temp = curr[j]
			if str1[i - 1] == str2[j - 1]:
				curr[j] = previous
			else:
				curr[j] = 1 + min(previous, curr[j - 1], curr[j])
			previous = temp
	return curr[n]
