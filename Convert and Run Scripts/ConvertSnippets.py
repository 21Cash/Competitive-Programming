import os
import re
from datetime import datetime

def log_message(message):
    # Log the message to log.txt with a timestamp
    with open('log.txt', 'a') as log_file:
        timestamp = datetime.now().strftime('%I:%M %p %d %b %Y')
        log_file.write(f"[Time {timestamp}] : {message}\n")
    # Print the message to the console without a timestamp
    print(message)

def extract_code_from_snippet(snippet_content):
    # Use regex to find the content within the CDATA section
    pattern = re.compile(r'<!\[CDATA\[(.*?)\]\]>', re.DOTALL)
    match = pattern.search(snippet_content)
    if match:
        code = match.group(1).strip()
        # Replace placeholders like ${2:false} with 'false'
        code = re.sub(r'\$\{\d+:(.*?)\}', r'\1', code)
        # Replace placeholders like $0, $1, $2 with an empty string
        code = re.sub(r'\$\d+', '', code)
        return code
    return ""

def ensure_file_exists(filename):
    if not os.path.exists(filename):
        with open(filename, 'w') as file:
            file.write('')

def read_directory_path(filename):
    if os.path.exists(filename):
        with open(filename, 'r') as file:
            return file.read().strip()
    return None

def create_templates_folder(output_path):
    if not os.path.exists(output_path):
        os.makedirs(output_path)

def process_snippet_files(snippets_path, templates_path):
    snippet_files = [f for f in os.listdir(snippets_path) if f.endswith('.sublime-snippet')]
    generated_files_count = 0

    for snippet_file in snippet_files:
        snippet_filepath = os.path.join(snippets_path, snippet_file)
        with open(snippet_filepath, 'r') as file:
            content = file.read()
        
        code = extract_code_from_snippet(content)
        
        if code:
            new_filename = os.path.splitext(snippet_file)[0] + '.cpp'
            new_filepath = os.path.join(templates_path, new_filename)
            
            with open(new_filepath, 'w') as new_file:
                new_file.write(code)
            generated_files_count += 1

    return generated_files_count

if __name__ == "__main__":
    # Clear the log file at the start
    with open('log.txt', 'w') as log_file:
        log_file.write('')

    ensure_file_exists("AbsoluteSnippetsDirectory.txt")
    ensure_file_exists("AbsoluteTemplateOutputDirectory.txt")
    
    snippets_path = read_directory_path("AbsoluteSnippetsDirectory.txt")
    templates_path = read_directory_path("AbsoluteTemplateOutputDirectory.txt")

    if snippets_path is None or templates_path is None:
        log_message("Files named AbsoluteTemplateOutputDirectory.txt or AbsoluteSnippetsDirectory.txt not found. Create the files and paste the paths.")
    elif not os.path.exists(snippets_path):
        log_message("The directory specified in AbsoluteSnippetsDirectory.txt does not exist.")
    elif not os.path.exists(templates_path):
        log_message("The directory specified in AbsoluteTemplateOutputDirectory.txt does not exist.")
    else:
        create_templates_folder(templates_path)
        generated_files_count = process_snippet_files(snippets_path, templates_path)
        log_message(f"{generated_files_count} files Converted.")
        
        # Output the final message and wait for any key press
        print(f"{generated_files_count} Snippet(s) converted.")
        input("Press any key to close.")
