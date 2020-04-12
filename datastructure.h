#ifndef mark	// use macro to avoid repeating declaration
#define mark 1
typedef struct node{
    long id;
    double lat,lon;
}Node;

typedef struct nodelist{
    Node spot;
    struct nodelist* next;
}NodeList;

typedef struct link{
    long id,nodex,nodey,way;
    double length,veg,arch,land;
    //POI
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

#endif