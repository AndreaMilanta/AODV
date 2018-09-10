/*
 * author: Andrea Milanta
 *
 * This file contains string definition and prototype of functions to
 * convert an AODV data structure to a packet (char array) and viceversa
 */

#ifndef STRUCT2PACKET_H
#define STRUCT2PACKET_H

#include "AODV.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/******************************************************************/
/*------------------------------DEFINE----------------------------*/

/*-------------------SEPARATORS------------------*/
#define ITEM_SEP ";"
#define VALUES_SEP ":"

/*-------------------PACKETS HEADER---------------*/
#define DATA_HEADER "DATA"
#define RREQ_HEADER "ROUTE_REQUEST"
#define RREP_HEADER "ROUTE_REPLY"

/*-------------------VALUE REPRESENTATION---------*/    // DO NOT MODIFY!!
#define NODE_REP "%2d"      // DO NOT MODIFY!!
#define HOPS_REP "%2d"      // DO NOT MODIFY!!
#define ID_REP "%2d"        // DO NOT MODIFY!!
#define PAYLOAD_REP "%s"    // DO NOT MODIFY!!

/*-------------------ITEM REPRESENTATION----------*/    // DO NOT MODIFY!!
#define DEST    "DEST"    VALUES_SEP NODE_REP
#define SRC     "SRC"     VALUES_SEP NODE_REP
#define HOPS    "HOPS"    VALUES_SEP HOPS_REP
#define REQ_ID  "REQ_ID"  VALUES_SEP ID_REP
#define REP_ID  "REQ_ID"  VALUES_SEP ID_REP
#define PAYLOAD "PAYLOAD" VALUES_SEP PAYLOAD_REP

/*-------------------PACKAGES REPRESENTATION------*/    // DO NOT MODIFY!!
#define DATA_REP DATA_HEADER ITEM_SEP DEST   ITEM_SEP PAYLOAD
#define RREQ_REP RREQ_HEADER ITEM_SEP REQ_ID ITEM_SEP DEST ITEM_SEP SRC ITEM_SEP
#define RREP_REP RREP_HEADER ITEM_SEP REP_ID ITEM_SEP DEST ITEM_SEP SRC ITEM_SEP HOPS ITEM_SEP

/*-------------------PACKAGES LENGTH--------------*/    // DO NOT MODIFY!!
#define DATA_PACKET_LEN sizeof(DATA_REP)-1 - 3 + DATA_PAYLOAD_LEN
#define RREQ_PACKET_LEN sizeof(RREQ_REP)-1 - 3
#define RREP_PACKET_LEN sizeof(RREP_REP)-1 - 4



/******************************************************************/
/*-----------------------FUNCTION PROTOTYPES----------------------*/

/*-------------------struct to packet------*/
void data2packet(struct DATA_PACKET* data, char* packet);
void rreq2packet(struct RREQ_PACKET* rreq, char* packet);
void rrep2packet(struct RREP_PACKET* rrep, char* packet);

/*-------------------packet to struct------*/
char packet2data(char* packet, struct DATA_PACKET* data);
char packet2rreq(char* packet, struct RREQ_PACKET* rreq);
char packet2rrep(char* packet, struct RREP_PACKET* rrep);

#endif //STRUCT2PACKET
