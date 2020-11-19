import collections
import itertools
import sys

class SpiralGrid:
    def __init__(self):
        self.dir_generator = self.direction_generator() # TODO make private?
        self.neighbors = [
            (-1, -1), (0 , -1), (1, -1), 
            (-1,  0),           (1,  0), 
            (-1,  1), (0,   1), (1,  1)]

        self.start_pos = (1, 1)
        self.grid = collections.OrderedDict()
        self.grid[self.start_pos] = 1

    def _add_point(self, increment : bool):
        move_dir = next(self.dir_generator)
        last_point = next(reversed(self.grid))
        new_pos = (last_point[0] + move_dir[0], last_point[1] + move_dir[1])

        val = 0
        if increment:
            val = self.grid[last_point] + 1
        else:
            for pos in self.neighbors:
                neighbor = (new_pos[0] + pos[0], new_pos[1] + pos[1])
                if neighbor in self.grid:
                    val += self.grid[neighbor]

        self.grid[new_pos] = val

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

    def create_grid(self, reach_value, increment : bool):
        while self.grid[next(reversed(self.grid))] < reach_value:
            self._add_point(increment)

    def get_manhattan_distance(self, to_value):
        # 1.                                    Get a list of all values
        # 2.                                                             In the list, get the index that contains serched value.
        # 3. 
        # 4.             Get a list of all keys
        # 5.                                   In the list, get the key with the same index as searched for value
        pos = list(self.grid.keys())[list(self.grid.values()).index(to_value)]
        return abs(pos[0] - self.start_pos[0]) + abs(pos[1] - self.start_pos[1])

    def get_max_val(self):
        return self.grid[next(reversed(self.grid))]

    def get_val_at_index(self, index):
        return list(self.grid.values())[index]


if __name__ == "__main__":
    def task_1(search_value):
        grid = SpiralGrid()
        grid.create_grid(search_value, increment = True)
        
        dist = grid.get_manhattan_distance(search_value)
        print("Manhattan distance to value {} is {}".format(search_value, dist))

    def task_2(search_value):
        grid = SpiralGrid()
        grid.create_grid(search_value, increment = False)

        val = grid.get_max_val()
        print("Number after incremented number: ", val)

    task_1(int(sys.argv[1]))
    task_2(int(sys.argv[1]))