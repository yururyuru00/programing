package prog_training;

import java.util.HashMap;

public class CarTable {

	public static void main(String[] args) {

		HashMap<NumberPlate, String> carMap = new HashMap<NumberPlate, String>();

		NumberPlate np = new NumberPlate("兵庫", new int[]{1,2}, 'あ', new int[]{5, 5, 4, 1});
		NumberPlate np2 = new NumberPlate("兵庫", new int[]{1,2}, 'あ', new int[]{5, 5, 4, 1});
		NumberPlate np3 = new NumberPlate("兵庫", new int[]{1,2}, 'あ', new int[]{5, 5, 4, 1});

		carMap.put(np2, "12");
		System.out.println(carMap.get(np3));

	}

}
