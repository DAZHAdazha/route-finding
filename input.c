#include<stdio.h>
#include<stdlib.h>
#include"datastructure.h"

int input(NodeList* pNode,WayList* pWay,LinkList* pLink,GeomList* pGeom){
    long nodeAmount=0,wayAmount=0,linkAmount=0,geomAmount=0;
    FILE *fp = NULL;
    char buff[650];
    fp = fopen("./Final_Map.map", "r");
    while(1){
        if(feof(fp)) 
            break;  
        fgets(buff,650,(FILE*)fp);
        if(strstr(buff,"<node")!=NULL){
            nodeAmount++;
            Node tempNode;
            char tempStr[25];
            NodeList* TempNode=(NodeList*)malloc(sizeof(NodeList));
            TempNode->next=NULL;
            // get the id of current node
            int length = strlen(strstr(buff,"id="))-strlen(strstr(buff,"lat="))-4;
            strncpy(tempStr,strstr(buff,"id=")+3,length);
            tempStr[length]='\0';
            tempNode.id=atoi(tempStr);
            // get the lat of current node
            length = strlen(strstr(buff,"lat="))-strlen(strstr(buff,"lon="))-5;
            strncpy(tempStr,strstr(buff,"lat=")+4,length);
            tempStr[length]='\0';
            tempNode.lat=atof(tempStr);
            // get the lon of current node
            length = strlen(strstr(buff,"lon="))-strlen(strstr(buff,"/n"))-5;
            strncpy(tempStr,strstr(buff,"lon=")+4,length);
            tempStr[length]='\0';
            tempNode.lon=atof(tempStr);

            TempNode->spot=tempNode;
            pNode->next=TempNode; 
            pNode=pNode->next;
        }
            
        if(strstr(buff,"<link")!=NULL){
            linkAmount++;
            LinkList* TempLink=(LinkList*)malloc(sizeof(LinkList));
            TempLink->next=NULL;

            Link tempLink;

            char tempStr[25];
            // get the id of current link
            int length = strlen(strstr(buff,"id="))-strlen(strstr(buff,"node="))-4;
            strncpy(tempStr,strstr(buff,"id=")+3,length);
            tempStr[length]='\0';
            tempLink.id=atoi(tempStr);

            //get the nodex of current link
            length = strlen(strstr(buff,"node="))-strlen(strstr(strstr(buff,"node=")+1,"node="));
            strncpy(tempStr,strstr(buff,"node=")+5,length);
            tempStr[length]='\0';
            tempLink.nodex=atoi(tempStr);

            //get the nodey of current link
            length = strlen(strstr(strstr(buff,"node=")+1,"node="))-strlen(strstr(buff,"way="));
            strncpy(tempStr,strstr(strstr(buff,"node=")+1,"node=")+5,length);
            tempStr[length]='\0';
            tempLink.nodey=atoi(tempStr);

            // get the way of current link
            length = strlen(strstr(buff,"way="))-strlen(strstr(buff,"length="))-4;
            strncpy(tempStr,strstr(buff,"way=")+4,length);
            tempStr[length]='\0';
            tempLink.way=atoi(tempStr);

            // get the length of current link
            length = strlen(strstr(buff,"length="))-strlen(strstr(buff,"veg="))-7;
            strncpy(tempStr,strstr(buff,"length=")+7,length);
            tempStr[length]='\0';
            tempLink.length=atof(tempStr);

            // get the veg of current link
            length = strlen(strstr(buff,"veg="))-strlen(strstr(buff,"arch="))-4;
            strncpy(tempStr,strstr(buff,"veg=")+4,length);
            tempStr[length]='\0';
            tempLink.veg=atof(tempStr);

            // get the arch of current link
            length = strlen(strstr(buff,"arch="))-strlen(strstr(buff,"land="))-5;
            strncpy(tempStr,strstr(buff,"arch=")+5,length);
            tempStr[length]='\0';
            tempLink.arch=atof(tempStr);

            TempLink->currentLink=tempLink;
            pLink->next=TempLink; 
            pLink=pLink->next;
        }
            
        if(strstr(buff,"<way")!=NULL){
            wayAmount++;
            WayList* TempWay=(WayList*)malloc(sizeof(WayList));
            TempWay->next=NULL;

            Way tempWay;
            char tempStr[25];

            NodeList* wayNodeList=(NodeList*)malloc(sizeof(NodeList));
            wayNodeList->next=NULL;
            NodeList* pointer=wayNodeList;
            
            // get the id of current way
            int length = strlen(strstr(buff,"id="))-strlen(strstr(buff,"node="))-3;
            strncpy(tempStr,strstr(buff,"id=")+3,length);
            tempStr[length]='\0';
            tempWay.id=atoi(tempStr);

            // get the nodelist for current way
            char iterChar[480];
            char tempChar[480];
            char tempResult[25];

            //printf("%s\n",buff);
            strcpy(iterChar,strstr(buff,"node="));
            while(1){
                if(strstr(iterChar+1,"node=")!=NULL){

                    NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                    temp->next=NULL;

                    strcpy(tempChar,iterChar);
                    strcpy(iterChar,strstr(iterChar+1,"node="));
                    strncpy(tempResult,tempChar,strlen(tempChar)-strlen(iterChar));
                    tempResult[strlen(tempChar)-strlen(iterChar)]='\0';

                    Node tempNode;
                    tempNode.id=atoi(tempResult+5);

                    temp->spot=tempNode;
                    pointer->next=temp; 
                    pointer=pointer->next;
                } 
                else{
                    strncpy(tempResult,iterChar,strlen(iterChar)-strlen(strstr(iterChar,"/way"))-1);
                    tempResult[strlen(iterChar)-strlen(strstr(iterChar,"/way"))-1]='\0';

                    NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                    temp->next=NULL;
                    Node tempNode;
                    tempNode.id=atoi(tempResult+5);
                    temp->spot=tempNode;
                    pointer->next=temp; 
                    pointer=pointer->next;
                	break;
                }
            }
            tempWay.head=wayNodeList;

            TempWay->currentWay=tempWay;
            
            pWay->next=TempWay; 
            pWay=pWay->next;
        }
            
        if(strstr(buff,"<geom")!=NULL){
            geomAmount++;
            GeomList* TempGeom=(GeomList*)malloc(sizeof(GeomList));
            TempGeom->next=NULL;

            Geom tempGeom;
            char tempStr[25];
            // get the id of current geom
            int length = strlen(strstr(buff,"id="))-strlen(strstr(buff,"node="))-3;
            strncpy(tempStr,strstr(buff,"id=")+3,length);
            tempStr[length]='\0';
            tempGeom.id=atoi(tempStr);

            //get the nodelist of current geom

            NodeList* geomNodeList=(NodeList*)malloc(sizeof(NodeList));
            geomNodeList->next=NULL;
            NodeList* pointer=geomNodeList;
            char iterChar[650];
            char tempChar[650];
            char tempResult[25];

            //printf("%s\n",buff);
            strcpy(iterChar,strstr(buff,"node="));
            while(1){
                if(strstr(iterChar+1,"node=")!=NULL){

                    NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                    temp->next=NULL;

                    strcpy(tempChar,iterChar);
                    strcpy(iterChar,strstr(iterChar+1,"node="));
                    strncpy(tempResult,tempChar,strlen(tempChar)-strlen(iterChar));
                    tempResult[strlen(tempChar)-strlen(iterChar)]='\0';
                    
                    Node tempNode;
                    tempNode.id=atoi(tempResult+5);

                    temp->spot=tempNode;
                    pointer->next=temp; 
                    pointer=pointer->next;
                } 
                else{
                    strncpy(tempResult,iterChar,strlen(iterChar)-strlen(strstr(iterChar,"/geom"))-1);
                    tempResult[strlen(iterChar)-strlen(strstr(iterChar,"/geom"))-1]='\0';
                    
                    NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                    temp->next=NULL;
                    Node tempNode;
                    tempNode.id=atoi(tempResult+5);
                    temp->spot=tempNode;
                    pointer->next=temp; 
                    pointer=pointer->next;
                	break;
                }
            }
            tempGeom.head=geomNodeList;

            TempGeom->currentGeom=tempGeom;
            
            pGeom->next=TempGeom; 
            pGeom=pGeom->next;
        }  
    }
    printf("nodeAmount:%d,wayAmount:%d,geomAmount:%d,linkAmount:%d\n",nodeAmount,wayAmount,geomAmount,linkAmount);
    fclose(fp);
    return 0;
}

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
}

