import sys

if len(sys.argv) < 2:
    print("Please provide a filename as the first argument.")
    sys.exit()

filename = sys.argv[1]

with open(filename, "r") as f:
    for line in f:
        if "IOPS" in line:
            iops = line.split("=")[1].split(",")[0].strip()
            print("IOPS= " + iops)
            bw = line.split("=")[2].split("(")[0].strip()
            print("BW= " + bw)
        elif " lat (usec):" in line:
            avg_lat = line.split("=")[3].split(",")[0].strip()
            print("lat= " + avg_lat + "us")
            print("")
        elif " lat (msec):" in line:
            avg_lat = line.split("=")[3].split(",")[0].strip()
            print("lat= " + avg_lat + "ms")
            print("")
