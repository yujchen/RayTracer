//YU-JUI CHEN 
//998896915
//yujchen@ucdavis.edu
#include "draw.h"



CDraw::CDraw(float* PB, int w, int h, CShapes* s)
{
	Red = 1;
	Green = 1;
	Blue = 1;
	width = w;
	height = h;
	PixelArray = PB;





	//clears the buffer
	//for (int i = 0; i < (width * height * 3 ); i++ ) 	//Clears the PixelBuffer;
	//PixelArray[i] = 0;

	shapes = s;

} //CDraw Constructor

CDraw::~CDraw() {} //CDraw Destructor


void CDraw::PixelArray_clear()
{
	for (int j = 0; j < (width * height * 3); j++)
	{
		PixelArray[j] = 0;
	}
}

void CDraw::PixelArray_Reload()
{
	/*
	for (int i = 0; i < shapes->numPolys; i++)
	{
	for (int j = 0; j < (width * height * 3 ); j++ )
	PixelArray[j] += shapes->polyhedra[i].pbLayer[j];
	}*/
}

void CDraw::buffer_clear_ID(int ID)
{
	/*
	for (int i = 0; i < shapes->numPolys; i++)
	{
	if (i == ID)
	{
	for (int j = 0; j < (width * height * 3 ); j++ )
	{
	shapes->polyhedra[i].pbLayer[j] = 0;
	}
	continue;
	}
	for (int j = 0; j < (width * height * 3 ); j++ )
	{
	PixelArray[j] += shapes->polyhedra[i].pbLayer[j] ;
	}
	}
	*/
}




















/**
Display the coordinates of polyhedra on commandline.
**/
void CDraw::DisplayCoords(int ID)
{
	if (ID == -1)
	{
		for (int a = 0; a < shapes->numPolys; a++)
			shapes->polyhedra[a].printLines();
	}
	else
		shapes->polyhedra[ID].printLines();
}









/**
This function finds the intersection.
**/
CPoints CDraw::findIntesection(CLines line1, CLines line2)
{
	CPoints intersect;
	/*
	cout << "    Line1 is drawn from (" << line1.p1.x << ", "
	<< line1.p1.y << ") to (" << line1.p2.x << ", "
	<< line1.p2.y << ")." << endl;
	cout << "    Line2 is drawn from (" << line2.p1.x << ", "
	<< line2.p1.y << ") to (" << line2.p2.x << ", "
	<< line2.p2.y << ")." << endl;
	*/

	float dx1 = line1.p2.x - line1.p1.x;
	float dy1 = line1.p2.y - line1.p1.y;
	float dx2 = line2.p2.x - line2.p1.x;
	float dy2 = line2.p2.y - line2.p1.y;

	//cout << "dx1: " << dx1 << ";;dx2: " << dx2 << endl;
	//cout << "dy1: " << dy1 << ";;dy2: " << dy2 << endl;


	float m1, b1, m2, b2;
	float intersectX, intersectY;

	if (dx1 != 0)
	{
		m1 = dy1 / dx1;
		b1 = line1.p1.y - (m1 * line1.p1.x);
	}
	else
		intersectX = line1.p1.x;



	if (dx2 != 0)
	{
		m2 = dy2 / dx2;
		b2 = line2.p1.y - (m2 * line2.p1.x);
	}
	else
		intersectX = line2.p1.x;



	if (dx1 == 0)
	{
		intersectY = round((m2 * intersectX) + b2);
	}
	else if (dx2 == 0)
	{
		intersectY = round((m1 * intersectX) + b1);
	}
	else
	{
		intersectX = round((b2 - b1) / (m1 - m2));
		intersectY = round((m1 * intersectX) + b1);
	}

	/*
	if ( dx1 == 0 )
	intersectX = line1.p1.x;
	if ( dx2 == 0 )
	intersectX = line2.p1.x;
	if ( dy1 == 0 )
	intersectY = line1.p1.y;
	if ( dy2 == 0 )
	intersectY = line2.p1.y;
	*/
	if (dy1 == 0)
		intersectY = line1.p1.y;
	if (dy2 == 0)
		intersectY = line2.p1.y;

	intersect.x = intersectX;
	intersect.y = intersectY;
	//cout << "m1: " << m1 << " then m2: " << m2 << endl;
	//cout << "Found intersection: (" << intersect.x << ", " << intersect.y << ")." << endl;
	return intersect;
}//End findIntesection


 /**
 Function: changeRGB prompts the user to set the color they want to use.
 Simply modifies the values that LayerMakePix() inserts into the pixelbuffer.
 **/
void CDraw::changeRGB()
{
	float R = -1;
	float G = -1;
	float B = -1;
	cout << "Input values between 0 ~ 1" << endl;
	while (R < 0 || R > 1)
	{
		cout << "Red: ";
		cin >> R;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error
	}
	while (G < 0 || G > 1)
	{
		cout << "Green: ";
		cin >> G;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error
	}
	while (B < 0 || B > 1)
	{
		cout << "Blue: ";
		cin >> B;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error
	}
	Red = R;
	Green = G;
	Blue = B;
}//End changeRGB








 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////







CDraw::CDraw(float* PBXY, float* PBXZ, float* PBYZ, int w, int h, CShapes* s)
{
	firstrun = 0;
	Red = 1;
	Green = 1;
	Blue = 1;
	width = w;
	height = h;
	PB_XY = PBXY; //Pixel buffer for XY
	PB_XZ = PBXZ; //Pixel buffer for XZ
	PB_YZ = PBYZ; //Pixel buffer for YZ    

	Ia = 1; //Ambient Light Intensity
	IL = 1; //Light Source Intensity
	lsrc_x = 0;  lsrc_y = 0;  lsrc_z = -10; //user defined later
	fx = -5;   fy = 0;   fz = -10;
	ka_r = 1;
	ka_g = 1;
	ka_b = 1; //Ambient RGB constant
	kd_r = 0.6; kd_g = 0.2; kd_b = 0.2; //Diffuse RGB constant
	ks_r = 1; ks_g = 1; ks_b = 1; //Specular RGB constant
	K = 0;
	pc = 9;


	shapes = s;
	prev_varNDC = -2;
} //CDraw Constructor



