import argparse
import random


def create_record():
    hour = random.randint(0, 23)
    minute = random.randint(0, 59)
    return '%02d' % hour + ':' + '%02d' % minute


def create_schedule(length, name):
    with open(name, 'w') as output:
        for index in range(length):
            output.write(create_record() + ' ' + create_record() + '\n')


parser = argparse.ArgumentParser(description='Generates parking lot schedule.')
parser.add_argument('length', metavar='length', type=int, help='schedule length as an integer')
parser.add_argument('name', metavar='name', type=str, help='name of the generated schedule')
args = parser.parse_args()
# create schedule
create_schedule(args.length, args.name)
