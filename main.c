#include <stdio.h>
#include <stdlib.h>
#include "sndfile.h"

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
      return 1;
    }

  dispFileInfo(&inFileInfo);

  sf_close(inFile);

  return 0;
}

int dispFileInfo(SF_INFO* pInFileInfo)
{
  int fs;

  if(pInFileInfo == NULL)
  {
    printf("ERROR: SF_INFO pointer.\n");
    return 1;
  }

  fs = pInFileInfo->samplerate;
  printf("Sample Rate = %d Hz\n", fs);

  return 0;
}
