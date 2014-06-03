#include <GL/freeglut.h>
#include <GL/gl.h>

const int NumPoints = 5000;

void init(void)
{
	vec2 points[NumPoints];
	//Specify the vertices for a triangle
	vec2 vertices[3] = 
	{
		vec2(-1.0, -1.0),
		vec2(0.0, 1.0),
		vec2(1.0, -1.0)
	};

	//Select an arbitrary initial point inside of the triangle
	pointis[0] = vec2(0.25, 0.50);

	//Compute and store N-1 new points
	for (int i = 1; i < NumPoints; ++i)
	{
		int j = rand(void) % 3;	//Pick a vertex at random
		//Compute the point halfway between the selected vertex
		//and the previous point
		point[i] = (points[i - 1] + vertices[j]) / 2.0;
	}

	//Load shaders and use the resulting shader program
	GLuint program = InitShader ("vshader21.glsl", "fshader21.glsl");
	glUseProgram(program);

	//Create a vertex array object
	GLuint vao;
	glGenBuffers(1, &vao);
	glBindVertexArray(vao);

	//Create and initialize a buffer object
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	//Initialize the vertex position attribute from the vertex shader
	GLuint loc = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glClearColor(1.0, 1.0, 1.0, 1.0); //White background
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	//Clear the window
	glDrawArrays(GL_POINTS, 0, NumPoints);	//Draw the points
	glFlush(void);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	//If you are using freeglut, the next two lines will check if the code 
	//is truly 3.2. Otherwisse, comment them out.
	glutInitContextVersion(3, 2);
	glutInitContexProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Sierpinski Gasket");

	glewInit(void);
	init(void);
	glutDisplayFunc(display);

	glutMainLoop(void);
	return 0;
}
