C, N, K = list(map(int,input().split()))
child = []
for j in range(0,N):
    c = list(int,map(input().split()))
    child.append(c)
if K == 0:
    if N > C:
        print("Bad")
    else:
        overlaps, num_of_overlaps = 0,0
        overlaps, num_of_overlaps = overlaps_exists(child)
        if overlaps == 0:
            print("Good")
        elif overlaps == 1:
            print("Bad")
elif K == 1:
    if N > C:
        print("Bad")
    else:
        demand = 0
        for i in child:
            demand += i[1]-i[0]+1
        if demand > C:
            print("Bad")
        else:
            overlaps, num_of_overlaps = 0,0
            overlaps, num_of_overlaps = overlaps_exists(child)
            if overlaps == 0:
                print("Good")
            elif overlaps == 1:
                num_overlaps = [0]*len(child)
                max = 0
                for i in range(len(child)):
                    for j in range(i+1, len(child)):
                        if child[i][1] >= child[j][0]:
                            num_overlaps[i] += 1
                            num_overlaps[j] += 1
                for i in range(len(child)):
                    if num_overlaps[i] > num_overlaps[max]:
                        max = i
                if (child[max][1]+child[max][0]-1) > (C-demand+child[max][0]+child[max][1]-1):
                    print("Bad")
                else:
                    print("Good")