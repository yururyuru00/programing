package prog_training;

import java.util.Arrays;
import java.util.Objects;

public final class NumberPlate {

	private String place;
	private int[] clas = new int[2];
	private char c;
	private int[] number = new int[4];

	public NumberPlate(String place, int[] clas, char c, int[] number) {
		System.out.println("line14");
		this.place = place;
		this.clas = clas;
		this.c = c;
		this.number = number;
	}

	@Override
	public boolean equals(Object obj) {
		System.out.println("line23");
		if(obj instanceof NumberPlate) {
			System.out.println("line25");
			NumberPlate np = (NumberPlate) obj;
			return this.place.equals(np.place) &&
					   Arrays.equals(this.clas, np.clas) &&
					   this.c == np.c &&
					   Arrays.equals(this.number, np.number);
        }
		else {
			System.out.print("line33");
			return false;
		}
	}

	@Override
	public int hashCode() {
		System.out.println("line40");
		return Objects.hash(place, clas[0], clas[1], c, number[0], number[1], number[2], number[3]);
	}

}


