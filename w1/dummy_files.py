import sys
import os

def usage_error():
    print("Usage:\n\tpython dummy_files.py number_of_files")
    sys.exit()

def create_dummy_files(i):
    while i > 0:
        name = "./files/file" + str(i) + ".txt"
        f = open(name, 'w')
        f.write(name)
        f.close()
        i-=1

if __name__ == "__main__":
    if not (len(sys.argv) == 2):
        usage_error()    
    try:
        num_files = int(sys.argv[1])
        if num_files <= 0: raise ValueError()
        if not os.path.isdir('files'):
            os.mkdir('files')
        create_dummy_files(num_files)
        print(f'{num_files} file(s) created.')
    except:
        usage_error()