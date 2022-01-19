class HackerEarth1:   
    def _str_(self):
        return 'Hack1'

class HackerEarth2(HackerEarth1):
    def _str_(self):
        return 'Hack2'

class HackerEarth3 (HackerEarth2):
    pass

Hack = HackerEarth3()
print(Hack)