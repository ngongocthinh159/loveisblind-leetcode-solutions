class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] preCount = new int[numCourses];
        int[] removed = new int[numCourses];
        int[] res = new int[numCourses];
        
        // Count prerequisites of each course
        for (int i = 0; i < prerequisites.length; i++) {
            preCount[prerequisites[i][0]]++;
        }
        
        // Gradually remove sources with no prerequisite
        for (int count = 0; count < numCourses; count++) {
            boolean sourceFound = false;
            
            // Find source
            for (int i = 0; i < preCount.length; i++) {
                if (removed[i] == 1) continue;
                
                if (preCount[i] == 0) {
                    sourceFound = true;
                    
                    // Remove source
                    removed[i] = 1;
                    res[count] = i;
                    
                    // Update prerequisites after removing the source
                    // Decrease the preCount of all courses have the removed source as prerequisite
                    for (int j = 0; j < prerequisites.length; j++) {
                        if (prerequisites[j][1] == i) preCount[prerequisites[j][0]]--;
                    }
                    
                    break; // After removed the source => break the for loop for stop looking for new source
                }
            }
            
            if (!sourceFound) return new int[0];
        }
        
        return res;
    }
}