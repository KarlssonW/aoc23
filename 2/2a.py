import re

def process(f):
    sum = 0
    for line in f.readlines():
        possible = True
        
        for set in line.split(":")[1].split(";"):
            reds = re.findall(r"(\d+) red", set)
            greens = re.findall(r"(\d+) green", set)
            blues = re.findall(r"(\d+) blue", set)
            
            if ((reds and int(reds[0]) > 12) or
               (greens and int(greens[0]) > 13) or
               (blues and int(blues[0]) > 14)):
                possible = False
        
        if possible:
            sum += int(re.findall(r"(\d+):", line)[0])
    print(sum)

if __name__ == "__main__":
    with open("input.txt") as f:
        process(f)