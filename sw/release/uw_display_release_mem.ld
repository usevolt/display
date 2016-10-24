/*
 * GENERATED FILE - DO NOT EDIT
 * (c) Code Red Technologies Ltd, 2008-2016
 * (c) NXP Semiconductors 2013-2016
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v7.7.2 [Build 379] [2015-03-31]  on Mon Oct 24 10:07:58 EEST 2016)
*/

MEMORY
{
  /* Define each memory region */
  MFlash256 (rx) : ORIGIN = 0x2000, LENGTH = 0x3e000 /* 248K bytes */
  RamLoc64 (rwx) : ORIGIN = 0x10000080, LENGTH = 0xfee0 /* 65248 bytes */
  RamPeriph16 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x4000 /* 16K bytes */


}
  /* Define a symbol for the top of each memory region */
  __top_MFlash256 = 0x2000 + 0x3e000;
  __top_RamLoc64 = 0x10000080 + 0xfee0;
  __top_RamPeriph16 = 0x20000000 + 0x4000;



