# include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName){
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val){
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore(int depth) {
    RubiksCubeBitboard cube;
    queue<RubiksCubeBitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while(!q.empty()){
        int n = q.size();
        curr_depth++;
        if(curr_depth == depth) break;   // This depth as 9 we have set here is kind of temporary, we can change it and can try it for different depths as it was saying it is system dependent that till what depth you can calculate it.
        for(int counter = 0; counter <n; counter++){
            RubiksCubeBitboard node = q.front();
            q.pop();
            for(int i=0;i<18;i++){
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}





/*
Actually here i was thinking that where we are setting the other states that were not explored as something then
i got it as i can use this function "CornerDBMaker(string _fileName, uint8_t init_val)" to do so that is initially 
i will assign to every that number and then i will apply it so whatever will have to be change so they will get change 
otherwise it will become that number that i want it

SO SUCH THAT I WILL DO SO
*/