# Project Euler Problem: 33
# Goal: find the denominator of the product of all for digit-canceling fractions less than one.
# Author: Cooper Bell

def common_frac(first, second):
    f = [int(a) for a in str(first)]
    s = [int(b) for b in str(second)]

    if (0 in s) or (0 in f):
        return False

    if first >= second:
        return False

    if f[0] == s[0]:
        return float(f[1])/float(s[1])
    elif f[1] == s[1]:
        return float(f[0])/float(s[0])
    elif f[0] == s[1]:
        return float(f[1])/float(s[0])
    elif f[1] == s[0]:
        return float(f[0])/float(s[1])
    else:
        return False

denoms = [i for i in range(10,100)]
nums = [j for j in range(10,100)]
num, denom = 1, 1

for n in nums:
    for d in denoms:
        if (common_frac(n, d)) and (common_frac(n, d) == float(n) / float(d)):
            print "%s / %s" % (n, d)
            num *= n
            denom *= d

print num, denom
