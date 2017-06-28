import java.util.Arrays;

public class Test
{
	public static double sqrt(double c)
	{
		if(c<0) return Double.NaN;
		double err = 1e-15;
		double t = c;
		while(Math.abs(t - c/t) > err*t)
			t = (c/t + t) / 2.0;
		return t;
	}

	public static int rank(int key, int[] a)
	{
		int lo = 0;
		int hi = a.length - 1;
		while(lo <= hi)
		{
			int mid = lo + (hi - lo)/2;
			if(key < a[mid]) hi = mid - 1;
			else if(key > a[mid]) lo = mid + 1;
			else return mid;
		}
		return -1;
	}
	public static void main(String []args)
	{
		int [] a = {1, 2, 1, 42};
		Arrays.sort(a);
	//	stdDraw.point(12,4);
		for(int i=0; i<a.length; ++i)
			System.out.println(a[i]);
		System.out.println(sqrt(3780));

		if((args[0] == args[1])&&(args[0] == args[2]))
			System.out.println("equal");
		else
			System.out.println("Not equal");
		System.out.println(args[0]+" "+args[1]+" "+args[2]);
		System.out.println('b'+'c');

	}
}
