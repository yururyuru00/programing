package practice10;
import java.util.Date;

public class R10_2_1 {

	public static void main(String[] args) {
		Date epoch = new Date();
		System.out.println(epoch.getTime()/1000/60/60/24 + "日");
	}

}
