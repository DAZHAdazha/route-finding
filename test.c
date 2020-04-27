#ifndef flag	// use macro to avoid repeating declaration
#define flag 1

#include<stdio.h>
#include<stdlib.h>
#include"datastructure.h"

//test for go through all the <node>
void showNode(NodeList* nodeHead){
    long amount=0;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
        amount++;
        printf("<node> id:%d,lon:%lf,lat:%lf\n",nodeHead->spot.id,nodeHead->spot.lon,nodeHead->spot.lat);
        nodeHead=nodeHead->next;
    }
    printf("the amount of the nodes is %d\n",amount);
    return;
}

//test for go through all the <link>
void showLink(LinkList* linkHead){
    long amount=0;
    linkHead=linkHead->next;
    while(linkHead!=NULL){ 
        amount++;
        printf("<link> id:%d,nodex:%d,nodey:%d,way:%d,length:%lf,veg:%lf,arch:%lf\n",linkHead->currentLink.id,linkHead->currentLink.nodex,linkHead->currentLink.nodey,linkHead->currentLink.way,linkHead->currentLink.length,linkHead->currentLink.veg,linkHead->currentLink.arch);
        linkHead=linkHead->next;
    }
    printf("the amount of the links is %d\n",amount);
    return;
}

// test for go through all the <way>
void showWay(WayList* wayHead){
    long amount=0;
    wayHead=wayHead->next;
    while(wayHead!=NULL){ 
        amount++;
        printf("<wayID> :%d\n",wayHead->currentWay.id);
        wayHead->currentWay.head=wayHead->currentWay.head->next;
        while(wayHead->currentWay.head!=NULL){
            printf("<wayNode> :%d\n",wayHead->currentWay.head->spot.id);
            wayHead->currentWay.head=wayHead->currentWay.head->next;
        }
        printf("\n");
        wayHead=wayHead->next;
    }
    printf("the amount of the ways is %d\n",amount);
    return;
}
    
// test for go through all the <geom>
void showGeom(GeomList* geomHead){
    long amount=0;
    geomHead=geomHead->next;
    while(geomHead!=NULL){ 
        amount++;
        printf("<geomID> :%d\n",geomHead->currentGeom.id);
        geomHead->currentGeom.head=geomHead->currentGeom.head->next;
        while(geomHead->currentGeom.head!=NULL){
            printf("<node> :%d\n",geomHead->currentGeom.head->spot.id);
            geomHead->currentGeom.head=geomHead->currentGeom.head->next;
        }
        geomHead=geomHead->next;
    }
    printf("the amount of the geoms is %d\n",amount);
    return;
}


//  test for go through all the adjacencylist
void showAdjacentList(AdjacencyList* adjacentHead){
    int amount=0;
    AdjacencyList* pAdjacent=adjacentHead;
    pAdjacent=pAdjacent->next;
    while(pAdjacent!=NULL){ 
        amount++;
        printf("<pAdjacent id> :%d\n",pAdjacent->spot.id);
        pAdjacent->head=pAdjacent->head->next;
        while(pAdjacent->head!=NULL){
            printf("%d lat:%lf,lon:%lf dis:%lf\n",pAdjacent->head->spot.id,pAdjacent->head->spot.lat,pAdjacent->head->spot.lon,pAdjacent->head->spot.dis);
            pAdjacent->head=pAdjacent->head->next;
        }
        printf("\n");
        pAdjacent=pAdjacent->next;
    }
    printf("the amount of the adjacent is %d\n",amount);
    return;
}

//  test for go through all the edgelist
void showEdgeList(EdgeList* edgeHead){
    long amount=0;
    edgeHead=edgeHead->next;
    while(edgeHead!=NULL){ 
        amount++;
        printf("<edge> x:%d,y:%d,dis:%lf\n",edgeHead->e.x,edgeHead->e.y,edgeHead->e.dis);
        edgeHead=edgeHead->next;
    }
    printf("the amount of the edges is %d\n",amount);
    return;
}

//  test for go through all the queue
void showQueue(Queue* pq){
	NodeList* nodeHead=pq->head;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
        printf("<node> id:%d,dis:%lf\n",nodeHead->spot.id,nodeHead->spot.dis);
        nodeHead=nodeHead->next;
    }
    printf("in total %d nodes\n",pq->n);
    return;
}

#endif