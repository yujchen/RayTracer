//YU-JUI CHEN 
//998896915
//yujchen@ucdavis.edu

#include "shapes.h"
#include "draw.h"

CShapes* shapes;
CDraw* drawer;
void RecordShapes(int width, int height);

float *PB_XY; //Pixel buffer for XY
float *PB_XZ; //Pixel buffer for XZ
float *PB_YZ; //Pixel buffer for YZ

int width = 0, height = 0;

void display1();
void display2();
void display3();


//Prompts the user to enter the size via console->store width and height
void GetWindowDimensions(int& w, int& h)
{
	string size;
	cout << "Please enter window size in the format width(space)height: ";
	getline(cin, size);
	stringstream(size) >> w >> h;
}//End GetWindowDimensions



 //Reads the input file and stores the coordinates into the backend.
void RecordShapes(int width, int height)
{
	int numShapes = 0, numCords = 0, numFaces = 0, polyID = 0, pt1 = 0, pt2 = 0, pt3 = 0;

	//CShapes* shapes;

	ifstream inf("3d_coloring.txt");				//Opens the input file
	inf >> numShapes;						//Read first value, which is the number of shapes

	shapes = new CShapes(numShapes);
	//cout << "Number of Shapes: " << shapes->numPolys << endl;

	while (polyID != numShapes)
	{
		inf >> numCords;
		shapes->polyhedra[polyID].SetPolys(numCords);
		shapes->polyhedra[polyID].SetPB(width, height);
		//cout << "Number of points of the polyhedra: "
		//		 << shapes->polyhedra[polyID].numPoints << endl;		

		for (int i = 0; i < numCords; i++)
		{
			inf >> shapes->polyhedra[polyID].points[i].x
				>> shapes->polyhedra[polyID].points[i].y
				>> shapes->polyhedra[polyID].points[i].z
				>> shapes->polyhedra[polyID].points[i].nx
				>> shapes->polyhedra[polyID].points[i].ny
				>> shapes->polyhedra[polyID].points[i].nz;

			//	cout << setprecision(1) << fixed
			//			 << shapes->polyhedra[polyID].points[i].x
			//			 << ' ' << shapes->polyhedra[polyID].points[i].y
			//			 << ' ' << shapes->polyhedra[polyID].points[i].z << endl; 
			//Formats output to same as input.
			//setprecision specifies minimum precision
			//fixed says that there will be fixed number of decimal digit after the decimal point.
		}
		inf >> numFaces;												//Begin setting faces of polyhedron


		shapes->polyhedra[polyID].numFaces = numFaces;
		shapes->polyhedra[polyID].faces = new CFaces[numFaces];
		shapes->polyhedra[polyID].copyfaces = new CFaces[numFaces];

		int d = 0;
		int numEdges = 0;

		for (int i = 0; i < numFaces; i++) //setting up pairs of points for an edge
		{
			inf >> numEdges >> pt1 >> pt2 >> pt3;

			shapes->polyhedra[polyID].faces[i].verfaces = new int[numEdges]; //storing how to connect the points
																			 //for every line, there is two points
			shapes->polyhedra[polyID].copyfaces[i].verfaces = new int[numEdges]; //storing how to connect the points
																				 //for every line, there is two points

			shapes->polyhedra[polyID].faces[i].verfaces[d] = pt1;
			shapes->polyhedra[polyID].copyfaces[i].verfaces[d] = pt1;
			d++;
			shapes->polyhedra[polyID].faces[i].verfaces[d] = pt2;
			shapes->polyhedra[polyID].copyfaces[i].verfaces[d] = pt2;
			d++;
			shapes->polyhedra[polyID].faces[i].verfaces[d] = pt3;
			shapes->polyhedra[polyID].copyfaces[i].verfaces[d] = pt3;
			d++;

			//cout << "pt1: " << pt1 << " pt2: " << pt2 << endl;
			shapes->polyhedra[polyID].faces[i].p1 = shapes->polyhedra[polyID].points[pt1];
			shapes->polyhedra[polyID].faces[i].p2 = shapes->polyhedra[polyID].points[pt2];
			shapes->polyhedra[polyID].faces[i].p3 = shapes->polyhedra[polyID].points[pt3];
			shapes->polyhedra[polyID].copyfaces[i].p1 = shapes->polyhedra[polyID].points[pt1];
			shapes->polyhedra[polyID].copyfaces[i].p2 = shapes->polyhedra[polyID].points[pt2];
			shapes->polyhedra[polyID].copyfaces[i].p3 = shapes->polyhedra[polyID].points[pt3];

			shapes->polyhedra[polyID].faces[i].edges = new CLines[3]; //Three edges per triangle
			shapes->polyhedra[polyID].copyfaces[i].edges = new CLines[3]; //Three edges per triangle
			int q = 0;
			shapes->polyhedra[polyID].faces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt1];
			shapes->polyhedra[polyID].faces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt2];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt1];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt2];
			q++;
			shapes->polyhedra[polyID].faces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt2];
			shapes->polyhedra[polyID].faces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt3];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt2];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt3];
			q++;
			shapes->polyhedra[polyID].faces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt3];
			shapes->polyhedra[polyID].faces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt1];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p1 = shapes->polyhedra[polyID].points[pt3];
			shapes->polyhedra[polyID].copyfaces[i].edges[q].p2 = shapes->polyhedra[polyID].points[pt1];
			q = 0;
			d = 0;

		}
		numCords = 0;
		numFaces = 0;

		//shapes->polyhedra[polyID].printLines();

		if (shapes->polyhedra[polyID].numPoints > 1)																		//There needs to be at least two points to draw a line.
		{
			shapes->polyhedra[polyID].twop = true;
			//shapes->polyhedra[polyID].SetLines();
		}
		else
			shapes->polyhedra[polyID].twop = false;

		++polyID;
		numCords = 0;
	}

	//shapes->MakeCopy(); //make an copy of the original world coordinates
	for (int c = 0; c < shapes->numPolys; c++)
	{
		//shapes->polyhedra[c].printLines_copy();
	}
}



