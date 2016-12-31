//YU-JUI CHEN 
//998896915
//yujchen@ucdavis.edu

#include "shapes.h"

bool listComp(const CPoints& lhs, const CPoints& rhs) { return lhs.x < rhs.x; }
CPoints::CPoints() {}//End CPoints
CPoints::~CPoints() {}//End CPoints

CPolyhedra::CPolyhedra() {}//End CPolyhedra Constructor
CPolyhedra::~CPolyhedra() {}//End CPolyhedra Destructor

							//Sets the edges for the polyhedron
void CPolyhedra::SetLines()
{

}//End SetLines

 //Sets the number of points
void CPolyhedra::SetPolys(int num)
{
	numPoints = num;
	points = new CPoints[num];
}//End SetPolys

 //Sets the layer of pixel buffer (xy, xz, and yz) for each polyhedron
void CPolyhedra::SetPB(int w, int h)
{
	pbLayer_XY = new float[w * h * 3]; //allocate new pixel buffer, XY-plane
	pbLayer_XZ = new float[w * h * 3]; //allocate new pixel buffer, XZ-plane
	pbLayer_YZ = new float[w * h * 3]; //allocate new pixel buffer, YZ-plane

	for (int i = 0; i < (w*h * 3); i++) 	//Clears the PixelBuffer;
	{
		pbLayer_XY[i] = 0;
		pbLayer_XZ[i] = 0;
		pbLayer_YZ[i] = 0;
	}
}//End SetPB


 //P2: Print all lines of the polyhedra
void CPolyhedra::printLines()
{
	/*
	cout << "Lines for Polyhedra(" << polyIndex << "):" << endl;
	for (int i = 0; i < numLines; i++)
	{
	cout << "    Line(" << i << ") is drawn from (" << lines[i].p1.x << ", "
	<< lines[i].p1.y << ", " << lines[i].p1.z << ") to (" << lines[i].p2.x << ", "
	<< lines[i].p2.y << ", " << lines[i].p2.z << ")." << endl;
	}*/
}//End printLines

 //P2: Print all copy lines
void CPolyhedra::printLines_copy()
{/*
 cout << "Copy_Lines for Polyhedra(" << polyIndex << "):" << endl;
 for (int i = 0; i < numLines; i++)
 {
 cout << "    Line(" << i << ") is drawn from (" << copy_lines[i].p1.x << ", "
 << copy_lines[i].p1.y << ", " << copy_lines[i].p1.z << ") to (" << copy_lines[i].p2.x << ", "
 << copy_lines[i].p2.y << ", " << copy_lines[i].p2.z << ")." << endl;
 }*/
}//End printLines




CShapes::CShapes() {}//End CShapes Standard Constructor
CShapes::CShapes(int num)
{
	numPolys = num;
	polyhedra = new CPolyhedra[num];
	for (int i = 0; i < numPolys; i++)
		polyhedra[i].polyIndex = i;
}//End CShapes Constructor

CShapes::~CShapes() {}//End CShapes Destructor

					  //Makes an original copy of the input file.
void CShapes::MakeCopy()
{
	/*
	for (int i = 0; i < numPolys; i++)
	{
	polyhedra[i].copy_points = new CPoints [polyhedra[i].numPoints];
	polyhedra[i].copy_lines  = new CLines  [polyhedra[i].numLines];
	for (int j = 0; j < polyhedra[i].numLines; j++)
	{
	polyhedra[i].copy_lines[j] = polyhedra[i].lines[j];
	}
	for (int j = 0; j < polyhedra[i].numPoints; j++)
	{
	polyhedra[i].copy_points[j] = polyhedra[i].points[j];
	}

	}*/
}




