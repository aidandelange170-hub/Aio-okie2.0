#!/usr/bin/env python3
"""
Web-based IDE application that replicates the functionality of the C++ GUI version
"""
import os
import json
from flask import Flask, render_template, request, jsonify, send_from_directory
import subprocess
import tempfile
import threading
from datetime import datetime

app = Flask(__name__)

# Load configuration
import json
with open('config.json', 'r') as f:
    config = json.load(f)

# Language support mapping
LANGUAGES = {
    'cpp': {'name': 'C++', 'extension': '.cpp', 'color': '#f34b7d'},
    'python': {'name': 'Python', 'extension': '.py', 'color': '#3572A5'},
    'javascript': {'name': 'JavaScript', 'extension': '.js', 'color': '#f1e05a'},
    'java': {'name': 'Java', 'extension': '.java', 'color': '#b07219'},
    'csharp': {'name': 'C#', 'extension': '.cs', 'color': '#178600'},
    'ruby': {'name': 'Ruby', 'extension': '.rb', 'color': '#701516'},
    'php': {'name': 'PHP', 'extension': '.php', 'color': '#4F5D95'},
    'go': {'name': 'Go', 'extension': '.go', 'color': '#00ADD8'}
}

# Store active sessions
sessions = {}

class CodeRunner:
    @staticmethod
    def run_code(code, language):
        """Execute code in the specified language"""
        try:
            with tempfile.NamedTemporaryFile(mode='w', delete=False, suffix=LANGUAGES[language]['extension']) as f:
                f.write(code)
                temp_file = f.name
            
            output = ""
            error = ""
            
            if language == 'python':
                result = subprocess.run(['python3', temp_file], capture_output=True, text=True, timeout=10)
            elif language == 'javascript':
                result = subprocess.run(['node', temp_file], capture_output=True, text=True, timeout=10)
            elif language == 'cpp':
                # Compile and run C++
                exe_file = temp_file.replace(LANGUAGES[language]['extension'], '.exe')
                compile_result = subprocess.run(['g++', '-o', exe_file, temp_file], capture_output=True, text=True)
                if compile_result.returncode == 0:
                    result = subprocess.run([exe_file], capture_output=True, text=True, timeout=10)
                    os.remove(exe_file)
                else:
                    return {"output": "", "error": compile_result.stderr}
            elif language == 'java':
                # Compile and run Java
                class_name = os.path.basename(temp_file).replace('.java', '')
                class_dir = os.path.dirname(temp_file)
                compile_result = subprocess.run(['javac', temp_file], capture_output=True, text=True, cwd=class_dir)
                if compile_result.returncode == 0:
                    result = subprocess.run(['java', class_name], capture_output=True, text=True, timeout=10, cwd=class_dir)
                    os.remove(os.path.join(class_dir, class_name + '.class'))
                else:
                    return {"output": "", "error": compile_result.stderr}
            elif language == 'csharp':
                # Run with mono if available
                result = subprocess.run(['mono', temp_file], capture_output=True, text=True, timeout=10)
            elif language == 'ruby':
                result = subprocess.run(['ruby', temp_file], capture_output=True, text=True, timeout=10)
            elif language == 'php':
                result = subprocess.run(['php', temp_file], capture_output=True, text=True, timeout=10)
            elif language == 'go':
                result = subprocess.run(['go', 'run', temp_file], capture_output=True, text=True, timeout=10)
            else:
                return {"output": "", "error": f"Language {language} not supported"}
            
            os.remove(temp_file)
            
            return {
                "output": result.stdout,
                "error": result.stderr if result.returncode != 0 else ""
            }
        except subprocess.TimeoutExpired:
            return {"output": "", "error": "Execution timed out after 10 seconds"}
        except Exception as e:
            return {"output": "", "error": f"Execution error: {str(e)}"}

@app.route('/')
def index():
    """Main page of the IDE"""
    return render_template('index.html', languages=LANGUAGES)

@app.route('/api/run', methods=['POST'])
def run_code():
    """Execute code and return output"""
    data = request.json
    code = data.get('code', '')
    language = data.get('language', 'python')
    
    result = CodeRunner.run_code(code, language)
    return jsonify(result)

@app.route('/api/languages', methods=['GET'])
def get_languages():
    """Get supported languages"""
    return jsonify(LANGUAGES)

@app.route('/api/save', methods=['POST'])
def save_file():
    """Save file to server"""
    data = request.json
    code = data.get('code', '')
    filename = data.get('filename', 'untitled.txt')
    
    try:
        with open(filename, 'w') as f:
            f.write(code)
        return jsonify({"success": True, "message": f"File {filename} saved successfully"})
    except Exception as e:
        return jsonify({"success": False, "error": str(e)})

@app.route('/api/load', methods=['POST'])
def load_file():
    """Load file from server"""
    data = request.json
    filename = data.get('filename', '')
    
    try:
        with open(filename, 'r') as f:
            content = f.read()
        return jsonify({"success": True, "content": content})
    except Exception as e:
        return jsonify({"success": False, "error": str(e)})

@app.route('/static/<path:path>')
def send_static(path):
    return send_from_directory('static', path)

if __name__ == '__main__':
    app.run(host=config.get('host', '0.0.0.0'), port=config.get('port', 5000), debug=config.get('debug', True))