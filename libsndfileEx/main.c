#include <stdlib.h>
#include <stdio.h>
#include "sndfile.h"

#define		DATA_BLOCK_LENGTH			256
#define		STEREO						2

char*				pzInFileName;
char*				pzOutFileName;
SNDFILE*			psInFile;
SNDFILE*			psOutFile;
SF_INFO				sInFileInfo;
SF_INFO				sOutFileInfo;
int					iFs;
int					iFormat;
int					iNbChannels;

int main(void)
{
	int			iInDataRead[STEREO*DATA_BLOCK_LENGTH];
	int			iOutDataWrite[STEREO*DATA_BLOCK_LENGTH];
	int			iInData[DATA_BLOCK_LENGTH];
	int			iOutData[DATA_BLOCK_LENGTH];
	int			i, j;
	int			iNSamples;
	int			iNReadSamples;

	pzInFileName		= "input.wav";
	pzOutFileName		= "output.wav";

	psInFile = sf_open(pzInFileName, SFM_READ, &sInFileInfo);
	printf("in file name: %s\n", pzInFileName);

	iFs	= sInFileInfo.samplerate;
	sOutFileInfo.samplerate		= iFs;

	iNbChannels = sInFileInfo.channels;
	sOutFileInfo.channels		= iNbChannels;

	iFormat = sInFileInfo.format;
	sOutFileInfo.format			= iFormat;

	psOutFile = sf_open(pzOutFileName, SFM_WRITE, &sOutFileInfo);
	printf("out file: %s\n", pzOutFileName);
	
	iNSamples		= (int)sInFileInfo.frames * sInFileInfo.channels;

	while(iNSamples > 0)
	{
		for(i = 0; i < STEREO * DATA_BLOCK_LENGTH; i++)
		{
			iInDataRead[i] = 0;
		}

		iNReadSamples = (int)sf_read_int(psInFile, iInDataRead, STEREO * DATA_BLOCK_LENGTH);
		iNSamples -= iNReadSamples;

		for(i = 0; i < STEREO; i++)
		{
			for(j = 0; j < iNReadSamples/2; j++)
			{
				iInData[j]	= iInDataRead[STEREO*j + i];
			}

			for(j = 0; j < iNReadSamples/2; j++)
			{
				iOutData[j] = iInData[j];
			}

			for(j = 0; j < iNReadSamples/2; j++)
			{
				iOutDataWrite[STEREO*j + i]	= iOutData[j];
			}
		}
	    sf_write_int(psOutFile, iOutDataWrite, iNReadSamples);
    }

	sf_close (psInFile);
	sf_close (psOutFile);

	printf("OK\n");
	
	getchar();

	return 0;
}