void CDraw::changeAmbient()
{
	float ID = -2.0;

	while (ID < 0 || ID > 1)
	{
		cout << "Ambient Intensity: ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	}Ia = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Ka_Red (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	}ka_r = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Ka_G (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} ka_g = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Ka_B (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} ka_b = ID; ID = -2.0;
}


void CDraw::changeDiffuse()
{
	float ID = -2.0;

	while (ID < 0 || ID > 1)
	{
		cout << "Kd_R (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	}kd_r = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Kd_G (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} kd_g = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Kd_B (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} kd_b = ID; ID = -2.0;
}

void CDraw::changeSpecular()
{
	float ID = -2.0;

	while (ID < 0 || ID > 1)
	{
		cout << "Kd_Red (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	}ks_r = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Kd_G (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} ks_g = ID; ID = -2.0;
	while (ID < 0 || ID > 1)
	{
		cout << "Kd_B (0 to 1): ";
		cin >> ID;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error                  
	} ks_b = ID; ID = -2.0;
}

void CDraw::Menu_3D()
{
	//HiddenSurface();


	int choice = 0;
	bool task = 0;
	ComputeNDC();
	Phong_Lighting();
	//sortHidden_x();
	//sortHidden_y();
	sortHidden_z();


	cout << "Choose 1-7:\n    (1)Ambient\n"
		<< "    (2)Diffuse\n"
		<< "    (3)Specular\n    (4)From Point\n"
		<< "    (5)Light Source\n"
		<< "    (6)Phong Constant"
		<< endl << "Your choice: ";

	while (task == 0)
	{
		cin >> choice;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error
		if (choice > 0 && choice < 7)
		{
			task = 1;
			switch (choice)
			{
			case 1:
				changeAmbient();
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();    
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;

			case 2:
				changeDiffuse();
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();                
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;

			case 3:
				changeSpecular();
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();                
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;


			case 4:

				cout << "From point in format x(space)y(space)z: ";
				cin >> fx >> fy >> fz;
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();                
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;

			case 5:
				cout << "Light Source in format x(space)y(space)z: ";
				cin >> lsrc_x >> lsrc_y >> lsrc_z;
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();                
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;

			case 6:
				cout << "Phong constant: ";
				cin >> pc;
				ComputeNDC();
				Phong_Lighting();
				//sortHidden_x();
				//sortHidden_y();
				sortHidden_z();
				//drawALLDDA_3D();                
				shapes->CreateAllEdgeList();

				Fill_ID();
				break;
			}
		}
		else
		{
			cout << "Invalid Choice. Try again.\nYour choice: ";
		}
		PB_XYZ_clear();
		PB_XYZ_Reload();
	}

}

void CDraw::LayerMakePix_XY(int ID, int i, int j, float R, float G, float B)
{

	int k = 3; //every pixel is represented by every three consecutive PixelArray
	int index = k * (i + width * j); //index is the first of the three desired index;
	shapes->polyhedra[ID].pbLayer_XY[index] = R;   //Turn on R
	shapes->polyhedra[ID].pbLayer_XY[index + 1] = G;   //Turn on G
	shapes->polyhedra[ID].pbLayer_XY[index + 2] = B;   //Turn on B

}//End LayerMakePix

void CDraw::LayerMakePix_XZ(int ID, int i, int j, float R, float G, float B)
{

	int k = 3; //every pixel is represented by every three consecutive PixelArray
	int index = k * (i + width * j); //index is the first of the three desired index;
	shapes->polyhedra[ID].pbLayer_XZ[index] = R;   //Turn on R
	shapes->polyhedra[ID].pbLayer_XZ[index + 1] = G;   //Turn on G
	shapes->polyhedra[ID].pbLayer_XZ[index + 2] = B;   //Turn on B


}//End LayerMakePix

void CDraw::LayerMakePix_YZ(int ID, int i, int j, float R, float G, float B)
{

	int k = 3; //every pixel is represented by every three consecutive PixelArray
	int index = k * (i + width * j); //index is the first of the three desired index;
	shapes->polyhedra[ID].pbLayer_YZ[index] = R;   //Turn on R
	shapes->polyhedra[ID].pbLayer_YZ[index + 1] = G;   //Turn on G
	shapes->polyhedra[ID].pbLayer_YZ[index + 2] = B;   //Turn on B


}//End LayerMakePix


void CDraw::drawALLDDA_3D()
{
	for (int i = 0; i < shapes->numPolys; i++)
	{
		//cout << "Drawing ID: " << i <<   endl;
		drawDDA_ID_3D(i);
	}
}//End drawALLDDA: 




void CDraw::drawDDA_ID_3D(int ID)
{
	for (int j = 0; j < shapes->polyhedra[ID].numFaces; j++)
	{
		for (int r = 0; r < 3; r++)
		{
			CPoints p1 = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1;
			CPoints p2 = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p2;
			float R, G, B;
			R = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_r;
			G = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_g;
			B = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_b;


			int dx = p2.x - p1.x;
			int dy = p2.y - p1.y;
			int steps, k;
			float xIncre, yIncre;
			float x = p1.x;
			float y = p1.y;

			float rIncre, gIncre, bIncre;
			float dr = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p2.Ip_r - shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_r;
			float dg = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p2.Ip_g - shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_g;
			float db = shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p2.Ip_b - shapes->polyhedra[ID].hidden_faces_z[j].edges[r].p1.Ip_b;



			if (fabs(dx) > fabs(dy))
			{
				steps = fabs(dx);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			else
			{
				steps = fabs(dy);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			xIncre = float(dx) / float(steps);
			yIncre = float(dy) / float(steps);

			//MakePix(round(x), round(y));
			LayerMakePix_XY(ID, round(x), round(y), R, G, B);
			for (k = 0; k < steps; k++)
			{
				x += xIncre;
				y += yIncre;
				R += rIncre;
				G += gIncre;
				B += bIncre;
				//MakePix(round(x), round(y));
				LayerMakePix_XY(ID, round(x), round(y), R, G, B);

			}
		}
	}


	for (int j = 0; j < shapes->polyhedra[ID].numFaces; j++)
	{
		for (int r = 0; r < 3; r++)
		{
			CPoints p1 = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1;
			CPoints p2 = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p2;
			float R, G, B;
			R = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_r;
			G = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_g;
			B = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_b;

			int dx = p2.x - p1.x;
			int dz = p2.z - p1.z;
			int steps, k;
			float xIncre, zIncre;
			float x = p1.x;
			float z = p1.z;

			float rIncre, gIncre, bIncre;
			float dr = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p2.Ip_r - shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_r;
			float dg = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p2.Ip_g - shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_g;
			float db = shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p2.Ip_b - shapes->polyhedra[ID].hidden_faces_y[j].edges[r].p1.Ip_b;

			if (fabs(dx) > fabs(dz))
			{
				steps = fabs(dx);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			else
			{
				steps = fabs(dz);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			xIncre = float(dx) / float(steps);
			zIncre = float(dz) / float(steps);

			//MakePix(round(x), round(y));
			LayerMakePix_XZ(ID, round(x), round(z), R, G, B);
			for (k = 0; k < steps; k++)
			{
				x += xIncre;
				z += zIncre;
				R += rIncre;
				G += gIncre;
				B += bIncre;
				//MakePix(round(x), round(z));
				LayerMakePix_XZ(ID, round(x), round(z), R, G, B);

			}
		}
	}

	for (int j = 0; j < shapes->polyhedra[ID].numFaces; j++)
	{
		for (int r = 0; r < 3; r++)
		{
			CPoints p1 = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1;
			CPoints p2 = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p2;
			float R, G, B;
			R = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_r;
			G = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_g;
			B = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_b;

			int dy = p2.y - p1.y;
			int dz = p2.z - p1.z;
			int steps, k;
			float yIncre, zIncre;
			float y = p1.y;
			float z = p1.z;

			float rIncre, gIncre, bIncre;
			float dr = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p2.Ip_r - shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_r;
			float dg = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p2.Ip_g - shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_g;
			float db = shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p2.Ip_b - shapes->polyhedra[ID].hidden_faces_x[j].edges[r].p1.Ip_b;

			if (fabs(dy) > fabs(dz))
			{
				steps = fabs(dy);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			else
			{
				steps = fabs(dz);
				rIncre = dr / steps;
				gIncre = dg / steps;
				bIncre = db / steps;
			}
			yIncre = float(dy) / float(steps);
			zIncre = float(dz) / float(steps);

			//MakePix(round(x), round(y));
			LayerMakePix_YZ(ID, round(y), round(z), R, G, B);
			for (k = 0; k < steps; k++)
			{
				y += yIncre;
				z += zIncre;
				R += rIncre;
				G += gIncre;
				B += bIncre;
				//MakePix(round(x), round(y));
				LayerMakePix_YZ(ID, round(y), round(z), R, G, B);

			}
		}
	}
}//End drawDDA_ID




 //Clear the XY, XZ, and YZ-Screen
void CDraw::PB_XYZ_clear()
{
	for (int j = 0; j < (width * height * 3); j++)
	{
		PB_XY[j] = 0;
		PB_XZ[j] = 0;
		PB_YZ[j] = 0;
	}
}

//Reload the XY, XZ, and YZ-Screen
void CDraw::PB_XYZ_Reload()
{
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < (width * height * 3); j++)
		{
			PB_XY[j] += shapes->polyhedra[i].pbLayer_XY[j];
			PB_XZ[j] += shapes->polyhedra[i].pbLayer_XZ[j];
			PB_YZ[j] += shapes->polyhedra[i].pbLayer_YZ[j];
		}
	}
}

//Clear the buffer for a particular polyhedron
void CDraw::buffer_XYZ_clear_ID(int ID)
{
	for (int i = 0; i < shapes->numPolys; i++)
	{
		if (i == ID)
		{
			for (int j = 0; j < (width * height * 3); j++)
			{
				shapes->polyhedra[i].pbLayer_XY[j] = 0;
				shapes->polyhedra[i].pbLayer_XZ[j] = 0;
				shapes->polyhedra[i].pbLayer_YZ[j] = 0;
			}
			continue;
		}
		for (int j = 0; j < (width * height * 3); j++)
		{
			PB_XY[j] += shapes->polyhedra[i].pbLayer_XY[j];
			PB_XZ[j] += shapes->polyhedra[i].pbLayer_XZ[j];
			PB_YZ[j] += shapes->polyhedra[i].pbLayer_YZ[j];
		}
	}
}

//Clear the buffer for all polyhedron
void CDraw::buffer_XYZ_clearall_ID()
{
	for (int i = 0; i < shapes->numPolys; i++)
	{

		for (int j = 0; j < (width * height * 3); j++)
		{
			shapes->polyhedra[i].pbLayer_XY[j] = 0;
			shapes->polyhedra[i].pbLayer_XZ[j] = 0;
			shapes->polyhedra[i].pbLayer_YZ[j] = 0;
		}
		for (int j = 0; j < (width * height * 3); j++)
		{
			PB_XY[j] += shapes->polyhedra[i].pbLayer_XY[j];
			PB_XZ[j] += shapes->polyhedra[i].pbLayer_XZ[j];
			PB_YZ[j] += shapes->polyhedra[i].pbLayer_YZ[j];
		}
	}
}




/**
User input function: ask the user what kind of transformation they would like
to perform on a particular polygon. Then calls translate, scale, or rotate
on that polygon.
**/
void CDraw::Transform()
{
	int choice = 0;
	bool task = 0;
	int ID = -2;
	int x = 0;
	int y = 0;
	int z = 0;
	int degree = 0;
	float xscale, yscale, zscale;
	CLines rotAxis;

	cout << "Choose 1, 2, or 3 for different transformations:\n    (1)Translate\n    (2)Scale\n    (3)Rotate"
		<< endl << "Your choice: ";
	while (task == 0)
	{
		cin >> choice;
		cin.clear();              //clears error message cin
		cin.ignore(100000, '\n'); //clears error message if it's more than one error
		if (choice == 1 || choice == 2 || choice == 3)
		{
			task = 1;
			switch (choice)
			{
			case 1:
				while (ID < -1 || ID >= shapes->numPolys)
				{
					cout << "Polygon ID: ";
					cin >> ID;
					cin.clear();              //clears error message cin
					cin.ignore(100000, '\n'); //clears error message if it's more than one error
				}

				cout << "Translation Vector in format x(space)y(space)z: ";
				cin >> x >> y >> z;
				Translate(ID, x, y, z);
				break;

			case 2:
				while (ID < -1 || ID >= shapes->numPolys)
				{
					cout << "Polygon ID: ";
					cin >> ID;
					cin.clear();              //clears error message cin
					cin.ignore(100000, '\n'); //clears error message if it's more than one error
				}

				cout << "Scaling factor in format: x(space)y(space)z: ";
				cin >> xscale >> yscale >> zscale;
				Scale(ID, xscale, yscale, zscale);

				break;

			case 3:
				while (ID < -1 || ID >= shapes->numPolys)
				{
					cout << "Polygon ID: ";
					cin >> ID;
					cin.clear();              //clears error message cin
					cin.ignore(100000, '\n'); //clears error message if it's more than one error
				}
				cout << "Please specify two points for the rotation axis." << endl;
				cout << "Point1 in format x(space)y(space)z:";
				cin >> rotAxis.p1.x >> rotAxis.p1.y >> rotAxis.p1.z;
				cout << "Point2 in format x(space)y(space)z:";
				cin >> rotAxis.p2.x >> rotAxis.p2.y >> rotAxis.p2.z;
				cout << "Degree (0~360): ";
				cin >> degree;

				Rotate(ID, rotAxis, degree);
				break;

			}
		}
		else
		{
			cout << "Invalid Choice. Try again.\nYour choice: ";
		}
	}
}//End Transform

 //Will run in every iteration to check if NDC needs to be renewed
void CDraw::ComputeNDC()
{
	float max, min;
	max = shapes->polyhedra[0].points[0].x;
	min = shapes->polyhedra[0].points[0].x;

	//looking for the max and min value in the list of x, y, z coordinates.
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numPoints; j++)
		{
			/*
			cout << "Compute NDC" << endl;
			cout << shapes->polyhedra[i].points[j].x << ", "
			<< shapes->polyhedra[i].points[j].y << ", "
			<< shapes->polyhedra[i].points[j].z << endl;
			*/
			if (max < shapes->polyhedra[i].points[j].x)
				max = shapes->polyhedra[i].points[j].x;
			if (max < shapes->polyhedra[i].points[j].y)
				max = shapes->polyhedra[i].points[j].y;
			if (max < shapes->polyhedra[i].points[j].z)
				max = shapes->polyhedra[i].points[j].z;

			if (min > shapes->polyhedra[i].points[j].x)
				min = shapes->polyhedra[i].points[j].x;
			if (min > shapes->polyhedra[i].points[j].y)
				min = shapes->polyhedra[i].points[j].y;
			if (min > shapes->polyhedra[i].points[j].z)
				min = shapes->polyhedra[i].points[j].z;
		}
	}//done looking for max and min

	NDCmax = max;
	NDCmin = min;
	varNDC = max - min;


	for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
	{
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++) //all the faces
		{
			for (int u = 0; u < 3; u++) //for each edges, 3 per triangle
			{
				shapes->polyhedra[i].faces[j].edges[u].p1.x = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.x - NDCmin) / varNDC) * width; // assuming that width = height
				shapes->polyhedra[i].faces[j].edges[u].p1.y = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.y - NDCmin) / varNDC) * width;
				shapes->polyhedra[i].faces[j].edges[u].p1.z = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.z - NDCmin) / varNDC) * width;

				shapes->polyhedra[i].faces[j].edges[u].p2.x = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.x - NDCmin) / varNDC) * width;
				shapes->polyhedra[i].faces[j].edges[u].p2.y = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.y - NDCmin) / varNDC) * width;
				shapes->polyhedra[i].faces[j].edges[u].p2.z = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.z - NDCmin) / varNDC) * width;
			}
		}
	}
	cout << "Normalizing: " << varNDC << " world units <-> 1 NDC "
		<< "<-> window size: " << width << endl;
	//cout << "max is: " << max << " ; min is: " << min << endl;
	//cout << "varNDC is: " << varNDC << endl;
}


