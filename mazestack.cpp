/**
#include <iostream>
#include <stack>

using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    stack<Coord> mazerunner;
    char open = '.';
    char visited = 'v';
    
    //Start at beginning
    mazerunner.push(Coord(sr,sc));
    maze[sr][sc] = visited;
    
    while(!mazerunner.empty())
    {
        Coord mee = mazerunner.top();
        //cout <<  "(" << mee.r() << ", " << mee.c() << ")\n";
        mazerunner.pop();
        
        //we are at the finish line!
        if ( (mee.r() == er) && (mee.c() == ec))
            return true;
        
        //North?
        if (maze[mee.r()-1][mee.c()] == open)
        {
            mazerunner.push(Coord(mee.r()-1, mee.c()));
            maze[mee.r()-1][mee.c()] = visited;
        }
        //East?
        if (maze[mee.r()][mee.c()+1] == open)
        {
            mazerunner.push(Coord(mee.r(),mee.c()+1));
            maze[mee.r()][mee.c()+1] = visited;
        }
        //South?
        if (maze[mee.r()+1][mee.c()] == open)
        {
            mazerunner.push(Coord((mee.r()+1),mee.c()));
            maze[mee.r()+1][mee.c()] = visited;
        }
        //West?
        if (maze[mee.r()][mee.c()-1] == open)
        {
            mazerunner.push(Coord(mee.r(),mee.c()-1));
            maze[mee.r()][mee.c()-1] = visited;
        }
    }
    return false;
}


int main()
    {
        char maze[10][10] = {
            { 'X','X','X','X','X','X','X','X','X','X'},
            { 'X','.','.','.','.','.','.','.','.','X'},
            { 'X','X','.','X','.','X','X','X','X','X'},
            { 'X','.','.','X','.','X','.','.','.','X'},
            { 'X','.','.','X','.','.','.','X','.','X'},
            { 'X','X','X','X','.','X','X','X','.','X'},
            { 'X','.','X','.','.','.','.','X','X','X'},
            { 'X','.','.','X','X','.','X','X','.','X'},
            { 'X','.','.','.','X','.','.','.','.','X'},
            { 'X','X','X','X','X','X','X','X','X','X'}
        };
        
        if (pathExists(maze, 6,4, 1,1))
            cout << "Solvable!" << endl;
        else
            cout << "Out of luck!" << endl;
    }
***/