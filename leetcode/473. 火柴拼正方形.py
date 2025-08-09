class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        S=sum(matchsticks)
        if S%4:
            return False
        S//=4
        
        @cache
        def f(rest,status,nth):
            if not rest:
                rest=S
                nth+=1
            if nth>4:
                return True

            for i in range(0,len(matchsticks)):
                if status&(1<<i) and matchsticks[i]<=rest and f(rest-matchsticks[i],status^(1<<i),nth):
                    return True
            return False
            
        
        return f(S,(1<<len(matchsticks))-1,1)
        