/**
Translate a polygon along a vect V(x,y,z).
Simply adds x, y, and z to the respect x, y, and z component of each point in
the polyhedra.
**/
void CDraw::Translate(int ID, int x, int y, int z)
{
	/*
	cout << "x is: " << x << " y is: " << y << endl;
	cout << "Old values: " << endl;
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
	cout << "(" << shapes->polyhedra[ID].points[i].x << ", "
	<< shapes->polyhedra[ID].points[i].y << ")" << endl;
	}
	cout << "New values: " << endl;*/
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		shapes->polyhedra[ID].points[i].x += x;
		shapes->polyhedra[ID].points[i].y += y;
		shapes->polyhedra[ID].points[i].z += z;

		shapes->polyhedra[ID].copy_points[i].x += x;
		shapes->polyhedra[ID].copy_points[i].y += y;
		shapes->polyhedra[ID].copy_points[i].z += z;
	}
	/*
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
	cout << "(" << shapes->polyhedra[ID].points[i].x << ", "
	<< shapes->polyhedra[ID].points[i].y << ")" << endl;
	}*/
	if (shapes->polyhedra[ID].numPoints > 1)																		//There needs to be at least two points to draw a line.
	{
		shapes->polyhedra[ID].SetLines();
		ComputeNDC();
	}
	buffer_XYZ_clearall_ID();
	drawALLDDA_3D();
}//End Translate



 /**
 Finds the center of a polygon by taking the average of the points of the
 polygon.
 **/
