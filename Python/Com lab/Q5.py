
class car:
    ''' car class '''

    def __init__(self,y,mo,mi):
        '''
        year : year of manufacture
        model : model of the car
        mileage : current mileage
        '''
        self.year = y
        self.model = mo
        self.mileage = mi

    def get_year(self):
        ''' Return of the manufacture year'''
        return self.year

    def get_model(self):
        return self.model

    def get_mileage(self):
        return self.mileage

    def accelerate(self):
        return "accelerating"


car1 = car(2019,"chr",5000)
car2 = car(2020,"BMW",1000)

