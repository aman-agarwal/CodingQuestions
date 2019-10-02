
def oneApart(s1, s2):
    i = 0
    j = 0
    while i < len(s1) and j < len(s2):
        if s1[i] != s2[j]:
            if s1[i+1:] == s2[j:] or s1[i:] == s2[j+1:] or s1[i+1:] == s2[j+1:]:
                print 1
            else:
                print 0
            break
        i += 1
        j += 1
    if i == len(s1) and j == len(s2):
        print 1
