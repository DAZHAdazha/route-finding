#include<stdio.h>
#include"datastructure.h"

int getIndex(long id,Marked marks[]){
        for(int i=0;i<3941;i++){
            if(marks[i].id==id)
                return i;
        }
    }

// int hasPathTO(Node v){

// }

void dfs(long id,Marked marked[],AdjacencyList* pAdjacent){
    AdjacencyList* adjacentHead=pAdjacent;
    int v=getIndex(id,marked);
    marked[v].val=1;
    // go through the adjacent list for the node v
    adjacentHead=adjacentHead->next;

    while(adjacentHead!=NULL){
        if(adjacentHead->spot.id==id){
            adjacentHead->head=adjacentHead->head->next;   
            while(adjacentHead->head!=NULL){
                printf("%d lat:%lf,lon:%lf dis:%lf\n",adjacentHead->head->spot.id,adjacentHead->head->spot.lat,adjacentHead->head->spot.lon,adjacentHead->head->spot.dis);
                int w=getIndex(adjacentHead->head->spot.id,marked);
                if(!marked[w].val){
                    // code here to add edgeTo[w]=v;
                    dfs(adjacentHead->head->spot.id,marked,pAdjacent);
                }
                adjacentHead->head=adjacentHead->head->next;
            }
            break;
        }
        adjacentHead=adjacentHead->next;
    }
}

// NodeList pathTo(){
    
// }

