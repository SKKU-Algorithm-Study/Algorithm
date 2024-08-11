# 도영이가 만든 맛있는 음식 : https://www.acmicpc.net/problem/2961

# 재료 N개 =>  신맛 S, 쓴맛 B
# 요리 -=> 신맛 = 재료 신맛의 곱, 쓴맛 = 쓴맛의 합
# 신맛과 쓴맛의 차이를 작게! 재료는 최소 1개이상

# 완전탐색 => 2^10 : 1024 시간복잡도 1초

# 절댓값 출력!

n = int(input())
ingreds = [list(map(int, input().split())) for _ in range(n)]
ans = 1000000000
# 1, 2, 3, 4, 5, ...1023까지 가면서 그떄의 비트에 따라 재료 가져와서 합, 곱 계산

for i in range(1, 2**n):
    if ans == 0: break
    bin_num = str(bin(i))[2:]
    print("bin_num", bin_num)

    tmp_s = 1
    tmp_b = 0
    idx = 0
    for j in range(n):
        print("j", j, idx)
        # 길이가 n미만인 경우, 0으로 처리하기.
        if j < n - len(bin_num): continue
        if bin_num[idx] == '1': 
            tmp_s *= ingreds[j][0]
            tmp_b += ingreds[j][1]
        idx += 1
    ans = min(ans, abs(tmp_s - tmp_b))

print(ans)