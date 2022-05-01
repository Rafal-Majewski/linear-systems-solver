# Linear Systems Solver
## Building
```
mkdir build
cd build
cmake ..
make
```
## Running tests
Build the project and then while being in the `build` directory run:
```
ctest
```

## Usage
### Solving linear systems
```
./linear-systems-solver arg1Name=arg1Value arg2Name=arg2Value ...
```
#### Parameters
- `method`: The method to use to solve the linear system. Possible values are:
  - `g`: Gauss elimination
  - `pg`: Partial Gauss elimination
  - `fg`: Full Gauss elimination
#### Input
The linear system itself is passed in the standard input.
The required format is:
```
rowsCount columnsCount
coef_0_0 coef_0_1 ... coef_0_{columnsCount - 1} var_0_name const_0
coef_1_0 coef_1_1 ... coef_1_{columnsCount - 1} var_1_name const_1
...
coef_{rowsCount - 1}_0 coef_{rowsCount - 1}_1 ... coef_{rowsCount - 1}_{columnsCount - 1} var_{rowsCount - 1}_name const_{rowsCount - 1}
```

For example:
```
3 3
 2  3  7 x  48
 3  0 -1 y  1
-1 -5 -6 z -47
```
Corresponding to the following linear system:
```
 2x + 3y + 7z = 48
 3x + 0y - 1z = 1
-1x - 5y - 6z = -47
```
Which written in the matrix form is:
```
[  2  3  7 ][ x ]   [  48 ]
[  3  0 -1 ][ y ] = [  1  ]
[ -1 -5 -6 ][ z ]   [ -47 ]
```