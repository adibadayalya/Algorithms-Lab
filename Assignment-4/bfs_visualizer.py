import pygame
from pygame import gfxdraw
import random
import time

pygame.init()
pygame.font.init()
myfont = pygame.font.SysFont("Comic Sans MS", 12)
myfont2 = pygame.font.SysFont("Comic Sans MS", 30)


screen = pygame.display.set_mode((500, 500))

running = True
coordiantes = []  
edges = []


def visited_color(i):
    time.sleep(0.5)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (0, 255, 0))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    pygame.display.update()


def visited_color2(i):
    x = 1350
    y = 320 + 100
    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (0, 255, 0))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    textsurface = myfont.render(" -> Visited Node", True, (0, 255, 0))
    screen.blit(textsurface, (x + 30, y - 10))
    pygame.display.update()


def current_color(i):
    time.sleep(0.05)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (255, 0, 0))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    pygame.display.update()


def current_color2(i):
    x = 1350
    y = 260 + 100
    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (255, 0, 0))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    textsurface = myfont.render(" -> Current Node", True, (255, 0, 0))
    screen.blit(textsurface, (x + 30, y - 10))
    pygame.display.update()


def queue_color2(i):

    gfxdraw.aacircle(screen, 1350, 300, 20, (255, 255, 255))
    gfxdraw.filled_circle(
        screen, 1350, 300, 18, (0, 0, 255)
    )  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (1350 - 6, 300 - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (1350 - 8, 300 - 10))  # allignment change
    else:
        screen.blit(textsurface, (1350 - 16, 300 - 10))  # allignment change
    textsurface = myfont.render(" -> In Queue Node", True, (0, 0, 255))
    screen.blit(textsurface, (1350 + 30, 300 - 10))
    pygame.display.update()


def queue_color(i):
    time.sleep(0.5)
    x = 0
    y = 0
    for j in coordiantes:
        if j[2] == i:
            x = j[0]
            y = j[1]
            break

    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (0, 0, 255))  # colour inside the circle
    textsurface = myfont.render(str(i), True, (0, 0, 0))  # color of text
    if len(str(i)) == 1:
        screen.blit(textsurface, (x - 6, y - 10))  # allignment change
    elif len(str(i)) == 2:
        screen.blit(textsurface, (x - 8, y - 10))  # allignment change
    else:
        screen.blit(textsurface, (x - 16, y - 10))  # allignment change
    pygame.display.update()


def node(x, y, n):
    gfxdraw.aacircle(screen, x, y, 20, (255, 255, 255))
    gfxdraw.filled_circle(screen, x, y, 18, (145, 240, 252))  # colour inside the circle
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


def addingEdgesforTree(non_visited, curr):
    pygame.event.pump()
    if not non_visited:
        return True
    for j in non_visited:
        pygame.event.pump()
        if possible(j, curr):
            non_visited.remove(j)
            x1 = 0
            y1 = 0
            x2 = 0
            y2 = 0
            for k in coordiantes:
                if k[2] == curr:
                    x1 = k[0]
                    y1 = k[1]
                    break
            for k in coordiantes:
                pygame.event.pump()
                if k[2] == j:
                    x2 = k[0]
                    y2 = k[1]
                    break
            edges.append([[x1, y1, curr], [x2, y2, j]])
            if addingEdgesforTree(non_visited, j):
                pygame.draw.line(screen, (255, 255, 255), (x1, y1), (x2, y2), width=3)
                pygame.display.flip()
                return True
            else:
                # pygame.draw.line(screen, (0, 0, 0), (x1, y1), (x2, y2), width=3)
                # pygame.display.flip()
                non_visited.append(j)
                edges.remove([[x1, y1, curr], [x2, y2, j]])
    return False


