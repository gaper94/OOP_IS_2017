#include <stdio.h> // FILE & fopen

// Отваряне на файл за четене
FILE* inFile;
inFile = fopen(fileName, "rb"); // rb - read binary

// Отваряне на файл за писане
FILE* outFile;
outFile = fopen(fileName, "wb"); // wb - write binary

// Когато се отваря с файл fopen, функцията връща нулев указател, когато файлът не може
// да бъде отворен поради някаква причина(потребителят няма права за писане/чете или не съществува такъв файл)
// и валиден указател, когато файлът е оторен коректно
if (inFile == nullptr)
{
  cout << "File " << fileName << " cannot be opened for reading!\n";
  return 1;
}

// Когато отворим един файл успешно и прикличим работата си с него трябва да го затворим
// Ако fopen ни върне нулев указател не трябва да затваряме файлът
fclose(inFile);
fclose(outFile);

// Структура описваща header-а на bmp файл
struct Header
{
  unsigned short int Type;
  unsigned int Size;
  unsigned short int Reserved1, Reserved2;
  unsigned int Offset;
};

// Структура описваща info header-a на bmp файл
struct InfoHeader
{
  unsigned int Size;
  int Width, Height;
  unsigned short int Planes;
  unsigned short int Bits;
  unsigned int Compression;
  unsigned int ImageSize;
  int xResolution, yResolution;
  unsigned int Colors;
  unsigned int ImportantColors;
} ;

// Структура описваща 8 битов RGB пиксел
struct Pixel
{
  unsigned char Red;
  unsigned char Green;
  unsigned char Blue;
};

Header pHeader;
InfoHeader pInfoHeader;   

// Прочитане на header-а поле по поле
fread(&pHeader.Type, sizeof(pHeader.Type), 1, inFile);
fread(&pHeader.Size, sizeof(pHeader.Size), 1, inFile);
fread(&pHeader.Reserved1, sizeof(pHeader.Reserved1), 1, inFile);
fread(&pHeader.Reserved2, sizeof(pHeader.Reserved2), 1, inFile);
fread(&pHeader.Offset, sizeof(pHeader.Offset), 1, inFile);

// Записване на header-а поле по поле
fwrite(&pHeader.Type, sizeof(pHeader.Type), 1, outFile);
fwrite(&pHeader.Size, sizeof(pHeader.Size), 1, outFile);
fwrite(&pHeader.Reserved1, sizeof(pHeader.Reserved1), 1, outFile);
fwrite(&pHeader.Reserved2, sizeof(pHeader.Reserved2), 1, outFile);
fwrite(&pHeader.Offset, sizeof(pHeader.Offset), 1, outFile);

// Прочитане на info header-а поле по поле
fread(&pInfoHeader->Size, sizeof(pInfoHeader->Size), 1, inFile);
fread(&pInfoHeader->Width, sizeof(pInfoHeader->Width), 1, inFile);
fread(&pInfoHeader->Height, sizeof(pInfoHeader->Height), 1, inFile);
fread(&pInfoHeader->Planes, sizeof(pInfoHeader->Planes), 1, inFile);
fread(&pInfoHeader->Bits, sizeof(pInfoHeader->Bits), 1, inFile);
fread(&pInfoHeader->Compression, sizeof(pInfoHeader->Compression), 1, inFile);
fread(&pInfoHeader->ImageSize, sizeof(pInfoHeader->ImageSize), 1, inFile);
fread(&pInfoHeader->xResolution, sizeof(pInfoHeader->xResolution), 1, inFile);
fread(&pInfoHeader->yResolution, sizeof(pInfoHeader->yResolution), 1, inFile);
fread(&pInfoHeader->Colors, sizeof(pInfoHeader->Colors), 1, inFile);
fread(&pInfoHeader->ImportantColors, sizeof(pInfoHeader->ImportantColors), 1, inFile);

