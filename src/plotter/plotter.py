import math
import matplotlib.pyplot
import serial

delay_duration = 20

port = 'COM3'
baudrate = 115200

monitor = serial.Serial(port, baudrate)
plotter = matplotlib.pyplot


def main():
    plotter.ion()
    axes = plotter.axes(projection='polar')
    axes.grid(True)
    axes.set(xlim=(0, math.pi), ylim=(0, 40))

    plotter.show()

    while monitor.isOpen():
        data = monitor.readline().split()
        angle = int(data[0])
        distance = float(data[1])

        if angle == 0:
            plotter.cla()
        
        plotter.polar(math.radians(angle), distance, 'o')
        plotter.draw()
        plotter.pause(1e-3 * delay_duration)

    plotter.close()


if __name__ == "__main__":
    main()
