import re

with open("./input.txt") as fin:
    line = fin.read().strip()

matches = re.findall(r"mul\((\d+),(\d+)\)", line)

ans = 0
for match in matches:
    ans += int(match[0]) * int(match[1])

print(ans)