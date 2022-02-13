from random import *

MAXN = 10
MAXW = 100
n = randint(1, MAXN)

def gen_array(n, low, high, repetitions = True):
    a = []
    used = []
    for _ in range(n):
        x = randint(low, high)
        while x in used:
            x = randint(low, high)
        a.append(x)
        if not repetitions:
            used.append(x)
    print(n)
    for x in a:
        print(x, end = " ")
    print("")


def gen_tree(n, typ = "NORMAL", weighted = False, make_complete_graph = False):
    edges = []
    perm = [0]
    temp = [i for i in range(1, n + 1)]
    shuffle(temp)
    perm += temp

    if typ == "NORMAL":
        for i in range(2, n + 1):
            if randint(0, 1):
                edges.append([i, randint(1, i - 1)])
            else:
                edges.append([randint(1, i - 1), i])

    elif typ == "STAR":
        center = randint(1, n)
        for i in range(2, n + 1):
            if i == center:
                continue
            if randint(0, 1):
                edges.append([i, center])
            else:
                edges.append([center, i])

    elif typ == "LINE":
        prev = 1
        for i in range(2, n + 1):
            if randint(0, 1):
                edges.append([i, prev])
            else:
                edges.append([prev, i])
            prev = i

    elif typ == "CATERPILLAR":
        path_size = randint(2, n)
        prev = 1
        for i in range(2, path_size + 1):
            if randint(0, 1):
                edges.append([i, prev])
            else:
                edges.append([prev, i])
            prev = i
        for i in range(path_size + 1, n + 1):
            parent = randint(1, path_size)
            if randint(0, 1):
                edges.append([i, parent])
            else:
                edges.append([parent, i])
    
    if make_complete_graph:
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                if [i, j] not in edges and [j, i] not in edges:
                    if random() < 0.4:
                        edges.append([i, j])
    
    for edge in edges:
        edge[0] = perm[edge[0]]
        edge[1] = perm[edge[1]]
    shuffle(edges)

    print(f"{n} {len(edges)}")
    if weighted:
        for edge in edges:
            print(f"{edge[0]} {edge[1]} {randint(1, MAXW)}")
    else:
        for edge in edges:
            print(f"{edge[0]} {edge[1]}")

def gen_graph(n, typ1 = "NORMAL", weighted = False, directed = False):
    edges = []
    perm = [0]
    temp = [i for i in range(1, n + 1)]
    shuffle(temp)
    perm += temp

    if typ1 == "NORMAL":
        prob = [[random() for _ in range(n + 1)] for _ in range(n + 1)]
    elif typ1 == "SPARSE":
        prob = [[uniform(0, 0.33) for _ in range(n + 1)] for _ in range(n + 1)]
    elif typ1 == "DENSE":
        prob = [[uniform(0.66, 1) for _ in range(n + 1)] for _ in range(n + 1)]

    if not directed:
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                if random() <= prob[i][j]: 
                    edges.append([i, j])
    else:
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if i == j:
                    continue
                elif random() <= prob[i][j]:
                    edges.append([i, j])

    for edge in edges:
        edge[0] = perm[edge[0]]
        edge[1] = perm[edge[1]]
    shuffle(edges)

    print(f"{n} {len(edges)}")
    if weighted:
        for edge in edges:
            print(f"{edge[0]} {edge[1]} {randint(1, MAXW)}")
    else:
        for edge in edges:
            print(f"{edge[0]} {edge[1]}")