showQueue(Queue* pq){
	NodeList* nodeHead=pq->head;
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
        printf("<node> id:%d,dis:%lf\n",nodeHead->spot.id,nodeHead->spot.dis);
        nodeHead=nodeHead->next;
    }
    printf("in total %d nodes\n",pq->n);
}

Node getNode(long id,NodeList* nodeHead){
    nodeHead=nodeHead->next;
    while(nodeHead!=NULL){ 
        if(id==nodeHead->spot.id){
            return nodeHead->spot;
        }
        nodeHead=nodeHead->next;
    }
}

void adjacent(NodeList* pNode,LinkList* linkHead,AdjacencyList* adjacentHead){

    AdjacencyList* pAdjacent=adjacentHead;
    NodeList* nodeHead = pNode;

    pNode=pNode->next;
    while(pNode!=NULL){

        long id=pNode->spot.id;

        AdjacencyList* TempAdjacent=(AdjacencyList*)malloc(sizeof(AdjacencyList));
        TempAdjacent->next=NULL;

        NodeList* adjacentNodeList=(NodeList*)malloc(sizeof(NodeList));
        adjacentNodeList->next=NULL;
        NodeList* pointer=adjacentNodeList;

        Node tempNode;
        tempNode.id=id;
        TempAdjacent->spot=tempNode;

        LinkList* pLink=linkHead;
        pLink=pLink->next;
        while(pLink!=NULL){ 
            if(pLink->currentLink.nodex==id){
                NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                temp->next=NULL;
                    
                Node tempNode;

                tempNode.id=pLink->currentLink.nodey;
                Node gotNode = getNode(tempNode.id,nodeHead);
                tempNode.lat=gotNode.lat;
                tempNode.lon=gotNode.lon;
                tempNode.dis=pLink->currentLink.length;

                temp->spot=tempNode;
                pointer->next=temp; 
                pointer=pointer->next;
            }    
            else if(pLink->currentLink.nodey==id){
                NodeList* temp=(NodeList*)malloc(sizeof(NodeList));
                temp->next=NULL;

                Node tempNode;

                tempNode.id=pLink->currentLink.nodex;
                Node gotNode = getNode(tempNode.id,nodeHead);
                tempNode.lat=gotNode.lat;
                tempNode.lon=gotNode.lon;
                tempNode.dis=pLink->currentLink.length;

                temp->spot=tempNode;
                pointer->next=temp; 
                pointer=pointer->next;
            } 
            pLink=pLink->next;
        }

        TempAdjacent->head=adjacentNodeList;
        pAdjacent->next=TempAdjacent; 
        pAdjacent=pAdjacent->next;

        pNode=pNode->next;
    }
}
