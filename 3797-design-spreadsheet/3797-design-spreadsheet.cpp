class Spreadsheet {
public:
    vector<vector<int>> sheet;  // 2D grid to store values
    int rows, cols;

    Spreadsheet(int r) {
        rows = r;
        cols = 26;
        sheet.assign(rows, vector<int>(cols, 0));
    }
    
    // Parse "A1" -> (row, col)
    pair<int, int> parseCell(const string &cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        sheet[r][c] = value;
    }
    
    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        sheet[r][c] = 0;
    }
    
    int getValue(string formula) {
        // formula is like "=X+Y"
        string expr = formula.substr(1); 
        size_t pos = expr.find('+');
        string left = expr.substr(0, pos);
        string right = expr.substr(pos + 1);

        return getValueOrInt(left) + getValueOrInt(right);
    }

private:
    int getValueOrInt(const string &token) {
        if (isalpha(token[0])) {  // It's a cell reference
            auto [r, c] = parseCell(token);
            return sheet[r][c];
        } else {  // It's an integer
            return stoi(token);
        }
    }
};
