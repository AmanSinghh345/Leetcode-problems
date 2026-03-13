import math
class Solution(object):
    def minNumberOfSeconds(self, h, workerTimes):
        """
        :type mountainHeight: int
        :type workerTimes: List[int]
        :rtype: int
        """
        mintime=1
        base=workerTimes[0]
        maxtime=base*(h*(h+1))//2
        ans=maxtime
        while maxtime>=mintime:
            mid=(maxtime+mintime)//2
            height=0
            for i in workerTimes:
                z=mid/i
                if z>0:
                    count=(math.sqrt(1+8*z)-1)//2
                    height+=count
            if height<h:
                mintime=mid+1
            else:
                ans=mid
                maxtime=mid-1
        return ans 
            