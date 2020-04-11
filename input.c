#include<stdio.h>
#include<stdlib.h>
#include"datastructure.h"

int input(NodeList* pNode,WayList* pWay,LinkList* pLink,GeomList* pGeom){
    FILE *fp = NULL;
    char buff[650];
    fp = fopen("./Final_Map.map", "r");
    while(1){
        if(feof(fp)) 
            break;  
        
        fgets(buff,650,(FILE*)fp);
        if(strstr(buff,"<node")!=NULL){
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
    fclose(fp);
    return 0;
}

   //test for go through all the <node>
    void showNode(NodeList* nodeHead){

        nodeHead=nodeHead->next;
        while(nodeHead!=NULL){ 
            printf("<node> id:%d,lon:%lf,lat:%lf\n",nodeHead->spot.id,nodeHead->spot.lon,nodeHead->spot.lat);
            nodeHead=nodeHead->next;
        }
    }

    //test for go through all the <link>
    void showLink(LinkList* linkHead){
        linkHead=linkHead->next;
        while(linkHead!=NULL){ 
            printf("<link> id:%d,nodex:%d,nodey:%d,way:%d,length:%lf,veg:%lf,arch:%lf\n",linkHead->currentLink.id,linkHead->currentLink.nodex,linkHead->currentLink.nodey,linkHead->currentLink.way,linkHead->currentLink.length,linkHead->currentLink.veg,linkHead->currentLink.arch);
            linkHead=linkHead->next;
        }
    }

    // test for go through all the <way>
    void showWay(WayList* wayHead){
        wayHead=wayHead->next;
        while(wayHead!=NULL){ 
            printf("<wayHead> :%d\n",wayHead->currentWay.id);
            printf("<innerbegin>\n"); 
            wayHead->currentWay.head=wayHead->currentWay.head->next;
            while(wayHead->currentWay.head!=NULL){
                printf("<way> :%d\n",wayHead->currentWay.head->spot.id);
                wayHead->currentWay.head=wayHead->currentWay.head->next;
            }
            printf("<innerend>\n");
            wayHead=wayHead->next;
        }
    }
    
  // test for go through all the <geom>
    void showGeom(GeomList* geomHead){
        geomHead=geomHead->next;
        while(geomHead!=NULL){ 
            printf("<geomHead> :%d\n",geomHead->currentGeom.id);
            printf("<innerbegin>\n"); 
            geomHead->currentGeom.head=geomHead->currentGeom.head->next;
            while(geomHead->currentGeom.head!=NULL){
                printf("<geom> :%d\n",geomHead->currentGeom.head->spot.id);
                geomHead->currentGeom.head=geomHead->currentGeom.head->next;
            }
            printf("<innerend>\n");
            geomHead=geomHead->next;
        }
    }
    
    
