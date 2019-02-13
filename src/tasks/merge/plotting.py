import matplotlib.pyplot as plt


if __name__ == "__main__":
    x, y, z = [], [], []
    with open("../../../out.txt", 'r', encoding='utf-8') as out:
        for line in out:
            x.append(int(line.split(" ")[0]))
            y.append(int(line.split(" ")[1]))
            z.append(int(line.split(" ")[2]))
    plt.plot(y, 'b')
    plt.plot(z, 'r')
    plt.xlabel('Num of elements')
    plt.ylabel('Milliseconds')
    plt.legend(['blue - ordinary', 'red - multithreading'], loc='best')
    plt.savefig('../../../sort.pdf', bbox_inches='tight')
