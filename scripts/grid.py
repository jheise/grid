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



from time import time,ctime

print "Grid Online", ctime(time())
#print "Creating TARDIS"
#factory.create_object("../models/TARDIS", "TARDIS.dae")
#print "Creating 343 Guilty Spark"
#factory.create_object("../models/spark", "skpfile.dae")