CPoints CDraw::find_center(int ID)
{
	CPoints center;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		center.x += shapes->polyhedra[ID].points[i].x;
		center.y += shapes->polyhedra[ID].points[i].y;
		center.z += shapes->polyhedra[ID].points[i].z;
		//cout << center.x << ' ' << center.y << ' ' << center.z << endl;
	}
	center.x = (int)(center.x / (shapes->polyhedra[ID].numPoints));
	center.y = (int)(center.y / (shapes->polyhedra[ID].numPoints));
	center.z = (int)(center.z / (shapes->polyhedra[ID].numPoints));

	return center;
}


/**
Scale a polygon by a user defined x and y factor.
Step1) Calls find_center, then translates the polygon to the center.
Steo2) Scale polygon around origin (0, 0)
Step3) Reverse step1 by transfering the polygon back.
**/
void CDraw::Scale(int ID, float xscale, float yscale, float zscale)
{
	CPoints center = find_center(ID);
	int xtemp;
	int ytemp;
	int ztemp;

	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		shapes->polyhedra[ID].points[i].x += (0 - center.x);
		shapes->polyhedra[ID].points[i].y += (0 - center.y);
		shapes->polyhedra[ID].points[i].z += (0 - center.z);
	}//Translate to origin manually..because Translate function draws it.

	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		xtemp = shapes->polyhedra[ID].points[i].x;
		ytemp = shapes->polyhedra[ID].points[i].y;
		ztemp = shapes->polyhedra[ID].points[i].z;
		shapes->polyhedra[ID].points[i].x = round(xtemp * xscale); //round or type cast (int)?
		shapes->polyhedra[ID].points[i].y = round(ytemp * yscale); //round or type cast (int)?
		shapes->polyhedra[ID].points[i].z = round(ztemp * zscale); //round or type cast (int)?
	}//Scale it by multiplying x and y component by the factor, then round

	Translate(ID, center.x, center.y, center.z); //Translate back to original spot then draw.
}//End Scale



 /**
 Rotate a polygon by a user defined angle: degree
 Step1) Calls find_center, then translates the polygon to the center.
 Steo2) Rotate polygon around origin (0, 0)
 Step3) Reverse step1 by transfering the polygon back.
 **/
void CDraw::Rotate(int ID, CLines Axis, int degree)
{
	/*
	CPoints center = find_center(ID);
	float cosa = cos(degree * PI / 180.0);  //PI = 3.14159265
	float sina = sin(degree * PI / 180.0);


	int xtemp;
	int ytemp;

	//cout << "cos: " << cosa << " sin: " << sina << endl;

	//Translate(ID, 0-center.x, 0-center.y);
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
	shapes->polyhedra[ID].points[i].x += (0-center.x);
	shapes->polyhedra[ID].points[i].y += (0-center.y);
	}//Manually translate because the Translate function draws it.

	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
	xtemp = shapes->polyhedra[ID].points[i].x;
	ytemp = shapes->polyhedra[ID].points[i].y;
	shapes->polyhedra[ID].points[i].x = (round)((xtemp*cosa) - (ytemp*sina)); //round or type cast (int)?
	shapes->polyhedra[ID].points[i].y = (round)((xtemp*sina) + (ytemp*cosa)); //round or type cast (int)?
	}

	Translate(ID, center.x, center.y, center.z); //Draw it at the end.
	*/
	float cosa = cos(degree * PI / 180.0);  //PI = 3.14159265
	float sina = sin(degree * PI / 180.0);


	float xtemp;
	float ytemp;
	float ztemp;

	float dx = Axis.p2.x - Axis.p1.x; // Vector x comp 
	float dy = Axis.p2.y - Axis.p1.y; // Vector y comp
	float dz = Axis.p2.z - Axis.p1.z; // Vector z comp
	float vecMag = sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
	float a = dx / vecMag;
	float b = dy / vecMag;
	float c = dz / vecMag;

	float d = sqrt(pow(b, 2) + pow(c, 2));

	//Step1: Translate the axis to the origin (and translate the polyhedron along
	//with it by the same vector)
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		shapes->polyhedra[ID].points[i].x += (0 - Axis.p1.x);
		shapes->polyhedra[ID].points[i].y += (0 - Axis.p1.y);
		shapes->polyhedra[ID].points[i].z += (0 - Axis.p1.z);
	}//Manually translate because the Translate function draws it.

	if (d != 0) //if d = 0, then it's already on the x axis
	{
		//Step2: rotate axis to align it with the XZ plane
		for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
		{
			ytemp = (shapes->polyhedra[ID].points[i].y * (c / d)) - (shapes->polyhedra[ID].points[i].z * (b / d));
			ztemp = (shapes->polyhedra[ID].points[i].y * (b / d)) + (shapes->polyhedra[ID].points[i].z * (c / d));

			shapes->polyhedra[ID].points[i].y = ytemp;
			shapes->polyhedra[ID].points[i].z = ztemp;
		}//Manually translate because the Translate function draws it.
	}
	//Step3: then rotate to align it with the Z axis.
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		xtemp = (d * shapes->polyhedra[ID].points[i].x) - (a * shapes->polyhedra[ID].points[i].z);
		ztemp = (a * shapes->polyhedra[ID].points[i].x) + (d * shapes->polyhedra[ID].points[i].z);

		shapes->polyhedra[ID].points[i].x = xtemp;
		shapes->polyhedra[ID].points[i].z = ztemp;
	}//Manually translate because the Translate function draws it.

	 //Step4: Rotation about Z by user input degree
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		xtemp = (shapes->polyhedra[ID].points[i].x * cosa) - (shapes->polyhedra[ID].points[i].y * sina);
		ytemp = (shapes->polyhedra[ID].points[i].x * sina) + (shapes->polyhedra[ID].points[i].y * cosa);

		shapes->polyhedra[ID].points[i].x = xtemp; //round or type cast (int)?
		shapes->polyhedra[ID].points[i].y = ytemp; //round or type cast (int)?
	}
	//Step3 inverse ->5: 
	for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
	{
		xtemp = (d * shapes->polyhedra[ID].points[i].x) + (a * shapes->polyhedra[ID].points[i].z);
		ztemp = (-a * shapes->polyhedra[ID].points[i].x) + (d * shapes->polyhedra[ID].points[i].z);

		shapes->polyhedra[ID].points[i].x = xtemp;
		shapes->polyhedra[ID].points[i].z = ztemp;
	}//Manually translate because the Translate function draws it.

	if (d != 0) //if d = 0, then it's already on the x axis
	{
		//Step2 inverse ->6: 
		for (int i = 0; i < shapes->polyhedra[ID].numPoints; i++)
		{
			ytemp = (shapes->polyhedra[ID].points[i].y * (c / d)) + (shapes->polyhedra[ID].points[i].z * (b / d));
			ztemp = (shapes->polyhedra[ID].points[i].y * (-b / d)) + (shapes->polyhedra[ID].points[i].z * (c / d));

			shapes->polyhedra[ID].points[i].y = ytemp;
			shapes->polyhedra[ID].points[i].z = ztemp;
		}//Manually translate because the Translate function draws it.
	}
	rotBool = 1;
	shapes->polyhedra[shapes->numPolys - 1].points[0] = Axis.p1;
	shapes->polyhedra[shapes->numPolys - 1].points[1] = Axis.p2;
	shapes->polyhedra[shapes->numPolys - 1].SetLines();

	shapes->polyhedra[shapes->numPolys - 1].lines[0] = Axis;
	Translate(ID, Axis.p1.x, Axis.p1.y, Axis.p1.z); //Draw it at the end.



}//End of Rotate



