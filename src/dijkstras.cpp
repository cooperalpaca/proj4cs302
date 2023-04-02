#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// struct Node
// {
//   int row, col;
//   int weight;
//   bool operator<(const Node &other) const
//   {
//     return weight < other.weight;
//   }
//   bool operator==(const Node &other) const
//   {
//     return row == other.row && col == other.col;
//   }

//   // Inequality operator for comparing nodes based on row and col members
//   bool operator!=(const Node &other) const
//   {
//     return !(*this == other);
//   }
// };

const int INF = numeric_limits<int>::max();
// structure of the nodes in the graph, this is not used as much however it was useful for my dijkstra function
struct Node
{
  int row, col;
  int dist;
  bool visited;
};
// structure used to compare nodes in the priority queue
struct CompareNode
{
  bool operator()(Node const &n1, Node const &n2)
  {
    return n1.dist > n2.dist;
  }
};

void dijkstras(vector<vector<int>> &weights, int start_row, int start_col, int end_row, int end_col)
{
  int n = weights.size();
  int m = weights[0].size();

  vector<vector<bool>> visited(n, vector<bool>(m, false));
  vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

  priority_queue<Node, vector<Node>, CompareNode> pq; // priority queue to store the nodes and their ddistances from the start

  pq.push({start_row, start_col, 0, false}); // add the start node to the queue and set the distance to 0
  distance[start_row][start_col] = 0;        // add the distance to the start into the vector of distances

  while (!pq.empty())
  {
    Node current = pq.top(); // get the current node that is at the top of the queue to check if it is the end
    pq.pop();

    if (visited[current.row][current.col]) // if the node has been checked already then skip it
    {
      continue;
    }

    visited[current.row][current.col] = true; // add it to the vector of visited nodes

    if (current.row == end_row && current.col == end_col) // if it is the end then move on from this loop
    {
      break;
    }

    vector<pair<int, int>> neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // vector to store the location of all the neigbors in relation to the current node

    for (auto neighbor : neighbors) // neighbor is equal to the pairs in the neighbors vector
    {
      int row = current.row + neighbor.first; // set the coords of neighbor to be the actual neighbor of the current
      int col = current.col + neighbor.second;

      if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col])
      {
        continue;
      }

      int dist = distance[current.row][current.col] + weights[row][col]; // calculate the distance of the neighbor of current one

      if (dist < distance[row][col])
      {
        distance[row][col] = dist;
        pq.push({row, col, dist, false}); // add the neighbor to the priority queue
      }
    }
  }

  // Reconstruct the shortest path from start to end node using the distance map
  int path_weight = 0;
  vector<pair<int, int>> path; // the nodes in the path

  Node current = {end_row, end_col, distance[end_row][end_col], false};
  while (current.row != start_row || current.col != start_col)
  {
    path.push_back({current.row, current.col});

    vector<pair<int, int>> neighbors = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // neighbor vector

    for (auto neighbor : neighbors) // for each part in the neighbors vector
    {
      int row = current.row + neighbor.first; // make the neighbor into the actual neighbor
      int col = current.col + neighbor.second;

      if (row < 0 || row >= n || col < 0 || col >= m)
      {
        continue;
      }

      int dist = distance[row][col];

      if (dist < INT_MAX && dist + weights[current.row][current.col] == distance[current.row][current.col]) // use the distance to determine if the neighbor being searched is the right one to go the shortest possible distance back to the start
      {
        current = {row, col, dist, false};
        path_weight += weights[current.row][current.col];
        break;
      }
    }
  }
  path.push_back({start_row, start_col});
  reverse(path.begin(), path.end()); // reverse the vector to read the nodes from start to end

  // Print out the coordinates of the nodes on the path and the path weight
  cout << path_weight << endl;
  for (auto p : path)
  {
    cout << p.first << " " << p.second << endl;
  }
}

int main()
{
  // Read input
  int num_tiles;
  cin >> num_tiles;

  unordered_map<char, int> tile_costs;
  for (int i = 0; i < num_tiles; i++)
  {
    char tile_name;
    int tile_cost;
    cin >> tile_name >> tile_cost;
    tile_costs[tile_name] = tile_cost;
  }

  int num_rows, num_cols;
  cin >> num_rows >> num_cols;

  vector<vector<int>> graph(num_rows, vector<int>(num_cols));
  for (int r = 0; r < num_rows; r++)
  {
    for (int c = 0; c < num_cols; c++)
    {
      char tile_char;
      cin >> tile_char;

      int weight = tile_costs[tile_char];
      graph[r][c] = weight; // set the value in the vector as the weight of each node
    }
  }
  int x, y, a, b;
  cin >> x >> y >> a >> b;      // get the coords of the start and end
  dijkstras(graph, x, y, a, b); // do dijkstras on the graph of ints

  return 0;
}
