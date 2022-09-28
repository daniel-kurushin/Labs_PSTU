from itertools import product

def compare(s1, s2):
	ngrams = [s1[i:i+3] for i in range(len(s1))]
	count = 0
	for ngram in ngrams:
		count += s2.count(ngram)

	return count/max(len(s1), len(s2)) > 0.6

class Person:

	def __init__(self, name=None, age=None):
		self.name = name
		self.age = age

	def __eq__(self, obj):
		return (obj.name == None or self.name == None or compare(obj.name, self.name)) \
		   and (obj.age == None or self.age == None or abs(obj.age - self.age) < 2)

	def __repr__(self):
		return f"Person('{self.name}', {self.age})"


to_search = [
	Person('Нташа', 19),
	Person(age=19),
	Person(name='Нташа'),
]

people = [
	Person('Лена', 19),
	Person('Катя', 23),
	Person('Маша', 18),
	Person('Вася', 34),
	Person('Коля', 43),
	Person('Наташа', 20),
]

for p1, p2 in product(people, to_search):
	print(p1, p2, p1 == p2)

