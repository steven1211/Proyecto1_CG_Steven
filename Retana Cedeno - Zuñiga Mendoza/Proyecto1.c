/**********************************************************************
    Costa Rican Institute of Technology
    Introduction to computer graphics, IC-8059
    I Semester 2021
    Professor: Dr. Francisco J. Torres-Rojas
    
       Students:                 

    Steven Josué Retana Cedeño         2017144537 
    Christian David Zúñiga Mendoza     ??????????
   
    Project 1: "2 Dimensional polygon handling"
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

/**************************************************************************************
|                                                                                    |
|                                 Global variables                                   |
|                                                                                    |
**************************************************************************************/
#define VERTICALRESOLUTION 200;      // Vertical window resolution  
#define HORIZONTALRESOLUTION 400;    // Horizontal window resolution
#define TH 100;                      // Texture array horizontal size 
#define TV 100;                      // Texture array vertical size

int originX = 0;
int originY = 0;

struct vertex
{
    int positionX;
    int positionY;
};


// TEXTURE array 
// RGB structure
// frameBufferStructure



/**************************************************************************************
|                                                                                    |
|                                 Function declarations                              |
|                                                                                    |
**************************************************************************************/

/**************************************************************************************
|                                                                                    |
|                                 Functions                                          |
|                                                                                    |
**************************************************************************************/

// Turn on the pixel at position (x,y) from the framebuffer
void plot(int x, int y){

}

// Color: 3-dimensional vectors taken from the RGB cube (Arguments between 0 and 1)
void set_color(float R, float G, float B){

}


// Draw a line between two points (x0,y0) and (x1,y1) in frameBuffer coordinates
void bresenham(int positionX0, int positionY0, int positionX1, int positionY1){

}

// Polygon fill: loop through the framebuffer from yMax to Ymin
void scanline(int yMin, int yMax){
    int scanline = yMax;
    while (scanline >= yMin){
        // Activate borders
        // Order intersections;
        // Color (de 2 en 2)
            // setColor(TEXTURA[x % TH][scanline % TV])
            // plot(x, scanline)
        // Update borders
        // Activos (-1/m)
        // Deactivate borders
        scanline--;
    }
}

// Fill a pixel with color
// TEXTURA : Two-dimensional matrix of RGBs 
// TH : TextureHorizontalSize
// TV : TextureVerticalSize
void setColor(int positionX, int positionY){
    //setColor(TEXTURA[positionX % TH][positionY & TV]);
    //plot(positionX,positionY);

}

// Move the window two-dimensional space, the size doesn't change
// 0 -> Left
// 1 -> Right
// 2 -> Up
// 3 -> Down
void pan(int direction, int xPosition, int yPosition){
    //xMin += xPosition;
    //xMax += xPosition;
    //yMin += yPosition;
    //yMax += yPosition;
}

// Change the window size in the two-dimensional space, the proportions and "center" of the windows doesn't change, framebuffer doesn't change
void zoom(int zoomInOut, int scaleFactor){
    //xC = (xMin + xMax)/2;
    //yC = (yMin + yMax)/2;

    //xMin = ((xMin - xC) * scaleFactor) + xC;
    //xMax = ((xMax - xC) * scaleFactor) + xC;
    //yMin = ((yMin - yC) * scaleFactor) + yC;
    //yMax = ((yMax - yC) * scaleFactor) + yC;
    
}

// Rotate by "a" radians against the hands of the clock
void rotateAllPolygons(int positionX, int positionY, int rotation, int directionOfRotation){

    // for vortex in vortex array do 
        //int positionX = vertex[i].getX();
        //int positionY = vertex[i].getY();
        //moveVertex(vertex, originX - vertex[i].getX(), originY - vertex[i].getY());   // Traslate vertex to origin
        //rotateVertex(vertex, rotation, directionOfRotation);                          // Rotate vertex
        //moveVertex(vertex, positionX, positionY);                                     // Return to position
        
}

void rotateVertex(int vertexNumber, int rotation, int directionOfRotation){
        //newXPosition = ((cos(rotation) * vertex[vertexNumber].getX()) - (sin(rotation) * vertex[vertexNumber].getY())); 
        //newYPosition = ((cos(rotation) * vertex[vertexNumber].getY()) + (sin(rotation) * vertex[vertexNumber].getX())); 
        //vertex[vertexNumber].setX(newXPosition)
        //vertex[vertexNumber].setY(newYPosition)    
}

void moveVertex(int vertexNumber, int movementX, int movementY){
    //vertex[vertexNumber].setX(vertex[vertexNumber].getX() + movementX);
    //vertex[vertexNumber].setY(vertex[vertexNumber].getY() + movementY);
}


// Map dots from universal coordinates to frameBuffer coordinates, independent proportions 
void mapWindowToFrameBuffer_Dots(int positionX, int positionY){
    //int frameX = horizontalResolution * ((positionX - xMin) / (xMax - xMin));
    //int frameY = verticalResolution * ((positionY - yMin) / (yMax - yMin));
}

