#setup std out catching
import sys
import site
site.addsitedir("/home/jubei/code/personal/grid/scripts")
import grid.catcher
from grid.utils import print_stuff

catcher = grid.catcher.StdoutCatcher()
sys.stdout = catcher

def make_tardis():
    print "Creating TARDIS"
    factory.create_object("../models/TARDIS", "TARDIS.dae")

def fail():
    make_tardis()
    print_stuff()



from time import time,ctime
#lightfactory.create_light(0, 0, 8, 0, 0, 1) #blue
lightfactory.create_light(0, 0, 8, 1, 1, 1) #white
#lightfactory.create_light(0, 0, 8, 0, 0, 0) #black
print "Grid Online", ctime(time())

make_tardis()
#print "Creating TARDIS"
#factory.create_object("../models/TARDIS", "TARDIS.dae")
#for x in range(20):
    #print x
#print "Loading Monkey"
#factory.create_object("../models/monkey", "monkey.obj")
#factory.create_object("../models/phoenix", "phoenix_ugv.md2")
#factory.create_object("../models/box", "box.obj")
#print "Creating 343 Guilty Spark"
#factory.create_object("../models/spark", "skpfile.dae")
