#include "file_utils.hh"

Vector<string> read_lines_from_file(string filename) {
    Vector<string> lines;
    // create input file stream
    ifstream f(filename);
    // check for error
    if (f.fail()) {
        throw runtime_error("Couldn't open file for reading");
    }
    // read lines from file
    string line;
    while (getline(f, line)) {
        lines.push_back(line);
    }
    // close file
    f.close();
    return lines;
}

void insert_line_in_file(string filename, string line) {
    // create output file stream with append mode
    ofstream f(filename, ios::app);
    // check for error
    if (f.fail()) {
        throw runtime_error("Couldn't open file for writing");
    }
    // append to file
    f << line << endl;
    // close file
    f.close();
}
