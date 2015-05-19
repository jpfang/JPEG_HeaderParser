#include <jpeg.h>

INT FileSize(FILE *pFile)
{
    long pos;
    
	//Set to file data end
	fseek(pFile, 0, SEEK_END);
    
	//Get file end position
	pos = ftell(pFile);
    
	//Set to file data begin
	fseek(pFile, 0, SEEK_SET);
    
	return pos;
}

INT JPEG_Read(FILE *pFileJPEG, UCHAR *pucFileBuffer, UINT *puiFileBufferSize)
{
	//Reading all file data to buffer
	if (fread(pucFileBuffer, *puiFileBufferSize, 1, pFileJPEG) == 0)
	{
		printf("Read Image Fail\n");
		
		return -1;
	}

	return 0;
}

INT JPEG_Open(CHAR *pcFileName, JPEGINFO_t *ptJPEGINFO)
{
	UINT uiImageWidth, uiImageHeight;
	UCHAR *pucFileBuffer; 	//JPEG image file buffer
	UINT uiFileBufferSize;	//JPEG image file buffer size(to check ucpFileBuffer position)
	FILE *pFileJPEG;

	pFileJPEG = fopen(pcFileName,"rb");

	//Check open file
	if (pFileJPEG == NULL)
	{
		printf("Open File Fail in %s\n",pcFileName);
		
		return -1;
	}
	
	//Get JPEG image file buffer size
	uiFileBufferSize = FileSize(pFileJPEG);

	//Get memory area for JPEG image file buffer
	pucFileBuffer = (UCHAR*)malloc(sizeof(UCHAR)*(uiFileBufferSize)) ;

	printf("Open %s successfully\n",pcFileName);

	//Get JPEG image file to buffer
	JPEG_Read(pFileJPEG, pucFileBuffer, &uiFileBufferSize);

	fclose(pFileJPEG);

	//Parser JPEG header
	if (JPEG_HeaderParser(ptJPEGINFO, (const UCHAR*)pucFileBuffer,
		&uiFileBufferSize,&uiImageWidth,&uiImageHeight) < 0)
	{
		printf("HeaderParser Fail\n");

		return -1;
	}

	return 0;
}

INT GetJPEG_ColorComponents(CHAR *pcFileName, UINT *puiColorComponents)
{
	JPEGINFO_t tJPEGINFO; //JPEG information struct

	//Open JPEG image file
	if (JPEG_Open(pcFileName,&tJPEGINFO) < 0)
	{
		return -1;
	}
	
	//Get JPEG color components
	*puiColorComponents  = tJPEGINFO.uiColorComponents;

	return 0;
}

INT GetJPEG_ImageSize(CHAR *pcFileName, UINT *puiWidth, UINT *puiHeight)
{
	JPEGINFO_t tJPEGINFO;

	//Open JPEG image file
	if (JPEG_Open(pcFileName,&tJPEGINFO) < 0)
	{
		return -1;
	}
	
	//Get JPEG width and height
	*puiWidth  = tJPEGINFO.uiWidth;
	*puiHeight = tJPEGINFO.uiHeight;
	
	return 0;
}
