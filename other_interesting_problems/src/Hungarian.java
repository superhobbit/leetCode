import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class Hungarian {
    private double[][] matrix;
    private double[][] weight_copy;
    private int length, smaller, n, m;
    private HashMap<Integer, Integer> map = new HashMap<>();
    public Hungarian(double[][] weight) {
        weight_copy = weight;
        n = weight.length;
        m = weight[0].length;
        if(n == 0 || m == 0)
            throw new IllegalArgumentException("illegal weight matrix");
        length = Integer.max(n, m);
        smaller = Integer.min(n, m);
        matrix = new double[length][length];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(weight[i][j] < 0)
                    throw new ArithmeticException("Weight value must be non-negative");
                matrix[i][j] = weight[i][j];
            }
        }
    }

    private void printMatrix() {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public Double calculate() {
        RCReduce(true);
        RCReduce(false);
        assign();
        StringBuilder sb = new StringBuilder();
        double res = 0;
        for(HashMap.Entry<Integer, Integer> entries : map.entrySet()) {
            int x = entries.getKey(), y = entries.getValue();
            sb.append("Worker: " + x + " assigned task: " + y + '\n');
            res += weight_copy[x][y];
        }
        System.out.println(sb.toString() + "Total cost: " + Double.toString(res));
        return res;
    }

    private void RCReduce(boolean is_i) {
        double[] rowMin = new double[length];
        Arrays.fill(rowMin, Integer.MAX_VALUE);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                if(is_i)
                    rowMin[i] = Math.min(rowMin[i], matrix[i][j]);
                else
                    rowMin[j] = Math.min(rowMin[j], matrix[i][j]);
            }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(is_i)
                    matrix[i][j] -= rowMin[i];
                else
                    matrix[i][j] -= rowMin[j];
            }
        }
    }

    private void assign() {
        boolean[] rows = new boolean[length];
        boolean[] cols = new boolean[length];
        while(true) {
            Arrays.fill(rows, false);
            Arrays.fill(cols, false);
            for(int i = 0; i < n; ++i) {
                if(!cols[i]) {
                    int count = 0, index = -1;
                    for(int j = 0; j < m; ++j) {
                        if(matrix[i][j] == 0 && !rows[j]) {
                            count++;
                            index = j;
                        }
                    }
                    if(count == 1) {
                        rows[index] = true;
                        map.put(i, index);
                    }
                }
            }
            if(map.size() == smaller)
                break;
            for(int j = 0; j < m; ++j) {
                if(!rows[j]) {
                    int count = 0, index = -1;
                    for(int i = 0; i < n; ++i) {
                        if(matrix[i][j] == 0 && !cols[i]) {
                            count++;
                            index = i;
                        }
                    }
                    if(count == 1) {
                        cols[index] = true;
                        map.put(index, j);
                    }
                }
            }
            if(map.size() != smaller) {
                double min = Integer.MAX_VALUE;
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if(!rows[j] && !cols[i])
                            min = Math.min(min, matrix[i][j]);
                    }
                }
//                for(int i = 0; i < length; ++i) {
//                    System.out.print(rows[i] + " ");
//                }
//                System.out.println();
//                for(int i = 0; i < length; ++i)
//                    System.out.print(cols[i] + " ");
//                System.out.println();
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if(!rows[j] && !cols[i])
                            matrix[i][j] -= min;
                        else if(rows[j] && cols[i])
                            matrix[i][j] += min;
                    }
                }
            } else {
                break;
            }
        }
    }

    public static void main(String[] args) {
        double[][] weight = {{74,29,46}, {51,12,65}};
        Hungarian h = new Hungarian(weight);
        Double res = h.calculate();
        System.out.println(res);
    }

}

