    public ArrayList<Integer> EulerCycle(int[][] graph) {
        ArrayList<Integer> path = new ArrayList<>();
        // recursive approach
        dfs(path, 0, graph);

        // iterate approach
        // only apply to directed graph
        // https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/

        return path;
    }
    public void dfs(ArrayList<Integer> path, int curr, int[][] graph) {
        for(int i = 0; i < graph[curr].length; ++i) {
            if(graph[curr][i] != 0) {
                graph[curr][i] = 0;
                graph[i][curr] = 0;
                dfs(path, i, graph);
            }
        }
        path.add(curr);
    }