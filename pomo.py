import time
import tkinter as tk
from tkinter import *
import pygame

root=tk.Tk()
root.geometry("300x400")

h_var = tk.IntVar()
m_var = tk.IntVar()
s_var = tk.IntVar()
r_var = tk.IntVar()

pygame.mixer.init()

def countdown(total_seconds):
    if total_seconds >= 0:
        hours, remainder = divmod(total_seconds,3600)
        minutes,seconds = divmod(remainder, 60)
        timer_text = f"{int(hours):02}:{int(minutes):02}:{int(seconds):02}"
        disp.config(text=timer_text)


        root.after(1000, countdown, total_seconds -1)
    else:
        pygame.mixer.music.load("/Users/joshuasingrew/Documents/GitHub/safe_source/pomodoro/alarm_sound/mixkit-rooster-crowing-in-the-morning-2462.wav")
        pygame.mixer.music.play()
        minutes,seconds = divmod(remainder, 60)
        timer_text = f"{int(minutes):02}:{int(seconds):02}"
        disp.config(text=timer_text)



def submit():
    h = h_var.get()
    m = m_var.get()
    S = s_var.get()
    r = r_var.get()


    total_seconds = h * 3600 + m *60 +S
    countdown(total_seconds)


def pomo():
    global disp
    h_label = tk.Label(root,text='hour',font =('calibre',10,'bold'))

    hour_entry =    tk.Entry(root,textvariable= h_var,font=('calibre',10,'bold'))

    m_label = tk.Label(root, text =     'minute',font =               ('calibre',10,'bold'))
    minut_entry =    tk.Entry(root,textvariable=    m_var,font=('calibre',10,'bold'))

    s_label = tk.Label(root, text =     'second',font =               ('calibre',10,'bold'))
    s_entry = tk.Entry(root,textvariable=    s_var,font=('calibre',10,'bold'))

    r_label = tk.Label(root,text = 'rest',font=('calibre',10,'bold') )
    r_entry  = tk.Entry(root,textvariable= r_var,font=('calibre',10,'bold'))



    sub_btn=tk.Button(root,text='Submit',command = submit)

    disp = tk.Label(root, text="00:00:00", width=10, height=5, bg="green", fg="white", font=("Helvetica", 20))

    h_label.grid(row=0,column=0)
    hour_entry.grid(row=0,column=1)

    m_label.grid(row=1,column=0)
    minut_entry.grid(row=1,column=1)

    s_label.grid(row=2,column=0)
    s_entry.grid(row=2,column=1)

    r_label.grid(row=3,column=0)
    r_entry.grid(row=3,column=1)

    sub_btn.grid(row=4,column=1)
    disp.grid(row=5, column=0, columnspan=2, pady=20)

pomo()
root.mainloop()
