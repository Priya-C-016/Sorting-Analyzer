from flask import Flask, request, jsonify, send_from_directory
import subprocess
import json
import os

app = Flask(__name__, static_folder='.', static_url_path='')
open('result.json', 'w').close()

@app.route('/')
def serve_index():
    return send_from_directory('.', 'index.html')

@app.route('/sort', methods=['POST'])
def sort_array():
    data = request.get_json()
    array = data.get('array', '')

    with open('input.txt', 'w') as f:
        f.write(array)

    subprocess.run(['./sort'])  # Make sure 'sort' is compiled

    with open('result.json', 'r') as f:
        result = json.load(f)

    return jsonify(result)

if __name__ == '__main__':
    app.run(debug=True)
