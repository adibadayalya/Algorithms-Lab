import pygame
from pygame import gfxdraw
import random
import time

pygame.init()
pygame.font.init()
myfont = pygame.font.SysFont("Calibri", 12)

traversalx=0
traversaly=480

screen = pygame.display.set_mode((500, 500))
pygame.display.set_caption('BFS Visualizer')
running = True
coordiantes = []  
edges = []


def visited_color(i):
    time.sleep(1)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (0, 0, 0))
    gfxdraw.filled_circle(screen, x, y, 18, (0, 0, 0))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (255, 255, 255))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    
    pygame.display.update()

def current_color(i):
    global traversalx
    global traversaly
    time.sleep(1.0)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (255, 0, 0))
    gfxdraw.filled_circle(screen, x, y, 18, (220, 220, 220))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    textsurface1 = myfont.render("-->"+str(i), True, (0, 0, 0))
    screen.blit(textsurface1, (traversalx, traversaly))
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
        traversalx+=20
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
        traversalx+=29
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
        traversalx+=38
    pygame.display.update()


def current_color2(i):
    #bottom right current node indicator 
    x = 450
    y = 460
    gfxdraw.aacircle(screen, x, y, 20, (0, 0, 0))
    gfxdraw.filled_circle(screen, x, y, 18, (220, 220, 220))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    textsurface = myfont.render("Current Node", True, (255, 0, 0))
    screen.blit(textsurface, (x - 34, 480))
    pygame.display.update()


def queue_color(i):
    time.sleep(1.0)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (0, 0, 0))
    gfxdraw.filled_circle(screen, x, y, 18, (220, 220, 220))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    pygame.display.update()


def node(x, y, n):
    gfxdraw.aacircle(screen, x, y, 20, (0, 0, 0))
    gfxdraw.filled_circle(screen, x, y, 18, (255, 255, 255))  # colour inside the circle
    textsurface = myfont.render(n, True, (0, 0, 0))  # color of text
    if len(n) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(n) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change


def ccw(A, B, C):
    return (C[1] - A[1]) * (B[0] - A[0]) > (B[1] - A[1]) * (C[0] - A[0])


def intersect(A, B, C, D):
    return ccw(A, C, D) != ccw(B, C, D) and ccw(A, B, C) != ccw(A, B, D)


def dist(j, x, y):
    return (j[0] - x) * (j[0] - x) + (j[1] - y) * (j[1] - y)


def distlinesegpoint(x1, y1, x2, y2, x3, y3):  # x3,y3 is the point
    px = x2 - x1
    py = y2 - y1

    norm = px * px + py * py

    u = ((x3 - x1) * px + (y3 - y1) * py) / float(norm)

    if u > 1:
        u = 1
    elif u < 0:
        u = 0

    x = x1 + u * px
    y = y1 + u * py

    dx = x - x3
    dy = y - y3

    dist = (dx * dx + dy * dy) ** 0.5

    return dist


def possible(i, j):
    x1 = 0
    y1 = 0
    x2 = 0
    y2 = 0
    for k in coordiantes:
        if k[2] == i:
            x1 = k[0]
            y1 = k[1]
            break
    for k in coordiantes:
        if k[2] == j:
            x2 = k[0]
            y2 = k[1]
            break
    for k in coordiantes:
        if k[2] == i or k[2] == j:
            continue
        d = distlinesegpoint(x1, y1, x2, y2, k[0], k[1])
        if d < 20:
            return False
    for k in edges:
        if (
            (x1 == k[0][0] and y1 == k[0][1])
            or (x1 == k[1][0] and y1 == k[1][1])
            or (x2 == k[0][0] and y2 == k[0][1])
            or (x2 == k[1][0] and y2 == k[1][1])
        ):
            continue
        if intersect([x1, y1], [x2, y2], k[0], k[1]):
            return False
    return True

def DFS(visited,k):
    visited[k]=1
    current_color(k)
    current_color2(k)
    for pair in edges:
        pygame.event.pump()
        if(pair[0][2]==k and visited[pair[1][2]]==0) or (pair[1][2]==k and visited[pair[0][2]]==0):
            visited[pair[0][2]] = 1
            visited[pair[1][2]] = 1
            if pair[0][2] == k:
                time.sleep(0.5)
                pygame.draw.line(
                    screen,
                    (0,163,108),
                    (pair[0][0], pair[0][1]),
                    (pair[1][0], pair[1][1]),
                    width=4,
                ) #drawing the path edge
                pygame.display.flip()
                queue_color(pair[1][2])
                DFS(visited,pair[1][2])
            else:
                #queue_list.append(pair[0][2])
                time.sleep(0.5)
                pygame.draw.line(
                    screen,
                    (0,163,108),
                    (pair[0][0], pair[0][1]),
                    (pair[1][0], pair[1][1]),
                    width=4,
                ) #drawing the path edge
                pygame.display.flip()
                queue_color(pair[0][2])
                DFS(visited,pair[0][2])
    visited_color(k)

def DFS_Start():
    visited = [0] * (nodes_number + 10)
    for pair in edges:
        if visited[pair[1][2]] == 0:
            DFS(visited,pair[1][2])
        elif visited[pair[0][2]] == 0 :
            DFS(visited,pair[0][2])
 


screen.fill((255, 255, 255))

pygame.display.update()

#NODES RANDOM
pygame.event.pump()
i = 1
nodes_number = int(input("Enter Number of Nodes: "))
while i <= nodes_number:
    pygame.event.pump()

    x = random.randint(40, 480)
    y = random.randint(10, 300)
    flag = True
    for j in coordiantes:
        if dist(j, x, y) <= 4000:
            flag = False
            break
    if flag == False:
        continue
    coordiantes.append([x, y, i])
    i += 1

#CONNECTED TREE

curr = 1
non_visited = []
for i in range(2, nodes_number + 1):  # number of nodes
    non_visited.append(i)

#RANDOM EDGE

for i in range(1, nodes_number + 1):
    pygame.event.pump()
    for j in range(
        random.randint(1, (nodes_number // 2) - 1),
        random.randint(nodes_number // 2, nodes_number + 1),
    ):
        pygame.event.pump()
        if i == j:
            continue
        if i != j and possible(i, j):
            x1 = 0
            y1 = 0
            x2 = 0
            y2 = 0
            for k in coordiantes:
                pygame.event.pump()
                if k[2] == i:
                    x1 = k[0]
                    y1 = k[1]
                    break
            for k in coordiantes:
                pygame.event.pump()
                if k[2] == j:
                    x2 = k[0]
                    y2 = k[1]
                    break
            edges.append([[x1, y1, i], [x2, y2, j]])
            pygame.draw.line(screen, (0, 0, 0), (x1, y1), (x2, y2), width=3) #drawing the initial edge
            pygame.display.flip()

#SHOW NODES
for i in coordiantes:
    pygame.event.pump()
    node(i[0], i[1], str(i[2]))
    pygame.display.update()
pygame.event.pump()
textsurfaces = myfont.render("Traversal Order: ",True,(0,0,0))
screen.blit(textsurfaces,(0,470))
pygame.display.update()

DFS_Start()


while True:  # <-- main game loop
    pygame.display.update()
#-----------------------------