void CDraw::Save_Exit()
{/*
 int choice = -2;
 int choice1 = -2;
 ofstream outf("3d_coloring.txt");


 cout << "Do you wish to save (0 for no; 1 for yes)?: ";
 while (choice < 0 || choice > 1)
 {
 cin >> choice;
 cin.clear();              //clears error message cin
 cin.ignore(100000, '\n'); //clears error message if it's more than one error
 }
 if (choice == 1)
 {
 cout << "Saving..." << endl;
 outf << shapes->numPolys << endl;
 //cout << shapes->numPolys << endl;
 for (int i = 0; i < shapes->numPolys; i++)
 {
 outf << shapes->polyhedra[i].numPoints << endl;
 //cout << shapes->polyhedra[i].numPoints << endl;
 for (int j = 0; j < shapes->polyhedra[i].numPoints; j++)
 {
 outf << setprecision(1) << fixed << shapes->polyhedra[i].points[j].x
 << ' ' << shapes->polyhedra[i].points[j].y << ' '
 << shapes->polyhedra[i].points[j].z << endl;
 //cout << setprecision(1) << fixed << shapes->polyhedra[i].points[j].x
 << ' ' << shapes->polyhedra[i].points[j].y << endl;
 }
 outf << shapes->polyhedra[i].numLines << endl;
 for (int j = 0; j < shapes->polyhedra[i].numLines * 2; j++)
 {
 outf << shapes->polyhedra[i].polyedges[j]+1 << ' '
 << shapes->polyhedra[i].polyedges[j+1]+1 << endl;
 j++;
 }
 outf << endl;
 //cout << endl;
 }
 }



 cout << "Do you wish to exit (0 for no; 1 for yes)?: ";
 while (choice1 < 0 || choice1 > 1)
 {
 cin >> choice1;
 cin.clear();              //clears error message cin
 cin.ignore(100000, '\n'); //clears error message if it's more than one error
 }

 if (choice1 == 1)
 {
 cout << "Bye!" << endl;
 exit(0);
 }*/
}

float CDraw::find_dist_1d(float x1, float x2)
{
	return sqrt(pow((x2 - x1), 2));
}


float CDraw::find_dist_2d(float x1, float x2, float y1, float y2)
{

	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

float CDraw::find_dist(float x1, float x2, float y1, float y2, float z1, float z2)
{

	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
}

void CDraw::find_Scene_Dist_K()
{
	float scenex, sceney, scenez; //basically vertex coordinates of input file

	float total_dist = 0;
	int count = 0;
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numPoints; j++)
		{
			scenex = shapes->polyhedra[i].points[j].x;
			sceney = shapes->polyhedra[i].points[j].y;
			scenez = shapes->polyhedra[i].points[j].z;
			total_dist += find_dist(lsrc_x, scenex, lsrc_y, sceney, lsrc_z, scenez);
			count++;
		}
	}
	K = total_dist / count; //K is a variable local in draw class

}//End find_Scene_Dist