void CFaces::CreateEdgeList()
{
	edgesn.clear();
	ymax = edges[0].p1.y;
	ymin = edges[0].p1.y;
	ymaxp = edges[0].p1;
	yminp = edges[0].p1;

	for (int g = 0; g < 3; g++)
	{
		//cout << "Points are: " << edges[g].p1.x << ' '<< edges[g].p1.y << endl;
		//cout << "Points are: " << edges[g].p2.x << ' '<< edges[g].p2.y << endl;

		if (ymax < edges[g].p1.y)
		{
			ymax = edges[g].p1.y;
			ymaxp = edges[g].p1;
		}
		if (ymin > edges[g].p1.y)
		{
			ymin = edges[g].p1.y;
			yminp = edges[g].p1;
		}
		if (ymax < edges[g].p2.y)
		{
			ymax = edges[g].p2.y;
			ymaxp = edges[g].p2;
		}
		if (ymin > edges[g].p2.y)
		{
			ymin = edges[g].p2.y;
			yminp = edges[g].p2;
		}
	}

	float dy, dx, b, x;
	float m;
	int yscan = ymin;
	for (yscan = ymin; yscan <= ymax; yscan++)
	{
		//cout << yscan << endl;
		Edges ed(yscan);
		for (int i = 0; i < 3; i++)
		{

			int segMin = 0;
			int segMax = 0;
			CPoints segMinp;
			CPoints segMaxp;
			if (edges[i].p2.y > edges[i].p1.y)
			{
				segMax = edges[i].p2.y;
				segMin = edges[i].p1.y;
				segMaxp = edges[i].p2;
				segMinp = edges[i].p1;
			}
			else if (edges[i].p2.y < edges[i].p1.y)
			{
				segMax = edges[i].p1.y;
				segMin = edges[i].p2.y;
				segMaxp = edges[i].p1;
				segMinp = edges[i].p2;
			}
			dy = edges[i].p2.y - edges[i].p1.y;
			dx = edges[i].p2.x - edges[i].p1.x;
			m = dy / dx;
			b = edges[i].p1.y - (m * edges[i].p1.x);
			if ((edges[i].p2.y == edges[i].p1.y) && edges[i].p2.x == edges[i].p1.x)
			{
				//continue;
			}

			if (dy == 0)
			{
				continue;
			}
			if (segMin == yscan)
				continue;
			if (segMax == yscan)
			{
				if (edges[i].p2.y > edges[i].p1.y)
					ed.xlist.push_back(edges[i].p2);
				else if (edges[i].p2.y < edges[i].p1.y)
					ed.xlist.push_back(edges[i].p1);
				continue;
			}
			else if (dx == 0)
			{
				if (yscan > segMin && yscan <= segMax)
					ed.xlist.push_back(edges[i].p1); //or edges[i].p2.x because it's vertical          
				continue;
			}
			x = (yscan - b) / m;
			float red;
			float green;
			float blue;

			float stepss = segMax - segMin;
			float currenta = yscan - segMin;
			float currentb = segMax - yscan;
			red = (currentb / stepss) * (segMinp.Ip_r) + (currenta / stepss) * (segMaxp.Ip_r);
			green = (currentb / stepss) * (segMinp.Ip_g) + (currenta / stepss) * (segMaxp.Ip_g);
			blue = (currentb / stepss) * (segMinp.Ip_b) + (currenta / stepss) * (segMaxp.Ip_b);

			//
			if (segMin == yscan)
				continue;

			if ((x < edges[i].p1.x && x < edges[i].p2.x) || (x > edges[i].p1.x && x > edges[i].p2.x))
			{
				//cout << "out of bound" << endl;
			}
			else
			{
				//cout << "xIntercept is: " << x << endl;   
				x = round(x);
				CPoints xtemp;
				xtemp.x = x;
				xtemp.Ip_r = red;
				xtemp.Ip_g = green;
				xtemp.Ip_b = blue;
				ed.xlist.push_back(xtemp);


			}
		}
		ed.xlist.sort(listComp);
		for (xInterceptlist::iterator itr = ed.xlist.begin(); itr != ed.xlist.end(); ++itr)
		{
			//cout << "xIntercept is: " << itr->x << endl; 
		}
		edgesn.push_back(ed);

	}



	edgexz.clear();
	zmax = edges[0].p1.z;
	zmin = edges[0].p1.z;
	zmaxp = edges[0].p1;
	zminp = edges[0].p1;
	for (int g = 0; g < 3; g++)
	{
		//cout << "Points are: " << edges[g].p1.x << ' '<< edges[g].p1.y << endl;
		//cout << "Points are: " << edges[g].p2.x << ' '<< edges[g].p2.y << endl;

		if (zmax < edges[g].p1.z)
		{
			zmax = edges[g].p1.z;
			zmaxp = edges[g].p1;
		}
		if (zmin > edges[g].p1.z)
		{
			zmin = edges[g].p1.z;
			zminp = edges[g].p1;
		}
		if (zmax < edges[g].p2.z)
		{
			zmax = edges[g].p2.z;
			zmaxp = edges[g].p2;
		}
		if (zmin > edges[g].p2.z)
		{
			zmin = edges[g].p2.z;
			zminp = edges[g].p2;
		}
	}
}

void CShapes::CreateAllEdgeList()
{
	for (int i = 0; i < numPolys; i++)
	{
		for (int j = 0; j < polyhedra[i].numFaces; j++)
		{
			polyhedra[i].hidden_faces_z[j].CreateEdgeList();
		}
	}
	//cout << "done CreateEdgeList" << endl;

}

Edges::Edges(int a)
{
	yvalue = a;
}