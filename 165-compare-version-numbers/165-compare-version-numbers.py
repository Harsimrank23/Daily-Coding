class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1=version1.split(".")
        l2=version2.split(".")
        
        l1=[int(i) for i in l1]
        l2=[int(i) for i in l2]
        
        while(len(l1)<len(l2)):
            l1.append(0)
            
        while(len(l2)<len(l1)):
            l2.append(0)
            
        for i in range(len(l1)):
            if (l1[i]>l2[i]):
                return 1
            elif (l2[i]>l1[i]):
                return -1
        
        return 0
            
        # print(l1)
        # print(l2)
        