int main(int argc, char *argv[])
{
	GetWindowDimensions(width, height);																							//Call GetWindowDimensions to set width and height

																																//allocate new pixel buffer, need initialization!!
	PB_XY = new float[width * height * 3];
	PB_XZ = new float[width * height * 3];
	PB_YZ = new float[width * height * 3];


	for (int i = 0; i < (width*height * 3); i++) 	//Clears the PixelBuffer;
	{
		PB_XY[i] = 0;
		PB_XZ[i] = 0;
		PB_YZ[i] = 0;
	}
	RecordShapes(width, height);
	//drawer = new CDraw ( PixelBuffer, width, height, shapes ); //2D
	drawer = new CDraw(PB_XY, PB_XZ, PB_YZ, width, height, shapes); // 3D


	glutInit(&argc, argv);


	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(width, height); 	//set window size to 200*200
	glutInitWindowPosition(0, 0);	//set window position
	glutCreateWindow("XY-Plane");	//create and set main window title
	glClearColor(0, 0, 0, 0); //clears the buffer of OpenGL
	glutDisplayFunc(display1);	//sets display function


	glutMainLoop();//main display loop, will display until terminate
	return 0;
}


//main display loop, this function will be called again and again by OpenGL
void display1()
{
	if (drawer->firstrun == 0)
	{

		for (int i = 0; i < (width*height * 3); i++) 	//Clears the PixelBuffer;
		{
			PB_XY[i] = 0;
			PB_XZ[i] = 0;
			PB_YZ[i] = 0;
		}
		//cout << "hi" << endl;
		drawer->firstrun = 1;
	}

	//Misc.
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glDrawPixels(width, height, GL_RGB, GL_FLOAT, PB_XY);
	//glFlush();	//Display blackscreen/ without this line, screen turns gray.

	//CShapes* shapes = RecordShapes(width, height);																								//Instantiate a CShape object that records all input.

	//CDraw* drawer = new CDraw ( PixelBuffer, width, height, shapes );
	//drawer->DrawLine();



	//draws pixel on screen, width and height must match pixel buffer dimension
	//glDrawPixels(width, height, GL_RGB, GL_FLOAT, PixelBuffer);


	//window refresh
	glFlush();
	glutPostRedisplay();
	drawer->Menu_3D();

}

