#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <filesystem>
#include <cmath>
using namespace std;

namespace fs = filesystem;

struct Pass
{
    int time_start, time_end, sender_id, receiver_id;
};

// Parse the CSV file to extract passes
vector<Pass> parseCSV(const string& filename)
{
    vector<Pass> passes;
    ifstream file(filename);

    if (!file.is_open())
    {
        throw runtime_error("Error: Could not open file " + filename);
    }

    string line;
    getline(file, line); // Skip header line

    while (getline(file, line))
    {
        stringstream ss(line);
        Pass pass;
        string value;

        try
        {
            getline(ss, value, ','); pass.time_start = stoi(value);
            getline(ss, value, ','); pass.time_end = stoi(value);
            getline(ss, value, ','); pass.sender_id = stoi(value);
            getline(ss, value, ','); pass.receiver_id = stoi(value);
            passes.push_back(pass);
        }
        catch (const exception& e)
        {
            cerr << "Invalid row: " << line << " - Skipping." << endl;
        }
    }
    return passes;
}
// Create a graph file (for one half of a match) with validation
void createGraphFile(const vector<Pass>& passes, const string& file_name)
{
    if (passes.empty()) return; // Do not create empty files

    ofstream outfile(file_name);

    // Collect unique players and edges
    unordered_set<int> players;
    unordered_map<int, vector<int>> adjacency_list;

    for (const auto& pass : passes)
    {
        players.insert(pass.sender_id);
        players.insert(pass.receiver_id);
        adjacency_list[pass.sender_id].push_back(pass.receiver_id);
    }

    // Write the number of vertices
    outfile << players.size() << "\n";

    // Map players to indices and write vertex details
    int index = 0;
    unordered_map<int, int> player_map;
    for (const int player : players)
    {
        outfile << index << " \"A" << player << "\"\n";
        player_map[player] = index++;
    }

    // Write edges for each player
    for (const int player : players)
    {
        int vertex_index = player_map[player];
        const auto& edges = adjacency_list[player];

        // Number of edges
        outfile << edges.size() << "\n";

        // Write edge details with validation
        for (const int dest : edges)
        {
            if (player_map.find(dest) == player_map.end())
            {
                cerr << "Invalid edge: " << player << " -> " << dest << " in file: " << file_name << "\n";
                continue; // Skip invalid edge
            }
            outfile << vertex_index << " " << player_map[dest] << "\n";
        }
    }

    outfile.close();
}

// Divide the total time into 14 matches
vector<pair<int, int>> divideTimeIntervals(int min_time, int max_time, int num_matches)
{
    vector<pair<int, int>> intervals;
    int interval_length = (max_time - min_time) / num_matches;

    for (int i = 0; i < num_matches; ++i)
    {
        int start_time = min_time + i * interval_length;
        int end_time = (i == num_matches - 1) ? max_time : start_time + interval_length;
        intervals.push_back({ start_time, end_time });
    }

    return intervals;
}

// Process matches and create files sequentially for each half
void processMatches(const vector<Pass>& passes, const string& output_folder, int num_matches)
{
    // Get the time range
    int min_time = passes.front().time_start;
    int max_time = passes.back().time_end;

    // Divide time into intervals for 14 matches
    auto intervals = divideTimeIntervals(min_time, max_time, num_matches);

    int file_num = 1; // Start numbering files from dg1.txt

    for (int match_num = 0; match_num < num_matches; ++match_num)
    {
        const auto& interval = intervals[match_num];
        int mid_time = (interval.first + interval.second) / 2;

        // Split passes into first and second halves
        vector<Pass> first_half, second_half;
        for (const auto& pass : passes) {
            if (pass.time_start >= interval.first && pass.time_end <= mid_time)
            {
                first_half.push_back(pass);
            }
            else if (pass.time_start > mid_time && pass.time_end <= interval.second)
            {
                second_half.push_back(pass);
            }
        }

        // Create graph files for each half
        createGraphFile(first_half, output_folder + "/dg" + to_string(file_num++) + ".txt");
        createGraphFile(second_half, output_folder + "/dg" + to_string(file_num++) + ".txt");
    }
}

struct Graphlet
{
    int num_v;
    vector<string> vertices;
    vector<pair<int, int>> edges;
};

// Create a pattern graph file
void createPatternFile(const Graphlet& graphlet, const string& folder, int file_num)
{
    string file_name = folder + "/pg" + to_string(file_num) + ".txt";
    ofstream outfile(file_name);

    // Number of vertices
    outfile << graphlet.num_v << "\n";

    // Write vertices
    for (int i = 0; i < graphlet.vertices.size(); ++i)
    {
        outfile << i << " \"" << graphlet.vertices[i] << "\"\n";
    }

    // Number of edges
    outfile << graphlet.edges.size() << "\n";

    // Edges with validation
    for (const auto& edge : graphlet.edges)
    {
        if (edge.first >= graphlet.num_v || edge.second >= graphlet.num_v)
        {
            cerr << "Invalid edge: " << edge.first << " -> " << edge.second << " in file: " << file_name << "\n";
            continue;
        }
        outfile << edge.first << " " << edge.second << "\n";
    }

    outfile.close();
}

int main() {
    string filename = "passes.csv"; // Input file
    string output_folder = "target_graph";
    int num_matches = 14;

    // Parse CSV
    vector<Pass> passes = parseCSV(filename);

    // Ensure output directory exists
    fs::create_directories(output_folder);

    // Process matches
    processMatches(passes, output_folder, num_matches);

    cout << "Target graph files created!" << endl;

    // Define folder for pattern graphs
    string folder = "pattern_graph";
    fs::create_directories(folder);

    // List of graphlets
    vector<Graphlet> graphlets = 
    {
        {1, {"A1"}, {}},                                        // Graphlet "1"
        {2, {"A1", "A2"}, {{0, 1}}},                            // Graphlet "12"
        {3, {"A1", "A2", "A3"}, {{0, 1}, {1, 2}}},              // Graphlet "123"
        {3, {"A1", "A2", "A1"}, {{0, 1}, {1, 0}}},              // Graphlet "121"
        {4, {"A1", "A2", "A3", "A4"}, {{0, 1}, {1, 2}, {2, 3}}}, // Graphlet "1234"
    };

    // Generate pattern graph files
    for (int i = 0; i < graphlets.size(); ++i)
    {
        createPatternFile(graphlets[i], folder, i + 1);
    }

    cout << "Pattern graph files created!" << endl;
    return 0;
}
