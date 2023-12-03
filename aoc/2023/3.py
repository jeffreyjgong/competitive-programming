def read_file_to_2d_array(file_path):
    array_2d = []
    with open(file_path, 'r') as file:
        for line in file:
            array_2d.append(list(line.strip()))
    
    return array_2d

def check_around_number(grid, row, cols, width, height):
    # check left number
    coords_to_check = []
    coords_to_check.append((row-1, cols[0]-1))
    coords_to_check.append((row, cols[0]-1))
    coords_to_check.append((row+1, cols[0]-1))

    # check middle
    for col in cols:
        coords_to_check.append((row-1, col))
        coords_to_check.append((row+1, col))

    # check right number
    coords_to_check.append((row-1, cols[len(cols)-1]+1))
    coords_to_check.append((row, cols[len(cols)-1]+1))
    coords_to_check.append((row+1, cols[len(cols)-1]+1))

    for coord in coords_to_check:
        if (is_valid(grid, coord[0], coord[1], width, height)):
            return True
    return False
    

def is_valid(grid, r, c, width, height):
    if (r < 0 or r >= height or c < 0 or c >= width):
        return False
    if (grid[r][c] != '.' and not grid[r][c].isdigit()):
        return True 

    return False

def cols_to_num(grid, r, cols):
    num = ""
    for col in cols:
        num += grid[r][col]
    
    return int(num)

def traverse_grid(grid):
    width = len(grid[0])
    height = len(grid)

    all_engine_parts = 0

    cur_cols = []

    for r in range(0, height):
        for c in range(0, width):
            if (not grid[r][c].isdigit()):
                if (len(cur_cols) > 0):
                    if (check_around_number(grid, r, cur_cols, width, height)):
                        all_engine_parts += cols_to_num(grid, r, cur_cols)
                    cur_cols.clear()
            else:
                # is digit
                cur_cols.append(c)
                if (c == width-1):
                    if (check_around_number(grid, r, cur_cols, width, height)):
                        all_engine_parts += cols_to_num(grid, r, cur_cols)
                    cur_cols.clear()

    return all_engine_parts 

file_path = 'input-3.txt'
grid = read_file_to_2d_array(file_path)

all_engine_parts = traverse_grid(grid)

print("Sum of engine parts: ", all_engine_parts)