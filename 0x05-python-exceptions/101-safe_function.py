#!/usrlbin/python3

from __future__ import print_function
import sys

def safe_function(fct, *args):
    try:
        res = fct(*args)
    except Exception as e:
        print("Exveption: {}".format(e), filesys.stderr)
        return None
    else:
        return res
