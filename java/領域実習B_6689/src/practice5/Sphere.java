package practice5;

public class Sphere {
	double r;
	double c_x;
	double c_y;
	double c_z;

	Sphere() {
		this.r=1;
		this.c_x=0;
		this.c_y=0;
		this.c_z=0;
	}

	Sphere(double r) {
		this(r, 0, 0, 0);

	}

	Sphere(double r_, double x, double y, double z) {
		this.r = r_;
		this.c_x=x;
		this.c_y=y;
		this.c_z=z;
	}


	void move(double x) {
		this.c_x=x;
	}

	void move(double x, double y) {
		this.c_x=x;
		this.c_y=y;
	}

	void move(double x, double y, double z) {
		this.c_x=x;
		this.c_y=y;
		this.c_z=z;
	}

	void scale(double r) {
		this.r = r;
	}
}
