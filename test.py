import sys
import random
import subprocess


def gen(value, min ,max):
    return random.sample(range(min, max), value)

i = 0
for i in range(100000):
    n = " ".join(map(str, gen(100, -18787800, 52562564)))
    res = subprocess.run(f"./push_swap {n} | wc -l", capture_output=True, text=True, shell=True)
    second = res.stdout.strip()
    if int(second) == 0:
        print(n)
        break
    if int(second) > 700:
        print("test case " + str(i) + "  failed with : " + second)
        print("case :" + n)
        break
    print("test case " + str(i) + " passed with : " + second)