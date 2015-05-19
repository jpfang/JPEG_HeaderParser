#include <stdio.h>
#include <stdlib.h>

//#define JPEGFILENAME "GNU_Linux.jpg"

#define SOI	0xD8	// Start of Image
#define SOF	0xC0    // Start of Frame (size information)
#define SOS	0xDA    // Start of Scan

#define S_OK 0
#define S_FAIL -1

#define BYTEtoWORD(x) (((x)[0]<<8)|(x)[1])

typedef signed char   	CHAR; 	//c
typedef signed long   	LONG; 	//l
typedef signed short  	SHORT;	//s
typedef signed int    	INT;	//i
typedef unsigned short 	WORD;	//us
typedef unsigned char   UCHAR;	//uc
typedef unsigned int    UINT;	//ui

typedef struct
{
	UINT uiWidth;
	UINT uiHeight;
	UINT uiColorComponents;
} JPEGINFO_t; //JPEG infotamtion struct

INT GetJPEG_ColorComponents(CHAR *pcFileName, UINT *puiColorComponents);

INT GetJPEG_ImageSize(CHAR *pcFileName, UINT *puiWidth, UINT *puiHeight);

INT FileSize(FILE *pFile);

INT JPEG_Read(FILE *pFileJPEG, UCHAR *pucFileBuffer, UINT *puiFileBufferSize);

INT JPEG_Open(CHAR *pcFileName, JPEGINFO_t *ptJPEGINFO);

void JPEG_ParaseSOF(JPEGINFO_t *ptJPEGINFO, const UCHAR *pucStream);

INT JPEG_MarkerParse(JPEGINFO_t *ptJPEGINFO, const UCHAR *pucStream,
					 UINT *puiStreamSize);

INT JPEG_HeaderParser(JPEGINFO_t *ptJPEGINFO ,const UCHAR *pucFileBuffer, 
					  UINT *puiFileBufferSize, UINT *puiImageWidth,
					  UINT* puiImageHeight);
