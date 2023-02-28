La idea es para cada i (0 , |S| - 1) hacer una busqueda binaria en el intervalo [i,|S| - 1] para buscar el menor X tal que [i,X] contenga 1 2 3 almenos una vez, para saber si en el intervalo [i,X] contiene almenos uno de esos numeros basta con hacer un pre-procesado con una matriz bidimencional donde M[i][j] te dice cuantos i hay hasta la posicion j luego hay i numeros en el intervalo a,b
M[i][b] - M[i][a-1]

https://codeforces.com/problemset/problem/1354/B
