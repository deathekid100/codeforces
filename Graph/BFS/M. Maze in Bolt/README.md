Basicamente es hacer un DFS sobre todas las posiciones que encaje al principio y tener en cuenta que se puede hacer reverse al string

1 - solo llevar dos valores i,j donde i es la posicion de las columnas y j es la posicion de las filas
2 - un movimiento es valido (down, up, left, right) si y solo si no exiten desde 0 .. n - 1 y desde i ... i + |S|(tamaño del string, ojo si i + ... se pasa del tamaño modular y asi empieza desde 0) si no coincide una posicion con 1.

https://codeforces.com/gym/104252/problem/M

