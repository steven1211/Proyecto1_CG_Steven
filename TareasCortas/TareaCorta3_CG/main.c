#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wand/MagickWand.h>
#include <magick/MagickCore.h>

void readAVSFile(char** argv){
	Image *image;
	ImageInfo *image_info;
	MemoryInfo *pixel_info;
	ExceptionInfo *exception;
	MagickBooleanType status;
	MapMode mode = ReadMode;
	PixelPacket *pxlPack;
	unsigned char *pxl;
	ssize_t cont, x, y;
	size_t height, width;
	unsigned char *pixels;
	MagickCoreGenesis(*argv,MagickTrue);
	exception=AcquireExceptionInfo();
	image_info=CloneImageInfo((ImageInfo *) NULL);
	strcpy(image_info->filename,argv[1]);
	image=AcquireImage(image_info);
	status=OpenBlob(image_info,image,mode,exception);
	width=ReadBlobMSBLong(image);
	height=ReadBlobMSBLong(image);
	ssize_t length;
	image->columns=width;
	image->rows=height;
	image->depth=8;  	
	status=SetImageExtent(image,image->columns,image->rows);
	pixel_info=AcquireVirtualMemory(image->columns,4*sizeof(*pixels));
	pixels=(unsigned char *) GetVirtualMemoryBlob(pixel_info);
	length=(size_t) 4*image->columns;
	for (y=0; y < (ssize_t) image->rows; y++){
		cont=ReadBlob(image,length,pixels);
		pxl=pixels;
		pxlPack=QueueAuthenticPixels(image,0,y,image->columns,1,exception);
		if (pxlPack == (PixelPacket *) NULL) break;
		for (x=0; x < (ssize_t) image->columns; x++){
			SetPixelAlpha(pxlPack,*pxl++);
			SetPixelRed(pxlPack,*pxl++);
			SetPixelGreen(pxlPack,*pxl++);
			SetPixelBlue(pxlPack,*pxl++);
			if (pxlPack->opacity != OpaqueOpacity) image->matte=MagickTrue;
			pxlPack++;
		}
	}
	pixel_info=RelinquishVirtualMemory(pixel_info);
	CloseBlob(image);
}

void writeAVSFile(){
	MagickPixelPacket pixelPack;
	MagickWand *wand;
	PixelWand *backGr;
	PixelIterator *iterator;
	PixelWand ** row;
	int width=500;
	int height=500;
	int x, y;
	size_t rowWidth;
	MagickWandGenesis();
	wand = NewMagickWand();
	backGr = NewPixelWand();
	PixelSetColor(backGr, "WHITE");
	MagickNewImage(wand, width, height, backGr);
	backGr = DestroyPixelWand(backGr);
	iterator = NewPixelIterator(wand);
	for (y = 0; y < height; ++ y){
	    row = PixelGetNextIteratorRow(iterator, &rowWidth);
	    for (x = 0; x < rowWidth; ++x){
	    	PixelGetMagickColor(row[x], &pixelPack);
			pixelPack.red   = rand() & QuantumRange;
	        pixelPack.green = rand() & QuantumRange;
	        pixelPack.blue  = rand() & QuantumRange;
	        pixelPack.opacity  = rand() & QuantumRange;
	        PixelSetMagickColor(row[x], &pixelPack);
	    }
	    PixelSyncIterator(iterator);
	}

	PixelSetIteratorRow(iterator, 30);
    row = PixelGetNextIteratorRow(iterator, &rowWidth);
    for (x = 0; x < rowWidth; ++x)
    {
        PixelGetMagickColor(row[x], &pixelPack);
        pixelPack.red   = QuantumRange;
        pixelPack.green = 0;
        pixelPack.blue  = 0;
        PixelSetMagickColor(row[x], &pixelPack);
    }
    PixelSyncIterator(iterator);

	PixelSetIteratorRow(iterator, 130);
    row = PixelGetNextIteratorRow(iterator, &rowWidth);
    for (x = 0; x < rowWidth; ++x)
    {
        PixelGetMagickColor(row[x], &pixelPack);
        pixelPack.red   = 0;
        pixelPack.green = QuantumRange;
        pixelPack.blue  = 0;
        PixelSetMagickColor(row[x], &pixelPack);
    }
    PixelSyncIterator(iterator);

    PixelSetIteratorRow(iterator, 230);
    row = PixelGetNextIteratorRow(iterator, &rowWidth);
    for (x = 0; x < rowWidth; ++x){
        PixelGetMagickColor(row[x], &pixelPack);
        pixelPack.red   = 0;
        pixelPack.green = 0;
        pixelPack.blue  = QuantumRange;
        PixelSetMagickColor(row[x], &pixelPack);
    }
	PixelSyncIterator(iterator);
	iterator = DestroyPixelIterator(iterator);
	MagickWriteImage(wand, "AVSFile.avs");
	wand = DestroyMagickWand(wand);
	MagickWandTerminus();
}

int main(int argc,char **argv){
	readAVSFile(argv);
	writeAVSFile();
	return(0);
}