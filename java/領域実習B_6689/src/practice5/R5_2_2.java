package practice5;


public class R5_2_2 {

	public static void main(String[] args) {
		//コンストラクタ1
		Sphere s = new Sphere();
		s.r = 2.5;
		s.c_y = 10.5;
		s.c_z = 10.99;

		//コンストラクタ2
		Sphere s2 = new Sphere(3, 1.11, 3.2, 8.9);

		System.out.printf("半径%.2f 座標(%.2f, %.2f, %.2f)\n", s.r, s.c_x, s.c_y, s.c_z);
		System.out.printf("半径%.2f 座標(%.2f, %.2f, %.2f)\n", s2.r, s2.c_x, s2.c_y, s2.c_z);

		//座標、半径の確認
		s.move(3,  4,  5.5);
		s2.scale(100);

		System.out.printf("半径%.2f 座標(%.2f, %.2f, %.2f)\n", s.r, s.c_x, s.c_y, s.c_z);
		System.out.printf("半径%.2f 座標(%.2f, %.2f, %.2f)\n", s2.r, s2.c_x, s2.c_y, s2.c_z);

		//メソッドのオーバーロードの確認
		s.move(10, 2);
		System.out.printf("半径%.2f 座標(%.2f, %.2f, %.2f)\n", s.r, s.c_x, s.c_y, s.c_z);

	}


}
