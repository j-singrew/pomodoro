import pygame

# Initialize the mixer module
pygame.mixer.init()

# Load and play the mp3 file
pygame.mixer.music.load("/Users/joshuasingrew/Documents/GitHub/safe_source/pomodoro/alarm_sound/mixkit-battleship-alarm-1001.wav")
pygame.mixer.music.play()

# Keep the script running until the music stops
while pygame.mixer.music.get_busy():
    pass
