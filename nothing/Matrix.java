import java.util.Arrays;

public class Matrix
{
	public static double dot(double[] x, double [] y)
	{
		double ans = 0.0;
		for(int i=0; i<x.length; ++i)
			ans += x[i]*y[i];
		return ans;
	}

	public static double[][] mult(double[][] a, double[][] b)
	{
		int N = a.length;
		int M = b[0].length;
		int Q = b.length;
		double[][] c = new double[N][M];

		for(int i=0; i< N; ++i)
			for(int j=0; j<M; ++j)
				for(int k=0; k<Q; ++k)
					c[i][k] = a[i][k] * b[k][j];
		return c;
	}

	public static double[][] transpose(double[][] a)
	{
		int N = a.length, M = a[0].length;
		double [][]t = new double[N][M];

		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				t[j][i] = a[i][j];
		return t;
	}

	public static double[] mult(double[][] a, double[] x)
	{
		int N = a.length, M = x.length;
		double[] b = new double[N];

		for(int i=0; i<N; ++i)
		{
			b[i] = 0.0;
			for(int j=0; j<M; ++j)
				b[i] += a[i][j]*x[j];
		}
		return b;
	}

	public static double[] mult(double[] y, double[][]a)
	{
		int N = a.length, M = y.length;
		double[] b = new double[N];

		for(int i=0; i<N; ++i)
		{
			b[i] = 0.0;
			for(int j=0; j<M; ++j)
				b[i] += a[i][j]*y[j];
		}
		return b;
	}

	public static void main(String[] args)
	{
		double[][] matrix_one = {{1,2,3,4},{1,2,3,4},{4,3,2,1},{4,3,5,6}};
		double[][] matrix_two = {{1,2,3,4},{4,3,2,1},{4,5,6,7},{4,3,3,3}};
		double[][] multMatrix = mult(matrix_two, matrix_one);
		for(int i=0; i<4; ++i)
		{
			for(int j=0; j<4; ++j)
				System.out.print(multMatrix[i][j]+" ");
			System.out.println();
		}
	}
}
