/*
Jacob Fifield 
MSU Denver CPE Senior Project II
Spring 2024
*/

#ifndef PIMS_E_SHELL_COMMANDS_H
#define	PIMS_E_SHELL_COMMANDS_H

//=================== PIMS_E Report Transfer Commands ================//

#define SINGLE_REPORT_TRANSFER 0xFA
#define PIMS_E_SINGLE_REPORT_TRANSFER 0xFA
#define DATA_RECEIVED 0x0E

//================== Maintenance Dump Commands =======================//
#define SD_MAINTENANCE_DUMP 0x0D
#define READY_SD_DUMP 0x0C
#define MAINTENANCE_DUMP_COMPLETE 0x0F

//=======================LORA Module Transfer Commands==================//
#define LORA_SINGLE_REPORT_TRANSFER 0xFB

#endif