// Map lines from universal coordinates to frameBuffer coordinates, independent proportions 
void mapWindowToFrameBuffer_Lines(int positionX0, int positionX1, int positionY0, int positionY1){
    //int frameX0 = horizontalResolution * ((positionX0 - xMin) / (xMax - xMin));
    //int frameY0 = verticalResolution * ((positionY0 - yMin) / (yMax - yMin));
    //int frameX1 = horizontalResolution * ((positionX1 - xMin) / (xMax - xMin));
    //int frameY1 = verticalResolution * ((positionY1 - yMin) / (yMax - yMin));
    //bresenham(frameX0, frameY0, frameX1, frame Y1)   

}

void mapWindowToFrameBuffer_Polygons(){
    // Map the vertices
    // Draw borders with Bresenham
    // Fill polygons with colors
}


/**************************************************************************************
|                                                                                    |
|                                 Main Function                                      |
|                                                                                    |
**************************************************************************************/



int main(){
    //glutInitWindowSize(horizontalResolution,verticalResolution);
    //glutInitWindowPosition(0,0);
    //glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    //glutInit();
    return 0;
}


/**************************************************************************************
|                                                                                    |
|                                 Bresenham                                          |
|                                                                                    |
**************************************************************************************/
// Bresenham algorithm to draw lines (Octant 1) -> [NE, E]
void octant_1(int x0, int y0, int x1, int y1){
    int Delta_E, Delta_NE, d, Xp, Yp;

    Delta_E = 2 * (y1 - y0);
    Delta_NE = 2 * ((y1 - y0) - (x1 - x0));
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color E */
            Xp++;
            d = d + Delta_E;
        } else {
            /* Color NE */
            Xp++;
            Yp++;
            d = d + Delta_NE;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 2) -> [E, SE]
void octant_2(int x0, int y0, int x1, int y1){
    int Delta_E, Delta_SE, d, Xp, Yp;

    Delta_E = 2 * (y1 - y0);
    Delta_SE = 2 * (y1 - y0);
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color SE */
            Xp++;
            Yp--;
            d = d + Delta_SE;
        } else {
            /* Color E */
            Xp++;
            d = d + Delta_E;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 3) -> [SE, S]
void octant_3(int x0, int y0, int x1, int y1){
    int Delta_SE, Delta_S, d, Xp, Yp;

    Delta_SE = 2 * (y1 - y0);
    Delta_S = -(x1 - x0);
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color S */
            Yp--;
            d = d + Delta_S;
        } else {
            /* Color SE */
            Xp++;
            Yp--;
            d = d + Delta_S;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 4) -> [S, SO]
void octant_4(int x0, int y0, int x1, int y1){
    int Delta_S, Delta_SO, d, Xp, Yp;

    Delta_S = -(x1 - x0);
    Delta_SO = -2 * (y1 - y0);
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color S */
            Yp--;
            d = d + Delta_S;
        } else {
            /* Color SO */
            Xp--;
            Yp--;
            d = d + Delta_SO;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 5) -> [SO, O]
void octant_5(int x0, int y0, int x1, int y1){
    int Delta_SO, Delta_O, d, Xp, Yp;

    Delta_SO = -2 * (y1 - y0);
    Delta_O = -2 * (y1 - y0);
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color SO */
            Xp--;
            Yp--;
            d = d + Delta_SO;
        } else {
            /* Color O */
            Xp--;
            d = d + Delta_O;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 6) -> [O, NO]
void octant_6(int x0, int y0, int x1, int y1){
    int Delta_O, Delta_NO, d, Xp, Yp;

    Delta_O = -2 * (y1 - y0);
    Delta_NO = 2 * (-(y1 - y0) - (x1 - x0));
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color O */
            Xp--;
            d = d + Delta_O;
        } else {
            /* Color NO */
            Xp--;
            Yp++;
            d = d + Delta_NO;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 7) -> [NO, N]
void octant_7(int x0, int y0, int x1, int y1){
    int Delta_NO, Delta_N, d, Xp, Yp;

    Delta_NO = 2 * (-(y1 - y0) - (x1 - x0));
    Delta_N = -2 * (x1 - x0);
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color NO */
            Xp--;
            Yp++;
            d = d + Delta_NO;
        } else {
            /* Color N */
            Yp++;
            d = d + Delta_N;
        }
        plot(Xp, Yp);
    }
}

// Bresenham algorithm to draw lines (Octant 8) -> [N, NE]
void octant_8(int x0, int y0, int x1, int y1){
    int Delta_N, Delta_NE, d, Xp, Yp;

    Delta_N = -2 * (x1 - x0);
    Delta_NE = 2 * ((y1 - y0) - (x1 - x0));
    Xp = x0;
    Yp = y0;
    plot(Xp, Yp);

    d = 2 * (y1 - y0) - (x1 - x0);
    while (Xp < x1) {
        if (d <= 0){
            /* Color NE */
            Xp++;
            Yp++;
            d = d + Delta_NE;
        } else {
            /* Color N */
            Yp++;
            d = d + Delta_N;
        }
        plot(Xp, Yp);
    }
}


