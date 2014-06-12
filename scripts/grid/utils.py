def make_tardis():
    global factory
    print "Creating TARDIS"
    factory.create_object("../models/TARDIS", "TARDIS.dae")

def print_stuff(count=10):
    for y in range(count):
        for x in range(10):
            print "x is ", x

def fail():
    make_tardis()
    print_stuff()
