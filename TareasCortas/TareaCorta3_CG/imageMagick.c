#include <stdio.h>
#include <stdlib.h>
#include "MagickCore/MagickCore.h"
#include <string.h>

int main()
{
  Image *im;
  ExceptionInfo *exception;
  ImageInfo *imInfo;
  Image *out;
 
  // Cargamos el archivo de imagen
  imInfo =CloneImageInfo((ImageInfo*)NULL);
  exception = AcquireExceptionInfo();
  strcpy(imInfo->filename, "acueducto_nerja.jpg");
  im = ReadImage(imInfo, exception);

  // Verificamos si hay errores
  CatchException(exception);
  if (im==NULL)
    {
      fprintf(stderr, "No tengo imagen\n");
      exit(1);
    }

  // Aplicamos el efecto
  out=CharcoalImage(im, 10.0, 12.0, exception);

  // Salvamos el archivo
  strcpy(out->filename, "acueducto_charcoal.jpg");
  WriteImage(imInfo, out);

  // Liberamos memoria y cerramos la API
  exception=DestroyExceptionInfo(exception);
  im = DestroyImage(im);
  out = DestroyImage(out);
  imInfo = DestroyImageInfo(imInfo);
  MagickCoreTerminus();

  return 0;
}