// Записване на info header-а поле по поле
fwrite(&pInfoHeader->Size, sizeof(pInfoHeader->Size), 1, outFile);
fwrite(&pInfoHeader->Height, sizeof(pInfoHeader->Width), 1, outFile);
fwrite(&pInfoHeader->Width, sizeof(pInfoHeader->Height), 1, outFile);
fwrite(&pInfoHeader->Planes, sizeof(pInfoHeader->Planes), 1, outFile);
fwrite(&pInfoHeader->Bits, sizeof(pInfoHeader->Bits), 1, outFile);
fwrite(&pInfoHeader->Compression, sizeof(pInfoHeader->Compression), 1, outFile);
fwrite(&pInfoHeader->ImageSize, sizeof(pInfoHeader->ImageSize), 1, outFile);
fwrite(&pInfoHeader->xResolution, sizeof(pInfoHeader->xResolution), 1, outFile);
fwrite(&pInfoHeader->yResolution, sizeof(pInfoHeader->yResolution), 1, outFile);
fwrite(&pInfoHeader->Colors, sizeof(pInfoHeader->Colors), 1, outFile);
fwrite(&pInfoHeader->ImportantColors, sizeof(pInfoHeader->ImportantColors), 1, outFile);

// Прочитаме 69 резервирани байта
for (int padVal = 0; padVal < 69; padVal++)
{
  unsigned char var = 0;
  fread(&var, sizeof(var), 1, inFile);
}

// Заделяме памет за пикселите на картината
Pixel **pImage;
pImage = (Pixel **)malloc(sizeof(Pixel *)* pInfoHeader->Height);

for (int i = 0; i < pInfoHeader->Height; i++)
{
  pImage[i] = (Pixel *)malloc(sizeof(Pixel)* pInfoHeader->Width);
}

// Прочитаме пикселите на изображението
for (int i = 0; i < pInfoHeader->Height; i++)
{
  for (int j = 0; j < pInfoHeader->Width; j++)
  {
     fread(&pImage[i][j].Red, sizeof(pImage[i][j].Red), 1, inFile);
     fread(&pImage[i][j].Green, sizeof(pImage[i][j].Green), 1, inFile);
     fread(&pImage[i][j].Blue, sizeof(pImage[i][j].Blue), 1, inFile);
  }
}

// Записваме 69 резервирани байта
for (int padVal = 0; padVal < 69; padVal++)
{
  unsigned char var = 0;
  fwrite(&var, sizeof(var), 1, outFile);
}

// Завъртаме надясно
if( rotatation == ROTATE_RIGHT)
{
   for( i = 0; i < pInfoHeader.Width; i++)
   {
      int width  = pInfoHeader.Width - i - 1;
      for( j = 0; j < pInfoHeader.Height ; j++)
      {
         fwrite(&pImage[j][width].Red, sizeof(pImage[j][width].Red), 1, outFile);
         fwrite(&pImage[j][width].Green, sizeofpImage[j][width].Green), 1, outFile);
         fwrite(&pImage[j][width].Blue, sizeof(pImage[j][width].Blue), 1, outFile);
      }	

      // Редовете трябва да са кратни на 4 байта
      int pad = 0;
      if ((pInfoHeader->Height * 3) % 4 != 0){
      {
         pad = 4 - ((pInfoHeader.Height * 3) % 4);
      }
      unsigned char var = 0;
      for (int padVal = 0; padVal < pad; padVal++)
      {
         fwrite(&var, sizeof(var), 1, outFile);
      }
   }
}
else // Завъртаме наляво
{
   for( i = 0; i < pInfoHeader.Width; i++)
   {
      int height  = pInfoHeader.Height -1;
      for( j = 0; j < pInfoHeader.Height ; j++)
      {
         fwrite(&pImage[height][i].Red, sizeof(pImage[height][i].Red), 1, outFile);
         fwrite(&pImage[height][i].Green, sizeof(pImage[height][i].Green), 1, outFile);
         fwrite(&pImage[height][i].Blue, sizeof(pImage[height][i].Blue), 1, outFile);
         height--;
      }

      // Редовете трябва да са кратни на 4 байта 
      int pad = 0;
      if ((pInfoHeader.Height * 3) % 4 != 0)
      {
         pad = 4 - ((pInfoHeader.Height * 3) % 4);
      }
      unsigned char var = 0;
       for (int padVal = 0; padVal < pad; padVal++)
      {
         fwrite(&var, sizeof(var), 1, outFile);
      }
   }
}

// Освобождаваме паметта за пикселите на изображението
free(pImage);
