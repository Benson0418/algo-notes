from collections import defaultdict

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not s:
            return []
        
        BASE = 131
        MOD = 1000000009
        
        def hashing(w):
            res = 0
            for x in w:
                res = (res * BASE + ord(x)) % MOD
            return res
        
        word_len = len(words[0])
        total_words = len(words)
        total_len = word_len * total_words
        n = len(s)
        
        if n < total_len:
            return []
        
        required = {}
        for w in words:
            h = hashing(w)
            required[h] = required.get(h, 0) + 1
        
        H = [0] * (n + 1)
        P = [1] * (n + 1)
        for i in range(1, n + 1):
            P[i] = (P[i-1] * BASE) % MOD
            H[i] = (H[i-1] * BASE + ord(s[i-1])) % MOD
        
        def get_hash(l):
            r = l + word_len
            return (H[r] - H[l] * P[r - l] % MOD + MOD) % MOD
        
        res = []
        
        for i in range(word_len):
            current = defaultdict(int)
            matched = 0
            for j in range(total_words):
                start_index = i + j * word_len
                if start_index + word_len > n:
                    break
                h_seg = get_hash(start_index)
                current[h_seg] += 1
                if h_seg in required:
                    if current[h_seg] == required[h_seg]:
                        matched += 1
                    elif current[h_seg] == required[h_seg] + 1:
                        matched -= 1
            if matched == len(required):
                res.append(i)
            
            seg_count = (n - i) // word_len
            for j in range(total_words, seg_count):
                remove_index = i + (j - total_words) * word_len
                add_index = i + j * word_len
                
                h_remove = get_hash(remove_index)
                h_add = get_hash(add_index)
                
                if h_remove in required:
                    if current[h_remove] == required[h_remove]:
                        matched -= 1
                    elif current[h_remove] == required[h_remove] + 1:
                        matched += 1
                current[h_remove] -= 1
                
                current[h_add] += 1
                if h_add in required:
                    if current[h_add] == required[h_add]:
                        matched += 1
                    elif current[h_add] == required[h_add] + 1:
                        matched -= 1
                
                if matched == len(required):
                    res.append(remove_index + word_len)
        
        return res
