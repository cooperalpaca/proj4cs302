Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | .001          | 89  Kb         |
| 20            | .001          | 104 Kb         |
| 50            | .003          | 197 Kb         |
| 100           | .009          | 51  Kb         |
| 200           | .036          |  2  Mb         |
| 500           | .219          | 10  Mb         |
| 1000          | .930          | 40  Mb         |
|---------------|---------------|----------------|


This project was made by cooper sarphie 