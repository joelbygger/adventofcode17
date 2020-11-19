import itertools
import spiral_grid


def test_get_directions():
    grid = spiral_grid.SpiralGrid()
    assert list(itertools.islice(grid.direction_generator(), 25)) == [(1, 0), (0, -1), (-1, 0), (-1, 0), (0, 1), (0, 1), (1, 0), (1, 0), (1, 0), (0, -1), (0, -1), (0, -1), (-1, 0), (-1, 0), (-1, 0), (-1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (1, 0), (1, 0), (1, 0)]

def test_create_grid():
    grid = spiral_grid.SpiralGrid()
    grid.create_grid(reach_value = 9)
    assert next(reversed(grid.grid)) == (2, 2)
    assert grid.grid[1,1] == 1
    assert grid.grid[0,0] == 5
    assert grid.grid[2,2] == 9


def test_get_manhattan_distance():
    grid = spiral_grid.SpiralGrid()
    grid.create_grid(reach_value = 1024)

    assert grid.get_manhattan_distance(1) == 0
    assert grid.get_manhattan_distance(12) == 3
    assert grid.get_manhattan_distance(23) == 2
    assert grid.get_manhattan_distance(1024) == 31

def test_part_1_answer():
    grid = spiral_grid.SpiralGrid()
    grid.create_grid(reach_value = 325489)

    assert grid.get_manhattan_distance(325489) == 552