void CDraw::ComputeVectorLRV()
{
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			for (int h = 0; h < 3; h++)
			{
				float lightmagp1 = find_dist(lsrc_x, shapes->polyhedra[i].copyfaces[j].edges[h].p1.x, lsrc_y, shapes->polyhedra[i].copyfaces[j].edges[h].p1.y, lsrc_z, shapes->polyhedra[i].copyfaces[j].edges[h].p1.z);
				float lightmagp2 = find_dist(lsrc_x, shapes->polyhedra[i].copyfaces[j].edges[h].p2.x, lsrc_y, shapes->polyhedra[i].copyfaces[j].edges[h].p2.y, lsrc_z, shapes->polyhedra[i].copyfaces[j].edges[h].p2.z);
				shapes->polyhedra[i].faces[j].edges[h].p1.Lx = (lsrc_x - shapes->polyhedra[i].copyfaces[j].edges[h].p1.x) / (lightmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p1.Ly = (lsrc_y - shapes->polyhedra[i].copyfaces[j].edges[h].p1.y) / (lightmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p1.Lz = (lsrc_z - shapes->polyhedra[i].copyfaces[j].edges[h].p1.z) / (lightmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p2.Lx = (lsrc_x - shapes->polyhedra[i].copyfaces[j].edges[h].p2.x) / (lightmagp2);
				shapes->polyhedra[i].faces[j].edges[h].p2.Ly = (lsrc_y - shapes->polyhedra[i].copyfaces[j].edges[h].p2.y) / (lightmagp2);
				shapes->polyhedra[i].faces[j].edges[h].p2.Lz = (lsrc_z - shapes->polyhedra[i].copyfaces[j].edges[h].p2.z) / (lightmagp2);

				//
				shapes->polyhedra[i].faces[j].edges[h].p1.NdotL = (shapes->polyhedra[i].faces[j].edges[h].p1.nx * shapes->polyhedra[i].faces[j].edges[h].p1.Lx) +
					(shapes->polyhedra[i].faces[j].edges[h].p1.ny * shapes->polyhedra[i].faces[j].edges[h].p1.Ly) +
					(shapes->polyhedra[i].faces[j].edges[h].p1.nz * shapes->polyhedra[i].faces[j].edges[h].p1.Lz);
				shapes->polyhedra[i].faces[j].edges[h].p2.NdotL = (shapes->polyhedra[i].faces[j].edges[h].p2.nx * shapes->polyhedra[i].faces[j].edges[h].p2.Lx) +
					(shapes->polyhedra[i].faces[j].edges[h].p2.ny * shapes->polyhedra[i].faces[j].edges[h].p2.Ly) +
					(shapes->polyhedra[i].faces[j].edges[h].p2.nz * shapes->polyhedra[i].faces[j].edges[h].p2.Lz);

				if (shapes->polyhedra[i].faces[j].edges[h].p1.NdotL < 0 || isnan(shapes->polyhedra[i].faces[j].edges[h].p1.NdotL))
				{
					shapes->polyhedra[i].faces[j].edges[h].p1.NdotL = 0;
				}

				if (shapes->polyhedra[i].faces[j].edges[h].p2.NdotL < 0 || isnan(shapes->polyhedra[i].faces[j].edges[h].p2.NdotL))
				{
					shapes->polyhedra[i].faces[j].edges[h].p2.NdotL = 0;
				}

				shapes->polyhedra[i].faces[j].edges[h].p1.Rx = -(shapes->polyhedra[i].faces[j].edges[h].p1.Lx) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p1.nx;
				shapes->polyhedra[i].faces[j].edges[h].p1.Ry = -(shapes->polyhedra[i].faces[j].edges[h].p1.Ly) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p1.ny;
				shapes->polyhedra[i].faces[j].edges[h].p1.Rz = -(shapes->polyhedra[i].faces[j].edges[h].p1.Lz) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p1.nz;
				shapes->polyhedra[i].faces[j].edges[h].p2.Rx = -(shapes->polyhedra[i].faces[j].edges[h].p2.Lx) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p2.nx;
				shapes->polyhedra[i].faces[j].edges[h].p2.Ry = -(shapes->polyhedra[i].faces[j].edges[h].p2.Ly) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p2.ny;
				shapes->polyhedra[i].faces[j].edges[h].p2.Rz = -(shapes->polyhedra[i].faces[j].edges[h].p2.Lz) + 2 * (shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) * shapes->polyhedra[i].faces[j].edges[h].p2.nz;

				float viewmagp1 = find_dist(fx, shapes->polyhedra[i].copyfaces[j].edges[h].p1.x, fy, shapes->polyhedra[i].copyfaces[j].edges[h].p1.y, fz, shapes->polyhedra[i].copyfaces[j].edges[h].p1.z);
				float viewmagp2 = find_dist(fx, shapes->polyhedra[i].copyfaces[j].edges[h].p2.x, fy, shapes->polyhedra[i].copyfaces[j].edges[h].p2.y, fz, shapes->polyhedra[i].copyfaces[j].edges[h].p2.z);

				shapes->polyhedra[i].faces[j].edges[h].p1.Vx = (fx - shapes->polyhedra[i].copyfaces[j].edges[h].p1.x) / (viewmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p1.Vy = (fy - shapes->polyhedra[i].copyfaces[j].edges[h].p1.y) / (viewmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p1.Vz = (fz - shapes->polyhedra[i].copyfaces[j].edges[h].p1.z) / (viewmagp1);
				shapes->polyhedra[i].faces[j].edges[h].p2.Vx = (fx - shapes->polyhedra[i].copyfaces[j].edges[h].p2.x) / (viewmagp2);
				shapes->polyhedra[i].faces[j].edges[h].p2.Vy = (fy - shapes->polyhedra[i].copyfaces[j].edges[h].p2.y) / (viewmagp2);
				shapes->polyhedra[i].faces[j].edges[h].p2.Vz = (fz - shapes->polyhedra[i].copyfaces[j].edges[h].p2.z) / (viewmagp2);

				shapes->polyhedra[i].faces[j].edges[h].p1.RdotV = (shapes->polyhedra[i].faces[j].edges[h].p1.Rx * shapes->polyhedra[i].faces[j].edges[h].p1.Vx) +
					(shapes->polyhedra[i].faces[j].edges[h].p1.Ry * shapes->polyhedra[i].faces[j].edges[h].p1.Vy) +
					(shapes->polyhedra[i].faces[j].edges[h].p1.Rz * shapes->polyhedra[i].faces[j].edges[h].p1.Vz);
				shapes->polyhedra[i].faces[j].edges[h].p2.RdotV = (shapes->polyhedra[i].faces[j].edges[h].p2.Rx * shapes->polyhedra[i].faces[j].edges[h].p2.Vx) +
					(shapes->polyhedra[i].faces[j].edges[h].p2.Ry * shapes->polyhedra[i].faces[j].edges[h].p2.Vy) +
					(shapes->polyhedra[i].faces[j].edges[h].p2.Rz * shapes->polyhedra[i].faces[j].edges[h].p2.Vz);

				if (shapes->polyhedra[i].faces[j].edges[h].p1.RdotV < 0 || isnan(shapes->polyhedra[i].faces[j].edges[h].p1.RdotV))
				{
					shapes->polyhedra[i].faces[j].edges[h].p1.RdotV = 0;
				}

				if (shapes->polyhedra[i].faces[j].edges[h].p2.RdotV < 0 || isnan(shapes->polyhedra[i].faces[j].edges[h].p2.RdotV))
				{
					shapes->polyhedra[i].faces[j].edges[h].p2.RdotV = 0;
				}

				//cout << "Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 NdotL:" << shapes->polyhedra[i].faces[j].edges[h].p1.NdotL << endl;
				//cout << "Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 NdotL:" << shapes->polyhedra[i].faces[j].edges[h].p2.NdotL << endl;
				//cout << "Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 RdotV:" << shapes->polyhedra[i].faces[j].edges[h].p1.RdotV << endl;
				//cout << "Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 RdotV:" << shapes->polyhedra[i].faces[j].edges[h].p2.RdotV << endl;
			}
		}
	}
}

void CDraw::Phong_Lighting()
{
	ComputeVectorLRV();
	find_Scene_Dist_K();
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			for (int h = 0; h < 3; h++)
			{
				//cout << "p1:" << shapes->polyhedra[i].faces[j].edges[h].p1.NdotL <<endl;
				//cout << "p2:" << shapes->polyhedra[i].faces[j].edges[h].p2.NdotL <<endl ;

				shapes->polyhedra[i].faces[j].edges[h].p1.dist = K + find_dist(fx, shapes->polyhedra[i].copyfaces[j].edges[h].p1.x, fy, shapes->polyhedra[i].copyfaces[j].edges[h].p1.y, fz, shapes->polyhedra[i].copyfaces[j].edges[h].p1.z);
				shapes->polyhedra[i].faces[j].edges[h].p2.dist = K + find_dist(fx, shapes->polyhedra[i].copyfaces[j].edges[h].p2.x, fy, shapes->polyhedra[i].copyfaces[j].edges[h].p2.y, fz, shapes->polyhedra[i].copyfaces[j].edges[h].p2.z);

				shapes->polyhedra[i].faces[j].edges[h].p1.Ip_r = (ka_r * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p1.dist) * (kd_r *(shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) + ks_r * pow((shapes->polyhedra[i].faces[j].edges[h].p1.RdotV), pc));
				shapes->polyhedra[i].faces[j].edges[h].p2.Ip_r = (ka_r * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p2.dist) * (kd_r *(shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) + ks_r * pow((shapes->polyhedra[i].faces[j].edges[h].p2.RdotV), pc));
				shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_r = shapes->polyhedra[i].faces[j].edges[h].p1.Ip_r;
				shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_r = shapes->polyhedra[i].faces[j].edges[h].p2.Ip_r;

				shapes->polyhedra[i].faces[j].edges[h].p1.Ip_g = (ka_g * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p1.dist) * (kd_g *(shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) + ks_g * pow((shapes->polyhedra[i].faces[j].edges[h].p1.RdotV), pc));
				shapes->polyhedra[i].faces[j].edges[h].p2.Ip_g = (ka_g * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p2.dist) * (kd_g *(shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) + ks_g * pow((shapes->polyhedra[i].faces[j].edges[h].p2.RdotV), pc));
				shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_g = shapes->polyhedra[i].faces[j].edges[h].p1.Ip_g;
				shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_g = shapes->polyhedra[i].faces[j].edges[h].p2.Ip_g;

				shapes->polyhedra[i].faces[j].edges[h].p1.Ip_b = (ka_b * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p1.dist) * (kd_b *(shapes->polyhedra[i].faces[j].edges[h].p1.NdotL) + ks_b * pow((shapes->polyhedra[i].faces[j].edges[h].p1.RdotV), pc));
				shapes->polyhedra[i].faces[j].edges[h].p2.Ip_b = (ka_b * Ia) + (IL / shapes->polyhedra[i].faces[j].edges[h].p2.dist) * (kd_b *(shapes->polyhedra[i].faces[j].edges[h].p2.NdotL) + ks_b * pow((shapes->polyhedra[i].faces[j].edges[h].p2.RdotV), pc));
				shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_b = shapes->polyhedra[i].faces[j].edges[h].p1.Ip_b;
				shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_b = shapes->polyhedra[i].faces[j].edges[h].p2.Ip_b;
				//cout << "dist1: " << shapes->polyhedra[i].faces[j].edges[h].p1.dist << endl;
				//cout << "dist2: " << shapes->polyhedra[i].faces[j].edges[h].p2.dist << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_r:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_r << endl;
				// cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_g:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_g << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_b:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_b << endl;

				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_r:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_r << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_g:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_g << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_b:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_b << endl << endl;

			}
		}
	}
	ComputeNDC_Ip();
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			for (int h = 0; h < 3; h++)
			{
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_r:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_r << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_g:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_g << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p1 Ip_b:" << shapes->polyhedra[i].faces[j].edges[h].p1.Ip_b << endl;
				//
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_r:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_r << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_g:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_g << endl;
				//cout << setprecision(10) <<"Shape: " << i << "; Face: " << j << "; Edges: " << h << "// p2 Ip_b:" << shapes->polyhedra[i].faces[j].edges[h].p2.Ip_b << endl << endl;

			}
		}
	}
}



