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
  CAM_PARAM,
  TRANSMISSION_PARAM
};

///////////////////////////////////////////////////////////////////////////////////////

struct __attribute__((__packed__)) RFsettingsPacket {
	uint32_t BW;
    uint8_t SF;
    uint8_t CR;
};
const uint32_t RFsettingsPacket_size = sizeof(RFsettingsPacket);


struct __attribute__((__packed__)) Xstrato_img_info {
    uint16_t  nbr_rx_packet;
    uint16_t  nbr_tx_packet;
    uint16_t  nbr_tot_packet;
};
const uint32_t Xstrato_img_info_size = sizeof(Xstrato_img_info);


struct __attribute__((__packed__)) TeleFileImgInfo {
    uint16_t  currentPacketNumber;
    uint16_t  numberOfUncodedFragments;
};
const uint32_t TeleFileImgInfoSize = sizeof(TeleFileImgInfo);


struct __attribute__((__packed__)) CameraSettingsPacket {
    uint8_t framesize;
    int  quality;
	bool whiteBalanceEnable;
	bool awbGainEnable;
	int wbMode;
	bool exposureEnable;
	int exposureValue;
	bool aec2Enable;
	bool rawGmaEnable;
};
const uint32_t CameraSettingsPacketSize = sizeof(CameraSettingsPacket);

struct __attribute__((__packed__)) TransmissionSettingsPacket {
    bool transmissionEnable; // 0 disable, 1 enable
	uint8_t silenceTime; // From 15s to 256s
	float marginRate; // From 1 to ..3
};
const uint32_t TransmissionSettingsPacketSize = sizeof(TransmissionSettingsPacket);


struct __attribute__((__packed__)) PositionPacket {
  float lat;
  float lon;
  float alt;
};
const uint32_t PositionPacketSize = sizeof(PositionPacket);


struct __attribute__((__packed__)) TelemetryPacket {
  PositionPacket position;

  uint32_t bme_press;
  float bme_temp;
  float bme_hum;

  //uint16_t bat_level;
  //uint32_t SD_Bytes_used;

  int rssi_balloon;
  float snr_balloon;
};
const uint32_t TelemetryPacketSize = sizeof(TelemetryPacket);

#endif
