
typedef struct node{
    long id;
    double lat,lon;
}Node;

typedef struct nodelist{
    Node spot;
    struct nodelist* next;
}Nodelist;

typedef struct link{
    long id,nodex,nodey,way;
    double length,veg,arch,land;
    //POI
}Link;

typedef struct way{
    long id;
    Nodelist* head;
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
    Nodelist* head;
}Geom;

typedef struct geomList{
    Geom currentGeom;
    struct GeomList* next;
}GeomList;

