# Historia
Los protagonistas son 3 estudiantes de bachillerato que como parte de sus actividades del club de literatura al que pertenecen exploran una biblioteca abandonada. Allí empiezan a ver algunos de los libros antiguos, al abrir uno de ellos emite una luz cegadora y cuando abren los ojos están en un castillo de un mundo medieval mágico en el que una reina, allí reciben las armas legendarias de los héroes (arco mágico, espada mágica y varita mágica) y se les encarga derrotar al lagarto endemoniado.
## Personajes
- Kishi Hideaki: gafas. Varita mágica.
- Fukuhara Arisu: pelo negro largo. Espada mágica.
- Hayashi Takesi: rapado. Arco mágico.

### Estadísticas iniciales de cada personaje
| Personaje       | Ataque físico | Defensa física | Ataque mágico | Defensa mágica | Velocidad |
|-----------------|---------------|----------------|---------------|----------------|-----------|
| Fukuhara Arisu  | 180           | 92             | 43            | 65             | 200       |
| Kishi Hideaki   | 20            | 82             | 173           | 201            | 100       |
| Hayashi Takeshi | 100           | 100            | 100           | 100            | 50        |

### Niveles
El nivel de un personaje se determinará por el número de ataques exitosos relizados siendo:
| Nivel               | 1 | 2 | 3  | 4  | nivel           |
|---------------------|---|---|----|----|-----------------|
| Enemigos derrotados | 0 | 5 | 10 | 15 | 5\*\(nivel\-1\) |

Cada nivel sumará 3 en cada estadística.


## Enemigos
Son los enemigos clásicos de cualquier juego de fantasia. Para darle mayor aleatoriedad se le sumará un número aleatorio entre -10 y 10 a cada una.
### Enemigos de camino fácil
| Nombre                       | Ataque físico | Defensa física | Ataque mágico | Defensa mágica | Velocidad |
|------------------------------|---------------|----------------|---------------|----------------|-----------|
| Slime                        | 60            | 120            | 45            | 72             | 50        |
| Goblin                       | 113           | 50             | 0             | 50             | 100       |
| Cachorro de lobo endemoniado | 100           | 70             | 40            | 60             | 88        |


### Enemigos de camino medio
| Nombre           | Ataque físico | Defensa física | Ataque mágico | Defensa mágica | Velocidad |
|------------------|---------------|----------------|---------------|----------------|-----------|
| Hombre lagarto   | 130           | 100            | 20            | 50             | 130       |
| Soldado demonio  | 100           | 100            | 100           | 100            | 100       |
| Lobo endemoniado | 120           | 100            | 80            | 70             | 140       |
| Hada oscura      | 40            | 60             | 150           | 200            | 90        |


### Enemigos de camino difícil
| Nombre                     | Ataque físico | Defensa física | Ataque mágico | Defensa mágica | Velocidad |
|----------------------------|---------------|----------------|---------------|----------------|-----------|
| Slime gigante              | 200           | 240            | 100           | 100            | 80        |
| Rey demonio                | 200           | 200            | 200           | 200            | 200       |
| Troll                      | 230           | 180            | 0             | 100            | 100       |
| Reina de las hadas oscuras | 100           | 100            | 250           | 300            | 300       |


# Idea general del juego
La idea consiste en hacer un juego RPG de consola de corta duración, la historia iría desde la aparición de los tres personajes principales (todos controlados por el jugador) hasta ir a una mazmorra y derrotar al jefe final, para ello tendría que subir de nivel con combates aleatorios (con una dificultad balanceada según la zona de la cuadrícula).
El sistema de combate sería por turnos y tendría seis variables: ataque y defensa físicos y mágicos, salud y velocidad. En los combates se decidiría el orden de los turnos por la velocidad y luego los daños se calcularían haciendo:
Daño = (ataque físico del movimiento – defensa física del oponente) + (ataque mágico del movimiento – defensa mágica del openente).
Si la velocidad de un personaje es mayor que la de su oponente tiene 50% de probabilidad de esquivar el ataque.
El jugador tendría un menú para elegir entre cuatro ataques y podría ver las estadísticas de sus ataques antes de realizarlos. Cada ataque, además tendría un número limitado de usos, que se reinician cuando el jugador va a uno de los puntos de curación.
Todas las estadísticas están condicionadas por el nivel que funcionaría como multiplicador de las estadísticas haciendo que el jugador deba tener combates antes de enfrentarse al jefe final.
La cuadrícula será de 15x15 casillas, el jugador saldrá de un punto inicial predefinido y tendrá que ir intuyendo el camino a la mazmorra de jefe final según donde haya enemigos más fuertes que tendrían una probabilidad de salir de un 35% por casilla.

# Diseño del programa
Al iniciar el programa habrá un menú de inicio que permita elegir entre empezar una nueva partida, cargar una guardada (almacenamiento persistente) o terminar el programa.
Si la partida es nueva se explicará la historia y el objetivo del juego (derrotar al jefe final) y se presentarán a los personajes.
Después empezaría el juego como tal pidiendo al jugador que introduzca la dirección de la casilla a la que quiere ir mediante WASD (arriba, izquierda, abajo, derecha) y se comprueba si hay obstáculos, en caso contrario el jugador se mueve de casilla y se aplica la probabilidad con números aleatorios para saber si hay un enemigo y si lo hay el jugador se enfrentaría a él. Para el combate habría que comprobar si la casilla es zona verde, amarilla o roja para establecer la dificultad del combate (nivel y tipo de enemigos), entonces se escogería un enemigo de una lista y se procedería al combate. En el combate se establece el orden de ataque según la velocidad, en los turnos de los personajes el jugador elige sus ataques (habría un menú con 4 ataques disponibles y cada ataque se podrá hacer un determinado número de veces).
La muerte de los personajes en el juego sería irreversible y penalizaría al resto de personajes (bajaría sus estadísticas en un 05%) y el jugador tendría que seguir la aventura con el personaje que queda. En caso de que los tres personajes mueran se termina el juego volviendo al menú principal.
En cada turno el jugador tendría la opción de guardar y cargar partida.
Este mismo sistema se aplicaría hasta el final del juego.

## Mapa del juego

![Esquema del mapa](/mapa.png)
## Matriz
- 0: muro
- 1: camino facil
- 2: camino medio
- 3: camino dificil
- 4: punto de curación
- 5: punto de inicio
- 6: jefe final

| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 3 | 3 | 3 | 3 | 3 | 0 | 3 | 0 | 4 | 0 |
| 0 | 6 | 0 | 0 | 0 | 3 | 0 | 0 | 0 | 3 | 0 | 3 | 0 | 3 | 0 |
| 0 | 4 | 3 | 3 | 3 | 3 | 0 | 0 | 0 | 3 | 0 | 3 | 0 | 2 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 3 | 4 | 3 | 0 | 2 | 0 |
| 0 | 2 | 2 | 2 | 3 | 3 | 3 | 3 | 3 | 3 | 0 | 3 | 0 | 2 | 0 |
| 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 3 | 0 | 2 | 0 |
| 0 | 0 | 0 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 0 |
| 0 | 0 | 0 | 3 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 |
| 0 | 5 | 0 | 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 4 | 0 | 2 | 0 |
| 0 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 4 | 0 | 2 | 0 |
| 0 | 1 | 1 | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 2 | 0 | 2 | 0 |
| 0 | 1 | 1 | 1 | 0 | 0 | 2 | 2 | 2 | 2 | 2 | 2 | 0 | 2 | 0 |
| 0 | 1 | 1 | 1 | 0 | 0 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 2 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
