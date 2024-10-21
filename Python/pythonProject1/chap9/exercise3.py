class Instrument:
    def make_sound(self):
        pass

class Erhu(Instrument):
    def make_sound(self):
        print('二胡在演奏')

class Piano(Instrument):
    def make_sound(self):
        print('钢琴在演奏')

class Violin(Instrument):
    def make_sound(self):
        print('小提琴在弹奏')

def play(instrument):
    instrument.make_sound()

erhu = Erhu()
piano = Piano()
violin = Violin()

play(erhu)
play(piano)
play(violin)