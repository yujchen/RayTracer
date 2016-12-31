//YU-JUI CHEN 
//998896915
//yujchen@ucdavis.edu
#pragma once
#ifndef SHAPES_H
#define SHAPES_H

#include <GL/glut.h>  //GLUT
#include <iostream>   //cout & cin
#include <sstream>    //stringstream
#include <string>     //string class
#include <fstream>    //file stream
#include <iomanip>    //input output manipulation
#include <cmath>      //math for DDA/Bresenham
#include <vector>
#include <list>
#include <algorithm>

#define PI 3.14159265
using namespace std;  //shortening std::

class CFaces;
typedef vector<CFaces> Facevec;

class Edges;
class xPairs;
class CPoints;
typedef list<CPoints> xInterceptlist; //sorted by increasing x
typedef vector<Edges> edgelist; //sorted by increasing y
typedef list<xPairs> listpairs;
typedef vector<CPoints> newPolygon;  //list for storing new points of clipping.





class CPoints
{
private:
protected:
public:
	float x;          //X-Coordinate
	float y;          //Y-Coordinate
	float z;          //Z-Coordinate

	float nx;         //Vertex Normal x
	float ny;         //Vertex Normal y
	float nz;         //Vertex Normal z

	float Ip_r, Ip_g, Ip_b; //RGB Components of the vertex point.


							//float ka_r, ka_g, ka_b; //Ambient RGB constant
							//float kd_r, kd_g, kd_b; //Diffuse RGB constant
							//float ks_r, ks_g, ks_b; //Specular RGB constant
							//float fx, fy, fz; //Coordinates of the from-point ff

							//float K;          //Non-negative const averaging dist from scene & light src
	float Lx, Ly, Lz; //Components of the light vector
	float Rx, Ry, Rz; //Components of the reflection vector
	float Vx, Vy, Vz; //Components of viewing vector 

	float NdotL;
	float RdotV;

	//float lsrc_x, lsrc_y, lsrc_z; //Light Source Point

	float dist; // ||f-p|| + K
	CPoints();
	~CPoints();
};

class xPairs
{
public:
	int xp1;
	int xp2;
};


class Edges
{
public:
	int yvalue;
	xInterceptlist xlist;
	listpairs pairs;
	Edges(int a);

};


class CLines : public CPoints
{
private:
protected:
public:
	CPoints p1;
	CPoints p2;
};

class CFaces : public CPoints
{
private:
protected:
public:
	CPoints p1;
	CPoints p2;
	CPoints p3;
	CLines* edges;
	int* verfaces;

	float hidden_x; //average values for sorting for painter's algorithm
	float hidden_y; //average values for sorting for painter's algorithm
	float hidden_z; //average values for sorting for painter's algorithm


	edgelist edgesn;
	edgelist edgexz;
	edgelist edgeyz;

	int ymax;
	int ymin;
	CPoints ymaxp;
	CPoints yminp;

	int zmax;
	int zmin;
	CPoints zmaxp;
	CPoints zminp;


	void CreateEdgeList();

};






struct comp_x
{
	inline bool operator() (const CFaces& face1, const CFaces& face2)
	{
		return (face1.hidden_x > face2.hidden_x);
	}
};

struct comp_y
{
	inline bool operator() (const CFaces& face1, const CFaces& face2)
	{
		return (face1.hidden_y > face2.hidden_y);
	}
};

struct comp_z
{
	inline bool operator() (const CFaces& face1, const CFaces& face2)
	{
		return (face1.hidden_z > face2.hidden_z);
	}
};

class CPolyhedra : public CLines
{
private:
protected:
public:
	bool twop;         //Whether or not there's more than 2 points in the Polyhedra.
	int numPoints;
	int numFaces;
	int polyIndex;
	CPoints* points;
	CLines* lines;
	CFaces* faces;
	CFaces* copyfaces;

	CFaces* original_faces;
	CFaces* hidden_faces_x;
	CFaces* hidden_faces_y;
	CFaces* hidden_faces_z;

	Facevec ortho_x;
	Facevec ortho_y;
	Facevec ortho_z;


	CPoints* copy_points;
	CLines*  copy_lines;

	void SetLines();
	void SetPolys(int num);
	void printLines();
	void printLines_copy(); //P2


	CPolyhedra();
	~CPolyhedra();
	int ymax;
	int ymin;

	void SetPB(int w, int h); //Setting XY,XZ,YZ pixel buffer of each polyhedr
	float* pbLayer_XY;  //XY-plane
	float* pbLayer_XZ;  //XZ-plane
	float* pbLayer_YZ;  //YZ-plane

};


class CShapes : public CPolyhedra
{
private:
protected:
public:
	int numPolys;
	CPolyhedra* polyhedra;
	CShapes();
	CShapes(int num);
	~CShapes();
	friend class CDraw;
	void MakeCopy();
	void CreateAllEdgeList();
};

#endif 