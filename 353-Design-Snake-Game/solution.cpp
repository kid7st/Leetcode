class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        score = 0;
        index = 0;
        x = 0;
        y = 0;
        this->food = food;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(direction == "U"){
            x -= 1;
            if(x < 0) return -1;
        }else if(direction == "L"){
            y -= 1;
            if(y < 0) return -1;
        }else if(direction == "D"){
            x += 1;
            if(x >= height) return -1;
        }else if(direction == "R"){
            y += 1;
            if(y >= width) return -1;
        }else{
            return score;
        }
        if(find(snake.begin(), snake.end(), make_pair(x, y)) != snake.end()) return -1;
        snake.push_back({x, y});
        if(index < food.size() && x == food[index].first && y == food[index].second){
            score += 1;
            index += 1;
        }else{
            snake.erase(snake.begin());
        }
        return score;
    }
    
private:
    vector<vector<int>> board;
    int width;
    int height;
    int score; // also the lenght of the snake
    int index; // index of the food vector
    //head of the snake
    int x; 
    int y;
    vector<pair<int, int>> food;
    vector<pair<int, int>> snake;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */