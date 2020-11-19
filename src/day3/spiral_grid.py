import collections
import itertools
import sys

class Helpers:
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


class SpiralGrid:
    def __init__(self):
        self.helpers = Helpers()
        self.direction_generator = self.helpers.direction_generator()

        self.start_pos = (1, 1)
        self.grid = collections.OrderedDict()
        self.grid[self.start_pos] = 1

    def _add_point(self):
        dir = next(self.direction_generator)
        last_point = next(reversed(self.grid))
        self.grid[(last_point[0] + dir[0], last_point[1] + dir[1])] = self.grid[last_point] + 1

    def create_grid(self, reach_value):
        while self.grid[next(reversed(self.grid))] < reach_value:
            self._add_point()

    def get_manhattan_distance(self, to_value):
        
        # 1.                                    Get a list of all values
        # 2.                                                             In the list, get the index that contains serched value.
        # 3. 
        # 4.             Get a list of all keys
        # 5.                                   In the list, get the key with the same index as searched for value
        pos = list(self.grid.keys())[list(self.grid.values()).index(to_value)]
        return abs(pos[0] - self.start_pos[0]) + abs(pos[1] - self.start_pos[1])



if __name__ == "__main__":
    grid = SpiralGrid()
    grid.create_grid(int(sys.argv[1]))
    dist = grid.get_manhattan_distance(int(sys.argv[1]))
    print("Manhattan distance to value {} is {}".format(sys.argv[1], dist))