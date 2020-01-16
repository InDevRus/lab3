import math
import matplotlib.pyplot
import serial

delay_duration = 10
distance_limit = 30

port = 'COM8'
baudrate = 115200

monitor = None
plotter = matplotlib.pyplot


def main():
    points_to_draw_count = 0

    plotter.ion()
    axes = plotter.axes(projection='polar')
    axes.grid(True)
    axes.set(xlim=(0, math.pi), ylim=(0, 40))

    plotter.show()

    while monitor.isOpen():
        axes.set(xlim=(0, math.pi), ylim=(0, 40))
        data = monitor.readline().split()
        angle = int(data[0])
        distance = float(data[1])

        if angle * (angle - 180) == 0:
            plotter.cla()

        if distance > distance_limit:
            continue

        points_to_draw_count += 1

        print(angle, distance)
        
        plotter.polar(math.radians(angle), distance, 'o')

        if points_to_draw_count >= 10:
            plotter.draw()
            points_to_draw_count = 0

        plotter.pause(1e-3 * delay_duration)

    plotter.close()


if __name__ == "__main__":
    try:
        monitor = serial.Serial(port, baudrate)
        main()
    except:
        pass
