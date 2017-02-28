//header file for quad



typedef struct force{
 double x;
 double y;
} force_t;

typedef struct particle
{
   double             x_pos;
   double             y_pos;
   double 	     mass;
   double      vel_x;
   double       vel_y;
} particle_t;

typedef struct Quadtree {
	struct Quadtree * nw;
	struct Quadtree * ne;
	struct Quadtree * se;
	struct Quadtree * sw;
	particle_t p;
	double width;
	double centerX;
	double centerY;
	double massCenterX;
	double massCenterY;
	double mass;	
}p_qtree;

typedef struct ForceInput {
	p_qtree * head;
	particle_t * particles;
	double theta_max;
	double G;
	double epsilon;
	double delta_t;
	int id;
	int interval;
}forceInput_t;

void insert(p_qtree ** node, particle_t p);

force_t* getForce(p_qtree ** node, particle_t p, double thetamax, double G, double epsilon);

void delete(p_qtree ** node);

void nullifyChildren(p_qtree **node);

void massification(p_qtree ** node);

void printTree(p_qtree ** node);

void * thread_func(void* arg);
