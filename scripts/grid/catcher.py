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

#catcher = StdoutCatcher()
#sys.stdout = catcher
