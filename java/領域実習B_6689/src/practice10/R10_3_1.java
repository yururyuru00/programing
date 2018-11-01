package practice10;
import java.util.GregorianCalendar;

public class R10_3_1 {

	public static void main(String[] args) {
		GregorianCalendar cal = new GregorianCalendar();
		int year_nth, month_nth, day_nth, weekday;
		int year = cal.get(GregorianCalendar.YEAR);
		System.out.println(year);
		if(cal.isLeapYear(year)) {
			System.out.println(year + "はうるう年です");
			cal.set(year, 2-1, 29);
			year_nth = cal.get(GregorianCalendar.WEEK_OF_YEAR);
			month_nth = cal.get(GregorianCalendar.WEEK_OF_MONTH);
			day_nth = cal.get(GregorianCalendar.DAY_OF_YEAR);
			weekday = cal.get(GregorianCalendar.DAY_OF_WEEK);
			System.out.printf("2/29は\n今年の%d週目\n 今月の%d週目\n 今年の%d日目\n 曜日番号%d", year_nth, month_nth, day_nth, weekday);

		}
		else {
			System.out.println(year + "はうるう年ではありません");
			
			cal.set(year, 2-1, 28);
			year_nth = cal.get(GregorianCalendar.WEEK_OF_YEAR);
			month_nth = cal.get(GregorianCalendar.WEEK_OF_MONTH);
			day_nth = cal.get(GregorianCalendar.DAY_OF_YEAR);
			weekday = cal.get(GregorianCalendar.DAY_OF_WEEK);
			System.out.printf("2/28は\n今年の%d週目\n 今月の%d週目\n 今年の%d日目\n 曜日番号%d", year_nth, month_nth, day_nth, weekday);
		}
	}
}

