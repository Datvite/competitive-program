import sympy as sp

m = sp.Symbol('m')
A = sp.Matrix([
    [1, -3, 2],
    [m+1, m-2, 1-m],
    [0, m-2, 2]
])

det = A.det()
solutions = sp.solve(det, m)
print(f"Det: {det}")
print(f"Solutions: {solutions}")