import pygame

# Initialize the mixer module
pygame.mixer.init()

# Load and play the mp3 file
pygame.mixer.music.load("path_to_your_audio_file.mp3")
pygame.mixer.music.play()

# Keep the script running until the music stops
while pygame.mixer.music.get_busy():
    pass
