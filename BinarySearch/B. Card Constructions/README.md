basta con detectar el la cantidad de cartas para la altura L
f[0] = 2
f[n] = f[n-1] + 3n + 2
luego hacer busquedas binarias sobre el arreglo e ir restando hasta q tengas 0 o 1 cartas
https://codeforces.com/problemset/problem/1345/B