//Will run in every iteration to check if NDC needs to be renewed
void CDraw::ComputeNDC_Ip()
{
	float max, min;
	max = shapes->polyhedra[0].copyfaces[0].edges[0].p1.Ip_r;
	min = shapes->polyhedra[0].copyfaces[0].edges[0].p1.Ip_r;

	//looking for the max and min value in the list of x, y, z coordinates.
	for (int i = 0; i < shapes->numPolys; i++)
	{
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			for (int h = 0; h < 3; h++)
			{
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_r)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_r;
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_g)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_g;
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_b)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_b;
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_r)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_r;
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_g)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_g;
				if (max < shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_b)
					max = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_b;

				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_r)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_r;
				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_g)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_g;
				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_b)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p1.Ip_b;
				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_r)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_r;
				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_g)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_g;
				if (min > shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_b)
					min = shapes->polyhedra[i].copyfaces[j].edges[h].p2.Ip_b;

			}
		}
	}


	NDCmax_Ip = max;
	NDCmin_Ip = min;
	varNDC_Ip = max - min;

	if (max != min)
	{

		for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
		{
			for (int j = 0; j < shapes->polyhedra[i].numFaces; j++) //all the faces
			{
				for (int u = 0; u < 3; u++) //for each edges, 3 per triangle
				{
					shapes->polyhedra[i].faces[j].edges[u].p1.Ip_r = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.Ip_r - NDCmin_Ip) / varNDC_Ip); // assuming that width = height
					shapes->polyhedra[i].faces[j].edges[u].p1.Ip_g = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.Ip_g - NDCmin_Ip) / varNDC_Ip);
					shapes->polyhedra[i].faces[j].edges[u].p1.Ip_b = ((shapes->polyhedra[i].copyfaces[j].edges[u].p1.Ip_b - NDCmin_Ip) / varNDC_Ip);

					shapes->polyhedra[i].faces[j].edges[u].p2.Ip_r = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.Ip_r - NDCmin_Ip) / varNDC_Ip);
					shapes->polyhedra[i].faces[j].edges[u].p2.Ip_g = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.Ip_g - NDCmin_Ip) / varNDC_Ip);
					shapes->polyhedra[i].faces[j].edges[u].p2.Ip_b = ((shapes->polyhedra[i].copyfaces[j].edges[u].p2.Ip_b - NDCmin_Ip) / varNDC_Ip);
				}
			}
		}
	}
	//cout << "Normalizing Color: " << varNDC_Ip << endl;
	//cout << "max is: " << max << " ; min is: " << min << endl;
	//cout << "varNDC is: " << varNDC_Ip << endl;
}//

void CDraw::HiddenSurface()
{
	//cout << "hiden surface" << endl;
	for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
	{
		// cout << "new " << endl;
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++) //all the faces
		{
			shapes->polyhedra[i].faces[j].hidden_z = (shapes->polyhedra[i].copyfaces[j].p1.z + shapes->polyhedra[i].copyfaces[j].p2.z + shapes->polyhedra[i].copyfaces[j].p3.z) / 3;
			shapes->polyhedra[i].faces[j].hidden_y = (shapes->polyhedra[i].copyfaces[j].p1.y + shapes->polyhedra[i].copyfaces[j].p2.y + shapes->polyhedra[i].copyfaces[j].p3.y) / 3;
			shapes->polyhedra[i].faces[j].hidden_x = (shapes->polyhedra[i].copyfaces[j].p1.x + shapes->polyhedra[i].copyfaces[j].p2.x + shapes->polyhedra[i].copyfaces[j].p3.x) / 3;
			//cout << shapes->polyhedra[i].copyfaces[j].p1.x << ' ' <<  shapes->polyhedra[i].copyfaces[j].p2.x << ' ' <<  shapes->polyhedra[i].copyfaces[j].p3.x << endl;
			//cout << shapes->polyhedra[i].faces[j].hidden_x << endl;
		}
	}
}

