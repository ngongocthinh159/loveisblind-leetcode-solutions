class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        explore(graph, 0, path, res);
        return res;
    }
    
    public static void explore(int[][] graph, int src, List<Integer> path, List<List<Integer>> res) {
        int current = src;
        
        if (current == graph.length - 1) {
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(0);
            temp.addAll(path);
            res.add(temp);
            return;
        }
        
        for (Integer next : graph[current]) {
            path.add(next);
            explore(graph, next, path, res);
            path.remove(path.size() - 1);
        }
    }
}