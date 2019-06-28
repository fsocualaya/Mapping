//#include <GL/glut.h>
#include <iostream>
#include "read.h"
#include "graph.h"
#include <chrono>
#include<vector>

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]) {
    cout<<"***************************************\n";
    cout<<"******************GRAFO_1**************\n";
    cout<<"***************************************\n\n";
    graph g1;
    rd gg;
    int cantidad;
    cout<<"Ingrese cantidad de taxis: "<<endl;
    cin>>cantidad;
    gg.getGraph(&g1);
    g1.iniciar_taxis(cantidad);
    auto mapataxis = g1.taxistas;
    long long a,b;
    bool ciclo=true;
    cout<<"Dijkstra: "<<endl;
    auto start = high_resolution_clock::now();
    for ( auto it = mapataxis.begin(); it != mapataxis.end(); ++it )
    {
      g1.Dijkstra(412528253,(*it).second->nodo->get());
      cout<<"---------------------------------------------"<<endl;
    }
    auto finish = high_resolution_clock::now();
    auto durationDij = duration_cast<microseconds>(finish-start);
    cout<<"A*: "<<endl;
    start = high_resolution_clock::now();
    for ( auto it = mapataxis.begin(); it != mapataxis.end(); ++it )
    {
      g1.A_Star(412528253,(*it).second->nodo->get());
      cout<<"---------------------------------------------"<<endl;
    }
    finish = high_resolution_clock::now();
    auto durationA = duration_cast<microseconds>(finish-start);
    cout<<"Tiempo tomado por Dijkstra con "<<cantidad<<" taxis : "<<durationDij.count()<<" microseconds"<<endl;
    cout<<"Tiempo tomado por A* con "<<cantidad<<" taxis : "<<durationA.count()<<" microseconds"<<endl;
    cout<<endl;
    /*
    g1.iniciar_taxis(3);
    while(ciclo){
      cout<<endl;
      Sleep(1000);
      g1.mover_taxis();
    }
    */


    /*
    while(ciclo){
      cout<<"ingrese nodos: "<<endl;
      cin>>a;
      if(a==0)break;
      cin>>b;
      g1.A_Star(a,b);
      cout<<endl;
    }
    */

    //g1.print();
    cout <<endl;
    /*
    g1.floyd_warshall();
    g1.dijkstra('A');
    g1.greedyBFS('A','F');
    cout<<"GGGGGGGGGGG"<<endl;
    */
    //



    /*g1.conexo();
    cout <<endl;
    g1.prim();
    cout <<endl;
    g1.kruskal();
    cout <<endl;
    cout<<g1.BFS()<<endl;
    cout <<endl;
    g1.bipartito();
    cout <<endl;
    cout<<"La densidad es: "<<g1.densidad()<<endl;
    cout <<endl;
    g1.info_nodo();
    */
    return EXIT_SUCCESS;
}



//git checkout -b feature/prim
//git push origin feature/prim
