#include<stdio.h>
#include"datastructure.h"
void showOriginalMap(NodeList* nodeHead,LinkList* nodeLink){

    NodeList* pNode=nodeHead;
    LinkList* pLink=nodeLink;
    double xmin=100,xmax=-100,ymin=100,ymax=0;

    pNode=pNode->next;
        while(pNode!=NULL){ 
            if(pNode->spot.lon>xmax)
                xmax=pNode->spot.lon;
            if(pNode->spot.lon<xmin)
                xmin=pNode->spot.lon;
            if(pNode->spot.lat>ymax)
                ymax=pNode->spot.lat;
            if(pNode->spot.lat<ymin)
                ymin=pNode->spot.lat;
           
            pNode=pNode->next;
        }
    double xdif,ydif;
    xdif=xmax-xmin;
    ydif=ymax-ymin;

    FILE *fp = NULL;
    fp = fopen("./originalMap.txt", "w+");
    pLink=pLink->next;
    while(pLink!=NULL){ 
        long x,y;
        int count=0;
        x=pLink->currentLink.nodex;
        y=pLink->currentLink.nodey;
        NodeList* pNode=nodeHead;

        pNode=pNode->next;
        while(pNode!=NULL){ 
            if(pNode->spot.id==x){

                fprintf(fp,"%lf %lf\n",(pNode->spot.lon-xmin)/xdif*1000,(pNode->spot.lat-ymin)/ydif*1000);
                count++;
            }
            if(pNode->spot.id==y){
                fprintf(fp,"%lf %lf\n",(pNode->spot.lon-xmin)/xdif*1000,(pNode->spot.lat-ymin)/ydif*1000);
                count++;
            }
            if(count==2){
                fprintf(fp,"\n");
                fprintf(fp,"\n");
                break;
            }
            pNode=pNode->next;
        }
        pLink=pLink->next;
    }
    fclose(fp);
}