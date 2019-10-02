
def _ed(s1, s2):
  if len(s1) == 0:
    return len(s2)
  elif len(s2) == 0:
    return len(s1)
  elif s1[0] == s2[0]:
    return _ed(s1[1:], s2[1:])
  else:
    return 1+min(_ed(s1[1:], s2), _ed(s1[1:], s2[1:]), _ed(s1, s2[1:]))   


def editDist(s1, s2):
  _eD(s1, s2)
