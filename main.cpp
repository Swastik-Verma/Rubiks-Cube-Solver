# include<bits/stdc++.h>
// # include "Model/RubiksCubeBitboard.cpp"  it is included in pathernDatabases/CornerDBMaker.cpp
# include "PatternDatabases/CornerDBMaker.cpp"
# include "Solver/IDAstarSolver.h"
# include "Solver/IDDFSSolver.h"


using namespace std;

int main(){

    // for(int i=1;i<=13;i++){
    //     //
    //     CornerDBMaker  depth_1_db("corner.db",i+1);
        
    //     auto start = chrono::high_resolution_clock::now();
    //     depth_1_db.bfsAndStore(i);
    //     auto end = chrono::high_resolution_clock::now();
    
    //     cout << "Time (till depth "<<i<<"): "
    //         << chrono::duration_cast<chrono::microseconds>(end - start).count()
    //         << " milliseconds\n";
    // }
    // Time (for depth 13): 56425205 milliseconds   
    // I have calculated this database till depth 13       
    
                                                
    RubiksCubeBitboard cube1;
    cube1.print();
    auto moves = cube1.randomShuffleCube(7);
    for(auto v : moves){
        cout<<cube1.getMove(v)<<"\t";
    }
    cout<<"\nAfter Shuffling,\n";
    cube1.print();
    
    IDAstarSolver<RubiksCubeBitboard,HashBitboard> IDAstarSolver_cube(cube1,"corner.db");
    cout<<"math\n";
    auto IDA_moves = IDAstarSolver_cube.solve();
    for(auto v : IDA_moves){
        cout<<cube1.getMove(v)<<"\t";
    }

    // IDDFSSolver<RubiksCubeBitboard,HashBitboard> IDAstarSolver_cube(cube1);
    // cout<<"math\n";
    // auto IDA_moves = IDAstarSolver_cube.solve();
    // for(auto v : IDA_moves){
    //     cout<<cube1.getMove(v)<<"\t";
    // }
  

    

    return 0;
}