struct MapPoint
{
	float x;
	float y;
	float z;
};

typedef struct MapPoint struct MapVector;

struct MapQuad
{
	struct MapPoint p1;
	struct MapPoint p2;
	struct MapPoint p3;
	struct MapPoint p4;
};

struct MapObject
{
	unsigned int id;
	short unsigned int type;
	union {
		struct MapPoint point;
		struct MapQuad surface;	
	} data;
};

