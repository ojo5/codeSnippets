import socket

# Create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
s.connect(('localhost', 4242))

# Send data to the server
s.send(b'Hello, world')  # Prefix the string with 'b' to send bytes

# Receive data from the server
data = s.recv(1024)

# Close the connection
s.close()

# Print the received data
print('Received', data.decode('utf-8'))  # Decode the bytes to a string before printing