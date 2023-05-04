///////////////////////////////////////////////////////////////////////////////////////
//
//                                                                                                                                                            
//	RRRRRRRRRRRRRRRRR   FFFFFFFFFFFFFFFFFFFFFFBBBBBBBBBBBBBBBBB           GGGGGGGGGGGGG
//	R::::::::::::::::R  F::::::::::::::::::::FB::::::::::::::::B       GGG::::::::::::G
//	R::::::RRRRRR:::::R F::::::::::::::::::::FB::::::BBBBBB:::::B    GG:::::::::::::::G
//	RR:::::R     R:::::RFF::::::FFFFFFFFF::::FBB:::::B     B:::::B  G:::::GGGGGGGG::::G
//	  R::::R     R:::::R  F:::::F       FFFFFF  B::::B     B:::::B G:::::G       GGGGGG
//	  R::::R     R:::::R  F:::::F               B::::B     B:::::BG:::::G              
//	  R::::RRRRRR:::::R   F::::::FFFFFFFFFF     B::::BBBBBB:::::B G:::::G              
//	  R:::::::::::::RR    F:::::::::::::::F     B:::::::::::::BB  G:::::G    GGGGGGGGGG
//	  R::::RRRRRR:::::R   F:::::::::::::::F     B::::BBBBBB:::::B G:::::G    G::::::::G
//	  R::::R     R:::::R  F::::::FFFFFFFFFF     B::::B     B:::::BG:::::G    GGGGG::::G
//	  R::::R     R:::::R  F:::::F               B::::B     B:::::BG:::::G        G::::G
//	  R::::R     R:::::R  F:::::F               B::::B     B:::::B G:::::G       G::::G
//	RR:::::R     R:::::RFF:::::::FF           BB:::::BBBBBB::::::B  G:::::GGGGGGGG::::G
//	R::::::R     R:::::RF::::::::FF           B:::::::::::::::::B    GG:::::::::::::::G
//	R::::::R     R:::::RF::::::::FF           B::::::::::::::::B       GGG::::::GGG:::G
//	RRRRRRRR     RRRRRRRFFFFFFFFFFF           BBBBBBBBBBBBBBBBB           GGGGGG   GGGG
//                                                                                                                                                                   
//  Interface header file for RF communication protocol 
//
//  EPFL Rocket Team - Nordend Project 2023
//
//  Lionel Isoz 
//  04.05.2023 
///////////////////////////////////////////////////////////////////////////////////////
#ifndef RADIO_PACKET_H
#define RADIO_PACKET_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////////////

enum CAPSULE_ID {
	// From Board to PC
	IMAGE_START = 0x01,
	IMAGE_MIDDLE,
	IMAGE_END,
	IMAGE_DATA,
	
	// From Board to LoRa
	IMAGE_LORA,
	TELEMETRY,			
	LED,
	RF_PARAM,
};

///////////////////////////////////////////////////////////////////////////////////////

struct __attribute__((__packed__)) RFsettingsPacket {
    uint8_t SF;
    uint8_t BW;
    uint8_t CR;
};
const uint32_t RFsettingsPacket_size = sizeof(RFsettingsPacket);

struct __attribute__((__packed__)) Xstrato_img_info {
    uint16_t  nbr_rx_packet;
    uint16_t  nbr_tot_packet;
};
const uint32_t Xstrato_img_info_size = sizeof(Xstrato_img_info);

#endif
