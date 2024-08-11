num = int(input())
signs = list(input().split())
numbers = set('0123456789')
answers = []

def check(p_num, depth):
    if depth == num:
        answers.append(int(p_num))
        return
    rest = set(numbers) - set(p_num)
    sign = signs[depth]
    last_num = int(p_num[-1])
    for n in rest:
        if (sign == '<' and last_num < int(n)) or (sign == '>' and last_num > int(n)):
            check(p_num + n, depth + 1)

for number in numbers:
    check(number, 0)

print(str(max(answers)).zfill(num + 1))
print(str(min(answers)).zfill(num + 1))
