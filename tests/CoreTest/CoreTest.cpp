// CoreTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "SkBitmap.h"
#include "SkDevice.h"
#include "SkPaint.h"

#include "SkRect.h"
#include "SkImageEncoder.h"
int _tmain(int argc, _TCHAR* argv[])
{
	// Declare a raster bitmap, which has an integer width and height,
	// and a format (config), and a pointer to the actual pixels.
	// Bitmaps can be drawn into a SkCanvas, but they are also used to

	// specify the target of a SkCanvas' drawing operations.
	SkBitmap bitmap;
	bitmap.setConfig(SkBitmap::kARGB_8888_Config, 200, 200);
	bitmap.allocPixels();

	// A Canvas encapsulates all of the state about drawing into a
	// device (bitmap).  This includes a reference to the device itself,
	// and a stack of matrix/clip values. For any given draw call (e.g.
	// drawRect), the geometry of the object being drawn is transformed
	// by the concatenation of all the matrices in the stack. The
	// transformed geometry is clipped by the intersection of all of the

	// clips in the stack.
	SkCanvas canvas(new SkDevice(bitmap));

	// SkPaint class holds the style and color information about how to
	// draw geometries, text and bitmaps.
	SkPaint paint;

	// SkIRect holds four 32 bit integer coordinates for a rectangle.

	SkRect r;

	paint.setARGB(255, 255, 0, 0);
	r.set(25, 25, 145, 145);
	canvas.drawRect(r, paint);

	paint.setARGB(255, 0, 255, 0);
	r.offset(20, 20);
	canvas.drawRect(r, paint);

	paint.setARGB(255, 0, 0, 255);
	r.offset(20, 20);
	canvas.drawRect(r, paint);

	// SkImageEncoder is the base class for encoding compressed images
	// from a specific SkBitmap.
	SkImageEncoder::EncodeFile("snapshot.png", bitmap,
		SkImageEncoder::kPNG_Type,
		100);
	return 0;
}

