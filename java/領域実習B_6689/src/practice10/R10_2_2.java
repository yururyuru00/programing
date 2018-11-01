package practice10;

import java.util.Date;

public class R10_2_2 {
	
	public static void main(String[] args) {
		Date now = new Date();
		long pass = now.getTime();
		long after = ((long)100*24*60*60*1000);
		now.setTime(pass+after);
		System.out.println(now);
	}

}
