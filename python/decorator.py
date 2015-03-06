#!/usr/bin/env python

def send_to_remote(func):
    def locate_host(*args, **kwargs):
        print "args: %s(len:%d), %s, %s(len:%d)" % (args, len(args), args[0], kwargs, len(kwargs))
        url = "http://localhost:"
        ret = func(*args, **kwargs)
        return url + str(ret)
    return locate_host

@send_to_remote
def add(x,y,z):
    return x+y+z


if __name__ == "__main__":
    ret = add(1,2,3)
    print ret

