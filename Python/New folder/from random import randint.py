from kivy.app import App

from kivy.app import App
from kivy.uix.gridlayout import GridLayout
from kivy.uix.label import Label # The uix module contains user interface elements
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
class MainScreen(GridLayout):

    def __init__(self, **kwargs):
        super(MainScreen,self).__init__(**kwargs)

        self.cols = 1

        # -- inside --
        self.inside = GridLayout()
        self.inside.cols = 2
        self.inside.add_widget(Label(text='First Number'))
        self.firstnumber = TextInput(multiline=False)
        self.inside.add_widget(self.firstnumber)
        self.inside.add_widget(Label(text='Second Number'))
        self.secondnumber = TextInput(multiline=False)
        self.inside.add_widget(self.secondnumber)
        # -- end of inside --
        self.add_widget(self.inside)
self.total = Label(text='Answer is')
        self.add_widget(self.total)
        self.findtotal = Button(text="Find Total", font_size=40)
        self.add_widget(self.findtotal)
        self.findtotal.bind(on_press = self.callback)

    def callback(self, event):
        firstnumber = self.firstnumber.text
        secondnumber= self.secondnumber.text
        total = int(firstnumber) + int(secondnumber)
        # Update the answer
        self.total.text = 'Answer is ' + str(total)
From Sampath Deegalla to Everyone:  11:04 AM
# define the base class of Kivy App
class MyApp(App): 

    # initialize and return the Root Widget
    def build(self):
        return MainScreen()

MyApp().run()
