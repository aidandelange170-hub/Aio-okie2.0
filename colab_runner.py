"""
Google Colab runner for the Web-based IDE
This script sets up and runs the web IDE with proper ngrok tunneling for external access
"""

import subprocess
import time
import threading
from flask_ngrok import run_with_ngrok
from app import app

def install_dependencies():
    """Install required packages"""
    print("Installing dependencies...")
    subprocess.run(["pip", "install", "-r", "requirements.txt"], check=True)
    subprocess.run(["pip", "install", "flask-ngrok"], check=True)
    print("Dependencies installed successfully!")

if __name__ == '__main__':
    print("Setting up the Complex Multi-Language Web IDE...")
    print("This may take a moment...")
    
    # Install dependencies if needed
    try:
        install_dependencies()
    except:
        print("Dependencies may already be installed.")
    
    # Enable ngrok tunneling
    run_with_ngrok(app)
    
    print("\nStarting the Web IDE...")
    print("Once started, you'll see a public URL above - open that in a new browser tab")
    
    # Run the app
    app.run()