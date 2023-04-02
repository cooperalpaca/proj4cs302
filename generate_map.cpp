#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
    // Read in the size of the map from standard input
    int N;
    cin >> N;

    // Define the set of chars to choose from
    vector<char> chars = {'f', 'g', 'G', 'h', 'm', 'r'};
    vector<int> vals = {3, 1, 2, 4, 7, 5};

    // Define a random number generator to select the chars
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 5);

    // Generate the map
    vector<vector<char>> map(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int char_index = distr(gen);
            map[i][j] = chars[char_index];
        }
    }

    // Print the mapping of each char to a number
    cout << chars.size() << endl;
    for (int i = 0; i < chars.size(); i++)
    {
        cout << chars[i] << " " << vals[i] << endl;
    }

    // Print the generated map
    cout << N << " " << N << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    // Print the start and end positions
    cout << "0 0" << endl;
    cout << N - 1 << " " << N - 1 << endl;

    return 0;
}
