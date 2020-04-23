#ifndef mark	// use macro to avoid repeating declaration
#define mark 1
typedef struct node{
    long id;
    double lat,lon,dis;
}Node;

typedef struct nodeList{
    Node spot;
    struct nodeList* next;
}NodeList;

typedef struct link{
    long id,nodex,nodey,way;
    double length,veg,arch,land;
}Link;

typedef struct way{
    long id;
    NodeList* head;
}Way;

typedef struct wayList{
    Way currentWay;
    struct wayList* next;
}WayList;

typedef struct linkList{
    Link currentLink;
    struct linkList* next;
}LinkList;

typedef struct geom{
    long id;
    NodeList* head;
}Geom;

typedef struct geomList{
    Geom currentGeom;
    struct geomList* next;
}GeomList;

typedef struct adjacencyList{
    Node spot;
    NodeList* head;
    struct adjacencyList* next;
}AdjacencyList;

typedef struct marked{
    int id,val;
}Marked;

// typedef struct queue{
//     NodeList* first;
//     NodeList* last;
//     int n;
// }Queue;


typedef struct queue{
    NodeList* head;
    int n;
}Queue;





typedef struct edge{
    long x,y;
    double dis;
}Edge;

typedef struct edgeList{
    Edge e;
    struct edgeList* next;
}EdgeList;


#endif