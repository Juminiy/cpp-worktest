import random

def generate_map(rows, cols):
    map_data = []

    # 随机选择S、E、C的位置，确保S和E之间至少有一个C
    while True:
        s_pos = (random.randint(0, rows - 1), random.randint(0, cols - 1))
        e_pos = (random.randint(0, rows - 1), random.randint(0, cols - 1))
        c_pos = (random.randint(0, rows - 1), random.randint(0, cols - 1))

        # 检查S和E之间是否至少有一个C
        if abs(s_pos[0] - e_pos[0]) + abs(s_pos[1] - e_pos[1]) > 1 and \
           not (s_pos == c_pos or e_pos == c_pos):
            break

    for i in range(rows):
        row = []
        for j in range(cols):
            if (i, j) == s_pos:
                row.append('S')
            elif (i, j) == e_pos:
                row.append('E')
            elif (i, j) == c_pos:
                row.append('C')
            elif random.random() < 0.0005:  # 20%的概率生成B
                row.append('B')
            else:  # 80%的概率生成0-100之间的数字
                row.append(random.randint(0, 100))
        map_data.append(row)

    return map_data

n = 100
m = 100
map_data = generate_map(n, m)

# 将地图数据写入文件
with open("map.txt", "w") as f:
    f.write(f"{n} {m}\n")  # 先写入n和m的值
    for row in map_data:
        f.write(" ".join(map(str, row)) + "\n")

print("地图已写入文件：map.txt")
