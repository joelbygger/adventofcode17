import collections
import itertools
import sys

class SpiralGrid:
    def __init__(self):
        #self.Point = collections.namedtuple('Point', (set('x', 'y'), 'val')) # TODO make private?
        #p = Point((x = 1, y = 1), val = 1)
        #p = dict({1,1}=1)
        ##p = {(1,1) : 1}
        self.dir_generator = self.direction_generator()
        self.start_pos = (1, 1)
        self.grid = collections.OrderedDict()
        self.grid[self.start_pos] = 1
        #self.grid[(1,2)] = 2
        #self.grid[(3,1)] = 5
        #self.grid[(3,1)] = 6
        print("1 ", self.grid)
        print("2 ", next(reversed(self.grid)))
        print("20 ", next(reversed(self.grid))[0])
        print("21 ", self.grid[next(reversed(self.grid))])
        print("3 ", self.grid[1,1])
        #print("31 ", self.grid[3,1])
        ##print("31 ", self.grid[1,2]) key error
        print("4 ", self.grid.items)
        ##print("41 ", self.grid.keys()[-1])
        ##print("5 ", self.grid.last())
        ##print("50 ", self.grid.index((1,1)))
        print("5 ", list(self.grid).index((1,1)))

    def direction_generator(self):
        steps_in_dir = 1
        steps_in_dir_increase = 0
        
        for dir in itertools.cycle([(1, 0), (0, -1), (-1 , 0), (0, 1)]): # Right, Up, Left, Down
            for _ in range(steps_in_dir):
                yield dir

            steps_in_dir_increase += 1
            if steps_in_dir_increase >= 2:
                steps_in_dir += 1
                steps_in_dir_increase = 0
    
    def _add_point(self):
        dir = next(self.dir_generator)
        last_point = next(reversed(self.grid))
        self.grid[(last_point[0] + dir[0], last_point[1] + dir[1])] = self.grid[last_point] + 1
        #for _ in range(3):
            #print("21 ", self.grid[next(reversed(self.grid))])
            #yield #next(reversed(self.grid))

    def create_grid(self, reach_value):
        while self.grid[next(reversed(self.grid))] < reach_value:
            self._add_point()
        #print(next(filter(lambda v: self.grid[v] > max_point_val, self.add_point())))
        #print(next(filter(lambda: self.grid[next(reversed(self.grid))] > max_point_val, self.add_point())))
        #print(" apa ", self.grid[next(self.add_point())])
        #print(next(filter(lambda v: v > max_point_val, self.grid[self.add_point()])))
        #p = [p for p in self.add_point() if self.grid[next(reversed(self.grid))] > max_point_val]
        #print("asd" , self.grid[next(reversed(self.grid))])

    def get_manhattan_distance(self, to_value):
        
        # 1.                                    Get a list of all values
        # 2.                                                             In the list, get the index that contains serched value.
        # 3. 
        # 4.             Get a list of all keys
        # 5.                                   In the list, get the key with the same index as searched for value
        pos = list(self.grid.keys())[list(self.grid.values()).index(to_value)]
        #print("tjoff2 ", pos)
        return abs(pos[0] - self.start_pos[0]) + abs(pos[1] - self.start_pos[1])
        #print("tjoff2 ", list(self.grid.keys())[list(self.grid.values()).index(to_value)])
        #print("tjoff5 ", list(self.grid.values()))
        #print("tjoff6 ", list(self.grid.keys()))
        #print("tjoff61 ", self.grid.keys())
        #print("tjoff7 ", self.grid.values().index(to_value))



if __name__ == "__main__":
    grid = SpiralGrid()
    grid.create_grid(int(sys.argv[1]))
    dist = grid.get_manhattan_distance(int(sys.argv[1]))
    print("Manhattan distance to value {} is {}".format(sys.argv[1], dist))