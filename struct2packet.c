/*
 * author: Andrea Milanta
 *
 * This file contains the functions implementation to convert 
 * an AODV data structure to a packet (char array) and viceversa
 */

#include "struct2packet.h"


/*---------------------struct to packet-----------------------*/

void rreq2packet(struct RREQ_PACKET* rreq, char* packet){
    sprintf(packet, RREQ_REP, rreq->req_id, rreq->dest, rreq->src);
}

void rrep2packet(struct RREP_PACKET* rrep, char* packet){
    sprintf(packet, RREP_REP, rrep->req_id, rrep->dest, rrep->src, rrep->hops);
}

void data2packet(struct DATA_PACKET* data, char* packet){
    sprintf(packet, DATA_REP, data->dest, data->payload);
}


/*---------------------packet to struct------------------------*/

// read route request package
char packet2rreq(char* packet, struct RREQ_PACKET* rreq)
{
    static char reqId[2];
    static char src[2];
    static char dest[2];
    if( strncmp(packet,RREQ_HEADER, sizeof(RREQ_HEADER)-1) == 0)
    {
        // id
        int idx = sizeof(RREQ_HEADER)-1 + sizeof(ITEM_SEP)-1 + sizeof(REQ_ID)-1 - (sizeof(ID_REP)-1);
        reqId[0] = packet[idx];
        reqId[1] = packet[idx+1];
        rreq->req_id = atoi(reqId);
        // dest
        idx += 2 + sizeof(ITEM_SEP)-1 + sizeof(DEST)-1 - (sizeof(NODE_REP)-1);
        dest[0] = packet[idx];
        dest[1] = packet[idx+1];
        rreq->dest = atoi(dest);
        // source
        idx += 2 + sizeof(ITEM_SEP)-1 + sizeof(SRC)-1 - (sizeof(NODE_REP)-1);
        src[0] = packet[idx];
        src[1] = packet[idx+1];
        rreq->src = atoi(src);

        return 1;
    }
    return 0;
}

// read route reply packet
char packet2rrep(char* packet, struct RREP_PACKET* rrep)
{
    static char repId[2];
    static char src[2];
    static char dest[2];
    static char hops[2];
    if( strncmp(packet,RREP_HEADER, sizeof(RREP_HEADER)-1) == 0)
    {
        // id
        int idx = sizeof(RREP_HEADER)-1 + sizeof(ITEM_SEP)-1 + sizeof(REP_ID)-1 - (sizeof(ID_REP)-1);
        repId[0] = packet[idx];
        repId[1] = packet[idx+1];
        rrep->req_id = atoi(repId);
        // dest
        idx += 2 + sizeof(ITEM_SEP)-1 + sizeof(DEST)-1 - (sizeof(NODE_REP)-1);
        dest[0] = packet[idx];
        dest[1] = packet[idx+1];
        rrep->dest = atoi(dest);
        // source
        idx += 2 + sizeof(ITEM_SEP)-1 + sizeof(SRC)-1 - (sizeof(NODE_REP)-1);
        src[0] = packet[idx];
        src[1] = packet[idx+1];
        rrep->src = atoi(src);
        // hops
        idx += 2 + sizeof(ITEM_SEP)-1 + sizeof(HOPS)-1 - (sizeof(HOPS_REP)-1);
        hops[0] = packet[idx];
        hops[1] = packet[idx+1];
        rrep->hops = atoi(hops);

        return 1;
    }
    return 0;
}

// read data packet
char packet2data(char* packet, struct DATA_PACKET* data)
{
    static char dest[2];
    if( strncmp(packet, DATA_HEADER, sizeof(DATA_HEADER)-1) == 0)
    {
        // dest
        int idx = sizeof(DATA_HEADER)-1 + sizeof(ITEM_SEP)-1 + sizeof(DEST)-1 - (sizeof(NODE_REP)-1);
        dest[0] = packet[idx];
        dest[1] = packet[idx+1];
        data->dest = atoi(dest);
        
        // payload
        idx = idx + 2 + sizeof(ITEM_SEP)-1 + sizeof(PAYLOAD)-1 - (sizeof(PAYLOAD_REP)-1);
        strncpy(data->payload, packet+idx, DATA_PAYLOAD_LEN);
        
        return 1;
    }
    return 0;
}
