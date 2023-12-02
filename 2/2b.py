import re

def process(f):
    sum = 0
    for line in f.readlines():
        reds = [int(num) for num in re.findall(r"(\d+) red", line)]
        greens = [int(num) for num in re.findall(r"(\d+) green", line)]
        blues = [int(num) for num in re.findall(r"(\d+) blue", line)]
        
        sum += max(reds) * max(greens) * max(blues)
    print(sum)

if __name__ == "__main__":
    with open("input.txt") as f:
        process(f)