def bfs():
    visited = []
    for i in range(nodes_number + 10):
        visited.append(0)
    visited[1] = 1
    queue_color(1)
    queue_color2(1)
    queue_list = [1]
    while len(queue_list) != 0:
        pygame.event.pump()
        top_node = queue_list[0]
        queue_list.pop(0)

        current_color(top_node)
        current_color2(top_node)

        for pair in edges:
            pygame.event.pump()
            if (pair[0][2] == top_node and visited[pair[1][2]] == 0) or (
                pair[1][2] == top_node and visited[pair[0][2]] == 0
            ):
                visited[pair[0][2]] = 1
                visited[pair[1][2]] = 1
                if pair[0][2] == top_node:
                    queue_list.append(pair[1][2])
                    time.sleep(0.05)
                    pygame.draw.line(
                        screen,
                        (200, 10, 200),
                        (pair[0][0], pair[0][1]),
                        (pair[1][0], pair[1][1]),
                        width=4,
                    )
                    pygame.display.flip()
                    current_color(top_node)
                    current_color2(top_node)
                    queue_color(pair[1][2])
                    queue_color2(pair[1][2])
                else:
                    queue_list.append(pair[0][2])
                    time.sleep(0.05)
                    pygame.draw.line(
                        screen,
                        (200, 10, 200),
                        (pair[0][0], pair[0][1]),
                        (pair[1][0], pair[1][1]),
                        width=4,
                    )
                    pygame.display.flip()
                    current_color(top_node)
                    current_color2(top_node)
                    queue_color(pair[0][2])
                    queue_color2(pair[0][2])
        visited_color(top_node)
        visited_color2(top_node)


def scrollX(screenSurf, offsetX):
    width, height = screenSurf.get_size()
    copySurf = screenSurf.copy()
    screenSurf.blit(copySurf, (offsetX, 0))
    if offsetX < 0:
        screenSurf.blit(copySurf, (width + offsetX, 0), (0, 0, -offsetX, height))
    else:
        screenSurf.blit(copySurf, (0, 0), (width - offsetX, 0, offsetX, height))


def scrollY(screenSurf, offsetY):
    width, height = screenSurf.get_size()
    copySurf = screenSurf.copy()
    screenSurf.blit(copySurf, (0, offsetY))
    if offsetY < 0:
        screenSurf.blit(copySurf, (0, height + offsetY), (0, 0, width, -offsetY))
    else:
        screenSurf.blit(copySurf, (0, 0), (0, height - offsetY, width, offsetY))

  


screen.fill((0, 0, 0))

pygame.display.update()

textsurface = myfont2.render("BFS Visualizer", True, (255, 255, 0))
screen.blit(textsurface, (1300, 70))
pygame.display.update()


# ------------------------------------------------------NODES RANDOM -------------------------------------------------------------
pygame.event.pump()
i = 1
nodes_number = int(input("Enter Number of Ndoes: "))
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

# ---------------------------------------------------- CONNECTED TREE -----------------------------------------------------------------------

curr = 1
non_visited = []
for i in range(2, nodes_number + 1):  # number of nodes
    non_visited.append(i)

# addingEdgesforTree(non_visited, curr)

# ----------------------------------------------------RANDOM EDGES --------------------------------------------------------------------------

for i in range(1, nodes_number + 1):
    pygame.event.pump()
    for j in range(
        random.randint(1, (nodes_number / 2) - 1),
        random.randint(nodes_number / 2, nodes_number + 1),
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
            pygame.draw.line(screen, (255, 255, 255), (x1, y1), (x2, y2), width=3)
            pygame.display.flip()


# ------------------------------------------------------SHOW NODES-------------------------------------------------

for i in coordiantes:
    pygame.event.pump()
    node(i[0], i[1], str(i[2]))
    pygame.display.update()


# ------------------------------------------------------BFS------------------------------------------

bfs()



while True:  # <-- the pyGame loop

#-----------------------------
    event = pygame.event.poll()
    pressed = pygame.key.get_pressed()
    if event.type == pygame.QUIT:
        break
    if pressed[pygame.K_UP]:
        scrollY(screen, 5)
    elif pressed[pygame.K_DOWN]:
        scrollY(screen, -5)
    elif pressed[pygame.K_LEFT]:
        scrollX(screen, 5)
    elif pressed[pygame.K_RIGHT]:
        scrollX(screen, -5)
    pygame.display.update()
#-----------------------------