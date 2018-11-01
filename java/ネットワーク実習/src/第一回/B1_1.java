package 第一回;
import java.util.Calendar;

public class B1_1 {

	public static void main(String[] args) {
		System.out.println("日 月 火 水 木 金 土 ");

		int i;
		int year = Integer.parseInt(args[0]);
		int month = Integer.parseInt(args[1])-1;

		Calendar cal = Calendar.getInstance();
		cal.set(year, month, 1);
		int first = cal.get(Calendar.DAY_OF_WEEK)-1;
		int last = cal.getActualMaximum(Calendar.DAY_OF_MONTH);

		for(i=0; i<first; i++) System.out.print("   ");
		for(i=1; i<=last; i++) {
			System.out.print(i);

			if(i<10) System.out.print("  ");
			else System.out.print(" ");

			if((i+first)%7==0) System.out.println();
			else ;
		}

	}

}
