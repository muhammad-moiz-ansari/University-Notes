
#!/usr/bin/env python3
import sys
import csv
import matplotlib.pyplot as plt

def read_csv(path):
    xs, rtt, bw = [], [], []
    with open(path, "r") as f:
        reader = csv.DictReader(f)
        for row in reader:
            xs.append(int(row["bytes"]))
            rtt.append(float(row["avg_rtt_sec"]))
            bw.append(float(row["approx_bandwidth_Bps"]))
    return xs, rtt, bw

def main():
    if len(sys.argv) < 3:
        print("Usage: plot_pingpong.py input.csv output_prefix")
        sys.exit(1)

    inp = sys.argv[1]
    prefix = sys.argv[2]

    xs, rtt, bw = read_csv(inp)

    plt.figure()
    plt.xscale("log", base=2)
    plt.yscale("log")
    plt.plot(xs, rtt, marker="o")
    plt.xlabel("Message size (bytes)")
    plt.ylabel("Average RTT (sec)")
    plt.title("MPI Ping-Pong RTT vs Message Size")
    plt.grid(True, which="both")
    plt.tight_layout()
    plt.savefig(prefix + "_rtt.png", dpi=150)

    plt.figure()
    plt.xscale("log", base=2)
    plt.plot(xs, bw, marker="o")
    plt.xlabel("Message size (bytes)")
    plt.ylabel("Approx. one-way Bandwidth (B/s)")
    plt.title("MPI Ping-Pong Bandwidth vs Message Size")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(prefix + "_bw.png", dpi=150)

    print("Plots written:", prefix + "_rtt.png", prefix + "_bw.png")

if __name__ == "__main__":
    main()
