sentence = input().split()
sentence = sorted(sentence)
words = {}
for i in sentence:
	words[i] = sentence.count(i)  
maxi = max(words.values())
for i in words:
	if (int(words.get(i)) == maxi):
		print(i)
