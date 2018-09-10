/*
 * author: Andrea Milanta
 *
 * This file contains value definition and data structures required
 * by the AODV protocol
 *
 * Function prototypes for utility functions are also defined here
 */

#ifndef AODV_H
#define AODV_H

/******************************************************************/
/*------------------------------DEFINE----------------------------*/

/*-------------------VALUES-------------*/
#define INF 50                 // Infinite

/*-------------------FIXED SIZES--------*/
#define DATA_PAYLOAD_LEN 11     // length of payload in data packages


/******************************************************************/
/*-------------------------DATA STRUCTURES------------------------*/

/*--------------------PACKETS-----------------*/
// data packet
struct DATA_PACKET{
    int dest;
    char payload[DATA_PAYLOAD_LEN];
};

// route request packet
struct RREQ_PACKET{
    int req_id;
    int dest;
    int src;
};

// route reply packet
struct RREP_PACKET{
    int req_id;
    int dest;
    int src;
    int hops;
};

/*--------------------TABLES-----------------*/
// routing table entry
struct ROUTING_TABLE_ENTRY{
    int dest;
    int next;
    int hops;       // number of hops to destination
    int age;        // age of current entry
    int valid;      // bool: is the current entry valid?
};

// waiting table entry (waiting for route reply)
struct DISCOVERY_TABLE_ENTRY{
    int req_id;
    int src;
    int dest;
    int snd;
    int valid;
    int age;
};

// queue entry data packages to be sent
struct QUEUE_ENTRY{
    struct DATA_PACKET data_pkg;
    int age;
    int valid;
};

#endif  // AODV_H
