import tkinter as tk
import time

# Set the countdown time in seconds
countdown_time = 1000  # e.g., 10 seconds

# Initialize the main window
root = tk.Tk()
root.title("Circular Countdown Timer")
root.geometry("300x300")

# Create a canvas to draw the circular timer
canvas = tk.Canvas(root, width=300, height=300, bg="white")
canvas.pack()

# Calculate center and radius of the circle
center_x, center_y = 150, 150
radius = 100

# Create a background circle
canvas.create_oval(center_x - radius, center_y - radius,
                   center_x + radius, center_y + radius,
                   outline="black", width=2)

# Timer text in the center
timer_text = tk.Label(root, text=str(countdown_time), font=("Arial", 24))
timer_text.place(x=140, y=135)

# Variable to store the current arc
arc = None

def update_timer(elapsed):
    global arc

    # Calculate the percentage of time left
    percent = elapsed / countdown_time

    # Calculate the end angle of the arc
    end_angle = 360 * percent

    # Update the arc
    if arc:
        canvas.delete(arc)
    arc = canvas.create_arc(center_x - radius, center_y - radius,
                            center_x + radius, center_y + radius,
                            start=90, extent=-end_angle,
                            fill="blue")

    # Update the timer text
    remaining_time = max(0, int(countdown_time - elapsed))
    timer_text.config(text=f"{remaining_time}")

def countdown(start_time):
    elapsed = time.time() - start_time

    if elapsed < countdown_time:
        # Update the circular timer
        update_timer(elapsed)
        # Call countdown again after 50 ms
        root.after(50, countdown, start_time)
    else:
        # Ensure the timer finishes at 0
        update_timer(countdown_time)
        timer_text.config(text="0")

# Start the countdown
start_time = time.time()
countdown(start_time)

# Run the tkinter main loop
root.mainloop()
