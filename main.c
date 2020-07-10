#include <stdio.h>
#include <stdlib.h>
#include "sndfile.h"

enum{
NO_ERROR        = 0,
FILE_ERROR      = 1,
POINTER_ERROR   = 2,
};

int dispFileInfo(SF_INFO* pInFileInfo);

int main(void)
{
  char *inFileName;
  SNDFILE *inFile;
  SF_INFO inFileInfo;

  inFileName = "noise.wav";

  inFile = sf_open(inFileName, SFM_READ, &inFileInfo);

  if(inFile == NULL)
    {
      printf("ERROR: file doesn't exist.\n");
      return FILE_ERROR;
    }

  dispFileInfo(&inFileInfo);

  sf_close(inFile);

  return NO_ERROR;
}

int dispFileInfo(SF_INFO* pInFileInfo)
{
  int fs;
  int nbChannels;

  if(pInFileInfo == NULL)
  {
    printf("ERROR: SF_INFO pointer.\n");
    return POINTER_ERROR;
  }

  // Display Sample Rate
  fs = pInFileInfo->samplerate;
  printf("Sample Rate = %d Hz\n", fs);

  // Display Number of channels
  nbChannels = pInFileInfo->channels;
  printf("Number of Channels = %d\n", nbChannels);

  return NO_ERROR;
}
