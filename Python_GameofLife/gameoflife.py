import random
from collections import defaultdict


celltable = defaultdict(int, {
 (1, 2): 1,
 (1, 3): 1,
 (0, 3): 1,
 } ) # Only need to populate with the keys leading to life

def sim(maxgenerations, universe, cellcount=(10,10)):
    for i in range(maxgenerations):
        ## for debug printing:
        # print "\nGeneration %3i:" % ( i, )
        # print return_universe(universe)
        nextgeneration = defaultdict(int)
        for row in range(cellcount[1]):
            for col in range(cellcount[0]):
                nextgeneration[(row,col)] = celltable[
                    ( universe[(row,col)],
                      -universe[(row,col)] + sum(universe[(r,c)]
                                                 for r in range(row-1,row+2)
                                                 for c in range(col-1, col+2) )
                    ) ]
        universe = nextgeneration
    return universe

def return_universe(universe):
    printdead, printlive = '-#'
    output = []
    for row in range(cellcount[1]):
        output.append(''.join(str(universe[(row,col)])
                            for col in range(cellcount[0])).replace(
                                '0', printdead).replace('1', printlive))

    return '\n'.join(output)



if __name__ == '__main__':
    ## sample starting conditions
    maxgenerations = 3
    cellcount = 10,10
    # blinker
    u = universe = defaultdict(int)
    u[(1,0)], u[(1,1)], u[(1,2)] = 1,1,1
