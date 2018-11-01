package snippet;

public class Snippet {
	char separator;
	
	
	int factor(int n)
	{
	  int d;
	  d = 2;
	  while (((d * d)  <= n)) {
	    if (((n % d) == 0)) {
	      putint(d);
	      putchar(separator);
	      n = (n / d);
	    }
	    else {
	      d = (d + 1);
	    }
	  }
	  putint(n);
	  putchar('\n');
	}
	
	
	int main()
	{
	  int n;
	  putchar('n');
	  putchar('=');
	  n = getint();
	  separator = '*';
	  factor(n);
	}
}

