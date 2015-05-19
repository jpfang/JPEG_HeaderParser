#include <jpeg.h>

INT main(int argc, char *argv[])
{
	CHAR *pcFileName; //Input file name
	UINT uiWidth = 0, uiHeight = 0;
	UINT uiColorComponents = 0;
	
	if (argc != 2) //How to use
	{
		printf("Usage. %s *.jpg\n",argv[0]);

		return -1;
	}
	else
	{
		pcFileName = argv[1]; //Get parameter(input file name)
	}

	printf("\n=====Testing Get JPEG Image Size Function=====\n");

	//Get JPEG image size function
	if( GetJPEG_ImageSize(pcFileName, &uiWidth ,&uiHeight) < 0)
	{
		printf("Get JPEG Image Size Fail\n");
	}
	else
	{
		printf("Image Information:\nWidth=%d, Height=%d\n",
			   uiWidth,uiHeight);
	}

	printf("\n=====Testing Get JPEG Color Components Function=====\n");

	//Get JPEG image color components
	if( GetJPEG_ColorComponents(pcFileName, &uiColorComponents) < 0)
	{
		printf("Get JPEH Color Components Fail\n");
	}
	else
	{
		printf("ColorComponents=%d\n",uiColorComponents);
	}
	
	return 0;
}
