//YU-JUI CHEN 
//998896915
//yujchen@ucdavis.edu
#pragma once
#ifndef DRAW_H
#define DRAW_H

#include "shapes.h"

class CPoints;
class CLines;
class CPolyhedra;
class CShapes;

#define DDA 1
#define BRESENHAM 2

class CDraw
{
private:
protected:
public:
	//int width, height;                          //width height of the pixel buffer defined by user.
	float* PixelArray;                          //Same pointer as the global variable in main
												//CShapes* shapes;                            //Stores information about all the polyhedra
												//float Red, Green, Blue;                     //RGB values for LayerMakePix




	CDraw(float* PB, int w, int h, CShapes* s); //Constructor
	~CDraw();                                   //Destructor

	void MakePix(int i, int j);                 //MakePix original function
	void LayerMakePix(int ID, int i, int j);    //A deviation of makepix that does makepix for a particular polyon, need ID

	void DrawLine();                            //Drawing general function-->for all function below.

	void drawDDA(CPoints p1, CPoints p2);       //DDA Line Drawing;
	void drawDDA_ID(int id);                    //DDA draw given ID;
	void drawALLDDA();                          //DDA draw all; 

	void Fill_All(); //Rasterize all the existing polyhedra
	void Fill_ID(); //Rasterize a particular buffer via edgelist and scanline algorithm



	void Transform(); //Transform general function-->leads to the three function below
	void Translate(int ID, int x, int y, int z); //Translate a polygon by a vector(x,y)
	void Rotate(int ID, CLines Axis, int degree); //Rotate a polygon by a degree
	void Scale(int ID, float xscale, float yscale, float zscale); //Scale polygon by a factor


	void buffer_clear_ID(int ID); //Clear the buffer for a particular polygon
	void PixelArray_clear();  //Clear the main buffer.
	void PixelArray_Reload(); //Reload the buffer of each polygon into the main buffer


	void DisplayCoords(int ID); //Display the coordinates of each point in polyhedra
	void AddPolygon();       //Add a polygon or a line, cannot just add a point
	void RemovePolygon();    //Remove a polygon or line
	void ModPolygon(int ID); //Modify a point of a polygon or line


	void Clipping(); //Clipping general function: contains Cohen-Sutherland and Sutherland-Hodgman Algorithm
	bool insideOutside(CPoints point, CPolyhedra polygon, CLines clipline); //checks if a point is inside or outside
	CPoints findIntesection(CLines line1, CLines line2); //find intersection

	void changeRGB(); //change LayerMakePix's color

	void Save_Exit(); //Save the data into output file and exit


					  //Project 2 Development below: for 3D_Drawing
	int width, height;                          //width height of the pixel buffer defined by user.
	float *PB_XY; //Pixel buffer for XY
	float *PB_XZ; //Pixel buffer for XZ
	float *PB_YZ; //Pixel buffer for YZ                     
	float Red, Green, Blue;                     //RGB values for LayerMakePix
	CShapes* shapes;                            //Stores information about all the polyhedra



	CDraw(float* PBXY, float* PBXZ, float* PBYZ, int w, int h, CShapes* s); //3D_Constructor
	void Menu_3D();

	void LayerMakePix_XY(int ID, int i, int j, float R, float G, float B);
	void LayerMakePix_XZ(int ID, int i, int j, float R, float G, float B);
	void LayerMakePix_YZ(int ID, int i, int j, float R, float G, float B);

	void drawDDA_ID_3D(int ID);
	void drawALLDDA_3D();

	void PB_XYZ_clear();
	void PB_XYZ_Reload();
	void buffer_XYZ_clear_ID(int ID);
	void buffer_XYZ_clearall_ID();

	void ComputeNDC();
	float varNDC;
	float NDCmax, NDCmin;
	float prev_varNDC;

	int rotBool;

	CPoints find_center(int ID); //finds the center of a polygon by calculating the average


	float Ia; //Ambient Light Intensity
	float IL; //Light Source Intensity
	float lsrc_x, lsrc_y, lsrc_z; //Light Source Point
	float fx, fy, fz; //Coordinates of the from-point ff

	float ka_r, ka_g, ka_b; //Ambient RGB constant
	float kd_r, kd_g, kd_b; //Diffuse RGB constant
	float ks_r, ks_g, ks_b; //Specular RGB constant
	float K;             //Non-negative const averaging dist from scene & light src
	float pc;         //phong constant
	void Phong_Lighting();



	float find_dist_1d(float x1, float x2);
	float find_dist_2d(float x1, float x2, float y1, float y2);
	float find_dist(float x1, float x2, float y1, float y2, float z1, float z2);
	void find_Scene_Dist_K();
	void ComputeVectorLRV();

	void ComputeNDC_Ip();
	float varNDC_Ip;
	float NDCmax_Ip, NDCmin_Ip;
	float prev_varNDC_Ip;

	int firstrun;

	void changeAmbient();
	void changeDiffuse();
	void changeSpecular();
	void HiddenSurface();
	void sortHidden_x();
	void sortHidden_y();
	void sortHidden_z();

}; //Draw Class


#endif    