import random

indir="test-cases/as-274-7-binsearch.sh-test/Inputs"

cno = 0
MAXN = 1000000


def gen(a, q, s):
    global cno

    assert(type(a) == list and len(a) > 0)
    assert(type(q) == list and len(q) > 0)
    assert(type(s) == str)
    for x in a+q:
        assert(type(x) == int and 0 <= x and x <= MAXN)
    assert(a == sorted(a))

    print("Generating:", cno)
    fname = "{0}/{1:03}-stdin.txt".format(indir, cno)
    cno += 1

    f = open(fname, "w")
    print(len(a), file=f)
    print(*a, file=f)
    print(len(q), file=f)
    print(*q, file=f)
    print("COMMENT:", s,file=f)
    f.close()

if __name__ == "__main__":
    gen([2, 5, 7], [4], "simple example with 1 query")
    gen([2, 5, 7], [2], "simple example with 1 query")
    gen([2, 5, 7], [0], "simple example with 1 query")
    gen([2, 5, 7], [7], "simple example with 1 query")
    gen([2, 5, 7], [8], "simple example with 1 query")

    gen([1, 2, 4], [0, 1, 2, 3, 4, 5], "simple example with 6 queries")
    gen([1, 3, 5, 7, 9, 11, 13], list(range(15)), "slightly bigger example")

    gen([1], [0, 1, 2], "example with only one number in the array")

    gen([1, 1], [0, 1, 2], "example with duplicate numbers")

    gen([1, 3, 5, 5, 5, 5, 7, 7, 7, 8], [0, 1, 4, 5, 6, 7, 8], "slightly bigger example with duplicate numbers")

    a = sorted([random.randint(0, MAXN) for i in range(MAXN)])
    q = [random.randint(0, MAXN) for i in range(MAXN)]
    gen(a, q, "very big random example")
