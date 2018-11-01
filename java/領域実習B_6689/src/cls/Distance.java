package cls;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;

public class Distance {
	int i, j;

	Distance() {
		i=0; j=0;
	}

	double calc(double[] a, double[] b) {
		return Math.sqrt( (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]) +
				(a[2]-b[2])*(a[2]-b[2]) + (a[3]-b[3])*(a[3]-b[3]) );
	}

	double[][] classFormat(BufferedReader br) throws NumberFormatException, IOException {
		String[] buffer_s;
		String buffer;
		int i=0, j;
		double[][] c = new double[100][4];

		while ((buffer = br.readLine()) != null) {
			buffer_s = buffer.split(",");
			for(j=0; j<4; j++) c[i][j] = Double.parseDouble(buffer_s[j]);
			i++;
		}
		return c;
	}

	double[][] tableFormat(double[][] c) {
		double[][] dist = new double[100][100];
		for(i=0; i<99; i++) {
			for(j=i+1; j<100; j++) {
				dist[i][j] = this.calc(c[i], c[j]);
				dist[j][i] = dist[i][j];
			}
			dist[i][i] = 0;
		}
		return dist;
	}

	double min(Map<Integer, ArrayList<Integer>> cmap, int a, int b, double[][] dist) {
		//グループa番とb番の最小距離を返す関数
		ArrayList<Integer> l1 = cmap.get(a);
		ArrayList<Integer> l2 = cmap.get(b);
		double m, min=100.0;

		if(l1!=null && l2!=null) {
			for(i=0; i<l1.size(); i++) {
				for(j=0; j<l2.size(); j++)
					if( (m = dist[l1.get(i)][l2.get(j)]) < min ) {min = m;}
			}
		}
		return min;
	}

	int update(Map<Integer, ArrayList<Integer>> cmap, int a, int b, double[][] dist) {
		ArrayList<Integer> l1 = cmap.get(a);
		ArrayList<Integer> l2 = cmap.get(b);

		for(i=0; i<l1.size(); i++) {
			for(j=0; j<l2.size(); j++) {
				dist[l1.get(i)][l2.get(j)] = 100;
				dist[l2.get(j)][l1.get(i)] = 100;
			}
		}
		cmap.get(a).addAll(cmap.get(b));
		cmap.remove(b);

		//更新が正しく行われているかテスト表示
		int counter=0;
		for(i=0; i<100; i++) {
			if(cmap.get(i)!=null) {
				System.out.print(cmap.get(i) + " ");
				counter++;
			}
			else ;
			if(i%10==0 && i>0) System.out.println();
		}
		System.out.println();

		return counter;
	}



}