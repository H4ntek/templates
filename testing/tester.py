import os

KOD = "xyz"
TESTS = 100

os.system(f'make CXXFLAGS="-std=c++17 -Wall -Wextra -O3 -fsanitize=address,undefined {KOD}')
os.system(f'make CXXFLAGS="-std=c++17 -Wall -Wextra -O3 -fsanitize=address,undefined {KOD}b')

for i in range(TESTS):
    os.system(f"python3 gen.py > in")
    os.system(f"./{KOD} < in > out")
    os.system(f"./{KOD}b < in > outb")

    if os.system("diff -wq out outb") == 0:
        print(f"OK, test: {i}")
    else:
        print(f"WRONG, test: {i}")
        break 