void CDraw::sortHidden_x()
{
	HiddenSurface();
	for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
	{
		Facevec temp(shapes->polyhedra[i].faces, shapes->polyhedra[i].faces + shapes->polyhedra[i].numFaces);
		//cout << "sorting hidden" << endl;
		for (Facevec::iterator itr = temp.begin(); itr != temp.end(); itr++)
		{
			//cout << itr->hidden_x << endl;
		}
		sort(temp.begin(), temp.end(), comp_x());

		for (Facevec::iterator itr = temp.begin(); itr != temp.end(); itr++)
		{
			//cout << itr->edges[0].p1.Ip_r << endl;
		}
		shapes->polyhedra[i].hidden_faces_x = new CFaces[shapes->polyhedra[i].numFaces];

		for (int g = 0; g < shapes->polyhedra[i].numFaces; g++)
		{
			shapes->polyhedra[i].hidden_faces_x[g] = temp.at(g);
		}
	}

	for (int i = 0; i < shapes->numPolys; i++)
	{
		cout << "new polyhedron: " << i << endl;
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			//cout << "hidden_x_ip_r: " << shapes->polyhedra[i].hidden_faces_x[j].edges[0].p1.Ip_r << endl;
		}
	}

}

void CDraw::sortHidden_y()
{
	HiddenSurface();
	for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
	{
		Facevec temp(shapes->polyhedra[i].faces, shapes->polyhedra[i].faces + shapes->polyhedra[i].numFaces);
		sort(temp.begin(), temp.end(), comp_y());
		for (Facevec::iterator itr = temp.begin(); itr != temp.end(); itr++)
		{
			//cout << itr->hidden_y << endl;
		}
		shapes->polyhedra[i].hidden_faces_y = new CFaces[shapes->polyhedra[i].numFaces];
		for (int g = 0; g < shapes->polyhedra[i].numFaces; g++)
		{
			shapes->polyhedra[i].hidden_faces_y[g] = temp.at(g);
		}
	}


}

void CDraw::sortHidden_z()
{
	HiddenSurface();
	for (int i = 0; i < shapes->numPolys; i++) // all the objects in the scene
	{
		Facevec temp(shapes->polyhedra[i].faces, shapes->polyhedra[i].faces + shapes->polyhedra[i].numFaces);
		sort(temp.begin(), temp.end(), comp_z());
		shapes->polyhedra[i].hidden_faces_z = new CFaces[shapes->polyhedra[i].numFaces];

		for (int g = 0; g < shapes->polyhedra[i].numFaces; g++)
		{
			shapes->polyhedra[i].hidden_faces_z[g] = temp.at(g);
		}
		//shapes->polyhedra[i].hidden_faces_z = &temp[0];
	}
	for (int i = 0; i < shapes->numPolys; i++)
	{
		//cout << "new polyhedron: " << i << endl;
		for (int j = 0; j < shapes->polyhedra[i].numFaces; j++)
		{
			//cout << "hidden_z: " << shapes->polyhedra[i].hidden_faces_z[j].hidden_z << endl;
		}
	}



}



/**
Rasterizes a polygon with a given ID by taking the edgelist computed already
in DrawLine function. It fills in between the pairs of coordinates. It begins
by drawing the edges with DDA, and then fill by calling LayerMakePix in between.
**/
void CDraw::Fill_ID()
{
	cout << "Rasterizing: ..." << endl;
	/*
	cout << "Ia: "   << Ia   << endl
	<< "Ka_r: " << ka_r << endl
	<< "Ka_g: " << ka_g << endl
	<< "Ka_b: " << ka_b << endl
	<< "Kd_r: " << kd_r << endl
	<< "Kd_g: " << kd_g << endl
	<< "Kd_b: " << kd_b << endl
	<< "Ks_r: " << ks_r << endl
	<< "Ks_g: " << ks_g << endl
	<< "Ks_b: " << ks_b << endl;
	*/
	//drawALLDDA_3D();                                   //Draw the edges then fill;


	for (int u = 0; u < shapes->numPolys; u++)
	{
		for (int k = 0; k < shapes->polyhedra[u].numFaces; k++)
		{
			//cout << "aaaaaaaassssss"<< endl;
			//cout << "hidden_z: " << shapes->polyhedra[u].hidden_faces_z[k].hidden_z << endl;
			for (edgelist::iterator itr = shapes->polyhedra[u].hidden_faces_z[k].edgesn.begin(); itr != shapes->polyhedra[u].hidden_faces_z[k].edgesn.end(); ++itr)
			{
				//cout << "Scanline at: " << itr->yvalue << endl;
				//cout << "List size: " << itr->xlist.size() << endl;
				int remaining = itr->xlist.size();
				for (xInterceptlist::iterator litr = itr->xlist.begin(); litr != itr->xlist.end(); litr++)
				{
					if (itr->xlist.size() == 1)
					{
						//cout << litr->x << endl;            
						break;
					}
					else
					{
						CPoints ix1;
						CPoints ix2;

						ix1 = *litr;
						ix1.x = round(ix1.x);
						--remaining;
						//cout << ix1 << endl;
						litr++;
						ix2 = *litr;
						ix2.x = round(ix2.x);
						--remaining;
						//cout << ix2 << endl;
						if (round(ix1.x) == round(ix2.x) || remaining < 0)
						{

						}
						else
						{

							float red;
							float green;
							float blue;
							float wh;
							float stepss;
							float currenta;
							float currentb;


							if (ix1.x <= ix2.x)
							{
								stepss = ix2.x - ix1.x;
								wh = ix1.x;
								currenta = wh - ix1.x;
								currentb = ix2.x - wh;

								red = (currentb / stepss) * (ix1.Ip_r) + (currenta / stepss) * (ix2.Ip_r);
								green = (currentb / stepss) * (ix1.Ip_g) + (currenta / stepss) * (ix2.Ip_g);
								blue = (currentb / stepss) * (ix1.Ip_b) + (currenta / stepss) * (ix2.Ip_b);
							}
							else
							{
								CPoints aatemp = ix2;
								ix2 = ix1;
								ix1 = aatemp;

								stepss = ix2.x - ix1.x;
								wh = ix1.x;
								currenta = wh - ix1.x;
								currentb = ix2.x - wh;

								red = (currentb / stepss) * (ix1.Ip_r) + (currenta / stepss) * (ix2.Ip_r);
								green = (currentb / stepss) * (ix1.Ip_g) + (currenta / stepss) * (ix2.Ip_g);
								blue = (currentb / stepss) * (ix1.Ip_b) + (currenta / stepss) * (ix2.Ip_b);
							}
							while (round(wh) != round(ix2.x))
							{
								LayerMakePix_XY(u, round(wh), itr->yvalue, red, green, blue);
								if (wh <= ix2.x)
								{
									++wh;
									currenta = wh - ix1.x;
									currentb = ix2.x - wh;
									red = (currentb / stepss) * (ix1.Ip_r) + (currenta / stepss) * (ix2.Ip_r);
									green = (currentb / stepss) * (ix1.Ip_g) + (currenta / stepss) * (ix2.Ip_g);
									blue = (currentb / stepss) * (ix1.Ip_b) + (currenta / stepss) * (ix2.Ip_b);
									//cout << "red: " << red << "; green: " << green << "; blue: " << blue << endl;
								}
								else
								{
									--ix1.x;
								}
							}
							LayerMakePix_XY(u, round(wh), itr->yvalue, red, green, blue); //fill in the last pix
																						  //cout << "testing " << endl;
						}
						if (litr == itr->xlist.end())
							break;
					}
				}
			}
		}
	}
}