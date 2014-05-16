#setup std out catching
import sys
class StdoutCatcher():
    def __init__(self):
        self._data = ""

    def write(self, data):
        self._data = self._data + data

    @property
    def data(self):
        retval = self._data
        self._data = ""
        return retval


catcher = StdoutCatcher()
sys.stdout = catcher

def make_tardis():
    print "Creating TARDIS"
    factory.create_object("../models/TARDIS", "TARDIS.dae")

def print_stuff(count=10):
    for y in range(count):
        for x in range(10):
            print "x is ", x



from time import time,ctime

print "Grid Online", ctime(time())
make_tardis()
#print "Creating TARDIS"
#factory.create_object("../models/TARDIS", "TARDIS.dae")
#for x in range(20):
    #print x
#print "Creating 343 Guilty Spark"
#factory.create_object("../models/spark", "skpfile.dae")
